/* Урок 4 схема 2
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
// светодиоды включаются с максимальной яркостью на 2 секунды.
digitalWrite(red, HIGH);
digitalWrite(green, HIGH);
digitalWrite(blue, HIGH);
delay(2000);
// выключаются светодиоды
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
delay(500);
//светодиоды разных цветов включаются поочередно   
digitalWrite(red, HIGH);  // включен красный
delay(1000); 
digitalWrite(red, LOW);
delay(500);
digitalWrite(green, HIGH);  //включен зелёный
delay(1000);               
digitalWrite(green, LOW);
delay(500);               
digitalWrite(blue, HIGH); // включен синий
delay(500);               
digitalWrite(blue, LOW);
delay(500);
// выключаются светодиоды
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);

// создание различных оттенков цветов.
analogWrite(red, 235);  // белый
analogWrite(green, 100);
analogWrite(blue, 255);
delay(1000);
analogWrite(red, 255);  // фиолетовый
analogWrite(green, 0);
analogWrite(blue, 255);
delay(1000);
analogWrite(red, 255);  // жёлтый
analogWrite(green, 140);
analogWrite(blue, 0);
delay(1000);
// выключаются светодиоды.
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
}
