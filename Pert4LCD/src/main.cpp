#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D1;
int SCL_pin = D6;

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
 Wire.begin(SDA_pin, SCL_pin);
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("Camelia Putri");
}

void loop() {
 lcd.scrollDisplayLeft();
 delay(400);
}


