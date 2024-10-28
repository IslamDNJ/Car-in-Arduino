// Урок 17 схема 1

#include <Servo.h> // подключается библиотека для управления сервоприводом  
Servo myservo;  // программно определяется сервопривод
#define button1 11  //назначаются имена констант (button1 на вывод 11)
#define button2 10 // button2 на вывод 10
#define led1 13 // led1 на вывод 13
#define led2 12  // led2 на вывод 12
int state1, state2, regim=1, buzer=9, i; //задаются необходимые переменные
float time;  
void setup() {
    pinMode(button1, INPUT);  // назначаются режимы работы пинов
    pinMode(button2, INPUT);
    pinMode(led1, OUTPUT); 
    pinMode(led2, OUTPUT);
     myservo.attach(7);  // серводвигатель программно подключается к выводу 7
}
void reg1(){    //инициализация функции reg1  (работа в режиме 1)
state1 = digitalRead(button1);  //считывается состояние кнопок 1 и 2
  state2 = digitalRead(button2);
  if (state1 == HIGH) {  // если кнопка 1 нажата, то:
       time= millis();   // засекается время 
       while(state1 == HIGH){   //до тех пор, пока кнопка 1 нажата            
       state1 = digitalRead(button1);   // считывается состояние кнопки 1
  if (millis() - time > 3000) {  // если прошло времени больше 3 секунд, то:
     regim = 2;                  // переменной regim присваивается значение 2 (то есть происходит переключение в режим 2)
     digitalWrite(buzer, HIGH); tone(buzer, 3000, 1000);}  //подается сигнал на бузер
     }
    if (regim == 1) {digitalWrite(led1, HIGH); delay (1000); digitalWrite(led1, LOW);} //если regim равно 1, то есть режим не изменился
                                                                      // (кнопка была нажата меньше 3х секунд), то светодиод 1 включается на 1 секунду.
 }
          
   if (state2 == HIGH) {digitalWrite(led2, HIGH); delay (1000); digitalWrite(led2, LOW); // если была нажата кнопка 2, то включается светодиод 2 на 1 сек.
}}                     // конец функции reg1

void reg2(){ //инициализация (начало) функции reg2  (работа в режиме 2)
  digitalWrite(led1, HIGH);   // включаются светдиоды
  digitalWrite(led2, HIGH);
  state1 = digitalRead(button1); // считывается состояние кнопок 1 и 2
  state2 = digitalRead(button2);
  if (state1 == HIGH) {  // если нажата кнопка 1, то вал серводвигателя поворачивается в положение 150 градусов
       myservo.write(150);
       delay (500);
       myservo.write(30);
       delay (500);
       myservo.write(90);
        }
   
  if (state2 == HIGH) {  // если кнопка 2 нажата, то:
       time= millis();   // засекается время 
       while(state2 == HIGH){     //до тех пор, пока кнопка 2 нажата           
       state2 = digitalRead(button2); // считывается состояние кнопки 2
  if (millis() - time > 3000) {       // если прошло времени больше 3 секунд, то 
      regim = 1;                      // переменной regim присваивается значение 1 (то есть выполняется переключение в режим 1)
    digitalWrite(led1, LOW); digitalWrite(led2, LOW);   // выключаются светодиоды
    digitalWrite(buzer, HIGH); tone(buzer, 3000, 1000);}}  // подается определенный сигнал на бузер
if (regim == 2) {digitalWrite(buzer, HIGH); tone(buzer, 4000, 500);}  //если regim равно 2, то есть режим не изменился
                                                                      // (кнопка была нажата меньше 3х секунд), то подается сигнал на бузер
}  } //  конец функции reg2

void loop(){    // основное тело программы
if (regim == 1) { reg1();}   // если regim равно 1, то выполняем функцию reg1
if (regim == 2) { reg2();}  // если regim равно 2, то выполняем функцию reg2
}
