
int aDataCheck = 7; # data가 있는지 없는지 체크하는 데이터핀 (A in)
int bSignal = 8; # 준비신호, higt를 기본으로 할당 (B out)
int cSignal = 11; # SPO2 : B value Low이면 data 전송 후 C를 Higt로 바꿔줌. (C in)

// 8bit data (2 진수)
int d8 = digitalRead(A4);
int d7 = digitalRead(A5);
int d6 = digitalRead(2);
int d5 = digitalRead(3);
int d4 = digitalRead(4);
int d3 = digitalRead(5);
int d2 = digitalRead(6);
int d1 = digitalRead(0);

char inByte;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode를 통해 각각의 디지털 포트들의 역할을 static 선언한다.
  pinMode(aDataCheck, INPUT);
  pinMode(bSignal, OUTPUT);
  pinMode(cSignal, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // 데이터 체크 function
  int isData = dataCheck();

  // 데이터가 있으면 1을 return 해줌.
  if(isData == 1)
  {
    // A가 High(1)이고 C가 High(1) 이면 Data Read 진행.
    int decNum = dataRead1();
    Serial.println(decNum); // SPO2에서 받아온 데이터 10진수 변환하여 print

    int decNum2 = dataRead2();
    Serial.println(decNum2);
  }
  
  delay(1);
}


int dataCheck() {
  
  // A핀을 읽는다
  int isData = digitalRead(aDataCheck);

  // SPO2 : 전송 데이터가 있으면 1(HIGH)로 나오고, 없으면 0(LOW) 으로 나온다.
  if(isData == 1)
  {
    // 전송 데이터가 있을 경우 B에 Low(0) 값을 전송한다.
    digitalWrite(bSignal, LOW);
  }

  return isData;
}


int dataRead1() {
  int a = digitalRead(aDataCheck);
  int c = digitalRead(cSignal);
  int decimalNum = null;

  // A가 High 이고 C가 High 이면, data를 읽는다.
  if ( a == 1 && c == 1)
  {
    // SP02에서 나온 출력값을 2진수 -> 10진수 변환.
    // pow(A, B) : A를 B제곱
    int decimalNum = pow(d8, 7) + pow(d7, 6) + pow(d6, 5) + pow(d5, 4) + pow(d4, 3) + pow(d3, 2) + pow(d2, 1) + pow(d1, 0);
     
    // 이후에 B에 다시 "High"를 전송한다.
    digitalWrite(bSignal, HIGH);
    
  }

  return decimalNum;
}


int dataRead2() {
  int c = digitalRead(cSignal);
  int decimalNum = null;

  // Read2 : if C value is Low, Data Reading and B signal "LOW" setting.
  if (c == 0)
  {
    // SP02에서 나온 출력값을 2진수 -> 10진수 변환.
    // pow(A, B) : A를 B제곱
    int decimalNum = pow(d8, 7) + pow(d7, 6) + pow(d6, 5) + pow(d5, 4) + pow(d4, 3) + pow(d3, 2) + pow(d2, 1) + pow(d1, 0);
     
    // 이후에 B에 다시 "LOW" 를 전송한다.
    digitalWrite(bSignal, LOW);
    
  }

  return decimalNum;
}


