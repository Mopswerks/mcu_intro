class LED_t {
  public:
  int pin;
//  int mode;

  int value_active;

  int state;

    char name[16];


  bool toggle() {
    int value = digitalRead(pin);
    digitalWrite(pin, !value);
    return true;
  }

  bool set() {
    digitalWrite(pin, value_active);
  }
  bool clear() {
    digitalWrite(pin, !value_active);
  }

  bool init(int newPin, int new_value_active ) {
      pin = newPin;
//      mode = newMode;
      pinMode(pin, OUTPUT);
      value_active = new_value_active;
      state = !value_active;
      digitalWrite(pin, state);
  }

  void print(char * scratch) {
      Serial.print(" LED toggle ");
      int led = digitalRead(LED_BUILTIN);
      if (led) Serial.print("ON");
      else Serial.print("OFF");   
  }


};