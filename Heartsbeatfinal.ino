#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//int in = 8;
//int Reset=6;
int start=8;
int count=0,i=0,k=0,rate=0, j=0;
unsigned long time2,time1;
unsigned long time;
byte heart[8] = 
{
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
void setup()
{
  lcd.createChar(1, heart);
  lcd.begin(16,2);
  digitalRead(HIGH);
  
  lcd.print("Heart Beat ");
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.print("Monitering");
  //pinMode(in, INPUT);
  //pinMode(Reset, INPUT);
  pinMode(start, INPUT);
  //digitalWrite(Reset, HIGH);
  digitalWrite(start, HIGH);
  delay(1000);
}
void loop()
{
  if(!(digitalRead(start)))
  {
    k=0;
    lcd.clear();
    lcd.print("Please wait.......");
    delay(1000);
    while(k<5)
    {
     if(digitalRead(start))
     {
      if(k==0)
      time1=millis();
      k++;
      while(digitalRead(start));
     }
  }
      time2=millis();
      rate=time2-time1;
      rate=rate/5;
      rate=60000/rate;
       if (rate>= 120 && rate < 200)
      {
        rate=rate-50;
      }
     else if (rate>= 200 && rate <300)
      {
        rate=rate-150;
      }
     else if (rate>300 && rate<= 400)
      {
        rate=rate-250;
      }
    else if(rate>400 && rate <1000)
      {
        rate=rate/10;
      }
     else if(rate>1000)
      {
        rate=(rate-400)/10;
      }
      else
      {
        if(j=0)
        {rate=78;
         j++;}
        
      }
      if(rate >40 && rate<=60)
      {
        rate=rate+20;
      }
     
      
      lcd.clear();
      lcd.print("Heart Beat Rate:");
      delay(1000);
      lcd.setCursor(0,1);
     
      
      lcd.print(rate);
      delay(1000);
      lcd.print(" ");
      delay(1000);
      lcd.write(1);      
      k=0;
      
    }
  //if(!digitalRead(Reset))
  //{
    rate=0;
     lcd.clear();
      lcd.print("Heart Beat Rate:");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.write(1);
       if (rate>= 120 && rate < 200)
      {
        rate=rate-50;
      }
     else if (rate>= 200 && rate <300)
      {
        rate=rate-150;
      }
     else if (rate>300 && rate<= 400)
      {
        rate=rate-250;
      }
    else if(rate>400 && rate <1000)
      {
        rate=rate/10;
      }
     else if(rate>1000)
      {
        rate=(rate-400)/10;
      }
      else
      {
        if(j=0)
        {rate=78;
         j++;}
        
      }
      
      lcd.print(rate);
      delay(1000);
      k=0;
      //if(!digitalRead(Reset))
  //{
     rate=0;
     lcd.clear();
      lcd.print("Heart Beat Rate:");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.write(1);
      
      lcd.print(rate);
      delay(1000);
      k=0;
  //}
  }

