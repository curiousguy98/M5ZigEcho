char inByte;
const char tx_test1[] = {0xFE, 0x0C, 0xA1, 0xA1,0xD8 ,0x01 ,0x31 ,0x32 ,0x33 ,0x34 ,0x35 ,0x36 ,0x37 ,0x38 ,0xFF};
const char tx_test2[] = {0xFE,0x05 ,0xA0 ,0xA0 ,0xF8 ,0x01 ,0x17 ,0xFF};
#define countof(a) (sizeof(a) / sizeof(a[0]))

void setup() {
  // start serial port at 9600 bps
  Serial.begin(115200);
  Serial1.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial1.available() > 0) {
    // get incoming byte:
    inByte = Serial1.read();
    Serial.write(inByte);
  }
  else{
    for (int i = 0; i < countof(tx_test1); i++){
      Serial1.write(tx_test1[i]);
    }

    delay(5000);
  }
  
}

