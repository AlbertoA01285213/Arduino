#include<Wire.h>
#include "Mouse.h"

const int MPU_addr=0x68;
float AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
float roll, pitch, yaw;
float rollF, pitchF, yawF;

float elapsedTime, currentTime, previousTime;
unsigned long tiempo = 0;

int anguloX = 0;
int anguloY = 0;
int anguloZ = 180;

int sensibilidad = 95;
int sM, sm;

const byte ledPin = 5;
const byte interruptPin = 7;
volatile boolean ledOn = false;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), modo, HIGH);
  
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Mouse.begin();

  Serial.begin(9600);
  Serial.print("Listo");
  delay(2000);
}

void loop()
{
  while(ledOn == true)
  {
    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);
    Wire.endTransmission(false);
  
    Wire.requestFrom(MPU_addr,14,true);
  
    AcX = Wire.read()<<8|Wire.read();    
    AcY = Wire.read()<<8|Wire.read();
    AcZ = Wire.read()<<8|Wire.read();
    Tmp = Wire.read()<<8|Wire.read();
    GyX = Wire.read()<<8|Wire.read();
    GyY = Wire.read()<<8|Wire.read();
    GyZ = Wire.read()<<8|Wire.read();

    AcX = AcX / 16384;
    AcY = AcY / 16384; // error de -0.05
    AcZ = AcZ / 16384; // error de +0.23

    GyX = GyX / 131.0;
    GyY = GyY / 131.0;
    GyZ = GyZ / 131.0;
  
    // Angulo Acc-----------------------------------------------------------------
    roll = atan(AcY / sqrt(pow(AcX, 2) + pow(AcZ, 2))) * 180 / PI;
    pitch = atan(-1 * AcX / sqrt(pow(AcY, 2) + pow(AcZ, 2))) * 180 / PI;
  
    // Tiempo---------------------------------------------------------------------  
    previousTime = currentTime;
    currentTime = millis();
    elapsedTime = (currentTime - previousTime)/100;
  
    // Angulo Gyro----------------------------------------------------------------
    anguloX = anguloX + GyX * elapsedTime;
    anguloY = anguloY + GyY * elapsedTime;
    anguloZ = anguloZ + GyZ * 0.0135;

    // Suavizacion -----------------------------------------------------------------------
    pitch = 1 * (pitch + 80);
    sensibilidad = sensibilidad / 100;

    sM = sensibilidad;
    sm = 1 - sensibilidad;

    yaw = anguloZ;
  
    rollF = sM*rollF + sm*roll;
    pitchF = sM*pitchF + sm*pitch;

    rollF = rollF * 0.9;
    pitchF = pitchF * 0.9;
    //yawF = sM*yawF + sm*yaw;

    // Mouse ---------------------------------------------------------
    Mouse.move(rollF, pitchF, 0);
  
    Serial.print("Roll: ");
    Serial.print(rollF);
    Serial.print("  | Pitch: ");
    Serial.print(pitchF);
    Serial.print("  | Yaw: ");
    Serial.println(yaw);
  }

}

void modo()
{
  if(ledOn)
  {
    ledOn = false;
    digitalWrite(ledPin, LOW);
  }
  else
  {
    ledOn = true;
    digitalWrite(ledPin, HIGH);
  }
}
