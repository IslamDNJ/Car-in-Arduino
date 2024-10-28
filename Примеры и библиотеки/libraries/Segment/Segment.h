// .h файл библиотеки Segment

#ifndef Segment_h
#define Segment_h
 
#include "Arduino.h"
 
class Segment
{
  public:
    Segment(int Pin1,int Pin2,int Pin3,int Pin4,int Pin5,int Pin6,int Pin7);
    void Indikator(double chislo,int Razr);
  
  private:
    int _DigPin[4], _dot, _Razryad [4], _i, _j, _latchPin,  _clockPin, _dataPin;

};
 
#endif