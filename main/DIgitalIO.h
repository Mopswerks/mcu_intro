class DigitalIO_t {
  public:

    int pin;
  int mode;

  int interval_as_msec;

  int state_normal;
  int state_active;
  int state; // current
  int state_prev;

  int raw;
  int level;
  int level_prev;
  char name[16];

  bool init(int newPin, int newPinMode, int newInterval_as_msec, int new_normal_state, int new_active_state) {
    pin = newPin;
    mode = newPinMode;
    pinMode(pin, mode);
    interval_as_msec = newInterval_as_msec;
    raw = 0;

    state_active = new_active_state;
    state_normal = new_normal_state;
    state = IDLE;
    state_prev = IDLE;
    level = IDLE;
  }


  int raw_sample() {
    raw = digitalRead(pin);
    return raw;
  }

  int level_sample() {  // level
    raw = digitalRead(pin);
    if (raw == state_active) level = ACTIVE;
    else level = IDLE;
    return level;
  }

  int state_get() {
    int is_changing = 0;
    level_sample();
    if ((level_prev == ACTIVE) && (level == ACTIVE)) { // still active
      state = Active;
    } else if ((level_prev == IDLE) && (level == IDLE)) { // still active
      state = Idle;
    } else if ((level_prev == IDLE) && (level == ACTIVE)) { // rising
      state = Rising;

    } else if ((level_prev == ACTIVE) && (level == IDLE)) { // rising
      state = Falling;
    }
    level_prev = level;

    return state;    
  }

  int edge_get() {
    int is_changing = 0;

    state_get();
    switch (state) {
      case Rising:
      case Falling:
        return state;
        break;
      default:
        break;
    }

    return Idle;
  }


  int poll() {
    int is_busy = state_get();
    return is_busy;
  }


  void print(char * scratch) {
    Serial.print(" DigialIO: ");
  }
};