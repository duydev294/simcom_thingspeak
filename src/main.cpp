#include <Arduino.h>
#include "thingspeak.h"
#include<SoftwareSerial.h>
#include "AT_Command.h"
#define RX 2
#define TX 3
char API_KEY[] =   "PLN98OMOMQQNZMPT";
char   field1[] =  "field1";
SoftwareSerial sim(RX,TX);
Thingspeak ts = Thingspeak (API_KEY,field1,&sim);
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
 sim.begin(115200);
  Serial.begin(9600);
   Serial.println("Serial start!");


}

void loop() {
  // put your main code here, to run repeatedly:
}