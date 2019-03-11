
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <SavLayFilter.h>

SavLayFilter::SavLayFilter(){
  _fillArrayCount = 0;
  _arrayPointer = 0;
  _sum = 0.0;
  _smoothedValue = 0.0;

}

float SavLayFilter::_calculating(int8_t windowSize, float inputArray[]) {
  for (int i = 0; i < windowSize/2; i++) {
    _sum += (inputArray[i] + inputArray[(windowSize - 1) - i]) * (_convoluteTable[_arrayPointer][i+1]);
  }
  _sum += inputArray[(windowSize) / 2] * (_convoluteTable[_arrayPointer][((windowSize) / 2)+1]);
  _sum = (_sum / *_normalizationFactor);

  return _sum;
}

float SavLayFilter::smoothing(float inputValue, int8_t windowSize, int8_t convoluteTable) {
  switch (convoluteTable) {								//Meant to save the table, norm factor user specifies
    case 0:
    _convoluteTable = _quadCubicSmooth;					//links and saves the table to be used
    //_normalizationFactor = _quadCubicSmoothNormal;	//Saves which norm factor will be used
    //Saves the normalization factor that is first column in each table
    break;	
    case 1:
    _convoluteTable =_quadFirstDerive;
    //_normalizationFactor = _quadFirstDeriveNormal;
    //_normalizationFactor = _quadFirstDerive[0];
    break;
    case 2:
    _convoluteTable = _quarticQuinticSmooth;
   //_normalizationFactor = _quadCubicSmoothNormal;
    //_normalizationFactor = _quarticQuinticSmooth[0];
    break;
    case 3:
    _convoluteTable = _cubicQuarticFirstDerive;
   // _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 4:
    _convoluteTable = _quinticFirstDerive;
   // _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 5:
    _convoluteTable = _quadCubicSecDerive;
    //_normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 6:
    _convoluteTable = _quarticQuinticSecDerive;
    //_normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 7:
    _convoluteTable = _cubicQuarticThirdDerive;
    //_normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 8:
    _convoluteTable = _quinticThirdDerive;
    //_normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 9:
    _convoluteTable = _quarticQuinticFourDerive;
    //_normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 10:
    _convoluteTable = _quinticFifthDerive;
    //_normalizationFactor = _quadCubicSmoothNormal;
    break;
  }

  if (_fillArrayCount != ((windowSize+1)/2)) {			//Checks if the data array is full
    _toBeSmoothedArray[_fillArrayCount] = inputValue;	//If not, then it adds it to the array
    _fillArrayCount++;									//This will cause the first half f window size to be empty
    return 0.0;

  } else {
    switch (windowSize) {						//Calls the calculation function on the windowsize set by user

      case 5:
      _arrayPointer = 0;						//Sets which line to call in the array for window size values
      _normalizationFactor = _convoluteTable[0, 0];			//Saves the norm factor for the windowsize/convolute table
      _smoothedValue = _calculating(windowSize, _toBeSmoothedArray);	//Computes a smooth value
      for (int j = 1; j <= windowSize; j++) {							// moves window over input array
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;					//Inputs newly smoothed value
      break;

      case 7:
      _arrayPointer = 1;
      _normalizationFactor = _convoluteTable[1, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 9:
      _arrayPointer = 2;
      _normalizationFactor = _convoluteTable[2, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 11:
      _arrayPointer = 3;
      _normalizationFactor = _convoluteTable[3, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 13:
      _arrayPointer = 4;
      _normalizationFactor = _convoluteTable[4, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 15:
      _arrayPointer = 5;
      _normalizationFactor = _convoluteTable[5, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 17:
      _arrayPointer = 6;
      _normalizationFactor = _convoluteTable[6, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 19:
      _arrayPointer = 7;
      _normalizationFactor = _convoluteTable[7, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 21:
      _arrayPointer = 8;
      _normalizationFactor = _convoluteTable[8, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 23:
      _arrayPointer = 9;
      _normalizationFactor = _convoluteTable[9, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      case 25:
      _arrayPointer = 10;
      _normalizationFactor = _convoluteTable[10, 0];
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;

      default:
      _smoothedValue = -9999999;

    }//END Switch
    //testingArray[0] = _arrayPointer;
    return _smoothedValue;
  }//END If
}



