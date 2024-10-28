// езда по линии. Едем по черной линии которая между датчиками
#define M11 5
#define M12 6
#define M21 9
#define M22 10
#define line1 7
#define line2 8
#include "Ultrasonic.h" //Подключается библиотека для работы с ультрозвуковым датчиком
Ultrasonic dalnomer(12, 13); //Программное подключение контактов датчика trig к пин 12, echo - к пин 13 
int right, left, state, i=0;
float dist;

void setup(){
pinMode(line1,OUTPUT);
pinMode(line2,OUTPUT);
pinMode(M11, OUTPUT);
pinMode(M12, OUTPUT);
pinMode(M21, OUTPUT);
pinMode(M22, OUTPUT);
dist = dalnomer.Ranging(CM);

}

void loop (){
right = digitalRead(line1); //правый датчик линии
left = digitalRead(line2); // левый датчик линии
dist = dalnomer.Ranging(CM);

if (dist <20){goRazvorot();}
if (right == 0){ //если заезжаем правым датчиком на черное, то
  goPravo(220);} //поворачиваем на право что бы съехать с линии
if (left == 0){ //если заезжаем левым датчиком на черное, то
  goLevo(220);} //поворачиваем на лево что бы съехать с линии  
if (right==1 & left==1) {  
  goPered(220);}
if (right==0 & left==0) {  
  goStop();} 
  
 // delay(10);
}

void goRazvorot(){
state = 0;i=0;
  while (state == 0) {
    goLevo(220);
    left = digitalRead(line2);
    if (left == 0){i=1;};
    if (i==1 & left ==1){state =1;}}}


int goPered(int Skorost){analogWrite(M12,LOW);
    analogWrite(M21,LOW);
    analogWrite(M11,Skorost);
    analogWrite(M22,Skorost);}
int goNazad(int Skorost){analogWrite(M11,LOW);
    analogWrite(M22,LOW); 
      analogWrite(M12,Skorost);
    analogWrite(M21,Skorost);}
int goLevo(int Skorost){analogWrite(M12,LOW);
   analogWrite(M22,LOW); 
    analogWrite(M11,Skorost);
    analogWrite(M21,Skorost);}
int goPravo(int Skorost){digitalWrite(M11,LOW);
    analogWrite(M21,LOW); 
    analogWrite(M12,Skorost);
   analogWrite(M22,Skorost);}
void goStop(){digitalWrite(M12,LOW);
    digitalWrite(M21,LOW);
    digitalWrite(M11,LOW);
    digitalWrite(M22,LOW);}
