class Console_t {
  public:


  int baudrate;

  char scratch[80];


  void init(uint32_t new_baudrate) {

    baudrate = new_baudrate;
    Serial.begin(baudrate);
  }

  int print() {
    Serial.print(scratch);
  }

  int print(char * buffer) {
    Serial.print(buffer);

  }

  int poll() {


  }

};