void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //시리얼 통신 초기화
}

void loop() {
  Serial.print("Hands on ");
  Serial.print("Learning ");
  Serial.println("is Fun!!!");
  delay(2000);
}
