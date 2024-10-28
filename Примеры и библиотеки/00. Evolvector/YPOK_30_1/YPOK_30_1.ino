#include <IRremote.h>
int Resiver = 11, res;
IRrecv irrecv(Resiver);
decode_results results;
  void setup(){
    Serial.begin(9600);
    irrecv.enableIRIn();}

  void loop(){ 
 if (irrecv.decode(&results)){ 
   res=results.value;
   Serial.println(res, HEX);
   irrecv.resume();  }}
