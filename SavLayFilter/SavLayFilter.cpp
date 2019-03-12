
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <SavLayFilter.h>

SavLayFilter::SavLayFilter(double* input, int tableNumber, int windowNumber){
  myInput = input;    //Creates the actual link
  //myConvoluteTable = tableNumber;   //Saves the table number
  myWindowSize = windowNumber;    //Saves the window size

  _fillArrayCount = 0;          //Sets all other private variables to zero
  _arrayPointer = 0;
  _sum = 0.0;
  _smoothedValue = 0.0;

  switch (tableNumber) {               //Meant to save the convolation table
    case 0:
      _convoluteTable = _quadCubicSmooth;         //links and saves the table to be used
      break;  
      case 1:
      _convoluteTable =_quadFirstDerive;
      break;
      case 2:
      _convoluteTable = _quarticQuinticSmooth;
      break;
      case 3:
      _convoluteTable = _cubicQuarticFirstDerive;
      break;
      case 4:
      _convoluteTable = _quinticFirstDerive;
      break;
      case 5:
      _convoluteTable = _quadCubicSecDerive;
      break;
      case 6:
      _convoluteTable = _quarticQuinticSecDerive;
      break;
      case 7:
      _convoluteTable = _cubicQuarticThirdDerive;
      break;
      case 8:
      _convoluteTable = _quinticThirdDerive;
      break;
      case 9:
      _convoluteTable = _quarticQuinticFourDerive;
      break;
      case 10:
      _convoluteTable = _quinticFifthDerive;
      break;
    default:                                //If anything else is given, automatically cubic smoothing
    _convoluteTable = _quadCubicSmooth;
  } //End Switch
}

float SavLayFilter::_calculating(double inputArray[]) {
  if (_convoluteTable == _quadFirstDerive){
    for (int i = 0; i < myWindowSize/2; i++) {
      _sum += (inputArray[i]) * (_convoluteTable[_arrayPointer][i+1]);
    }
    for (int i = (myWindowSize/2 + 1); i < myWindowSize; i++) {
      _sum += (inputArray[i]) * (-1 * _convoluteTable[_arrayPointer][(i - (myWindowSize/2 + 1)) + 1]);
    }
    _sum += inputArray[(myWindowSize) / 2] * (_convoluteTable[_arrayPointer][((myWindowSize) / 2)+1]);
    _sum = (_sum / *_normalizationFactor);

    return _sum;
  } else {

    for (int i = 0; i < myWindowSize/2; i++) {
      _sum += (inputArray[i] + inputArray[(myWindowSize - 1) - i]) * (_convoluteTable[_arrayPointer][i+1]);
    }
    _sum += inputArray[(myWindowSize) / 2] * (_convoluteTable[_arrayPointer][((myWindowSize) / 2)+1]);
    _sum = (_sum / *_normalizationFactor);

    return _sum;
  }
}

float SavLayFilter::smoothing() {
  if (_fillArrayCount != ((myWindowSize+1)/2)) {		  	//Checks if the data array is full
    _toBeSmoothedArray[_fillArrayCount] = *myInput;	   //If not, then it adds it to the array
    _fillArrayCount++;									              //This will cause the first half f window size to be empty
    _smoothedValue = 0.0;
    return _smoothedValue;

  } else {
    switch (myWindowSize) {						//Calls the calculation function on the windowsize set by user

      case 5:
        _arrayPointer = 0;						//Sets which line to call in the array for window size values
        _normalizationFactor = _convoluteTable[_arrayPointer];			              //Saves the norm factor for the windowsize/convolute table
        _smoothedValue = _calculating( _toBeSmoothedArray);	            //Computes a smooth value

        for (int j = 1; j <= myWindowSize; j++) {						            //moves window over input array
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;				      	//Inputs newly smoothed value
        break;

        case 7:
        _arrayPointer = 1;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 9:
        _arrayPointer = 2;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating(_toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 11:
        _arrayPointer = 3;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating(_toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 13:
        _arrayPointer = 4;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 15:
        _arrayPointer = 5;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 17:
        _arrayPointer = 6;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 19:
        _arrayPointer = 7;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 21:
        _arrayPointer = 8;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 23:
        _arrayPointer = 9;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        case 25:
        _arrayPointer = 10;
        _normalizationFactor = _convoluteTable[_arrayPointer];
        _smoothedValue = _calculating( _toBeSmoothedArray);

        for (int j = 1; j <= myWindowSize; j++) {
          _toBeSmoothedArray[j - 1] = _toBeSmoothedArray[j];
        }
        _toBeSmoothedArray[myWindowSize - 1] = *myInput;
        break;

        default:
        _smoothedValue = -9999999;

    }//END Switch
    //testingArray[0] = _arrayPointer;
    return _smoothedValue;
  }//END If
}



