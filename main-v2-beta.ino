#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int irSensorCount = 6;
const int ledPin = 13;
const int servoPin = 9; 

int irSensorPins[] = {2, 3, 4, 5, 6, 7};

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo barricadeServo;

int availableSlots = irSensorCount;

void setup() {
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();

  barricadeServo.attach(servoPin);

  for (int i = 0; i < irSensorCount; i++) 
    pinMode(irSensorPins[i], INPUT);
  
  pinMode(ledPin, OUTPUT);

  updateLCD();
}

void loop() {
  checkParkingSlots();
  simulateEntry();
  simulateExit();
}

void checkParkingSlots() {
  availableSlots = irSensorCount;

  for (int i = 0; i < irSensorCount; i++) {
    if (digitalRead(irSensorPins[i]) == HIGH) 
      availableSlots--;
    
  }

  updateLCD();
}

void simulateEntry() {
  digitalWrite(ledPin, HIGH); 
  lcd.clear();
  lcd.print("Welcome! Slots: ");
  lcd.print(availableSlots);
  delay(3000);
}

void simulateExit() {
  digitalWrite(ledPin, LOW);
  lcd.clear();
  lcd.print("Thank you!");
  barricadeServo.write(90); 
  delay(3000); 
  barricadeServo.write(0); 
  delay(1000); 
  updateLCD();
}

void updateLCD() {
  lcd.clear();
  lcd.print("Available: ");
  lcd.print(availableSlots);
  lcd.print(" slots");
}
