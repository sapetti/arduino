////simple Tx on pin D12
//#include <VirtualWire.h>
//
//char *controller;
//
//void setup() {
//  pinMode(13,OUTPUT);
//  vw_set_ptt_inverted(true); //
//  vw_set_tx_pin(12);
//  vw_setup(4000);// speed of data transfer Kbps
//}
//
//void loop(){
//  controller="1"  ;
//  vw_send((uint8_t *)controller, strlen(controller));
//  vw_wait_tx(); // Wait until the whole message is gone
//  digitalWrite(13,1);
//  delay(2000);
//  controller="0"  ;
//  vw_send((uint8_t *)controller, strlen(controller));
//  vw_wait_tx(); // Wait until the whole message is gone
//  digitalWrite(13,0);
//  delay(2000);
//
//}
// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
RH_ASK driver;
void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
void loop()
{
    const char *msg = "hello";
    Serial.println(msg);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
