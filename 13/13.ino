#include <SoftwareSerial.h>  // 블루투스 통신을 사용하기 위해 불러오는 라이브러리

int T = 2;                     // 블루투스 모듈의 TXD 핀과 연결된 2번을 T 라는 변수로,
int R = 3;                     // 블루투스 모듈의 RXD 핀과 연결된 3번을 R 이라는 변수로 선
SoftwareSerial my_blue(T, R);  // my_blue 라는 이름의 블루투스 객체를 선언
                               // 이 블루투스 객체는 T와 R에 의해 제어

void setup() {
  Serial.begin(9600);    // 시리얼 통신을 9600의 통신속도로 시작함
  my_blue.begin(38400);  // 블루투스 통신을 시작함
}

void loop() {
  if (my_blue.available()) {       // 블루투스를 사용할 수 있다면
    Serial.write(my_blue.read());  // 값을 읽어서 시리얼에 쓰기
  }
  if (Serial.available()) {        // 시리얼을 사용할 수 있다면
    my_blue.write(Serial.read());  // 값을 읽어 블루투스에 쓰기
  }
}