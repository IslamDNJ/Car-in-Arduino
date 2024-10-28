// Урок 24 схема 1
int latchPin = 8; //Пин подключен к ST_CP входу микросхемы
int clockPin = 12; //Пин подключен к SH_CP входу микросхемы
int dataPin = 11; //Пин подключен к DS входу микросхемы
int a,i; 
 void setup() {
  //устанавливаем режим OUTPUT для подключенных пинов
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
 void loop() {
  for (i=0; i<4; i++){ //запускаем 4 цикла попеременного моркания светодиодов
    digitalWrite(latchPin, LOW); // открываем «защелку» 
    shiftOut(dataPin, clockPin, MSBFIRST, 0b10101010); // передаем последовательно на dataPin
    digitalWrite(latchPin, HIGH);//Закрываем "защелку", тем самым устанавливая значения на выходах
    delay(500);
    digitalWrite(latchPin, LOW); // открываем «защелку» 
    shiftOut(dataPin, clockPin, MSBFIRST, 0b01010101); // передаем последовательно на dataPin
    digitalWrite(latchPin, HIGH); //Закрываем "защелку", тем самым устанавливая значения на выходах
    delay(500); }

  a= 0b00000001; // присваиваем переменной начально значение
  for (i=0; i<8; i++){ // запускаем 8 циклов для бегущего огонька в одну сторону
    digitalWrite(latchPin, LOW);// открываем «защелку» 
    shiftOut(dataPin, clockPin, MSBFIRST, a); // передаем последовательно на dataPin значение переменной "а"
    digitalWrite(latchPin, HIGH);  //Закрываем "защелку", тем самым устанавливая значения на выходах
    delay(250);
    a = a << 1;} //смещаем значение переменной "а" на один бит влево 
      
  for (i=0; i<8; i++){ // запускаем 8 циклов для бегущего огонька в другую сторону
   a = a >> 1;  //смещаем значение переменной "а" на один бит вправо
   digitalWrite(latchPin, LOW); // открываем «защелку» 
   shiftOut(dataPin, clockPin, MSBFIRST, a); // передаем последовательно на dataPin значение переменной "а"
   digitalWrite(latchPin, HIGH); //Закрываем "защелку", тем самым устанавливая значения на выходах
   delay(250);}
}
