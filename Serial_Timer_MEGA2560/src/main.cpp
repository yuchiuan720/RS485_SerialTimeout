#include <Arduino.h>
#include <SoftwareSerial.h>
unsigned int vSenser = 0;
#define rxPin 19
#define txPin 18
#define dirPin 41
//SoftwareSerial ser(rxPin, txPin);
#define ser Serial1
void SendStr(String str) {
  digitalWrite(dirPin, HIGH);
  ser.print(str);
  ser.flush();
  digitalWrite(dirPin, LOW);
}
void SendValue() {
  digitalWrite(dirPin, HIGH);
  delayMicroseconds(10);
  ser.print(vSenser);
  ser.flush();
  digitalWrite(dirPin, LOW);
  delayMicroseconds(10);
}
void serialEventRun(){
  String str;
  while (ser.available()) {
    str = ser.readString();
    delay(1);
    SendValue();
  }  
}
void setup() {
  pinMode(A0,INPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  // put your setup code here, to run once:
  ser.setTimeout(0);
  ser.begin(19200);
  while (!ser)
  {
    ;// waiting  Serial Port connected.
  }
  SendStr("Hello, Echo");
}

void loop() {
  // put your main code here, to run repeatedly:
  vSenser = analogRead(A0);
  //serialEventRun();
}