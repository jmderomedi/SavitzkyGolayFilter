#ifndef SavLayFilter_h
#define SavLatFilter_h

#include "Arduino.h"

class SavLayFilter {

  public:
    SavLayFilter();
    float quadCubicSmooth(int8_t windowSize, float inputValue, float *windowArray[]);

  private:
    float _quadCubicSmoothCalc(int8_t windowSize, float *windowArray[]);
    int8_t _arrayPointer;
    int8_t _fillArrayCount;
    float _sum;
    float _smoothedValue;
    float _toBeSmoothedArray[13];
    int16_t _quadCubicSmoothConvolute[][13] = {
      { -3, 12, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      { -2, 3, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      { -21, 14, 39, 54, 59, 0, 0, 0, 0, 0, 0, 0, 0},
      { -36, 9, 44, 69, 84, 89, 0, 0, 0, 0, 0, 0, 0},
      { -11, 0, 9, 16, 21, 24, 25, 0, 0, 0, 0, 0, 0},
      { -78, -13, 42, 87, 122, 147, 162, 167, 0, 0, 0, 0, 0},
      { -21, -6, 7, 18, 27, 34, 39, 42, 43, 0, 0, 0, 0},
      { -136, -51, 24, 89, 144, 189, 224, 249, 264, 269, 0, 0, 0},
      { -171, -76, 9, 84, 149, 204, 249, 284, 309, 324, 329, 0, 0},
      { -42, -21, -2, 15, 30, 43, 54, 63, 70, 75, 78, 79},
      { -254, -138, -33, 62, 147, 222, 287, 322, 387, 422, 447, 462, 467}
    };

    int16_t _quadCubicSmoothNormalFactor[][1] = {
      {35},
      {21},
      {231},
      {429},
      {143},
      {1105},
      {323},
      {2261},
      {3059},
      {8059},
      {5175}
    };

}//END Class

#endif
