#include "ADC.h"
#include "Teensy31FastADC.h"

int LED = 13;
int AIN = A14;
int AIN2 = A15;
int AIN3 = A16;
// for the highspeed functions you need to figure out the right channel via ADC_Module::channel2sc1aADC0["APIN#"]
const int channelA3 = ADC::channel2sc1aADC0[14];
const int channelA4 = ADC::channel2sc1aADC0[15];
const int channelA5 = ADC::channel2sc1aADC1[16];

void setup() {                
  highSpeed8bitADCSetup();
  pinMode(LED, OUTPUT); 
  pinMode(AIN, INPUT);
  pinMode(AIN2, INPUT);
  pinMode(AIN3, INPUT); 
  Serial.begin(115200);  
 
}

int val = 0;
int val2 = 0;
int val3 = 0;
int startTime;
int stopTime; 
int i;
int samples = 1000000;
int samplesPerSec;

void loop() {

  startTime = millis();
  
  for(i=0;i<samples;i++) {     
     //val = highSpeed8bitAnalogRead(channelA3);
     //val2 = highSpeed8bitAnalogRead(channelA4);
     val = highSpeed8bitAnalogRead(channelA5);
     //highSpeed8bitAnalogReadMacro(channelA4, channelA5, val2, val3);
     val2 = analogRead(AIN3);
     Serial.print(val);Serial.print(", ");Serial.print(val2);Serial.print(", ");/*Serial.print(val3);Serial.print(", ")*/;Serial.print("\n");
  }
  
  stopTime = millis();
  int totalTime = stopTime-startTime;
  samplesPerSec = samples*1000/totalTime;

  //PRINT Sample/sec
  //Serial.print("T: ");
  //Serial.print(totalTime);
  //Serial.print(" S/sec: ");
  //Serial.println(samplesPerSec);

  //BLINK
  digitalWrite(LED, HIGH);   
  delay(100);               
  digitalWrite(LED, LOW); 
  delay(100);
} 



/*
Timings in ms for 1.000.000 readings
analogRead
T: 8881 S/sec: 112599
T: 8882 S/sec: 112587
T: 8881 S/sec: 112599
T: 8881 S/sec: 112599
analogRead + highSpeed8bitADCSetup
T: 1630 S/sec: 613496
T: 1631 S/sec: 613120
T: 1631 S/sec: 613120
T: 1631 S/sec: 613120
highSpeedAnalogRead + highSpeed8bitADCSetup
T: 1022 S/sec: 978473
T: 1023 S/sec: 977517
T: 1022 S/sec: 978473
T: 1023 S/sec: 977517
ighSpeedAnalogReadMacro + highSpeed8bitADCSetup
T: 813 S/sec: 1230012
T: 814 S/sec: 1228501
T: 813 S/sec: 1230012
T: 814 S/sec: 1228501
*/
