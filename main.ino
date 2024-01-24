const int irSensor1 = 3; 
const int irSensor2 = 4; 

void setup() {
  Serial.begin(9600);
  
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
}

void loop() {
  int sensor1Value = digitalRead(irSensor1);
  int sensor2Value = digitalRead(irSensor2);


  if (sensor1Value == LOW) {
    Serial.println("Slot 1 Occupied");
  } else {
    Serial.println("Slot 1 Vacant");
  }


  if (sensor2Value == LOW) {
    Serial.println("Slot 2 Occupied");
  } else {
    Serial.println("Slot 2 Vacant");
  }

  delay(1000);
}