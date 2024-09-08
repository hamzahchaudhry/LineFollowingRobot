#include <LiquidCrystal.h>

//set pins for LCD and LEDs
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int redPin1 = 2;
int greenPin1 = 3;
int bluePin1 = 4;
int redPin2 = 1;
int greenPin2 = 0;
int bluePin2 = A0;
int redPin3 = A1;
int greenPin3 = A2;
int bluePin3 = A3;

void setup() {
  //set pins as outputs
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);

  lcd.begin(16, 2);
}

long previousMillis = 0;
void loop() {
  unsigned long currentMillis = millis();
  delay(20000);
  if (currentMillis - previousMillis >= 100) {
    previousMillis = currentMillis;

    setColor(255, 0, 0);
    delay(100);
    setColor(0, 255, 0);
    delay(100);
    setColor(0, 0, 255);
    delay(100);
    setColor(255, 255, 255);
    delay(100);
    setColor(170, 0, 255);

    lcd.setCursor(0, 0);
    lcd.print("AUTONOMOUS PRIME");
    scrollText("IF YOU'RE READING THIS YOU'RE LOSING", 125);
  }
}

void scrollText(String text, int interval) {
  static unsigned long textScrollMillis = 0;
  if (millis() - textScrollMillis >= interval) {
    textScrollMillis = millis();
    lcd.scrollDisplayLeft();
  }
  lcd.setCursor(0, 1);
  lcd.print(text);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin1, redValue);
  analogWrite(greenPin1, greenValue);
  analogWrite(bluePin1, blueValue);
  analogWrite(redPin2, redValue);
  analogWrite(greenPin2, greenValue);
  analogWrite(bluePin2, blueValue);
  analogWrite(redPin3, redValue);
  analogWrite(greenPin3, greenValue);
  analogWrite(bluePin3, blueValue);
}