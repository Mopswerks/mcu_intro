#include "declarations.h"

// Global Instances
uint32_t loop_count = 0;

Tick_t Tick;
Verbose_t Verbose;
Blink_t Blink;
Status_t Status;
LED_t builtin;
LED_t rgb[3];
LED_t white;

DigitalIO_t Mode;
AnalogIO_t Intensity;
Console_t Console;

int button_idle = 0;
int button_hold = 0;
int button_state = Idle;
int button_show = 500;


void loop() {
  // put your main code here, to run repeatedly:

  int is_busy = 0;


  if (Tick.poll()) {  // if a Tick interval has elapsed ..

    if (Verbose.poll(1)) is_busy++;; // derive Verbose events using 1 tick increment

    if (Blink.poll(Tick.ticks)) { // if Blink interval has elapsed
      builtin.toggle();
      is_busy++;
    }

      Intensity.read();

      Mode.poll();
        
      switch (Mode.state) {
        case Rising:
          button_hold = 0;
          button_idle = 0;
          is_busy++;
          rgb_set(Idle, Active, NoChange);
        break;
        case Falling:
          button_hold = 0;
          button_idle = 0;
          is_busy++;
          rgb_set(Active,Idle,NoChange);

        case Active:
          button_hold++;
          button_idle++;;
          if (button_hold >= button_show)
            rgb_set(NoChange,NoChange,Active);
          led_set(&white, Active);
          break;

        case Inactive:
        case Idle:
          button_idle++;
          button_hold = 0;
          rgb_set(NoChange,NoChange,Idle);
          led_set(&white, Inactive);
          break;
        default:
          break;
      }        

      if (button_idle >= button_show) {
        rgb_set(Idle,Idle,NoChange);
      }




    if (is_busy && Status.poll(Tick.ticks)) {
      formatted_output();
    }

  }
  loop_count++;
}

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  Serial.begin(USB_BAUD);
//  Console.init(USB_BAUD);
  Console.print("setup(): Start\n");


  Intensity.init(Analog_Pot, POT_SAMPLE_AS_MSEC);

  Mode.init(Button_NO, INPUT_PULLUP, BUTTON_SAMPLE_AS_MSEC, NORMALLY_OPEN, ACTIVE_LOW);

  rgb[Red].init(nLED_Red, 0);
  rgb[Green].init(nLED_Green, 0);
  rgb[Blue].init(nLED_Blue, 0);

  white.init(LED_White, 1);



  Console.print("\tWelcome to non-blocking millis() Events!\n");

  Tick.init(TICK_AS_MSEC);
  Verbose.init(VERBOSE_AS_MSEC);
  builtin.init(BOARD_LED, 1);
  Blink.init(BLINK_AS_TICKS);
  Status.init(STATUS_AS_TICKS);

  Console.print("setup(): End\n");

}

