void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {}
}

int pinCheck[] = {22, 26, 30, 34};
int pinLen = sizeof(pinCheck)/sizeof(pinCheck[0]);

void loop() { // run over and over
  for (int i = 0; i < pinLen; i++) {
    if (Serial.readString() == (String(pinCheck[i]) + "_ON")) {
      Serial.println("Acceso");
    }
  }
  
  Serial.write(Serial.read());
  
}
