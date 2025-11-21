// Board Confing

const unsigned BOARD_LED = LED_BUILTIN;

// User Constants
const uint32_t TICK_AS_MSEC  = 1;    // time event granularity
const uint32_t STATUS_AS_MSEC = 1; // how often we see messages
const uint32_t BLINK_AS_MSEC = 500;  // LED toggle delay
const uint32_t POT_SAMPLE_AS_MSEC = 10;  // Potentiomter sammple rate
const uint32_t BUTTON_SAMPLE_AS_MSEC = 10; // Button sample rate
const uint32_t VERBOSE_AS_MSEC  = 1000;  // Verbose message time

const uint32_t nLED_Red = PD2;
const uint32_t nLED_Green = PD3;
const uint32_t nLED_Blue = PD4;
const uint32_t LED_White = PD6;

const uint32_t USB_BAUD = 115200;

const uint32_t Button_NO = PD5;
const uint32_t Analog_Pot = A7;

const uint32_t ACTIVE_HIGH = 1;
const uint32_t ACTIVE_LOW = 0;

const uint32_t ACTIVE = 4;
const uint32_t IDLE = 0;

const uint32_t NORMALLY_CLOSED = 1;
const uint32_t NORMALLY_OPEN = 0;



// Note that intervals should be less than 1000 msec, and be convenient multiples of tick interval for best results

// Conversions
const uint32_t VERBOSE_AS_TICKS = VERBOSE_AS_MSEC/TICK_AS_MSEC;
const unsigned int BLINK_AS_TICKS = BLINK_AS_MSEC/TICK_AS_MSEC;  // LED toggle delay
const unsigned int STATUS_AS_TICKS = STATUS_AS_MSEC/TICK_AS_MSEC; // how often we see messages

extern uint32_t loop_count ;


enum LEDName {
  Red = 0,
  Green = 1,
  Blue = 2,
  White = 3,
};

enum StateName {
  Idle = 0,
  Active = 1,
  Rising = 2,
  Falling = 3,
  Inactive = 4,
  NoChange = 100,
};

#include "Tick.h"
#include "Verbose.h"
#include "Blink.h"
#include "Status.h"
#include "LED.h"
#include "Console.h"

#include "AnalogIO.h"
#include "DigitalIO.h"

