#define button 13
int DigPin[4] = {2,3,4,5}; // Пины к которым подключены dig выходы в последовательности: DIG4, DIG3, DIG2, DIG1
int Num[10]= {0b01110111,0b00010100,0b01011011,0b01011110,0b00111100,0b01101110,0b01101111,0b01010100,0b01111111,0b01111110};
int Razryad [4]; // массив для хранения каждой цифры разряда
int i,j,dot,val,state;
double number=0, time;
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (i = 0; i < 4; ++i){ // запускаем цикл в котором перебором присваимваем необходимым выводам режим ВЫХОД
     pinMode(DigPin[i], OUTPUT);}
}
 
void loop()
{
val=digitalRead(button);//считываем состояние кнопки
if (val == HIGH){ //если она нажата, то
  delay(200); state = 1 - state; // меняем состояние переменной state
  if (number == 0) { time = millis();}} // если number=0, то это первое нажатие кнопки и присваиваем переменной time текущее время
while (state == 1){   //пока состояние переменной state не поменяется, будем выводить секунды на индикатор
  number =(millis()-time)/1000.0; //переменно присваивается значение равное количеству секунд (за минусом запомненного)
  Indikator(number,1); // запуск функции, которая выводит значение переменной с 1 знаком после запятой
  val=digitalRead(button); // считываем состояние кнопки
  if (val == HIGH){state = 1-state; delay(200);}} // если кнопка нажата, то меняем состояние переменной state
Indikator(number,1); // при значении state =0 выводим последнее значение переменной number
}

void Indikator(double chislo, int Razr){  // получаем из программы число и колличество знаков после запятой
chislo = chislo * pow(10,Razr); // приводим дробное число к целому
if (chislo >= 10000){chislo=9999;} //если полученной число больше 4х разрядов, то выводим 9999
  Razryad[3] = chislo/1000; // выделяем из числа цифру четвертого разряда
  Razryad[2] = (chislo-Razryad[3]*1000)/100;// выделяем из числа цифру третьего разряда
  Razryad[1] = (chislo-Razryad[3]*1000-Razryad[2]*100)/10;// выделяем из числа цифру второго разряда
  Razryad[0] = (chislo-Razryad[3]*1000-Razryad[2]*100-Razryad[1]*10); // выделяем из числа цифру первого разряда
for (j=0; j < 4; j++){   // запускаем цикл перебора разрядов
  if (Razr == j){dot=0b10000000;} else {dot=0;}// Если разряд соответствует введенному количеству знаков после запятой, то ставим в этом разряде точку. Искусственно превращая число снова в дробное
 digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, Num[Razryad[j]] | dot); 
digitalWrite(latchPin, HIGH);
digitalWrite(DigPin[j],HIGH); //включаем вывод цифры на нужном разряде
delay(1); // задержка для фиксации информации на индикаторе
digitalWrite(DigPin[j],LOW); //отключаем разряд на котором вывили цифры
}}  
  

