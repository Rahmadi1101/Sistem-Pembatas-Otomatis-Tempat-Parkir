#include <Servo.h> 

#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 2
#define BUZZER_PIN 4
#define RELAY_PIN 3
#define SERVO_PIN 5 

Servo servoMotor;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  servoMotor.attach(SERVO_PIN); 
  servoMotor.write(0); 

  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) * 0.0344;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) {
    digitalWrite(LED_PIN, LOW); 
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RELAY_PIN, LOW); 

    servoMotor.write(90); 
    Serial.println("Servo: Katup terbuka");
  } else {
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(BUZZER_PIN, LOW);  
    digitalWrite(RELAY_PIN, HIGH); 

    servoMotor.write(0); 
    Serial.println("Servo: Katup tertutup");
  }

  delay(1000); 
}
