#ifndef SavLayFilter_h
#define SavLayFilter_h

#include "Arduino.h"

class SavLayFilter {

public:
    // Constructor
  SavLayFilter();
  float smoothing(int8_t sizeOfWindow, float inputVal, int8_t convoluteTableNum);
  float testingArray[10];

    //Resets the arrayPointer so it gets refilled with data from start
  void resetValues(){
    _arrayPointer = 0;
    _sum = 0;
    _smoothedValue = 0;
  };
private:
  void _resetValues();
  float _calculating(int8_t windowSize, float windowArray[]);

  int  (*_convoluteTable)[13];
  int (*_normalizationFactor)[1];

  int8_t _arrayPointer;
  int8_t _fillArrayCount;
  float _sum;
  float _smoothedValue;
    float _toBeSmoothedArray[13]; //Array that will be filled by quadCubicSmooth with inputValues
    int _quadCubicSmooth[11][13] = {   //Contains the convolutes for each window size
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

    int _quadCubicSmoothNormal[11][1] = {
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

    int _quarticQuinticSmooth;
    int _quadFirstDerive;
    int _cubicQuarticFirstDerive;
    int _quinticFirstDerive;
    int _quadCubicSecDerive;
    int _quarticQuinticSecDerive;
    int _cubicQuarticThirdDerive;
    int _quinticThirdDerive;
    int _quarticQuinticFourDerive;
    int _quinticFifthDerive;

};//END Class

#endif
