#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

int gasSensor = A0;
int gasValue = 0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Gas Detector");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  gasValue = analogRead(gasSensor);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  lcd.setCursor(0, 0);
  lcd.print("Gas:");
  lcd.print(gasValue);
  lcd.print("    ");

  lcd.setCursor(0, 1);

  if (gasValue > 400) {
    lcd.print("Gas Detected! ");
  } else {
    lcd.print("Air Safe      ");
  }

  delay(1000);
}