int lightln = A0; // 아두이노의 아날로그 핀을 선택함
int LED = 13; // LED와 연결한 13번 핀 번호 지정

void setup() {
  Serial.begin(9600); // 시리얼 연결을 시작함
  pinMode(LED, OUTPUT); //핀 모드 변경
}

void loop() {
  Serial.print("the light value is : "); // 스트링 문서를 시리얼 모니터에 출력함
  int lightValue = analogRead(lightln); //측정된 광/조도 값을 받아 옴
  Serial.println(lightValue); // 시리얼 모니터에 광/조도 값을 출력함
  onOff(lightValue); //함수 호출
  delay(3000); //3초 지연 실행
}

void onOff(int lightValue) {
  if (lightValue < 300) { //밝기가 밝으면
    digitalWrite(LED, HIGH); //LED ON
  }else { //어두우면
    digitalWrite(LED, LOW); //LED OFF
    }
}