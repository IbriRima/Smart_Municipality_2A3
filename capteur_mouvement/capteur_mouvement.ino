int Sortie_capteur_PIR=4; //on définie la broche 4 de l'arduino comme la sortie du capteur
int valeur_PIR=0;//on initialise la détection de mouvement à 0
int led=6;//broche de la led

void setup() {
  Serial.begin(9600);
  pinMode(Sortie_capteur_PIR,INPUT);//on définie la sortie du capteur comme une entrée de arduino
  pinMode(led,OUTPUT);//on défine la broche de la LED comme une sortie dans arduino
}
void loop() {
   valeur_PIR=digitalRead(Sortie_capteur_PIR);//Lecture de la broche 4 : la soitie du capteur
  if(valeur_PIR){//si mouvement détecté
    Serial.println("Détecté");
    digitalWrite(led,HIGH);//on allume la LED
    delay(2000);//on attend 0,5s avant de l'éteindre
    digitalWrite(led,LOW);//on éteind la LED
    delay(2000);//on attend 0,5s avant de la rallumer
    }
    else{
      Serial.println("RAS");
      }
}
