#include <SoftwareSerial.h>

int t = 2;
int r = 3;

SoftwareSerial ble(t,r);

void setup(){
  Serial.begin(9600);
  ble.begin(38400);
}

void loop() {
  if (Serial.available()) {
    ble.write(Serial.read()); //string 형태의 데이터를 읽어 들임
  }
  if (ble.available()) {
    String message = ble.readString(); //string 형태의 데이터를 읽어 들임
    Serial.print("the message is: ");
    Serial.print(message); //읽어 들인 값 출력
    Serial.print("the message length is: ");
    Serial.println(message.length()); //읽어 들인 값의 문자열 길이를 출력
    Serial.print("the firt character of message is: ");
    Serial.println(message[0]); //읽어 들인 값의 첫 번째 값 출력
    Serial.print("After trim() function the message length is: ");
    message.trin(); //문자열의 앞뒤 공백 문자 제거
    Serial.println(message.length());
  }
}