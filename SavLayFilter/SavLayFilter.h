#ifndef SavLayFilter_h
#define SavLayFilter_h


class SavLayFilter {

public:
//=======================================================================================
  SavLayFilter();
  //float smoothing(float*);                        //*Constructor. Generic function, calls cubic 
                                                  //smoothing table of window size 5
                                                  //Links the input to the filter
  float smoothing(float, int8_t, int8_t);        //*Constructor. Links the input data to the filter
  //float testingArray[10];                       //Takes the windows size and table that is choosen

  void resetValues(){                             //Resets entire filter. Be careful when calling
    for (int i = 0; i < 13; i++){                 //Since it will ruin current filtering
      _toBeSmoothedArray[i] = 0;
    }
    _fillArrayCount = 0;
    _sum = 0;
    _smoothedValue = 0;
    _arrayPointer = 0;
  };

//=======================================================================================
private:
  //void _resetValues();
  float _calculating(int8_t windowSize, float windowArray[]);   //Internally used to compute
                                                                //actually filtered value

  int  (*_convoluteTable)[14];              //Used to internally reference which table to use
  int* _normalizationFactor;           //Used to internally reference which normalization factor

  int8_t _arrayPointer;                     //Pointer for moving through data array
  int8_t _fillArrayCount;                   //Used to check if the data array is filled
  float _sum;                               //Returned value of _calculating()
  float _smoothedValue;                     //Returned value of the filter

    float _toBeSmoothedArray[13];           //Array that will be filled with the inputValues
                                            //Set to thirteen since that is max the window size can go to

    int _quadCubicSmooth[11][14] = {        //Contains the convolutes for each window size
                                            //First column is normization factor
      { 35, -3, 12, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    //Window size 5
      { 21, -2, 3, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},      //Window size 7
      { 231, -21, 14, 39, 54, 59, 0, 0, 0, 0, 0, 0, 0, 0},   //Window size 9
      { 429, -36, 9, 44, 69, 84, 89, 0, 0, 0, 0, 0, 0, 0},   //Window size 11
      { 143, -11, 0, 9, 16, 21, 24, 25, 0, 0, 0, 0, 0, 0},   //Window size 13
      { 1105, -78, -13, 42, 87, 122, 147, 162, 167, 0, 0, 0, 0, 0},   //Window size 15
      { 323, -21, -6, 7, 18, 27, 34, 39, 42, 43, 0, 0, 0, 0},        //Window size 17
      { 2261, -136, -51, 24, 89, 144, 189, 224, 249, 264, 269, 0, 0, 0},    //Window size 19
      { 3059, -171, -76, 9, 84, 149, 204, 249, 284, 309, 324, 329, 0, 0},   //Window size 21
      { 8059, -42, -21, -2, 15, 30, 43, 54, 63, 70, 75, 78, 79},            //Window size 23
      { 5175, -254, -138, -33, 62, 147, 222, 287, 322, 387, 422, 447, 462, 467}   //Window size 25
    };

    //Missing window size 17 because of scan line from paper
    int _quarticQuinticSmooth[11][14] = {
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,5,-30,75,131,0,0,0,0,0,0,0,0,0},
      {0,15,-55,30,135,179,0,0,0,0,0,0,0,0},
      {0,18,-45,-10,60,120,143,0,0,0,0,0,0,0},
      {0,110,-198,-160,110,390,600,677,0,0,0,0,0,0},
      {0,2145,-2860,-2937,-165,3755,7500,10125,11053,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,340,-255,-420,-290,18,405,790,1110,1320,1393,0,0,0},
      {0,11628,-6460,-13005,-11220,-3940,6378,17655,28190,36660,42120,44003,0,0},
      {0,285,-114,-285,-285,-165,30,261,495,705,870,975,1011,0},
      {0,1265,-345,-1122,-1255,-915,-255,590,1503,2385,3155,3750,4125,4253}
    };
    int _quadFirstDerive[11][14] = {
      {0,-2,-1,0,0,0,0,0,0,0,0,0,0,0},
      {0,-3,-2,-1,0,0,0,0,0,0,0,0,0,0},
      {0,-4,-3,-2,-1,0,0,0,0,0,0,0,0,0},
      {0,-5,-4,-3,-2,-1,0,0,0,0,0,0,0,0},
      {0,-6,-5,-4,-3,-2,-1,0,0,0,0,0,0,0},
      {0,-7,-6,-5,-4,-3,-2,-1,0,0,0,0,0,0},
      {0,-8,-7,-6,-5,-4,-3,-2,-1,0,0,0,0,0},
      {0,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,0,0,0},
      {0,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,0,0},
      {0,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,0},
      {0,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0}
    };
    int _cubicQuarticFirstDerive[11][14] = {
      {0,1,-8,0,0,0,0,0,0,0,0,0,0,0},
      {0,22,67,-58,0,0,0,0,0,0,0,0,0,0},
      {0,86,-142,-193,-126,0,0,0,0,0,0,0,0,0},
      {0,300,-294,-532,-503,-296,0,0,0,0,0,0,0,0},
      {0,1133,-660,-1578,-1796,-1489,-832,0,0,0,0,0,0,0},
      {0,12922,-4121,-14150,-18334,-17842,-13843,-7506,0,0,0,0,0,0},
      {0,748,-98,-643,-930,-1002,-902,-1002,-902,-673,-358,0,0,0},
      {0,6936,68,-4648,-7481,-8700,-8574,-8179,-5363,-2816,0,0,0,0},
      {0,84075,10032,-43284,-78176,-96947,-101900,-95338,-79564,-56881,-29592,0,0,0},
      {0,3938,815,-1518,-3140,-4130,-4567,-4098,-3350,-2365,-1222,0,0},
      {0,30866,8602,-8525,-20982,-29236,-33754,-35003,-33450,-29562,-23806,-16649,-8558,0}
    };
    int _quinticFirstDerive[11][14] = {
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,-90,18,-2,0,0,0,0,0,0,0,0,0,0},
      {0,-5758,-4538,2762,-508,0,0,0,0,0,0,0,0,0},
      {0,-3084,-3776,-1244,2166,-573,0,0,0,0,0,0,0,0},
      {0,-31380,-45741,-33511,-12,27093,-14647,0,0,0,0,0,0,0},
      {0,-175125,-279975,-266401,-130506,65229,169819,-78351,0,0,0,0,0,0},
      {0,-23945,-40483,-43973,-32306,-8671,16679,24661,-14404,0,0,0,0,0},
      {0,-332684,-583549,-686099,-604484,-348823,9473,322378,349928,-255102,0,0,0},
      {0,-15977364,-28754154,-35613829,-34807914,-26040033,-10949942,6402438,19052988,16649358,-15033066,0,0,0},
      {0,-357045,-654687,-840937,-878634,-752859,-478349,-106911,265164,489687,359157,-400653,0,0},
      {0,-6356625,-11820675,-15593141,-17062146,-15896511,-12139321,-6301491,544668,6671883,9604353,6024183,-8322182,0}  
    };
    int _quadCubicSecDerive[11][14];
    int _quarticQuinticSecDerive[11][14];
    int _cubicQuarticThirdDerive[11][14];
    int _quinticThirdDerive[11][14];
    int _quarticQuinticFourDerive[11][14];
    int _quinticFifthDerive[11][14];


    

    int _quadFirstDeriveNormal[11][1] = {
      {10},
      {28},
      {60},
      {110},
      {182},
      {280},
      {408},
      {570},
      {770},
      {1012},
      {1300}
    };

};//END Class

#endif
