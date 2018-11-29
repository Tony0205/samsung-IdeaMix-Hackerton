#include <SoftwareSerial.h>

SoftwareSerial digitSerial(2, 3);
char inByte;

void setup() {
  Serial.begin(9600);
  digitSerial.begin(9600);
}

void loop() {
  inByte = Serial.read();
   
  if(inByte == 'f')
  {
    writeSPO2();
  }
  
  //if(Serial.available())
  //{
  //  digitSerial.write(Serial.read());
  //}
    
  //if(digitSerial.available())
  //{
  //  Serial.write(digitSerial.read());
  //}
    
}


void writeSPO2()
{
  Serial.print(digitalRead(2));
  Serial.print(digitalRead(3));
  Serial.print(digitalRead(4));
  Serial.print(digitalRead(5));
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(8));
  Serial.print(digitalRead(9));
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(11));
  Serial.print(digitalRead(12));
}

