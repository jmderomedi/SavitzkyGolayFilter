#include <SavLayFilter.h>
/**
   License stuff
   Author: James Deromedi
*/

float phase = 0.0;
float twopi = 3.14159 * 2;
elapsedMicros usec = 0;

double outputValue;
int windowsize = 5;
int convoluteTable = 0;

SavLayFilter firstDerivative (&outputValue, 1, 7);           //Computes the first derivative

void setup() {
  Serial.begin(9800);
}

void loop() {
  outputValue = (sin(phase) * 50.0);                        //Creates sin wave pattern with A = 50
  phase = phase + 0.02;                                     //Shifts the sin wave
  if (phase >= twopi) phase = 0;                            //Resets the phase
  while (usec < 30000) ;                                    //Wait to make printing easier to read
  usec = usec - 30000;                                      //Keeps timer from overflowing

  Serial.print(outputValue);                                //Raw Value [Blue line]
  Serial.print(",");
  Serial.println(firstDerivative.smoothing());              //First derivative of the sin wave

}
