#define pin_Led 13;
#include "LiquidCrystal.h"
LiquidCrystal lcd(11,10,5,4,3,2);
char data;
void setup() {
Serial.begin(9600);
pinMode(pin_Led,OUTPUT);
digitalWrite(pin_Led,LOW);
analogWrite
}

void loop() {
int humidite=analogRead(0); 
Serial.println(humidite); 
delay(2000);
if(Serial.available)
 {

      data=Serial.read();
      if(humidite>=600)
      {
        if (digitalRead(pin_Led)==LOW)
        {
          digitalWrite(pin_Led,HIGH);
          Serial.write('1');    
          lcd.print("l'irrigation est términée");
          delay(10000);
        }
      }
      else 
      {
        digitalWrite(pin_Led,LOW);
        Serial.write('0');
        lcd.print("l'irrigation est en cours");
        delay(10000);
      }
 }

}
