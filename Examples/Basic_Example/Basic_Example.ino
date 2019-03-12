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

SavLayFilter smallFilter (&outputValue, 0, 5);             //Cubic smoothing with windowsize of 5
SavLayFilter largeFilter (&outputValue, 0, 25);            //Cubic smoothing with windowsize of 25

void setup() {
  Serial.begin(9800);
}

void loop() {
  float noise = analogRead(A1);                             //Creates random noise from a floating pin
  outputValue = (sin(phase) * 1000.0 + 2000.0) + noise;     //Creates sin wave pattern with A = 1000 and shifted up by 2000
  phase = phase + 0.02;                                     //Shifts the sin wave
  if (phase >= twopi) phase = 0;                            //Resets the phase
  while (usec < 30000) ;                                    //Wait to make printing easier to read
  usec = usec - 30000;                                      //Keeps timer from overflowing

  Serial.print(outputValue);                                //Raw Value [Blue line]
  Serial.print(",");
  Serial.print(smallFilter.compute());                    //Smoothed value of smaller window [Orange line]
  Serial.print(",");
  Serial.println(largeFilter.compute());                  //Smoothed value of smaller window [Red line]
}
