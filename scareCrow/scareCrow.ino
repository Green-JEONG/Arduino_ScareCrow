#include <Servo.h> // 서보모터 라이브러리 포함

// 핀 설정
#define TRIG 9  // 초음파 센서의 트리거 핀
#define ECHO 8  // 초음파 센서의 에코 핀
#define BUZZER_PIN 6 // 피에조 부저 핀
#define RED_LED 12  // RGB LED의 빨간색 핀
#define GREEN_LED 11 // RGB LED의 녹색 핀
#define BLUE_LED 10  // RGB LED의 파란색 핀
#define BUTTON1 4  // 택트 스위치 1 핀
#define BUTTON2 5  // 택트 스위치 2 핀

// 서보모터 인스턴스 생성
Servo myservo;

// 전역 변수 초기화
int pos = 90; // 서보모터의 초기 각도
bool armDirection = true; // 서보모터의 회전 방향 (true: 왼쪽, false: 오른쪽)

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);

  // 핀 모드 설정
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  // 서보모터 핀 연결 및 초기화
  myservo.attach(3);
  delay(500); // 서보모터 초기화 대기 시간
  myservo.write(pos); // 초기 위치로 서보모터 설정
}

void loop() {
  checkButtonControl(); // 버튼 입력을 확인하고 서보모터 제어
  checkUltrasonicSensor(); // 초음파 센서로 거리 측정 및 동작 제어
  delay(100); // 루프 지연
}

void checkButtonControl() {
  // 버튼 1, 2 입력 확인 후 서보모터 제어
  if (digitalRead(BUTTON1) == LOW) {
    myservo.write(0); // 서보모터를 왼쪽으로 회전
  }
  if (digitalRead(BUTTON2) == LOW) {
    myservo.write(180); // 서보모터를 오른쪽으로 회전
  }
}

void checkUltrasonicSensor() {
  long duration, distance;

  // 초음파 신호 전송
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // 초음파 신호 반환 시간 측정
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17 / 1000; // 거리 계산 (단위: cm)

  // 거리 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 물체가 10cm 이내에 감지되면 경보 활성화
  if (distance > 0 && distance <= 10) {
    activateAlarm(); // 경보 활성화
  } else {
    deactivateAlarm(); // 경보 비활성화
  }
}

void activateAlarm() {
  // 피에조 부저 경고음 발생
  tone(BUZZER_PIN, 1000); // 1000Hz의 소리 발생
  
  // 빨간색 LED 켜기
  digitalWrite(RED_LED, HIGH);

  // 서보모터 회전 (왼쪽 회전 후 오른쪽 회전)
  if (armDirection) {
    myservo.write(0); // 서보모터를 왼쪽으로 회전
  } else {
    myservo.write(180); // 서보모터를 오른쪽으로 회전
  }
  armDirection = !armDirection; // 회전 방향 전환
}

void deactivateAlarm() {
  // 피에조 부저 정지
  noTone(BUZZER_PIN);
  
  // 빨간색 LED 끄기
  digitalWrite(RED_LED, LOW);
  
  // 서보모터를 초기 위치로 이동
  myservo.write(90); // 서보모터를 중간 위치로 설정
}
