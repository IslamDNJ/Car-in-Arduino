
// Урок 12 схема 1
int led=10, buzer=8, foto=A0;   //переменным присваиваются номера выводов
int svet=510, tma=34;   // создаются переменные с пограничными значениями освещенности
int val, i=0;    // инициализируются необходимые технические переменные
void setup() {
pinMode(led, OUTPUT);   // контакт, к которому подключен светодиод, настраивается как выход
pinMode(buzer, OUTPUT);   // вывод с бузером настраивается как выход
Serial.begin(9600);   //открывается последовательный порт
}
void loop(){
 val = analogRead(foto); //считывается значение освещенности и присваивается переменной val
  Serial.println(val);  // значение переменной val передается на последовательный порт
if (val < tma+50) {     // если значение освещенности меньше tma+50, то:
 digitalWrite(led, HIGH);  // включается светодиод
 i=1;        // технической переменной присваивается значение 1 (то есть светодиод включался)
 delay (500); } // задержка для ограничения частоты считывания
if (val >svet - 50 && i==1) // если значение освещенности больше svet-50 и светодиод включался (то есть было темно), то:
     {
  digitalWrite(led, LOW);  // выключается светодиод
            tone(buzer, 440, 300);delay(300); // проигрывается мелодия "в траве сидел кузнечик"
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
            tone(buzer, 440, 300);delay(300);
  i=0;}     // техничкой переменной присваивается 0, означающий, что мелодия играла
delay (100); // задержка
}


