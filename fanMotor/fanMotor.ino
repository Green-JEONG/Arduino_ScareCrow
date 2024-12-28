int INA = 2;  
int INB = 1;

void setup() 
{ 
pinMode(INA,OUTPUT); 
pinMode(INB,OUTPUT); 
} 

void loop() 
{ 
digitalWrite(INA,HIGH);
digitalWrite(INB,LOW); 
delay(3000);
digitalWrite(INA,LOW);
digitalWrite(INB,HIGH);
delay(3000); 
digitalWrite(INA,LOW);
digitalWrite(INB,LOW);
delay(3000);
}