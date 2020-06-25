#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

int PIR_pin = 5;
int PWM_pin = 3;
long time_delay = 30000;
int dim_delay = 20;
long time_old = 0;
bool on_state = 0;
int inc_val = 0;

int buzzer = 11;

const int trig = 9;
const int echo = 10;
long Time;
int distance;
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

void setup() 
{
  Serial.begin(9600);
  pinMode(PIR_pin,INPUT);
  pinMode(PWM_pin,OUTPUT); 
  digitalWrite(PIR_pin, LOW);

  pinMode(buzzer,OUTPUT);    

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);  
  oled.begin(0x3C); 
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(3);
  oled.print("Ready!");
  oled.display();
  delay(2000);
}

void loop() 
{
   if (digitalRead(PIR_pin)==1){
        on_state = 1;
        time_old = millis();
    }
    if(on_state == 1){
        if (millis()-time_old<time_delay){
            inc_val = inc_val +1;
            if (inc_val>255){
                inc_val = 255;               
            }
            delay(dim_delay);
        }        
        else {
        inc_val = inc_val -1;
        if (inc_val<0){
            inc_val = 0;
            on_state = 0;
        }
        delay(dim_delay);
        }   
    }  
    else {
    time_old = millis();
    }

    if (on_state == 1) {
     digitalWrite(buzzer,HIGH); 
     delay(2); 
     digitalWrite(buzzer,LOW);
     delay(100); 
    }else {
     noTone(buzzer);
    }   
    digitalWrite(PWM_pin, inc_val);
    Serial.print(inc_val);

    if (on_state == 1) {
     digitalWrite(trig, LOW);
     delayMicroseconds(2);
     digitalWrite(trig, HIGH);
     delayMicroseconds(10);
     digitalWrite(trig, LOW);
     Time = pulseIn(echo, HIGH);
     distance = Time * 0.034 / 2;

     oled.clearDisplay();
     oled.setCursor(0, 0);
     oled.setTextSize(2);
     oled.print("Distance: ");
     oled.println(distance);
     oled.display();
     delay(250); 
     }
    if (on_state == 0) {
      oled.clearDisplay();
      oled.setCursor(0, 0);
      oled.setTextSize(2);
      oled.print("---");
      oled.display();
      delay(250); 
    }
}