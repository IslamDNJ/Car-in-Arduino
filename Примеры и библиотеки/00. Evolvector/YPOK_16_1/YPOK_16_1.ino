// Урок 16 схема 1 (Светофор)
#define red 13   // Назначаются имена констант
#define yellow 12
#define green 11 
#define tma 100
#define foto A0
#define BUTTON 6 
int bazvrem = 10;
int val, svet, del;

void setup() {
  pinMode(red, OUTPUT);   // назначаются режимы работы выводов
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);    
  pinMode(BUTTON, INPUT);
 digitalWrite(green, HIGH); }//при запуске программы, включается зеленый светодиод
 
void loop() {
svet = analogRead(foto); //считывается значение освещенности
val = digitalRead(BUTTON); // считывается состояние кнопки     
  if (val == HIGH) {         // если кнопка нажата, то:
  del = pauza (svet, bazvrem); // переменной del присваивается результат выполнения функции pauza
  delay (del*1000); //выполняется задержка перед запуском цикла светофора      
  digitalWrite(green, LOW); //выключается зеленый свет
  morganie(green,0.5,3);   //выполняется вызов функции morganie
  vkl2(green,yellow,1); // запускается функция vkl2 с аргументами green,yellow,1
  vkl(red,10); // вызывается функция vkl
  vkl2(red,yellow,1); //снова выполняется функция vkl2, но уже с аргументами red,yellow,1
  digitalWrite(green, HIGH);}} //включается зеленый свет      
  
 void vkl(int colour, int time) // инициализация функции vkl
   {digitalWrite(colour, HIGH);  //включается вывод с именем colour
   delay(time*1000);       // задержка
   digitalWrite(colour, LOW);} // выключается вывод colour

void vkl2(int colour1, int colour2, int time) // инициализация функции vkl2
{ digitalWrite(colour1, HIGH);  //включается вывод colour1
 digitalWrite(colour2, HIGH); //включается вывод colour2
 delay(time*1000);           // задержка
 digitalWrite(colour1, LOW);// выключается вывод colour1
 digitalWrite(colour2, LOW);}// выключается вывод colour2
      
void morganie(int colour, float time, int raz)// определение функции morganie
      { for (int i=0; i <= raz; i++){   //запуск цикла
      digitalWrite(colour, HIGH);  //включается вывод colour
      delay(time*1000);            // задержка
      digitalWrite(colour, LOW); //выключается вывод colour
      delay(time*1000); }}         // задержка

float pauza (int svet, int bazvrem) // инициализация функции  pauza
{ float vrem;
if  (svet<100){ vrem =  bazvrem/5 ;} // если уровень освещенности меньше 100, задержка перед светофорным циклом уменьшается в 5 раз
else {vrem = bazvrem;} // иначе действует базовая задержка времени
return vrem; } // Возвращаем в программу значение переменной vrem
