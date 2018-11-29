int LeftPress = 13;
int LeftRelease = 12;
int RightPress = 9;
int RightRelease = 10;
char inByte;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(LeftPress, OUTPUT);
    pinMode(LeftRelease, OUTPUT);
    pinMode(RightPress, OUTPUT);
    pinMode(RightRelease, OUTPUT);
      
    digitalWrite(LeftPress, LOW);
    digitalWrite(LeftRelease, LOW);  
    digitalWrite(RightPress, LOW);
    digitalWrite(RightRelease, LOW);  
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if(inByte == 'f')
    {
      writeFSR();
    }
    else if(inByte == '0') // All release
    {
      Rightcontrol(2);
      Leftcontrol(2);
    }
    else if(inByte == '1')  // Right press, Left release
    {
      Rightcontrol(1);
      Leftcontrol(2);
    }
    else if(inByte == '2')  //Right release, Left press
    {
      Rightcontrol(2);
      Leftcontrol(1);
    }
  }
}
// control ==1 press, control == 2 release
void Rightcontrol(int control)
{
  if(control == 1)
  {
    digitalWrite(RightPress, HIGH);
    digitalWrite(RightRelease, LOW);
  }
  else if(control == 2)
  {
    digitalWrite(RightPress, LOW);
    digitalWrite(RightRelease, HIGH);  
  }
}

void Leftcontrol (int control)
{
  if(control == 1)
  {
    digitalWrite(LeftPress, HIGH);
    digitalWrite(LeftRelease, LOW);
  }
  else if(control == 2)
  {
    digitalWrite(LeftPress, LOW);
    digitalWrite(LeftRelease, HIGH);  
  }
}

void writeFSR()
{
  Serial.print("A");
  Serial.print(analogRead(A0));

  Serial.print("B");
  Serial.print(analogRead(A1));
  
  Serial.print("C");
  Serial.print(analogRead(A2));
  
  Serial.print("D");
  Serial.print(analogRead(A3));
  
  Serial.print("E");
  Serial.print(analogRead(A4));
  
  Serial.print("F");
  Serial.println(analogRead(A5));

}
