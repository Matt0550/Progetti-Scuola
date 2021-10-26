#include <Servo.h>

#define JOYSTICK_X A8
#define JOYSTICK_Y A9

#define greenPin 36
#define servoPin 2
#define trigPin 7
#define echoPin 6
#define led 13
#define verifica 12

#define ledDestra 29
#define ledSinistra 37

Servo myservo;

void setup() {
  pinMode(25, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(0);
  pinMode(greenPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(verifica, INPUT);
  digitalWrite(led, HIGH);
  pinMode(ledDestra, OUTPUT);
  pinMode(ledSinistra, OUTPUT);
  digitalWrite(ledDestra, HIGH);
  digitalWrite(ledSinistra, HIGH);
  delay(500);
  digitalWrite(ledDestra, LOW);
  digitalWrite(ledSinistra, LOW);
  Serial.begin(9600);
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
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
 
  if (distance <= 20) {
    digitalWrite(greenPin, HIGH);
    myservo.write(90);
    delay(500);
  } else {
    digitalWrite(greenPin, LOW);
    myservo.write(0);
    delay(500);
  }
  
  int x = analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);

  //Serial.println("X: " + String(x));
  //Serial.println("Y: " + String(y));

  digitalWrite(ledDestra, LOW);
  digitalWrite(ledSinistra, LOW);
  
  if (x > 400 && x < 520)
  {
    
  }
  else if (x < 400)
  {
    digitalWrite(ledDestra, HIGH);
     delay(200);
  }
  else if (x > 530)
  {
    digitalWrite(ledSinistra, HIGH);
     delay(200);
  }

  int stato_led = digitalRead(verifica);
  if (stato_led == 0){
    Serial.println(stato_led);
    digitalWrite(25, HIGH);
    delay(300);
  }
  else{
    Serial.println(stato_led);
    digitalWrite(25, LOW);
    delay(300);
  }
}
