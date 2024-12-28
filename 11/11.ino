#include <Servo.h> //서보 라이브러리를 불러옴
Servo myservo;

                     // 서보를 제어할 서보 객체 선언을 통한 객체 생성
int value = 0;
void setup()
{
  myservo.attach(9); // 핀 9를 서보 오브젝트 연결
  myservo.write(0); // 서보 위치 0도로 초기화
}

void loop()           // 3초 지연 실행
{
  delay(3000);
  for(value = 0; value < 180; value += 1)

                                        // 0도에서 180도로 이동함
  {                               // 이동할때 각도는 1도씩 이동함
    myservo.write(value);         // 'value'변수의 위치로 서보를 이동시킴
    delay(100);                   // 서보 명령 간에 100ms를 기다림
  }
  delay(1000);                    // 1초 지연 실행.
  myservo.write(0);               // 서보 위치 0도로 초기화 함
}