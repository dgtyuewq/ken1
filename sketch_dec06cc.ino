#include <MeShield.h>
MeDCMotor mortor_9(9);
MeDCMotor mortor_10(10);
MePotentiometer poten(8);
MeUltrasonicSensor ultra(4);
Me7SegmentDisplay seg7(3);
void stopp();

double Offset9=0;
double Offset10=0;
float change = 0;
float x = 0;
float y = 0;
int d = 0;
MeRGBLed rgbled(6, 4);
MeJoystick joystick(7);
int bright=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  change = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int num;
  d=ultra.distanceCm();
   y = joystick.read(2);
  Serial.println(d);
  if(d<15){
    stpp();
  }
  else 
  {
    
for(int j=1;j<10;j++)
{
  y = joystick.read(2);
  num=j;
  d=ultra.distanceCm();
 for(int i=0;i<3;i++)
 {
   seg7.display(int(num));
  num=num*10;
  delay(300);
 }
 Serial.println(num);
 for(int k=1;k<5;k++)
 {
  seg7.display(int(num));
  num=num/10;
  delay(300);
  }
  }

    
    if(d<15){
    stpp();
  }
  change = poten.read();
  x = joystick.read(1);
    Serial.print(x);

  if(x>=200){
    green(change);
  }
  else if(x<-200){
    red(change);
  }
  else{
    blue(change);
  }
  }
}

void red(int change){
   for(int i=1;i<=4;i++){
      rgbled.setColor(i-1,0,0,0);
      rgbled.show();
      rgbled.setColor(i, change,0 ,0);
      rgbled.show();
      delay(100);
   
  }
}

void green(int change){
   for(int i=1;i<=4;i++){

      rgbled.setColor(i-1,0,0,0);
      rgbled.show();
      rgbled.setColor(i, 0,change ,0);
      rgbled.show();
      delay(100);
  }
}

void blue(int change){
   for(int i=1;i<=4;i++){

      rgbled.setColor(i-1,0,0,0);
      rgbled.show();
      rgbled.setColor(i, 0,0 ,change);
      rgbled.show();
      delay(100);
  }
}


void stpp(){
     int n=5;
    for(int k=1;k<=5;k++)
    {
     rgbled.setColor(0,255,0,0);
     rgbled.show();
     seg7.display(int(n--));
     delay(1000);
    }
    n=5;
    for(int m=1;m<=5;m++)
    {
     rgbled.setColor(0,0,255,0);
     rgbled.show();
     seg7.display(int(n--));
     delay(1000);
    }
    n=2;
    for(int o=1;o<=2;o++)
    {
     rgbled.setColor(0,255,100,0);
     rgbled.show();
     seg7.display(int(n--));
     delay(1000);
    }
}

