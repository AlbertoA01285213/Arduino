/* Codigo creado por Alberto Eugenio
 * Codigo consigue el angulo del giroscopio
 * Aun esta en desarrollo
 */


#include<Wire.h>

const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

float elapsedTime, currentTime, previousTime;
unsigned long tiempo = 0;

int anguloX = 0;
int anguloY = 0;
int anguloZ = 0;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.begin(9600);
  delay(100);
}

void loop()
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

  GyX = GyX / 131.0;
  GyY = GyY / 131.0;
  GyZ = GyZ / 131.0;
  
  previousTime = currentTime;
  currentTime = millis();
  elapsedTime = (currentTime - previousTime)/1000;

  anguloX = anguloX + GyX * 0.01;
  anguloY = anguloY + GyY * 0.01;
  anguloZ = anguloZ + GyZ * 0.01;
  
  Serial.println(anguloZ);
 }
