
#ifndef Ultrasonic_h
#define Ultrasonic_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 

#define CM 1
#define INC 0

class Ultrasonic
{
  public:
    Ultrasonic(int TP, int EP);
    long Timing();
    long Ranging(int sys);

    private:
    int Trig_pin;
    int Echo_pin;
    long  duration,distacne_cm,distance_inc;
    
};

#endif //#ifndef Ultrasonic_h
