//서보모터 라이브러리 불러옴
#include <Servo.h>

//for문 사용 카운터
int i = 0;

Servo servo_3; //서보모터 이름정해줌

void setup()
{
  //3번핀에 모터값 등록
  servo_3.attach(3);
}

void loop()
{
 for(i=0; i<180; i += 1){
 	//서보모터 움직이는 값 적용
    servo_3.write(i);
    delay(10);
  }
  
  
  
 /* 간단한 움직임 해보기
 //일반적으로 180도 까지 움직임
 
 servo_3.write(0);  //0도로 설정
 delay(500);
  
 servo_3.write(30); //30도 설정
 delay(500);
  
 servo_3.write(60); //60도 설정
 delay(500);
 
 servo_3.write(90); //90도 설정
 delay(500);
 
  */

}