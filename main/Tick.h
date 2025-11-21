
class Tick_t {
  public:
    bool is_pending;
    uint32_t millis_prev;
    uint32_t ticks;

    uint32_t msec;

    uint32_t interval_as_msec;

    bool init(uint32_t new_interval_as_msec) {
      is_pending = 0;
      ticks = 0;
      msec = 0;
      millis_prev = 0;
      interval_as_msec = new_interval_as_msec;
    }


    bool poll(uint32_t new_interval_as_msec) {
      interval_as_msec = new_interval_as_msec;
      poll();
    }

    bool poll() {
      is_pending = false;
      if (millis() - millis_prev >= interval_as_msec) { // Check for Tick event!
        /* A Tick is the smallest unit of time that we allow our code to run
        * eg, a 1ms tick runs 1000 times a second, while a 500ms tick only runs 2 times a second.
        *  There are times when we want absolute time in milliseconds for human convenience, while
        * Ticks allow us to allow time to pass in big chunks without doing anything.

        * For convenience, make 1 tick = 1msec.
        */

        millis_prev = millis();
        msec += interval_as_msec;
        ticks++;
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
