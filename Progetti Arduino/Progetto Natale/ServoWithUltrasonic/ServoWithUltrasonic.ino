#include <Servo.h>
//#include <LiquidCrystal.h>

int bluePin = 34;
int servoPin = 17;
int trigPin = 14;
int echoPin = 15;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myservo;

void setup() {
  myservo.attach(servoPin);
  myservo.write(0);
  pinMode(bluePin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  //lcd.begin(16, 2);
}

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
  if (distance <= 20) {
    digitalWrite(bluePin, HIGH);
    myservo.write(90);
    delay(500);
  } else {
    digitalWrite(bluePin, LOW);
    myservo.write(0);
  }
  //lcd.begin(16, 2);
  //lcd.print(distance);
  //lcd.print("cm");
  delay(200);
}
