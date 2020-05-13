#include "arduinoFFT.h"
#include "ADC.h"
#include "Teensy31FastADC.h"

int LED = 13;
int AIN = A14;
int AIN2 = A15;
int AIN3 = A16;
const int channelA3 = ADC::channel2sc1aADC0[14];
const int channelA4 = ADC::channel2sc1aADC0[15];
const int channelA5 = ADC::channel2sc1aADC0[16];

arduinoFFT FFT = arduinoFFT(); /* Create FFT object */

const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 44000; //Hz, must be less than 540,000 due to ADC

unsigned int sampling_period_us;
unsigned long microseconds;

double vReal[samples];
double vImag[samples];

void setup()
{
  highSpeed8bitADCSetup();
  pinMode(LED, OUTPUT); 
  pinMode(AIN, INPUT);
  pinMode(AIN2, INPUT);
  pinMode(AIN3, INPUT); 
  sampling_period_us = round(1000000*(1.0/samplingFrequency));
  Serial.begin(9600);
  delay(3000);
  Serial.println("Ready");
}

void loop()
{
  /*SAMPLING*/
  microseconds = micros();
  for(int i=0; i<samples; i++)
  {

      Serial.print("High Speed: "); Serial.println( highSpeed8bitAnalogRead(channelA4));
      Serial.println( analogRead(A15));

      delay(1000);
/*      highSpeed8bitAnalogRead(channelA4);
      vReal[i] = analogRead(A15);
      vImag[i] = 0;
     vReal2[i] = highSpeed8bitAnalogRead(channelA4);
      vImag2[i] = 0;
      vReal3[i] = highSpeed8bitAnalogRead(channelA5);
      vImag3[i] = 0;
     */ 
      while(micros() - microseconds < sampling_period_us){
        //Serial.println(micros());
      }
      
      microseconds += sampling_period_us;
  }
  
//  FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);  /* Weigh data */
//  FFT.Compute(vReal, vImag, samples, FFT_FORWARD); /* Compute FFT */
//  FFT.ComplexToMagnitude(vReal, vImag, samples); /* Compute magnitudes */
//  double x = FFT.MajorPeak(vReal, samples, samplingFrequency);
//  Serial.println(x, 6); //Print out what frequency is the most dominant.
  
}
