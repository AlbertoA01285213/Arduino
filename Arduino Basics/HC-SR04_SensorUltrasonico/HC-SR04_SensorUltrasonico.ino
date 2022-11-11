/*
 * Codigo creado por Alberto Eugenio
 * Codigo base para sensor ultrasonico de distancia
 */

// Ultrasonico delantero
#define echoPinDelantero 24
#define trigPinDelantero 25

// Ultrasonioc derecha
//#define echoPinDerecha 24
//#define trigPinDerecha 25
  
void setup() {

  Serial.begin(9600);
  pinMode(trigPinDelantero, OUTPUT);
  pinMode(echoPinDelantero, INPUT);
 // pinMode(trigPinDerecha, OUTPUT);
 // pinMode(echoPinDerecha, INPUT);

}

void loop() {

 //   digitalWrite(trigPinDerecha, LOW);
  //  delayMicroseconds(2);
  //  digitalWrite(trigPinDerecha, HIGH);
   // delayMicroseconds(10);
   // digitalWrite(trigPinDerecha, LOW);
   // int duration = 0;
   // duration = pulseIn(echoPinDerecha, HIGH);
   // int distanceDerecha = 0;
   // distanceDerecha = duration * 0.034 / 2;
   // Serial.println(distanceDerecha);

    digitalWrite(trigPinDelantero, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinDelantero, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinDelantero, LOW);
    int duration2 = 0;
    duration2 = pulseIn(echoPinDelantero, HIGH);
    int distanceDelantero = 0;
    distanceDelantero = duration2 * 0.034 / 2;
    Serial.println(distanceDelantero);
    delay(1000);
}
