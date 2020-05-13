#include "ADC.h"
#include "Teensy31FastADC.h"

ADC *adc = new ADC(); // adc object

int samples = 1000000;
int startTime;
int stopTime;
int totalTime;

int pin1 = A15;
int pin2 = A16;
int pin3 = A14;

int val1;
int val2;
int val3;
int result;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  highSpeed8bitADCSetup();
  adc->adc0->startContinuous(pin1);
  adc->adc1->startContinuous(pin2);
}

void loop() {
  // put your main code here, to run repeatedly:
  startTime = millis();
  Serial.println("Started");
  for(int i=0;i<samples;i++) {
    val1 = adc->adc0->analogReadContinuous();
    val2 = adc->adc1->analogReadContinuous();
    val3 = adc->analogRead(pin3, ADC_0);
    //val1 = result.result_adc0;
    //val2 = result.result_adc1;
    Serial.print(val1); Serial.print(","); Serial.print(val2); Serial.print(","); Serial.print(val3); Serial.print("\n");
  }
  stopTime = millis();
  totalTime = stopTime-startTime;
  //Serial.println(totalTime);
  //delay(3000);
  
}
