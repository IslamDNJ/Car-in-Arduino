
// Урок 9 схема 1
#include <LiquidCrystalRus.h> // Подключение библиотеки LCD экрана
LiquidCrystalRus lcd(3, 4, 8, 9, 10, 11); // устанавливаются выводы, к которым подключен экран
int termo = A0; // задается переменная, которой будет присваиваться значение сигнала со входа А0
int val; // переменная считывания напряжения в цифровом виде
float voltage; // переменная для вычисления реального напряжения
int temp; // переменная для вычисления температуры в градусах Цельсия
void setup()
{
lcd.begin(16, 2); // Инициализируется экран как 2х строчный с 16-ю символами в каждой строке
lcd.print("Температура"); // Вывод на экран слова: Температура
lcd.setCursor(3, 1); // курсор устанавливается на 4-й символ второй строки
lcd.print("градуса(ов)"); // Вывод на экран слова: градуса(ов)
 }
void loop()
{
  val = analogRead(termo); // считывается напряжение с входа А0
  voltage = (val*5.0/1023); // присвоение переменной результатов расчета реального напряжения
  temp = voltage*100-273.15; // Присвоение переменной результатов расчета температуры в градусах Цельсия
  delay(1000); // задержка для снижения частоты считывания 
  lcd.setCursor(0, 1); //установка курсора на первый символ второй строки
  lcd.print(temp); // вывод на экран значения температуры
}

