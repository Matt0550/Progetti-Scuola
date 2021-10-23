// inclusione della libreria Stepper 
#include <Stepper.h>
#include <Servo.h>

#define JOYSTICK_X A8
#define JOYSTICK_Y A9
#define JOYSTICK_BUTTON 46

#define bluePin 34
#define greenPin 30
#define yellowPin 24
#define redPin 22

#define servoPin 17
#define trigPin 14
#define echoPin 15

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15;

Stepper myStepper(stepsPerRevolution, 7, 8, 9, 10 );
Servo myservo;

void setup() {
  myStepper.setSpeed(rolePerMinute);
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);

  myservo.attach(servoPin);
  myservo.write(0);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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
    digitalWrite(bluePin, HIGH);
    myservo.write(90);
    delay(500);
  } else {
    digitalWrite(bluePin, LOW);
    myservo.write(0);
  }
  
  int x = analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);
  int button = !digitalRead(JOYSTICK_BUTTON);

  //Serial.print("X: " + String(x));
  //Serial.print(",\tY:" + String(y));
  //Serial.println(",\tP: " + String(button));

  if (x > 400 && x < 520)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, LOW);
    }
  }
  else if (x < 400)
  {
    myStepper.setSpeed(rolePerMinute);
    myStepper.step(30);
  }
  else if (x > 530)
  {
    myStepper.setSpeed(rolePerMinute);
    myStepper.step(-30);
    
  }
  delay(200);

}
