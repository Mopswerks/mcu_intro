class Verbose_t {
  public:

  uint32_t last_sec;
  uint32_t msec;

  uint32_t interval_as_msec;
  bool is_pending;

  bool init(uint32_t new_interval_as_msec) {
//    sec = 0;
    last_sec = 0;
    msec = 0;
    interval_as_msec = new_interval_as_msec;
  }

  bool poll(uint32_t ticks) {
    is_pending = false;

    msec += TICK_AS_MSEC * ticks;

    if ((msec >= VERBOSE_AS_MSEC) && (last_sec != msec/1000)) { // Check for a second elapsed

//      sec++;
      last_sec = msec/1000;
//      msec = 0;

      is_pending = true;
    }
    return is_pending;
  } 

  void print(char * scratch) {
    sprintf(scratch, "(%u.", msec/1000);    // Print out time in sec.msec
    Serial.print(scratch);
    sprintf(scratch, "%03u)",msec%1000);
    Serial.print(scratch);
  }

};