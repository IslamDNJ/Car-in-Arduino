// .cpp файл
#include "Arduino.h"
#include "Segment.h"

int _Num[10] = {0b01110111,0b00010100,0b01011011,0b01011110,0b00111100,0b01101110,0b01101111,0b01010100,0b01111111,0b01111110}; 

Segment::Segment(int Pin1,int Pin2,int Pin3,int Pin4,int Pin5,int Pin6,int Pin7)

{
_DigPin[0] = Pin1;
_DigPin[1] = Pin2;
_DigPin[2] = Pin3;
_DigPin[3] = Pin4;
_latchPin = Pin5;
_clockPin = Pin6;
_dataPin = Pin7;

  for (_i = 0; _i < 4; _i++){ // запускаем цикл в котором перебором присваимваем необходимым выводам режим ВЫХОД
  pinMode(_DigPin[_i], OUTPUT);}
 
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_dataPin, OUTPUT);
 }
 
void Segment::Indikator(double chislo, int Razr)
{
  chislo = chislo * pow(10,Razr); // приводим дробное число к целому
if (chislo >= 10000){chislo=9999;} //если полученной число больше 4х разрядов, то выводим 9999
  _Razryad[3] = chislo/1000; // выделяем из числа цифру четвертого разряда
  _Razryad[2] = (chislo-_Razryad[3]*1000)/100;// выделяем из числа цифру третьего разряда
  _Razryad[1] = (chislo-_Razryad[3]*1000-_Razryad[2]*100)/10;// выделяем из числа цифру второго разряда
  _Razryad[0] = (chislo-_Razryad[3]*1000-_Razryad[2]*100-_Razryad[1]*10); // выделяем из числа цифру первого разряда
for (_j=0; _j < 4; _j++){   // запускаем цикл перебора разрядов
  if (Razr == _j){_dot=0b10000000;} else {_dot=0;}// Если разряд соответствует введенному количеству знаков после запятой, то ставим в этом разряде точку. Искусственно превращая число снова в дробное
 digitalWrite(_latchPin, LOW);
shiftOut(_dataPin, _clockPin, MSBFIRST, _Num[_Razryad[_j]] | _dot); 
digitalWrite(_latchPin, HIGH);
digitalWrite(_DigPin[_j],HIGH); //включаем вывод цифры на нужном разряде
delay(1); // задержка для срабатывания запирающих транзисторов
 digitalWrite(_DigPin[_j],LOW); //отключаем разряд на котором вывили цифры
}
}
