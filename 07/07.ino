int lightln = A0; // 아두이노의 아날로그 핀을 선택함

void setup() {
  Serial.begin(9600); // 시리얼 연결을 시작함
}

void loop() {
  Serial.print("the light value is : "); // 스트링 문서를 시리얼 모니터에 출력함
  int lightValue = analogRead(lightln); //측정된 광/조도 값을 받아 옴
  Serial.println(lightValue); // 시리얼 모니터에 광/조도 값을 출력함
  delay(3000); //3초 지연 실행
}
