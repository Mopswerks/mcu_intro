  void formatted_output() {
    char scratch[80];

    Tick.print(scratch);

    Console.print(" Intensity(");
    Serial.print(Intensity.value);
    Console.print(")");

    Serial.print(" Mode: Raw(");
    Serial.print(Mode.raw);
    Serial.print(") Level(");
    Serial.print(Mode.level);
    Serial.print(")");
    Serial.print(") State(");
    Serial.print(Mode.state);
    Serial.print(")");

#if 0
    if (Mode.raw == ACTIVE_LOW)
    {
      rgb[Red].toggle();
      rgb[Green].toggle();
      rgb[Blue].toggle();
    }
#endif
#if 0
    if (Mode.state == ACTIVE)
    {
      rgb[Red].set();
      rgb[Green].set();
      rgb[Blue].set();
    } else {
      rgb[Red].clear();
      rgb[Green].clear();
      rgb[Blue].clear();
    }
#endif
    if (Blink.is_pending) {              // If LED was toggled in THIS loop, say so
      builtin.print(scratch);
    }

    if (Verbose.is_pending) {         // If 1 second has elapsed, print a summary
      Console.print(" Loops/Second: ");
      Serial.print(loop_count);

      Console.print(" Loops/Tick: ");
      Serial.print(loop_count/(1000/TICK_AS_MSEC));

      Console.print(" msec/tick: ");
      Serial.print(TICK_AS_MSEC);

      loop_count = 0;
    }

    Console.print("\n");

  
  };



  void led_set(LED_t * led, int value) {

    switch (value) {
      case Active:
        led->set();
        break;
      case Idle:
      case Inactive:
        led->clear();
        break;
      default:
        break;
    }

  }

  void rgb_set(int r, int g, int b) {
    led_set(&rgb[Red], r);
    led_set(&rgb[Green], g);
    led_set(&rgb[Blue], b);
  }
