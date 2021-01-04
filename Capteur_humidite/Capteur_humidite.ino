
#include "LiquidCrystal.h"
LiquidCrystal lcd(11,10,5,4,3,2);
char data;
void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
digitalWrite(13,LOW);
digitalWrite(11,LOW);
}

void loop() {
int humidite=analogRead(0); 
Serial.println(humidite); 
delay(1000);
if(Serial.available())
 {

      data=Serial.read();
      if(humidite >= 600)
      {
        if (digitalRead(13)==LOW)
        {
          digitalWrite(13,HIGH);
        }
        if(digitalRead(11)==HIGH)
        {
          digitalWrite(11,LOW);
        }
         Serial.write('1');    
          //lcd.print("l'irrigation est términée");
          delay(2000);
      }
      else if (humidite < 600)
      {
        digitalWrite(13,LOW);
        digitalWrite(11,HIGH);
        Serial.write('0');
        //lcd.print("l'irrigation est en cours");
        delay(2000);
      }
 }

}
