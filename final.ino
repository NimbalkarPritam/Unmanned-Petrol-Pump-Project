#include <Keypad.h>
#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(A1,A0,5,4,3,2) ; //set interfacing pins
char m[]="123456789123";
char i[12];
char w[4];
int j,k=0,l,o=0,n,x=0,y=0;
char p='s';
char z[]="1234";
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 9, 8, 7, 6 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 13,12, 11, 10 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//LiquidCrystal lcd(A1, A0, 5, 4, 3, 2);
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);   //initializing 16x2 lcd
  lcd.setCursor(0,0);  //Lcd on
  lcd.print("Welcome");
 }

void loop() 
{
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
   
    switch (key)
    {
      case '*':
        lcd.print("*");
        break;
      case '#':
       lcd.print("#");
        break;
      default:
        lcd.print('*');
        w[y]=key;
        y++;
    }
  }

  if(y==4)
  {
    y=0;
    lcd.setCursor(0,1);
   // for(y=0;y<4;y++)
    //{
        if(z[0]==w[0]&&z[1]==w[1]&&
            z[2]==w[2]&&z[3]==w[3])
            {
         lcd.print('v');
         delay(1000);
         lcd.clear();
         lcd.print("Current Balance is:");
         lcd.setCursor(0,1);
          lcd.print('9');
           lcd.print('9');
            lcd.print('9');
             lcd.print('9');
            }
            else
            {
              lcd.print('n');
              }
     // }
   }
  
 if(Serial.available())  //RF
 {
 
  j=Serial.read();
  i[k]=j;
  k++;
  if(k==12)
  {
    k=0;
    
  
  for(o=0;o<12;o++)
  {
   if(m[0]==i[0]&&m[1]==i[1]&&m[2]==i[2]&&
    m[3]==i[3]&&m[4]==i[4]&&m[5]==i[5]&&
    m[6]==i[6]&&m[7]==i[7]&&m[8]==i[8]&&
    m[9]==i[9]&&m[10]==i[10]&&m[11]==i[11])
 {
  
  if(x==0)
  {
    lcd.setCursor(0,1);
  lcd.print("VALID");
    x++;
   SendMessage();
   lcd.clear();
    lcd.setCursor(0,0);
  } }
 else
 {
  lcd.setCursor(0,1);
  lcd.print("INVALID");
  }
 }
 
 /*   
   lcd.print("Current Balance is:");
    Serial.print(z);      //serial transmission
 while(1)
  
 else
 {
     lcd.setCursor(0,1);
  lcd.print("INVALID");
  
 }
 }
 lcd.setCursor(0,0);
 for(l=0;l<4;l++)
    {
        
       lcd.print(i[l]); 
    }

*/
  }}
}

void SendMessage()
    {
      Serial.println("at");
      delay(1000);
      Serial.println("at+cmgf=1");
      delay(1000);
      Serial.println("at+cmgs=\"9158488384\"\r");
       delay(1000);
      Serial.println("1234");
       delay(1000);
       Serial.println((char)26);
        delay(1000);
    }
    
