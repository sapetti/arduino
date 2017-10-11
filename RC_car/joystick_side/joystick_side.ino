/*
Read the joystick. SWITCH HAS PULL UP RESISTOR !!!!!!!!.
Use wireless transmission ...
*/
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

RH_ASK wirelessDriver;
  
int analogInputPinX   = A3; // Arduino pin for the joystick X and Y inputs
int analogInputPinY   = A2;
int digitalInputPin  = 2;   // Arduino pin for the joystick switch
int wait = 1000; 
int inputX;                 // analogRead for the joystick X and Y
int inputY;
int inputSW;                // digitalRead for the switch; nb pull UP resistor.


const int STATIC = 1;      // Direction constants transmitted from the car
const int FORWARDS = 2;
const int BACKWARDS = 3;
const int LEFT = 4;
const int RIGHT = 5;
int x_dir;               // Holds one of the direction constants above
int y_dir;               // Holds one of the direction constants above

void setup()
{ 
//  lcd.init();                      // initialize the lcd 
//
//  // Print a message to the LCD.
//  lcd.backlight();
//  lcd.print("Joystick Transmit");
//  lcd.setCursor(0,1);
//  lcd.print("Starting ...");
  
//  pinMode(analogInputPinX,   INPUT);
//  pinMode(analogInputPinY,   INPUT);
//  pinMode(digitalInputPin,   INPUT);
//  digitalWrite (digitalInputPin, HIGH); // Joystick has a pull up resistor.
  
  if (!wirelessDriver.init())
      {
         Serial.println("Wireless init failed");
         delay(10000);
      }  
      
  Serial.begin(9600);  
  delay(2000);
}

void loop()
{
  //delay(wait);
//  inputX = analogRead(analogInputPinX);
//  inputY = analogRead(analogInputPinY);
  // Serial.print("X is read as ");
  // Serial.print(inputX);
  // Serial.print(" and Y is read as ");
  // Serial.println(inputY);
  // Serial.println("");
//  
//  inputSW = digitalRead(digitalInputPin);
//  if (inputSW == LOW)
//      {
//      Serial.print("YAY ! Digital switch is Pressed ! ");
//      }  
//
//  x_dir = STATIC; // Normal X position is 522
//  if (inputX < 510)
//    {
//      x_dir = LEFT;
//    }
//    if (inputX > 530)
//    {
//      x_dir = RIGHT;
//    }
//  y_dir = STATIC; // Normal Y position is 513
//  if (inputY < 500)
//    {
//      y_dir = FORWARDS;
//    }
//    if (inputY > 530)
//    {
//      y_dir = BACKWARDS;
//    }
//  
//   lcd.clear();
//   lcd.setCursor(0,0);
//   lcd.print("X dir is ");
//   lcd.print(x_dir);
//   lcd.setCursor(0,1);
//   lcd.print("Y dir is ");
//   lcd.print(y_dir);


//----------------------------->>
  y_dir = STATIC;
  x_dir = STATIC;
//----------------------------->>

  sendMessage(x_dir, y_dir);
}

void sendMessage(int sendX, int sendY)
{
char msg[3];

  msg[0] = sendX;
  msg[1] = sendY;
  msg[2] = '\0';

  wirelessDriver.send((uint8_t *)msg, strlen(msg));
  wirelessDriver.waitPacketSent();
 Serial.print("SENT MESSAGE : ");
 Serial.print(sendX, HEX);
 Serial.println(sendY, HEX);
 // Serial.println(msg);
  delay(200);
}
