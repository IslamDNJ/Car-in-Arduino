// Урок 15 схема 1
#define knopka 7        // Вводятся имена констант
#define ledred 4
#define ledgreen 3
#define serva 2
#define buzer 8
#define foto A0
#include <Servo.h>  // подключается бибилиотека для управления серводвигателем
 
Servo myservo;   // серводвигатель определяется на уровне программы

int val=0, i=0, knop=0;   // определяются переменные
void setup() 
{ 

  myservo.attach(serva);    //серводвигатель подключается к пину с именем serva 
  pinMode(knopka, INPUT);   // устанавливаются режимы работы пинов контроллера 
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
    
} 
 
void loop() 
{
 
 knop = digitalRead(knopka);   //считывается состояние кнопки
 if (knop == HIGH) {          // если кнопка нажата, то выполняются следующие действия
 i=1;
 digitalWrite(ledred, LOW);     // отключается красный и включается зеленый светодиоды
 digitalWrite(ledgreen, HIGH);
 val = analogRead(foto);
          while(val >500){     // в цикле ожидается затемнение фоторезистора 
 val = analogRead(foto);
 }
 delay (500);
 while(val<800){              // после затемнения фоторезистора ожидается увеличение количества света
 val = analogRead(foto);
 }

delay (50);                  //после увеличения освещенности выключается зеленый светодиод
digitalWrite(ledgreen, LOW);

                     }
  val = analogRead(foto);   // строки программного когда, которые выполняются если кнопка не нажата
 if (val < 500) {               // если произошло затемнение, то серводвигатель поворачивается
   
  myservo.write(90);           
  tone(buzer, 4000, 20);   // с помощью бузера подается звуковой сигнал
 
 }
 else {
 myservo.write(0);                 // если нет затемнения, вал серводвигателя в нулевом положении
 digitalWrite(ledred, HIGH);}  // и включен красный светодиод
 delay (50);
 
}

