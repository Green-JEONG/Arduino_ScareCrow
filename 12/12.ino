#include <Servo.h>
Servo myservo;
int lightln = A0;
int value = 0;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  Serial.print("the light value is : ");
    int lightValue = analogRead(lightln);
    Serial.println(lightValue);

    if (lightValue < 300) {    //밝기가 밝으면
        myservo.write(0);
        for(value = 0; value < 180; value += 1) {
            myservo.write(value);
            delay(100);
          }
      } else {                 //어두우면
          myservo.write(180);
        for(value = 180; value > 0; value -= 1) {
            myservo.write(value);
            delay(100);
          }
      }
}