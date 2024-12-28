#include <DHT.h>

int Sensor_pin = 8;
int LED = 13;

DHT my_sensor(Sensor_pin, DHT11);

void setup() {
  Serial.begin(9600);
  my_sensor.begin();
  pinMode(LED, OUTPUT);
}

void onOff(int humi) {
  if (humi < 50){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
}

void loop(){
  delay(500);
  int temp = my_sensor.readTemperature();
  int humi = my_sensor.readHumidity();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" / ");
  Serial.print("Humidity: ");
  Serial.println(humi);
  onOff(humi);
}