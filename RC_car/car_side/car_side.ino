#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
RH_ASK driver;
int enablePinA = 10;
int in1PinA = 9;
int in2PinA = 8;
int enablePinB = 6;
int in1PinB = 5;
int in2PinB = 4;


const int STATIC = 1;      // Direction constants transmitted from the car
const int FORWARDS = 2;
const int BACKWARDS = 3;
const int LEFT = 4;
const int RIGHT = 5;
const int MAX = 5000;

void setup(){
    Serial.begin(9600); // Debugging only
    if (!driver.init()){
         Serial.println("init failed");
    }
    pinMode(in1PinA, OUTPUT);
    pinMode(in2PinA, OUTPUT);
    pinMode(enablePinA, OUTPUT);
    pinMode(in1PinB, OUTPUT);
    pinMode(in2PinB, OUTPUT);
    pinMode(enablePinB, OUTPUT);
    //digitalWrite(in1PinA, LOW);
    //digitalWrite(in2PinA, LOW);
}

void loop(){
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    boolean reverse = true;
    int speedA = MAX;
    int speedB = MAX;
    int x_dir = 0;
    int y_dir = 0;
    if (driver.recv(buf, &buflen)){
        // Message with a good checksum received, dump it.
        driver.printBuffer("Got:", buf, buflen);
          
        x_dir = buf[0];
        y_dir = buf[1];
        Serial.println(x_dir);
        Serial.println(y_dir);

        reverse = (y_dir == STATIC || y_dir == FORWARDS) ? true : false;
        
        speedA = (y_dir == STATIC) ? 0 : MAX;
        speedB = (y_dir == STATIC) ? 0 : MAX;
        
        switch (x_dir){
          case STATIC:
            break;
  
          case LEFT:
            speedA = speedA/2;
            break;
  
          case RIGHT:
            speedB = speedB/2;            
            break;
            
          default:
            Serial.println("Received X as UNKNOWN");
            break;
        }     
    }
    setMotor(in1PinA, in1PinA, enablePinA, speedA, !reverse);
    setMotor(in1PinB, in2PinB, enablePinB, speedB, reverse);
}

void setMotor(int pin1, int pin2, int enablePin, int speed, boolean reverse){
  Serial.print("setMotor:: ");
  Serial.println(speed);
  analogWrite(enablePin, speed);
  digitalWrite(pin1, ! reverse);
  digitalWrite(pin2, reverse);
}
