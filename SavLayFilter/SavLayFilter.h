#ifndef SavLayFilter_h
#define SavLayFilter_h

#include "Arduino.h"

class SavLayFilter {

  public:
    SavLayFilter();
    float quadCubicSmooth(int8_t sizeOfWindow, float inputVal);
    
  private:
    float _quadCubicSmoothCalc(int8_t windowSize, float windowArray[]);
    int8_t _arrayPointer;
    int8_t _fillArrayCount;
    float _sum;
    float _smoothedValue;
    float _toBeSmoothedArray[13]; //Array that will be filled by quadCubicSmooth with inputValues
    int _quadCubicSmoothConvolute[11][13] = {
      { -3, 12, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //Window size 5
      { -2, 3, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //Window size 7
      { -21, 14, 39, 54, 59, 0, 0, 0, 0, 0, 0, 0, 0},   //Window size 9
      { -36, 9, 44, 69, 84, 89, 0, 0, 0, 0, 0, 0, 0},   //Window size 11
      { -11, 0, 9, 16, 21, 24, 25, 0, 0, 0, 0, 0, 0},   //Window size 13
      { -78, -13, 42, 87, 122, 147, 162, 167, 0, 0, 0, 0, 0},   //Window size 15
      { -21, -6, 7, 18, 27, 34, 39, 42, 43, 0, 0, 0, 0},    //Window size 17
      { -136, -51, 24, 89, 144, 189, 224, 249, 264, 269, 0, 0, 0},    //Window size 19
      { -171, -76, 9, 84, 149, 204, 249, 284, 309, 324, 329, 0, 0},   //Window size 21
      { -42, -21, -2, 15, 30, 43, 54, 63, 70, 75, 78, 79},    //Window size 23
      { -254, -138, -33, 62, 147, 222, 287, 322, 387, 422, 447, 462, 467}   //Window size 25
    };

    int _quadCubicSmoothNormalFactor[11][1] = {
      {35}, //5
      {21}, //7
      {231},  //9
      {429},  //11
      {143},  //13
      {1105}, //15
      {323},  //17
      {2261}, //19
      {3059}, //21
      {8059}, //23
      {5175}  //25
    };

};//END Class

#endif
