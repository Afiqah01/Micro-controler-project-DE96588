#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int x,y,t ;
void setup ()
{
  pinMode( 8, INPUT);
  pinMode( 2, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode( A5, INPUT);
  pinMode( A4, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop ()
{
  x= digitalRead(8);
  y= analogRead(A5);
  t= analogRead(A4);
  t= (t*5)/1.024;
  t= t/10;
  lcd.setCursor(0,0);  
  lcd.print("T: ");//T=Temperature
  lcd.println(t);
  lcd.setCursor(0,1);
  lcd.print("HD:"); //HD= human detected 0= yes 1= no
  lcd.println(x);
  lcd.print("   LDR:  ");// Milivolt trough LDr
  lcd.println(y);
  
  if (x<1)
  {
    digitalWrite(6,0);
    digitalWrite(2,0);
    
  }
  else
  {
    if ((y<550) && (t>32))
    {
      {digitalWrite(6,1);
       digitalWrite(2,1);}
      delay(4000);
      
    }
    
    else
    {
     	 if ((y>550) && (t>32))
    	{
           {digitalWrite(6,0);
            digitalWrite(2,1);}
           delay(4000);
           
    	}
    	
      		else
    		{
      			if ((y<550) && (t<32))
    			{
                  {digitalWrite(6,1);
                   digitalWrite(2,0);}
                  delay(4000);
                  
    			}
    				
        			else
        			{
                      {digitalWrite(6,0);
                       digitalWrite(2,0);}
                      delay(1000);
        			}
            }
    }
          
      
      
    
  }
}
       
        
      
    
  
  
  
  