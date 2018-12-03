
#include "Arduino.h"
#include "SavLayFilter.h"

SavLayFilter::SavLayFilter(){
  _fillArrayCount = 0;
  _arrayPointer = 0;
  _sum = 0.0;
  _smoothedValue = 0.0;

}

float SavLayFilter::_calculating(int8_t windowSize, float inputArray[]) {
  //int8_t i = 0;
  for (int i = 0; i < windowSize/2; i++) {
    _sum += (inputArray[i] + inputArray[(windowSize - 1) - i]) * (_convoluteTable[_arrayPointer][i]);
  }
  _sum += inputArray[(windowSize) / 2] * (_convoluteTable[_arrayPointer][(windowSize) / 2]);
  _sum = (_sum) / ( _normalizationFactor[_arrayPointer][0]);

  return _sum;
}

float SavLayFilter::smoothing(int8_t windowSize, float inputValue, int8_t convoluteTable) {
  switch (convoluteTable) {
    case 0:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 1:
    _convoluteTable =_quadFirstDerive;
    _normalizationFactor = _quadFirstDeriveNormal;
    break;
    case 2:
    _convoluteTable = _quarticQuinticSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 3:
    _convoluteTable = _cubicQuarticFirstDerive;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 4:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 5:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 6:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 7:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 8:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 9:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
    case 10:
    _convoluteTable = _quadCubicSmooth;
    _normalizationFactor = _quadCubicSmoothNormal;
    break;
  }
  //int8_t j = 1;
  if (_fillArrayCount != ((windowSize+1)/2)) {
    _toBeSmoothedArray[_fillArrayCount] = inputValue;
    _fillArrayCount++;
    return 0.0;
  } else {
    switch (windowSize) {

      case 5:
      _arrayPointer = 0;
      _smoothedValue = _calculating(windowSize, _toBeSmoothedArray);
        //Moving the data over
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 7:
      _arrayPointer = 1;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 9:
      _arrayPointer = 2;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 11:
      _arrayPointer = 3;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 13:
      _arrayPointer = 4;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 15:
      _arrayPointer = 5;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 17:
      _arrayPointer = 6;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 19:
      _arrayPointer = 7;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 21:
      _arrayPointer = 8;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 23:
      _arrayPointer = 9;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      case 25:
      _arrayPointer = 10;
      _smoothedValue = _calculating( windowSize, _toBeSmoothedArray);
      for (int j = 1; j <= windowSize; j++) {
        _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
      }
      _toBeSmoothedArray[windowSize - 1] = inputValue;
      break;
      default:
      _smoothedValue = -9999999;
    }//END Switch
    testingArray[0] = _arrayPointer;
    return _smoothedValue;
  }//END If
}



