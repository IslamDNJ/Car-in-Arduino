
// Урок сигнализатор заряда
#include <Servo.h>  //подключается библиотека для управления серводвигателем
Servo serv;   // Присваиваем серводвигателю имя serv
int serva = 8; //Определяется номер пина к которому подключен серводвигатель
int kond = A0; // определяется номер входа для считывания уровня напряжения
int val=0, ugol=0; //задаются начальные значения переменным 

void setup() 
{ 
 serv.attach(serva); // подсоединяется серводвигатель к назначенному выводу
 } 
void loop() 
{
 val = analogRead(kond);//считываются значения напряжения с конденсатора
 Serial.println(val);  // вывод на последовательный порт значения с датчика
 ugol = map (val,0,1024,0,180); // перевод значения с датчика в углы поворота серводвигателя
 serv.write(ugol); // поворот серводвигателя на полученный угол
}



