#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);
int distance;
void setup() {
  oled.begin(0x3C); // Address 0x3C for 128x32

  oled.clearDisplay();

  oled.setCursor(0, 0);

  oled.setTextColor(SSD1306_WHITE);
  oled.display();
}

void loop() {
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextSize(2);
  oled.println("Distance : ");
  oled.println(distance);
  oled.display();
  delay(250); 
}
