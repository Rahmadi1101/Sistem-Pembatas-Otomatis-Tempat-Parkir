KODE PROGRAM ARDUINO:

#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 2
#define BUZZER_PIN 4
#define RELAY_PIN 3

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

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

  // Menampilkan hasil pengukuran jarak
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) {
    digitalWrite(LED_PIN, LOW);  
    digitalWrite(BUZZER_PIN, HIGH);  
    digitalWrite(RELAY_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);  
    digitalWrite(BUZZER_PIN, LOW); 
    digitalWrite(RELAY_PIN, HIGH);  
  }

  delay(1000); 
}
