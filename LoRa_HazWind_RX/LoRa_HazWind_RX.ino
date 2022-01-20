#include <SoftwareSerial.h>
#include <string.h>
#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial14.h"

#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1

SoftwareSerial reyax(11, 10);
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

String message;

void ScanDMD(){
  dmd.scanDisplayBySPI();
}

void dmd_txt(char *txt){
  dmd.drawMarquee(txt, strlen(txt), (32*DISPLAYS_ACROSS)-1, 1);
  long start = millis();
  long timer = start;
  boolean ret = false;
  while(!ret){
    if((timer+10) < millis()) {
      ret = dmd.stepMarquee(-1,0);
      timer = millis();
    }
  }
}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void setup() {
  Timer1.initialize(500);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);
  dmd.selectFont(Arial_14);
  Serial.begin(9600);
  reyax.begin(9600);

  delay(100);

  reyax.print("AT\r\n");
  Serial.print("AT\r\n");
}

void loop() {
  if(reyax.available() > 0){
    message = reyax.readString();
    Serial.print("Data received: ");
    Serial.println(message);

    String dt = getValue(message, ',', 2);

    if(dt = "a"){
      dmd_txt("Evacuacion Puerta 1");
    } else if(dt = "b"){
      dmd_txt("Evacuacion Puerta 2");
    } else if(dt = "c"){
      dmd_txt("Evacuacion Puerta 3");
    } else if(dt = "d"){
      dmd_txt("Evacuacion Puerta 4");
    } else if(dt = "e"){
      dmd_txt("Evacuacion Puerta 5");
    } else if(dt = "f"){
      dmd_txt("Evacuacion Puerta 6");
    } else if(dt = "g"){
      dmd_txt("Evacuacion Puerta 7");
    } else if(dt = "h"){
      dmd_txt("Evacuacion Puerta 8");
    } else if(dt = "z"){
      dmd_txt("Ruta de Evacuacion");
    }
  } else {
    dmd_txt("Sin datos.");
    Serial.println("NO DATA");
  }

  delay(200);
}