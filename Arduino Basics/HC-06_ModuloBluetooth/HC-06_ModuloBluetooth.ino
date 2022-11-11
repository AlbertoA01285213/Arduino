char inputByte;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  while(Serial.available() > 0)
  {
    inputByte = Serial.read();
    Serial.println(inputByte);
  }
}
