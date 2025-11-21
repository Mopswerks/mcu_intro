class Blink_t {
  public:
    bool is_pending;
    uint32_t interval_as_ticks;

    bool init(uint32_t new_interval_as_ticks) {
      interval_as_ticks = new_interval_as_ticks;
    }
    bool poll(uint32_t ticks) {
      is_pending = false;
      if ((ticks % interval_as_ticks) == 0) { 
        /*
        * The mod "%" operator is the remainder of a integer division, eg 5 % 3 = 2.
        * This is useful for triggering an event on a multiple, aka every 10th iteration.
        */

        is_pending = true;  // Set a flag for processing later
      }
      return is_pending;
    }  

};
