#include <Arduino.h>
#include <SoftwareSerial.h>
unsigned int vSenser = 0;
#define rxPin 0
#define txPin 1
SoftwareSerial ser(rxPin, txPin);
//#define ser Serial
void serialEventRun(){
  String str;
  while (ser.available()) {
    str = ser.readString();
    ser.print(vSenser);
  }  
}
void setup() {
  pinMode(A0,INPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  // put your setup code here, to run once:
  ser.setTimeout(1);
  ser.begin(9600);
  while (!Serial)
  {
    ;// waiting  Serial Port connected.
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  vSenser = analogRead(A0);
  serialEventRun();
}