// Урок 28 Шаговый двигатель
#include <Stepper.h>
#define Button 7
const int stepsPerRevolution = 4096;  // change this to fit the number of steps per revolution
int termo = A0;// Переменная termo для вывода A0
int val, val2, state = 0, Step0=0, Step, Stp, i;
float voltage;// Переменная для вычисления реального напряжения                                     
float voltage2;
Stepper myStepper(stepsPerRevolution, 8,9,10,11); //инициализация шагового двигателя на пины 8-10

void setup() {
 myStepper.setSpeed(5);} //устанавливаем скорость в 5 оборот в минуту

void loop() {
 val2= digitalRead(Button);
  if (val2 == HIGH){
   if (state ==1){ // если шел цикл измерения отклоненией, то
     digitalWrite(13,LOW);
     myStepper.step(-Step0); //поворачиваем шаговик в нулевое положение
     state = 0;} //изменяется состояние, тем самым прерывается цикл измерения отклонений
   else {  //если state 0, то запускается цикл измерений
     state = 1;
     val = analogRead(termo);// считывается цифровое значение напряжение с контакта А0
     voltage = (val*4.7/1023);// рассчитывается исходное напряжение
     Step0=0;
     digitalWrite(13,HIGH);}
   delay(500);}//задержка от ложных срабатываний кнопки
  if (state == 1){
   val = analogRead(termo);// считывается цифровое значение напряжение с контакта А0
   voltage2 = (val*4.7/1023);// преобразуется цифровое значение напряжения в реальное
   Stp = (voltage2-voltage)*100; // расчет количества шагов от начального значения   
   Step = Stp*512 - Step0; // Расчет шагов на данный момент (может быть отрицательным)
   myStepper.step(Step); //поворачиваем шаговик на "Step" оборотов
   Step0 = Stp*512; // Запоминаем на сколько повернули от начального значения     
   delay(300);}}
