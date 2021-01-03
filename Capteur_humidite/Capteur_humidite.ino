
#include "LiquidCrystal.h"
LiquidCrystal lcd(11,10,5,4,3,2);
char data;
void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);

}

void loop() {
int humidite=analogRead(0); 
Serial.println(humidite); 
delay(2000);
if(Serial.available())
 {

      data=Serial.read();
      if(humidite >= 600)
      {
        if (digitalRead(13)==LOW)
        {
          digitalWrite(13,HIGH);
          Serial.write('1');    
          lcd.print("l'irrigation est términée");
          delay(1000);
        }
      }
      else 
      {
        digitalWrite(13,LOW);
        Serial.write('0');
        lcd.print("l'irrigation est en cours");
        delay(10000);
      }
 }

}
