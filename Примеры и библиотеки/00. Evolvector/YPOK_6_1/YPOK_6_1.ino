// Урок 6 схема 1 (Светофор)
int red = 12, yellow = 11, green = 10; // Инициализируются переменные, которым присваиваются номера контактов контроллера 
void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);  // контакты контроллера настраиваются как ВЫХОД   
              }
              
void loop() {                // начинается выполнение алгоритма
  digitalWrite(green, HIGH);  // включается зеленый диод 
  delay(10000);               // который держится включённым 10 секунд
 
  digitalWrite(green, LOW);  // моргание светодиодом 3 раза
  delay(500);
  digitalWrite(green, HIGH);
  delay (500);
  digitalWrite(green, LOW);
  delay (500);
  digitalWrite(green, HIGH);
  delay (500);
  digitalWrite(green, LOW);
  delay (500);
  digitalWrite(green, HIGH);
  delay (500);
  digitalWrite(green, LOW);
  delay (500);
  
  digitalWrite(green, HIGH); // включается одновремено зеленый и желтый сигналы на 1 секунду
  digitalWrite(yellow, HIGH);
  delay (1000);
  
  digitalWrite(green, LOW); // выключается желтый и зеленый, после чего включается красный на 10 секунд
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay (10000);
  
  digitalWrite(yellow, HIGH); // включается желтый на 1 секунду
  delay(1000);
  digitalWrite(yellow, LOW); // выключаются все сигналы
  digitalWrite(red, LOW);
}
