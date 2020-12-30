void setup() {
Serial.begin(9600);
}

void loop() {
int humidite=analogRead(0); 
Serial.println(humidite); 
delay(2000);
}
