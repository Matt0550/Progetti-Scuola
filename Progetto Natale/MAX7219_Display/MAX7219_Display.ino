#include "LedControl.h"
#define DIN 21
#define CS 20
#define CLK 19
#define Moduli 1

#define bluePin 34
#define greenPin 30
#define yellowPin 26
#define redPin 22

LedControl lc = LedControl(DIN, CLK, CS, Moduli);

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);
  lc.setIntensity(0, 6);
  lc.clearDisplay(0);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, HIGH);
  delay(500);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);

  Serial.begin(9600);
}

int row = 0;
int col = -1;
int pinCheck[] = {22, 26, 30, 34};
int pinLen = sizeof(pinCheck)/sizeof(pinCheck[0]);

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bluePin, HIGH);
  for (int i = 0; i < pinLen; i++) {
    if (digitalRead(pinCheck[i]) == HIGH)
    {
      col++;
      if (col == 8) {
        row++;
        col=0;
      }
      lc.setLed(0, col, row, true);
      
      Serial.println(String(pinCheck[i]) + "_ON");
    }
  }
  delay(5000);
  lc.clearDisplay(0);
  row = 0;
  col = -1;

}
