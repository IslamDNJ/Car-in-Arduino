#define button 13
#include <Segment.h>
Segment SEG(2,3,4,5,8,12,11);
int val, state;
double number=0, time;

void setup()
{}
 
void loop()
{
val=digitalRead(button);//считываем состояние кнопки
if (val == HIGH){ //если она нажата, то
  delay(200); state = 1 - state; // меняем состояние переменной state
  if (number == 0) { time = millis();}} // если number=0, то это первое нажатие кнопки и присваиваем переменной time текущее время
while (state == 1){   //пока состояние переменной state не поменяется, будем выводить секунды на индикатор
  number =(millis()-time)/1000.0; //переменно присваивается значение равное количеству секунд (за минусом запомненного)
  SEG.Indikator(number,1); // запуск функции, которая выводит значение переменной с 1 знаком после запятой
  val=digitalRead(button); // считываем состояние кнопки
  if (val == HIGH){state = 1-state; delay(200);}} // если кнопка нажата, то меняем состояние переменной state
SEG.Indikator(number,1); // при значении state =0 выводим последнее значение переменной number
}
