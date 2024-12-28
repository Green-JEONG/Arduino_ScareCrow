#include <SoftwareSerial.h>
#include <DHT.h>

int t = 2;
int r = 3;
int pin = 8;

DHT sensor(pin, DHT11);
SoftwareSerial ble(t,r);

void setup() {
  Serial.begin(9600);
  ble.begin(38400);
  sensor.begin();
}

void loop() {
  if(Serial.available()){
    ble.write(Serial.read());
  }
  if(ble.available()){
    char command = ble.read(); //char형태의 값을 읽어 들임
    if(command == 't'){ //char t와 비교하여 같으면
      int temp = sensor.readTemperature(); //센서로 부터 온도 값 읽어 들임
      String data = "the temperature is: "; //문자열 생성
      data.concat(temp);  //온도값을 문자열에 추가
      data.concat("\n");  //문자열의 끝을 알림
      ble.write(data.c_str()); //블루투스를 통하여 마스터로 전송
      Serial.println(data); //시리얼로 전송
    }
    if(command == 'h'){ //char h와 비교하여 같으면
      int humi = sensor.readHumidity(); //센서로 부터 습도 값 읽어 들임
      String data = "the humidity is: ";
      data.concat(humi);
      data.concat("\n");
      ble.write(data.c_str());
      Serial.println(data);
    }
  }
}