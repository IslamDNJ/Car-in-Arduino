// Урок 22_1 Угадай случайное число
#define buzer A0
#define button1 A1
#define button2 A2

int SegPin[7] = {6,7,8,9,10,12,13}; //пины к которым подключен индикатор в последовательности: A,F,B,G,C,D,E
int DigPin[4] = {2,3,4,5}; // Пины к которым подключены dig выходы в последовательности: DIG4, DIg3, DIG2, DIG1
int Dot = 11; // Пин к которому подключен контакт точки DP

boolean Num[10][7] = {   // Двумерный массив каждой цифры индикатора
{1,1,1,0,1,1,1}, //0
{0,0,1,0,1,0,0}, //1
{1,0,1,1,0,1,1}, //2
{1,0,1,1,1,1,0}, //3
{0,1,1,1,1,0,0}, //4
{1,1,0,1,1,1,0}, //5
{1,1,0,1,1,1,1}, //6
{1,0,1,0,1,0,0}, //7
{1,1,1,1,1,1,1}, //8
{1,1,1,1,1,1,0}}; //9

int i,j, chislo=0, chislo2=0; //технические переменные для перебора 2-мерного массива и прочего использования
boolean state = 0, val;
void setup()
{
for (i = 0; i < 7; ++i){ // запускаем цикл в котором перебором присваимваем необходимым выводам режим ВЫХОД
  pinMode(SegPin[i], OUTPUT);}
for (i = 0; i < 4; ++i){ // запускаем цикл в котором перебором присваимваем необходимым выводам режим ВЫХОД
  pinMode(DigPin[i], OUTPUT);}
pinMode(Dot, OUTPUT);
pinMode(buzer, OUTPUT);
pinMode(button1, INPUT);
pinMode(button2, INPUT);
randomSeed(analogRead(A5));}

void indikator(int nomer){ //так как часто надо выводить нужное число на индикатор создадим для этого функцию
  for (i = 0; i < 7; i++) { // запускаем цикл для вывода числа на текущий разряд индикатора
   digitalWrite(SegPin[i], Num[nomer][i]);}} 

void loop() {
while (state == 0){  //пока State =0 крутимся в цикле
 digitalWrite(DigPin[0], 1); // включение первого разряда. Вместо HIGH используем 1
 indikator(chislo);   //выводим число на первый разряд
 val = digitalRead(button1); 
 if (val==HIGH){ //если копка 1 нажата, то
  delay (300);
  chislo = chislo+1;   //увеличиваем число на 1
  if (chislo == 10){chislo=0;}} //если число равно 10, то сброс на 0
 val = digitalRead(button2); //если кнопка 2 нажата
 if (val==HIGH){state=1;}  // переходим в состояние 2
}

if (state == 1){    //если state=1
digitalWrite(DigPin[0],0);   //зажигаем поочередно 8 в сегментах начиная с последнего. 
for (j=3; j >= 0; j--){
  indikator(8);
  digitalWrite(DigPin[j],1);
  tone(buzer,3000,250);             //при этом каждый раз издается звук
  delay(300);
  digitalWrite(DigPin[j],0); 
}
delay (500);
chislo2=random(0,10);  //присваиваем случайное значение
if (chislo2 == chislo){ // если угадали
 for (j=0; j < 4; j++){digitalWrite(DigPin[j],1);} //зажигаем все сегменты
 indikator(chislo2);   //выводим победившее число
 tone(buzer,5000,1000);  //высокий звук
 delay(2000);
 for (j=0; j<4; j++){digitalWrite(DigPin[j],0);} //гасим все сегменты
 }
else { //если не угадали
  digitalWrite(DigPin[3],1);  //включаем 4 сегмент
  indikator(chislo2);  //выводим случайно число 
  tone(buzer,300,1000);   
  delay(1000);
  digitalWrite(DigPin[3],0); //гасим сегмент
}state =0;} // возврат к состоянию 1
}

  
