
// Урок 5 схема 1
//создаются переменные, которым присваиваются номера контактов контроллера
int LED = 3;
int BUTTON = 2;
int val = 0;  // переменная состояния нажатия кнопки
void setup() {
 pinMode(LED, OUTPUT); // для пина, к которому подключен светодиод устанавливается режим: ВЫХОД
 pinMode(BUTTON, INPUT); // для пина, к которому подключена кнопка, устанавливается режим: ВХОД (считывание)
}
void loop(){
 val = digitalRead(BUTTON); // считывается значение с кнопки и присваивается переменной val. если нажата, то HIGH, если нет, то LOW. 
 if (val == HIGH)   // если нажата, то 
    {
 digitalWrite(LED, HIGH);    // включается светодиод
    } else {             // иначе, если не нажата
 digitalWrite(LED, LOW);   // то выключается светодиод
           }
}


