void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //시리얼 통신 초기화

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World !!"); //시리얼을 통하여 컴퓨터로 전송될 메시지
  delay(3000);                      //대기 시간 설정 3초
}
