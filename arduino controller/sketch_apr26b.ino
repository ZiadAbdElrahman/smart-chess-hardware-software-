int dire1=2,step1=3, dire2=12,step2=13;
int magnet=6;
char x0='1', y0='a';
char x1,y1,x2,y2;
String receivedString;
int num = 10;
int Tdelay = 1;
 void moveR()
 {
  digitalWrite(dire1,HIGH);
  for(int i=0;i<num;i++)
  {
    digitalWrite(step1,HIGH);
    delay(Tdelay);
    
    digitalWrite(step1,LOW);
    delay(Tdelay);
  }
 }
void moveL()
 {
  digitalWrite(dire1,LOW);
  for(int i=0;i<num;i++)
  {
    digitalWrite(step1,HIGH);
    delay(Tdelay);
    digitalWrite(step1,LOW);
    delay(Tdelay);
  }
 }
void moveU()
 {
  digitalWrite(dire2,HIGH);
  for(int i=0;i<num;i++)
  {
    digitalWrite(step2,HIGH);
    delay(Tdelay);
    digitalWrite(step2,LOW);
    delay(Tdelay);
  }
 }
 
void moveD()
 {
  digitalWrite(dire2,LOW);
  for(int i=0;i<num;i++)
  {
    digitalWrite(step2,HIGH);
    delay(Tdelay);
    digitalWrite(step2,LOW);
    delay(Tdelay);
  }
 }
 
void setup(){
  
  pinMode(dire1,OUTPUT);
  
  pinMode(dire2,OUTPUT);
  
  pinMode(step1,OUTPUT);
   
}

void loop()
{
  if(Serial.available())
  {  
      char c = Serial.read();
      if(c=='R' || c=='r')moveD();
      if(c=='L'||c=='l')moveU();
      if(c=='U'||c=='u')moveR();
      if(c=='D'||c=='d')moveL(); 
  }//serial

}//end loop 


