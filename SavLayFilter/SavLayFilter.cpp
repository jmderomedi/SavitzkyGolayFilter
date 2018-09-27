
#include "Arduino.h"
#include "SavLayFilter.h"

SavLayFilter::SavLayFilter() {
  _fillArrayCount = 0;
}

float SavLayFilter::quadCubicSmoothCalc(int8_t windowSize, float *_toBeSmoothedArray[]) {
  int8_t i = 0;
  for (i; i < windowSize; i++) {
    _sum += (*_toBeSmoothedArray[i] + *_toBeSmoothedArray[(windowSize - 1) - i]) * _quadCubicSmoothConvolute[_arrayPointer][i];
  }
  _sum += *_toBeSmoothedArray[(windowSize + 1) / 2] * _quadCubicSmoothConvolute[_arrayPointer][(windowSize + 1) / 2];
  _sum = _sum / _quadCubicSmoothNormalFactor[_arrayPointer][0];

  return _sum;
}

float SavLayFilter::quadCubicSmooth(int8_t windowSize, float inputValue) {
  int8_t j = 1;
  if (_fillArrayCount != windowSize) {
    _toBeSmoothedArray[_fillArrayCount] = inputValue;
    _fillArrayCount++;
    return 0.0;
  } else {
    switch (windowSize) {
      case 5:
        _arrayPointer = 0;
        _smoothedValue = quadCubicSmoothCalc(windowSize, _toBeSmoothedArray[]);
        for (j; j <= windowSize; j++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 7:
        _arrayPointer = 1;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 9:
        _arrayPointer = 2;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 11:
        _arrayPointer = 3;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 13:
        _arrayPointer = 4;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 15:
        _arrayPointer = 5;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 17:
        _arrayPointer = 6;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 19:
        _arrayPointer = 7;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 21:
        _arrayPointer = 8;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 23:
        _arrayPointer = 9;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
      case 25:
        _arrayPointer = 10;
        _smoothedValue = quadCubicSmoothCalc( windowSize, _toBeSmoothedArray[]);
        for (i; i <= windowSize; i++) {
          *_toBeSmoothedArray[i - 1] = *_toBeSmoothedArray[i];
        }
        *_toBeSmoothedArray[windowSize - 1] = inputValue;
        break;
    }//END Switch
    return _smoothedValue;
  }//END If
}



