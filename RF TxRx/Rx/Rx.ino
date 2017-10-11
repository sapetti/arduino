//simple Tx on pin D12
//#include <VirtualWire.h>
//
//void setup(){
//  vw_set_ptt_inverted(true); // Required for DR3100
//  vw_set_rx_pin(12);
//  vw_setup(4000);  // Bits per sec
//  pinMode(13, OUTPUT);
//  vw_rx_start();       // Start the receiver PLL running
//}
//
//void loop(){
//  uint8_t buf[VW_MAX_MESSAGE_LEN];
//  uint8_t buflen = VW_MAX_MESSAGE_LEN;
//  if (vw_get_message(buf, &buflen)){ // Non-blocking
//    if(buf[0]=='1'){
//      digitalWrite(13,1);
//    }  
//    if(buf[0]=='0'){
//      digitalWrite(13,0);
//    }
//  }
//}
// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
RH_ASK driver;
void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
        // Message with a good checksum received, dump it.
        driver.printBuffer("Got:", buf, buflen);
        driver.symbol_6to4(buf);
      
        Serial.println("got reply from : 0x");
        Serial.println(buflen);
        Serial.println(": ");
        Serial.println((char*)buf);
        //Serial.println(buf[]);
      Serial.println("");

        
    }
}
