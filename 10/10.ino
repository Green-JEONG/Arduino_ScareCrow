#include <DHT.h>

int Sensor_pin = 8;

DHT my_sensor(Sensor_pin, DHT11);
int INA = 11;
int INB = 12;

void setup() {
  Serial.begin(9600);
  my_sensor.begin();
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
}

void loop() {
  delay(500);
  int temp = my_sensor.readTemperature();
  int humi = my_sensor.readHumidity();

  if (humi > 53) {
  // 습도 값이 53보다 크면 DC 모터 팬 구동
    digitalWrite(INA, LOW);
    digitalWrite(INB, HIGH);
  } else {
  // 습도 값이 53보다 작거나 같으면 DC 모터 팬 구동 정지
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
  }
  Serial.print("Tempreature: ");
  Serial.print(temp);
  Serial.print(" / ");
  Serial.print("Humidity: ");
  Serial.println(humi);
}