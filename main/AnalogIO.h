class AnalogIO_t {
  public:

  int pin;

  int interval_as_ticks;


  int value_last;
  int value;
  char name[16];

    bool init(int newPin, int newInterval_as_ticks ) {
      pin = newPin;
//      pinMode(pin, INPUT);
      interval_as_ticks = interval_as_ticks;
      value = 0;
      value_last = 0;


  }

  int poll(uint32_t ticks) {


  }

  int read() {
    value = analogRead(pin);
  }



    void print(char * scratch) {
      Serial.print(" AnalogIO: ");
  }



};