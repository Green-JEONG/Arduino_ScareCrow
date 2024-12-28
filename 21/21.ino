#include <SoftwareSerial.h>
int t = 2;
int r = 3;
int pin = 13;
int light = A0;
int mode = '0'; // 실행 상태 저장 할 변수
int threshold = 280; //밝다와 어둡다는 구분할 한계 값

SoftwareSerial ble(t,r);

void setup(){
  Serial.begin(9600);
  ble.begin(9600); //38400이 작동되지 않으면 수동으로 9600 변환 권장
  pinMode(pin, OUTPUT);
}

void loop(){
  if (Serial.available()) {
    ble.write(Serial.read());
  }

  if (ble.available()) {
    char command = ble.read(); //블루투스에서 전달하는 메시지 읽음
    if(command == '0'){ //전달된 값이 0이면
      mode = '1'; // 한계 값에 의하여 LED를 자동으로 크고 끄도록 모드 변경
      String data = "the automatic light on \n";
      ble.write(data.c_str());
      Serial.println(data);
    }
  }

  if (mode == '0') {
    digitalWrite(pin, LOW);
  }
}