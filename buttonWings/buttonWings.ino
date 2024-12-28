#include <Servo.h> //헤어파일 포함
Servo myservo; //myservo 변수 선언 
int pos = 90; //초기 각도값 설정 

void setup() {
  myservo.attach(3); //서보모터의 입출력핀을 3번 핀으로 지정
  pinMode(4,INPUT); //4번 버튼의 디지털 입력으로 사용
  pinMode(5,INPUT); //5번 버튼의 디지털 입력으로 사용
  myservo.write(90); //전원이 연결되면 서보모터 90도에 맞춰 입력 대기
  delay(500);
  Serial.begin(9600); //시리얼 모니터 사용
}

void loop() {
  if(digitalRead(4) == HIGH) //4번 버튼을 누를 경우
  {
  pos = pos + 15; //+15도 회전
  Serial.println("왼팔"); //시리얼 모니터에 왼팔를 출력
 delay(50);
  }
  if(digitalRead(5) == HIGH) //5번 버튼을 누를 경우
  {
 pos = pos - 15; //-15도 회전
  Serial.println("오른팔"); //시리얼 모니터에 오른팔을 출력 
  delay(50);
  }

  if(pos < 0) //서보모터의 각도가 0도 보다 작아질 경우
  pos = 0; //서보모터 0도 고정
  if(pos > 180) //서보모터의 각도가 180도 보다 커질 경우
  pos = 180; //서보모터 180도 고정
  myservo.write(pos); //pos값에 맞춰 서보모터 회전
  delay(15);
}