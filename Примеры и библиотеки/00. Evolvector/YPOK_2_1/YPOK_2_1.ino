
// Урок 2 схема 1
// задаётся переменная led, которой присваивается число 3
int led = 3;
void setup()
{
// вывод led определяется как ВЫХОД  
  pinMode(led, OUTPUT);     
}
void loop()
{
// Включается светодиод
  digitalWrite(led, HIGH);   
// пауза на 1 секунду  
  delay(1000);              
// Выключается светодиод
  digitalWrite(led, LOW);    
// снова пауза на 1 секунду
  delay(1000);             
}
