// Урок 4 схема 3
// Плавный перелив цветов RGB светодиода
//создаются переменные red, green, blue, которым присвоиваются соответствующие номера выводов.*/ 
int RedPin = 9; //красный на 9 
int GreenPin = 10; // зеленый на 10
int BluePin = 11; // синий на 11
//необходимо задать переменные текущих значений яркости каждого цветов, и присвоить им произвольные (случайные) значения 
int ValRed = random(0, 255); // функция random генерирует произвольное значение из указанного интервала (от 0 до 255)
int ValGreen = random(0, 255);
int ValBlue = random(0, 255);

void setup() {                
  pinMode(RedPin, OUTPUT); // для выводов контроллера задается режим: ВЫХОД
  pinMode(GreenPin, OUTPUT); 
  pinMode(BluePin, OUTPUT); 
  
  analogWrite(RedPin, ValRed);   // светодиод включается с ранее присвоенными параметрами 
  analogWrite(GreenPin, ValGreen);
  analogWrite(BluePin, ValBlue);
}

void loop() {
    
  int NewValRed = random(10, 255); //Создание дополнительных переменных, которым также присваиваются случайные числа
  int NewValGreen = random(10, 255);
  int NewValBlue = random(10, 255);
  
  //запускается цикл, который выполняется пока значения новых переменных не сравняются с текущими
  while ((ValRed != NewValRed)&(ValGreen != NewValGreen)&(ValBlue != NewValBlue)) {   
//для красного канала      
      if (ValRed < NewValRed){  //если новое больше текущего
        analogWrite(RedPin, ValRed++ ); //то текущий увеличивается
      };
      if (ValRed > NewValRed) { // если меньше - уменьшается
        analogWrite(RedPin, ValRed-- );
      };
 //для зелёного канала    
     if (ValGreen < NewValGreen){
        analogWrite(GreenPin, ValGreen++ );
      };
     if (ValGreen > NewValGreen) {
        analogWrite(GreenPin, ValGreen-- );
      };  
//для синего канала  
     if (ValBlue < NewValBlue){
        analogWrite(BluePin, ValBlue++ );
      };
     if (ValBlue > NewValBlue) {
        analogWrite(BluePin, ValBlue-- );
      }; 
   delay(10); //Задержка для того, чтобы изменения цветов были заметны 
  }    
}
