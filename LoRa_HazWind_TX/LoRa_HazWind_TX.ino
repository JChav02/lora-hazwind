#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial reyax(11, 10); // RX, TX

int pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9;
int dataLength, ledStatus = HIGH;
String data;

void setup() {
  Serial.begin(9600);
  reyax.begin(9600);

  delay(100);

  reyax.print("AT\r\n");
  Serial.print("AT\r\n");
}

void loop() {
  if(digitalRead(pin2) == 0){
    data = "a";
  } else if(digitalRead(pin3) == 0){
    data = "b";
  } else if(digitalRead(pin4) == 0){
    data = "c";
  } else if(digitalRead(pin5) == 0){
    data = "d";
  } else if(digitalRead(pin6) == 0){
    data = "e";
  } else if(digitalRead(pin7) == 0){
    data = "f";
  } else if(digitalRead(pin8) == 0){
    data = "g";
  } else if(digitalRead(pin9) == 0){
    data = "h";
  } else {
    data = "z";
  }

  dataLength = data.length();
  String message;
  message = message + "AT+SEND=0" + "," + dataLength + "," + data + "\r\n";
  reyax.print(message);
  Serial.print("Data sent: ");
  Serial.println(message);
  delay(100);
}