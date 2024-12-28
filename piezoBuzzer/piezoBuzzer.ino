int BuzzerPin= 6; // 사용할 포트 핀번호  
int num = 8; // 몇개의 음을 사용할 것인지  
int tones[] = {261,293,329,349,391,440,493,523}; // 음계별 주파수  
void setup()  
{  
}  
void loop()  
{  
    for ( int i=0; i < num; i++ ) {  
       tone(BuzzerPin,tones[i],1000);  
       delay(1000);  
    }  
    noTone( BuzzerPin);  
    delay(3000);  
}