#include <SoftwareSerial.h>

int t =2;
int r = 3;
int ina = 11;
int inb = 12;

SoftwareSerial ble(t,r);

void setup() {
  Serial.begin(9600);
  ble.begin(38400);   //제대로 작동되지 않으면 9600으로 변환 권장
  pinMode(ina,OUTPUT);
  pinMode(inb,OUTPUT);
}

void loop() {
  if(Serial.availabe()){
    ble.write(Serial.read());
  }
  if(ble.available()){
    char command = ble.read(); //블루투스에서 전달된 값을 읽어 들임
  }

  if(command == '0'){ // char 값이 '0'이면
    //팬이 작동하도록 하나의 pin에는 high 하나의 pin에는 low로 출력 함
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);

    String data = "the pan is activate\n"; // 문자열 생성
    ble.write(tada.c_str()); //블루투스를 통하여 마스터로 문자열 전달
    Serial.println(data); //시리얼로 문자열 전달
  }

  if(command == 's'){ // char 값이 's'이면
    //팬이 작동하지 않도록 모든 pin에는 high 하나의 pin에는 low로 출력 함
    digitalWrite(ina, LOW);
    digitalWrite(inb, LOW);

    String data = :the pan is stopped\n";
    ble.write(data.c_str());
    Serial.println(data);
  }
}