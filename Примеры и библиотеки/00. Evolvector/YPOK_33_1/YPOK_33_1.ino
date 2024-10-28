//Урок 33
// Присваиваем константам номера пинов
#define M11 5
#define M12 6
#define M21 9
#define M22 10
#define line1 7
#define line2 8
#define buzer 3
#define led A1

#include "IRremote.h" //подключаем библиотеку для чтения ИК сигналов
IRrecv irrecv(11); // Указываем пин, к которому подключен приемник
decode_results results;
#include "Ultrasonic.h" //Подключается библиотека для работы с ультрозвуковым датчиком
Ultrasonic dalnomer(12, 13); //Программное подключение контактов датчика trig к пин 12, echo - к пин 13 
int res, reg, right, left, state, i=0, j=0, s, MemDist=100, dist, izmerenie, schet, fix; // объявление необходимых переменных
float time, timer, timer2; 

void setup(){ // назначение пинам необходимых режимов работы 
Serial.begin(9600);
pinMode(M11, OUTPUT);
pinMode(M12, OUTPUT);
pinMode(M21, OUTPUT);
pinMode(M22, OUTPUT);
pinMode(M21, OUTPUT);
pinMode(line1, INPUT);
pinMode(line2, INPUT);
pinMode(buzer, OUTPUT);
pinMode(led, OUTPUT);
irrecv.enableIRIn(); // Запускаем прием
}
 
void loop() {
  if (irrecv.decode(&results)){ // Если данные пришли 
    res=results.value;
    irrecv.resume();} // Принимаем следующую команду
  else {res=0;}
  switch (res) {
    case 0x6897:// Если нажата кнопка 1 
      reg = 1;
      break;
    case 0xFFFF9867:// Если нажата кнопка 2
      reg = 2;
      break;
    case 0xFFFFB04F:// Если нажата кнопка 3
      reg = 3;
      break;
    case 0x30CF:// Если нажата кнопка 4
      reg = 4;
      break;
    case 0x18E7:// Если нажата кнопка 5
      reg = 5;
      time=millis();
      dist=0;
      res=0;
      break;
    case 0x7A85:// Если нажата кнопка 6
      reg = 6;
      break;
    case 0x10EF:// Если нажата кнопка 7
      reg = 7;
      break;
    case 0x38C7:// Если нажата кнопка 8
      reg = 8;
      timer2=millis();
      schet=0;
      break;
    case 0x5AA5:// Если нажата кнопка 9
      reg = 9;
      state = 0;
      break;
    case 0x52AD:// Если нажата кнопка # 
      reg = 0;
      goStop();
      break; }   
 
 switch (reg) { // выбор режимов в зависимости от значения переменной reg
    case 1:
      reg1();
      break;
    case 2:
      reg2();
      break;
    case 3:
      reg3();
      break;
    case 4:
      reg4();
      break;
    case 5:
      reg5();
      break;
    case 6:
      reg6();
      break;
    case 7:
      reg7();
      break;
    case 8:
      reg8();
      break;
    case 9:
      reg9();
            break; }}
  
void reg1(){ 
     switch (res) {
      case 0x629D:// Если нажата кнопка вперед
        time = millis();
        goPered(255);
        break;
      case 0xFFFFA857:// Если нажата кнопка назад
        time = millis();
        goNazad(255);
        break;
      case 0x22DD:// Если нажата кнопка влево
        time = millis();
        goLevo(255);
        break;
      case 0xFFFFC23D:// Если нажата кнопка вправо
        time = millis();
        goPravo(255);
        break;
      case 0xFFFFFFFF:// Если кнопка удерживается
        time = millis();
        break;
     }
        if (millis()-time > 200){ //если нет нажатия на кнопку более 200 миллисекунд, то остановка
          goStop();}}

void reg2(){
switch (res) {
      case 0x629D:// Если нажата кнопка 
        time = millis();
        goNazad(255);
        break;
      case 0xFFFFA857:// Если нажата кнопка 
        time = millis();
        goPered(255);
        break;
      case 0x22DD:// Если нажата кнопка 
        time = millis();
        goLevo(255);
        break;
      case 0xFFFFC23D:// Если нажата кнопка 
        time = millis();
        goPravo(255);
        break;
      case 0xFFFFFFFF:// Если нажата кнопка 
        time = millis();
        break;
     }
        if (millis()-time > 200){
          goStop();}}

void reg3(){
right = digitalRead(line1); //правый датчик линии
left = digitalRead(line2); // левый датчик линии
dist = dalnomer.Ranging(CM); 
if (dist <20){goRazvorot();}
if (right == 0){ //если заезжаем правым датчиком на черное, то
  goPravo(230);} //поворачиваем на право что бы съехать с линии
if (left == 0){ //если заезжаем левым датчиком на черное, то
  goLevo(230);} //поворачиваем на лево что бы съехать с линии  
if (right==1 & left==1) { // если оба датчика на белом поле, то едем вперед  
  goPered(230);} 
if (right==0 & left==0){
  goStop();}
}

void reg4(){ // объезд припятствий с дальномером
dist = dalnomer.Ranging(CM); // замер дистанции
s=s+50;  // техническая переменная хаотичной задержки
if (s > 310) s=0; // сброс переменной
if (dist < 10){ //если препятствие ближе 10 см, то
  while (dist < 30){  //отъезжаем назад пока расстояние не будет больше 30 см
   goNazad(255);
   delay(s); 
   dist = dalnomer.Ranging(CM);}
 if (j < 4){ goLevo(255);} else {goPravo(255);} // после отъезда назад делаем разворот в право или лево
  delay(s+100);
   j=j+1; if (j>6){j=0;}} // изменение технической переменной
goPered(255); // едем вперед
}

void reg5(){
if (millis()-time < 5000){
  goLevo(255);
  dist = dalnomer.Ranging(CM);
  if ((dist - MemDist) < 0){MemDist=dist;}
  delay(30);
  }
else {
  goPravo(255);
  delay (70);
  goStop();
  dist = dalnomer.Ranging(CM);
  if ((dist-MemDist) < 5){goPered(255); delay (2000); reg=0;goStop();MemDist =100;}
  delay(20);
}}

void reg6(){
goPered(255);
s=s+50;  // техническая переменная хаотичной задержки
if (s > 310) s=0; // сброс переменной
right = digitalRead(line1); //правый датчик линии
left = digitalRead(line2); // левый датчик линии
if (right == 0 || left == 0 ){ //если заезжаем правым или левым датчиком на черное, то
  goNazad(255);
  delay(s+400);   
  goLevo(255); //делаем разворот
  delay(s+500); // задержка по времени
  }}
if(right == 0 & left == 0){
   goStop();
}

void reg7(){
goPered(255);
s=s+50;  // техническая переменная хаотичной задержки
if (s > 310) s=0; // сброс переменной
right = digitalRead(line1); //правый датчик линии
left = digitalRead(line2); // левый датчик линии
if (right == 0 || left == 0 ){ //если заезжаем правым или левым датчиком на черное, то
 delay(100); goStop(); delay(50);
 right = digitalRead(line1); //правый датчик линии
 left = digitalRead(line2); // левый датчик линии
 if (right == 0 & left == 0 ){ // если все еще на черной линии, то нашли клад
  delay(1000); goLevo(255); delay(2000); goStop(); reg=0;}
 else {goNazad(255);
  delay(s+400);   
  goLevo(255); //делаем разворот
  delay(s+500); // задержка по времени
  } 
} }

void reg8(){
 switch (res) {
      case 0x629D:// Если нажата кнопка вперед
        time = millis();
        goPered(255);fix=0;
        break;
      case 0xFFFFA857:// Если нажата кнопка назад
        time = millis();
        goNazad(255);fix=0;
        break;
      case 0x22DD:// Если нажата кнопка влево
        time = millis();
        goLevo(255);fix=0;
        break;
      case 0xFFFFC23D:// Если нажата кнопка вправо
        time = millis();
        goPravo(255);fix=0;
        break;
      case 0xFFFFFFFF:// Если кнопка удерживается
        time = millis();
        break;
     }
     if (millis()-time > 200){ //если нет нажатия на кнопку более 200 миллисекунд, то остановка
          goStop(); izmerenie = 1;} else {izmerenie = 0; digitalWrite(led,0);} //если кнопка нажимается, значит робот двигается, следовательно светодиод гасится и измерение не производится
          
   if (izmerenie==1 & fix == 0){//если робот стоит (т.е. izmerenie==1 и переменная fix=0, т.е. измерение еще не проводилось, то
   dist = dalnomer.Ranging(CM); //измеряем расстояние
   Serial.println(dist);
      if (dist == 10){beep(buzer,300); //если оно равно 10, то раздается "бип" и включается светодиод. Переменной fix фиксируем измерение. Пока робот не начнет движение fix будет равен 1 и измерение проводиться не будет.
      digitalWrite(led,1); schet=schet+1; fix=1;}} //так же при расстоянии равном 10 см счет увеличивается на 1.

if (schet >= 3 & fix==1){ //если счет равен 3
  fix = 0; schet=0;reg=0; // сбрасываем все переменные
  if (millis()-timer2 < 30000) { //если прошло от момента старта (нажатия кнопки 8) менее 30 секунд, то фиксируется победа
     beep(buzer,500);delay(300);digitalWrite(led,0);beep(buzer,600);digitalWrite(led,1);delay(600);beep(buzer,900);digitalWrite(led,0); //звучит победный сигнал. Светодиод при этом мигает.
  }else {digitalWrite(led,0), beep(buzer,900);//если больше 30 секунд, то звучит проигрышный сигнал и светодиод не горит
}}} 


void reg9(){
  dist = dalnomer.Ranging(CM); //измеряем расстояние  
if (dist < 15 & dist > 1){  // если оно в пределах от 1 до 15 см, то
  timer=timer+1;  //увеличиваем переменную на 1 (переменная считает количество появления препятствия в зоне контроля)
  time= millis(); //засекаем время
  delay (400);
  while (dist < 15 & dist > 1){ //измеряем расстояние, пока оно в пределах от 1 до 15 см
    dist = dalnomer.Ranging(CM);  
    if (millis() - time > 2000){ MemDist=dist; Reg9Move(); goStop(); timer=0; MemDist=100;}}} //если расстояние удерживается более 2х секунд, то запоминаем текущее расстояние и выполняем функцию следование за предметом (Reg9Move). Псоле возвращение из функции задаются необходимые данные (MemDist=100 необходимо для других режимов) .
  if (timer == 2 & (millis()-time) > 2000){ goLevo(255); delay(2000);goStop(); timer=0;} // если прошло 2 секунды и препятствие появлялось в зоне контроле 2 раза, то выполняется поворот налево
  if (timer == 3){ goPravo(255); delay(1000);goStop(); timer=0;}// если прошло 2 секунды и препятствие появлялось в зоне контроле 3 раза, то выполняется поворот направо
  if ((millis() - time) > 2000) {timer=0;}    //если условия не выполнились и прошло более 2х секунд, то счетчик сбрасывается на 0.
}
void Reg9Move(){ //функция следования за предметом
 while (dist < 30){ //пока расстояние меньше 30 см, выполняется эта функция
 dist = dalnomer.Ranging(CM); // измеряем расстояние
 delay (10);
 if ((MemDist - dist) > 1){goNazad(255);} // если расстояние уменьшалось от запомненного более чем на 1 см, то отъезжаем назад 
 if ((MemDist - dist) < -1){goPered(255);} //если расстояние увеличилось от запомненного более чем на 1 см, то едем вперед 
 if ((MemDist - dist) < 1 & (MemDist-dist) > -1) {goStop();}}} // если расстояние в пределах 1 см от запомненного, то останавливаемся

//далее следуют функции для езды вперед назад лево и право. А так же функция разворота для режима езды по линии.
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
    
void goRazvorot(){ // функция разворота для режима езды по линии
state = 0;
  while (state == 0) { //пока переменная state=0, выполняются команды цикла
    goLevo(255); //поворачиваем влево
    left = digitalRead(line2); //считываем информацию с левого датчика
    if (left == 0){i=1;}; //если зафиксировали черно поле, то запоминаем это событием присвоением переменной i значения 1
    if (i=1 & left ==1){state =1;}}}    // если снова зафиксировали белое поле, а до этого было черное, то разворот завершен, можно выходитьиз цикла.

/* Библиотека IRremote использует таймер контроллера который так же используется в функции tone  
 *  поэтому использовать функцию tone нельзя. При этом пользоваться ШИМ на пинах 3 и 11 тоже нельзя по той же причине.
 *  Для подачи сигнала бузером используется ручное генерирование импульсов.
 */
void beep(int buz, unsigned char delayms){ //"бип" бузером
for (i=0; i<(delayms*10); i++){
digitalWrite(buz,1);
delayMicroseconds(100); //задержка в микросекундах
digitalWrite(buz,0);
delayMicroseconds(100);
}}
