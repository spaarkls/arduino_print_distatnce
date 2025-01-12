#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Инициализация дисплея с адресом 0x27

const int trigPin = 7;
const int echoPin = 6;
const int colorGreen = 12;

void setup() {
  lcd.begin(20, 4);
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinGreen, OUTPUT);
}

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2; // Перевод в сантиметры
  return distance;
}

void loop() {
  float distance = measureDistance();
  lcd.setCursor(0, 0);
  lcd.print("Distance:         ");  // Очищаем строку
  lcd.setCursor(10, 0);
  lcd.print(distance);
  lcd.print(" cm");
  if (distance > 10) {
    digitalWrite(colorGreen, HIGH);
  } else {
    digitalWrite(colorGreen, LOW);
  }
  delay(500);
}
