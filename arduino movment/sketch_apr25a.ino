int dire1=2,step1=3, dire2=12,step2=13;
int magnet=6;
char x0='1', y0='a';
char x1,y1,x2,y2;
String receivedString;
int num = 86;
int Tdelay = 2;
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
 void On()
{
  digitalWrite(magnet,HIGH);
  delay(100);
}
void Off()
{
  digitalWrite(magnet,LOW);
  delay(100);
}
void setup(){
  
  pinMode(dire1,OUTPUT);
  
  pinMode(dire2,OUTPUT);
  
  pinMode(step1,OUTPUT);
  pinMode(magnet,OUTPUT);
  Off();
  pinMode(step2,OUTPUT);
  //x0='a';y0='1'; 
  Serial.begin(9600);
  
}
void move_order(char X1,char Y1, char X2, char Y2 ){
   if(Y1>='a' && Y1<='h' && Y2>='a' && Y2<='h' && X1>='1' && X1<='8' && X2>='1' && X2<='8')
    {
    int distx = X2-X1;
    int disty = Y2-Y1;
    //Serial.println(distx);
    //Serial.println(disty);
    //=======================x direction==========================
    if(distx>0)
    {
      moveU();
      for(int i=0;i<distx;i++) {moveR();moveR();}
      moveD();
    }
    
    else if (distx<0)
    {
      distx*=(-1);
      moveU();
      for(int i=0;i<distx;i++) {moveL();moveL();}
      moveD();
    }
    
    //=====================y direction===========================
    if(disty>0){
      moveR();
      for(int i=0;i<disty;i++) {moveU();moveU();}
      moveL();
    }
    else if(disty<0)
    {
      moveR();
      disty*=(-1);
      for(int i=0;i<disty;i++) {moveD();moveD();}
      moveL();
    }
     
   }//endif
    
}
void Smove_order(char X1,char Y1, char X2, char Y2 ){
    int distx = X2-X1;
    int disty = Y2-Y1;
    //=======================x direction==========================
    if(distx>0)
    {
      moveU();
      for(int i=0;i<distx;i++) {moveR();moveR();}
      moveD();
    }
    
    else if (distx<0)
    {
      distx*=(-1);
      moveU();
      for(int i=0;i<distx;i++) {moveL();moveL();}
      moveD();
    }
    
    //=====================y direction===========================
    if(disty>0){
      moveR();
      for(int i=0;i<disty;i++) {moveU();moveU();}
      moveL();
    }
    else if(disty<0)
    {
      moveR();
      disty*=(-1);
      for(int i=0;i<disty;i++) {moveD();moveD();}
      moveL();
    }
     
       
}

void loop()
{
  if(Serial.available()){  
    receivedString = Serial.readStringUntil('\n');
  
    y1=receivedString[0]; //a
    x1=receivedString[1]; //7
    y2=receivedString[2]; //a
    x2=receivedString[3]; //5
    if(y1>='a' &&y1<='h'){
    //move_order(x0,y0,x1,y1);
    Smove_order(x0,y0,x1,y1);
    delay(2000);
    On();
    Smove_order(x1,y1,x2,y2);
    Off();
    Smove_order(x2,y2,x0,y0);
    }
    }//serial

}//end loop 


