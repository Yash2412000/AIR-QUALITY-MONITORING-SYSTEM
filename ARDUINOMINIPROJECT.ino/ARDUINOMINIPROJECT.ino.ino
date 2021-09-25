#include <SoftwareSerial.h>



// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 6, 5, 4, 3); // LCD connections
/*
 D13 ==> RS
GND  ==>   R/W
D12  ==> Enable
D6   ==> DB4
D5   ==> DB5
D4   ==> DB6
D3   ==> DB7
 
*/

float t=0;
char data = 0;

String apiKey = "1565W434E21D4VX2";  // Write API key
int smokeA0 = A5;
char auth[]="92dEINKz0zIxec0RWmsXLF5xgoLPHoJZ";


SoftwareSerial ser(8,9); // RX, TX

void setup() 

{                
// enable debug serial 
  Serial.begin(9600); //  serial data transmission at Baudrate of 9600

// enable software serial

  ser.begin(9600); 
  lcd.begin(16, 2);  // to intialize LCD

 
  lcd.setCursor(0,0); 

  lcd.print(" Welcome");

  lcd.setCursor(0,1);

  

  delay(3000);


  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("     AIR"); 

  lcd.setCursor(0,1);

  lcd.print("QUALITY MONITOR");  

  delay(3000); 


  



  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("WIFI");

  lcd.setCursor(0,1);

  lcd.print("   CONNECTED");

 }
  


void loop() 
{
  delay(1000);

  t = analogRead(A0);  // Read sensor value and stores in a variable t


  Serial.print("Airquality = ");

  Serial.println(t);

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print ("Air Qual: ");
  lcd.print (t);
   
  lcd.setCursor (0,1);
  if (t<=50)
   {
   lcd.print("Fresh Air");
   Serial.print("Fresh Air ");
 
   }
  else if( t>=100 && t<=300 )
   {
   lcd.print("Poor Air");
   Serial.print("Poor Air");
  
   }
  else if (t>=300 )
  {
  lcd.print("Very Poor");
  Serial.print("Very Poor");
  
  }
  //lcd.scrollDisplayLeft();
  delay(10000);

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("SENDING DATA");

  lcd.setCursor(0,1);

  lcd.print("TO CLOUD");


}
