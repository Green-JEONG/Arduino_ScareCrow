int INA = 11; // INA에 11 저장
int INB = 12; // INB에 12 저장

void setup(){
  pinMode(INA, OUTPUT); // INA(11)번 핀을 출력 모드로 설정
  pinMode(INB, OUTPUT); // INB(12)번 핀을 출력 모드로 설정
}

void loop(){
//반시계 방향으로 회전
  digitalWrite(INA, HIGH); // INA핀에 HIGH를 출력
  digitalWrite(INB, LOW); // INB핀에 LOW를 출력
  delay(3000); // 3초 동안 쉬기

//시계 방향으로 회전
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  delay(3000);

//회전X
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(3000);
}