
/* Урок 4 схема 1
создаются переменные red, green, blue, которым
присвоиваются соответствующие номера выводов.*/ 
int red = 9;
int green = 10;
int blue = 11;
void setup() {  
// для этих выводов задается режим работы: ВЫХОД.
pinMode(red, OUTPUT);  
pinMode(green, OUTPUT); 
pinMode(blue, OUTPUT); 
}
void loop()
{
// светодиоды включаются с максимальной яркостью на 3 секунды.
digitalWrite(red, HIGH);
digitalWrite(green, HIGH);
digitalWrite(blue, HIGH);
delay(3000);
// выключаются светодиоды
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
delay(1000);
//светодиоды разных цветов включаются поочередно  
digitalWrite(red, HIGH);  // включен красный
delay(1000);              // задержка на 1 секунду
digitalWrite(red, LOW);
delay(500);               // задержка на 0,5 секунды
digitalWrite(green, HIGH);  // включен зелёный
delay(1000);              // задержка на 1 секунду 
digitalWrite(green, LOW);
delay(500);               // задержка на 0,5 секунды
digitalWrite(blue, HIGH); // включен синий
delay(500);               // задержка на 0,5 секунды
digitalWrite(blue, LOW);
delay(500);             // задержка на 0,5 секунды
// выключаются светодиоды
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
}




