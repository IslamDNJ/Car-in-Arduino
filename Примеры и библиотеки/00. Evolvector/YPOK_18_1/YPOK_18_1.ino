
// Урок 19 схема 1 (Рингтоны на выбор)

int button = 7, state, regim=1, buzer=8, i=1, z;  // Определяются переменные, которые используются в программе
float time; // Переменная для фиксации времени
void setup() {
    pinMode(button, INPUT);  //контакт контроллера для считывания состояния кнопки настраивается как Вход
  }
void loop(){
if (regim == 1) { reg1();}  // Выбор режима зависимости от значения переменной regim. Если 1, то выполняется функция reg1
if (regim == 2) { reg2();}  // если 2, то выполняется функция reg2 
}


void reg1(){  // функция reg1 для первого режима работы
state = digitalRead(button); // проверяется нажата ли кнопка
delay (50);   // задержка против случайных срабатываний кнопки
    if (state == HIGH) {  //если кнопка нажата, то:
       time= millis();  // засекается время нажатия
       while(state == HIGH){         //и пока кнопка нажата 
       state = digitalRead(button);  // считывается её состояние    
  if (millis() - time > 3000) {  // если нажатие длится больше 3 секунд
     regim = 2;                  // переменной regim присваивается значение 2 (значит потом будет выполнен переход в режим 2)
     digitalWrite(buzer, HIGH); tone(buzer, 3000, 1000);}  // бузером подается звуковой сигнал
     }
    if (regim == 1) {song();} // если кнопку отпустили раньше, чем через 3 секунды (то есть режим не переключился), то выполняется функция song
 }
}

void reg2(){  // функция reg2 для второго режима работы
  state = digitalRead(button); // проверяется состояние кнопки (нажата или нет)
  delay(50);// задержка против случайных срабатываний кнопки
  if (state == HIGH) {  //если кнопка нажата то:
       time= millis(); // засекается время нажатия
       while(state == HIGH){          //и пока кнопка нажата      
       state = digitalRead(button);// считывается её состояние 
  if (millis() - time > 3000) {// если нажатие длится больше 3 секунд
      regim = 1;// переменной regim присваивается значение 1 (значит потом будет выполнен переход в режим 1)
     digitalWrite(buzer, HIGH); tone(buzer, 3000, 1000);} // с помощью бузера подается звуковой сигнал
    }
if (regim == 2) { // если кнопку отпустили раньше, чем через 3 секунды (то есть режим не переключился), то выполняется ряд действий:
i=i+1;     //к переменной i прибавляется единица. Переменная i отвечает за номер мелодии.
if (i>4) {i=1;} // если i больше 4, то её значение сбрасывается на 1, так как мелодий всего 4
for (z=1; z<=i; z++){ // запускаются циклы (количество циклов равно номеру мелодии)
digitalWrite(buzer, HIGH); tone(buzer, (1000+z*300), 100); delay(400);} //подается звуковой сигнал. Частота звучания сигнала увеличивается в зависимости от номера мелодии.
}  
}}

void song (){  // функция song
if (i == 1) {song1();}  // в зависимости от значения i запускаются функцию song1, song2, song3, либо song 4
if (i == 2) {song2();}
if (i == 3) {song3();}
if (i == 4) {song4();}
}



void song1(){   // Далее определяются функции от song1 до song4, которые воспроизводят запрограммированные мелодии.
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            delay(600);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            delay(600);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 494, 100);delay(100);
            tone(buzer, 494, 100);delay(100);
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 523, 100);delay(100);
            tone(buzer, 523, 100);delay(100);
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 440, 300);delay(300);}
void song2(){
    tone(buzer, 247, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,370, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,329, 500); delay(500);
    tone(buzer,247, 500); delay(500);
    tone(buzer,247, 500); delay(500);
    tone(buzer,247, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,370, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,497, 500); delay(500);
    delay(500);
    tone(buzer,497, 500); delay(500);
    tone(buzer,277, 500); delay(500);
    tone(buzer,277, 500); delay(500);
    tone(buzer,440, 500); delay(500);
    tone(buzer,440, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,370, 500); delay(500);
    tone(buzer,329, 500); delay(500);
    tone(buzer,247, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,370, 500); delay(500);
    tone(buzer,417, 500); delay(500);
    tone(buzer,329, 500); delay(500);
}
void song3(){
        tone(buzer,264, 125); delay(125);
        delay(250);
        tone(buzer,264, 125); delay(125);
        delay(125);
        tone(buzer,297, 500); delay(500);
        delay(125);
        tone(buzer,264, 500); delay(500);
        delay(125);
        tone(buzer,352, 500); delay(500);
        delay(125);
        tone(buzer,330, 1000); delay(1000);
        delay(250);
        tone(buzer,264, 125); delay(125);
        delay(250);
        tone(buzer,264, 125); delay(125);
        delay(125);
        tone(buzer,297, 500); delay(500);
        delay(125);
        tone(buzer,264, 500); delay(500);
        delay(125);
        tone(buzer,396, 500); delay(500);
        delay(125);
        tone(buzer,352, 1000); delay(1000);
        delay(250);
        tone(buzer,264, 125); delay(125);
        delay(250);
        tone(buzer,264, 125); delay(125);
        delay(125);
        tone(buzer,264, 500); delay(500);
        delay(125);
        tone(buzer,440, 500); delay(500);
        delay(125);
        tone(buzer,352, 250); delay(250);
        delay(125);
        tone(buzer,352, 125); delay(125);
        delay(125);
        tone(buzer,330, 500); delay(500);
        delay(125);
        tone(buzer,297, 1000); delay(1000);
        delay(250);
        tone(buzer,466, 125); delay(125);
        delay(250);
        tone(buzer,466, 125); delay(125);
        delay(125);
        tone(buzer,440, 500); delay(500);
        delay(125);
        tone(buzer,352, 500); delay(500);
        delay(125);
        tone(buzer,396, 500); delay(500);
        delay(125);
        tone(buzer,352, 1000); delay(1000);
}
void song4(){
        tone(buzer,659, 125); delay(125);
        tone(buzer,659, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,523, 125); delay(125);
        tone(buzer,659, 125); delay(125);
        delay(125);
        tone(buzer,784, 125); delay(125);
        delay(375);
        tone(buzer,392, 125); delay(125);
        delay(375);
        tone(buzer,523, 125); delay(125);
        delay(250);
        tone(buzer,392, 125); delay(125);
        delay(250);
        tone(buzer,330, 125); delay(125);
        delay(250);
        tone(buzer,440, 125); delay(125);
        delay(125);
        tone(buzer,494, 125); delay(125);
        delay(125);
        tone(buzer,466, 125); delay(125);
        delay(42);
        tone(buzer,440, 125); delay(125);
        delay(125);
        tone(buzer,392, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(125);
        tone(buzer,784, 125); delay(125);
        delay(125);
        tone(buzer,880, 125); delay(125);
        delay(125);
        tone(buzer,698, 125); delay(125);
        tone(buzer,784, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(125);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,587, 125); delay(125);
        tone(buzer,494, 125); delay(125);
        delay(125);
        tone(buzer,523, 125); delay(125);
        delay(250);
        tone(buzer,392, 125); delay(125);
        delay(250);
        tone(buzer,330, 125); delay(125);
        delay(250);
        tone(buzer,440, 125); delay(125);
        delay(125);
        tone(buzer,494, 125); delay(125);
        delay(125);
        tone(buzer,466, 125); delay(125);
        delay(42);
        tone(buzer,440, 125); delay(125);
        delay(125);
        tone(buzer,392, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(125);
        tone(buzer,784, 125); delay(125);
        delay(125);
        tone(buzer,880, 125); delay(125);
        delay(125);
        tone(buzer,698, 125); delay(125);
        tone(buzer,784, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(125);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,587, 125); delay(125);
        tone(buzer,494, 125); delay(125);
        delay(375);
        tone(buzer,784, 125); delay(125);
        tone(buzer,740, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(42);
        tone(buzer,622, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,415, 125); delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        tone(buzer,587, 125); delay(125);
        delay(250);
        tone(buzer,784, 125); delay(125);
        tone(buzer,740, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(42);
        tone(buzer,622, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,698, 125); delay(125);
        delay(125);
        tone(buzer,698, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(625);
        tone(buzer,784, 125); delay(125);
        tone(buzer,740, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(42);
        tone(buzer,622, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,415, 125); delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        tone(buzer,587, 125); delay(125);
        delay(250);
        tone(buzer,622, 125); delay(125);
        delay(250);
        tone(buzer,587, 125); delay(125);
        delay(250);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,784, 125); delay(125);
        tone(buzer,740, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(42);
        tone(buzer,622, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,415, 125); delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        tone(buzer,587, 125); delay(125);
        delay(250);
        tone(buzer,784, 125); delay(125);
        tone(buzer,740, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(42);
        tone(buzer,622, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,698, 125); delay(125);
        delay(125);
        tone(buzer,698, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(625);
        tone(buzer,784, 125); delay(125);
        tone(buzer,740, 125); delay(125);
        tone(buzer,698, 125); delay(125);
        delay(42);
        tone(buzer,622, 125); delay(125);
        delay(125);
        tone(buzer,659, 125); delay(125);
        delay(167);
        tone(buzer,415, 125); delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        delay(125);
        tone(buzer,440, 125); delay(125);
        tone(buzer,523, 125); delay(125);
        tone(buzer,587, 125); delay(125);
        delay(250);
        tone(buzer,622, 125); delay(125);
        delay(250);
        tone(buzer,587, 125); delay(125);
        delay(250);
        tone(buzer,523, 125); delay(125);
        
}


