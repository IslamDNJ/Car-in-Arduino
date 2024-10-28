//Урок 21 (Музыка света)
#define buzer 11
#define button 10
unsigned int LedHerz[7] = {1,2,3,4,5,6,7};
unsigned int Led[7] = {2,3,4,5,6,7,8};//пины к которым подключены светодиод
unsigned int BuzerTone[7]= {523,587,659,698,784,880,988}; //частота нот второй октавы от "до" до "си"
int i,j=0,raz, val, vrem = 2;
float time;
boolean state=0;

void setup(){
  pinMode (buzer, OUTPUT);
  pinMode (button, INPUT);
  for (i = 0; i < 7; ++i)
    {pinMode(Led[i], OUTPUT);}
}
void morganie(int Pin, int Herz, int vrem){// функция morganie (задаем номер пина, частоту моргания и время моргания)
raz = Herz*vrem; // рассчитываем количество морганий
for (int i=0; i < raz; i++){   //запуск цикла
    digitalWrite(Pin, HIGH);  //включаеся вывод Pin
    delay(1000/(Herz*2));     // задержка на половину частоты моргания
    digitalWrite(Pin, LOW); //включается вывод Pin
    delay(1000/(Herz*2)); }}  // задержка на половину частоты моргания

void loop(){
val = digitalRead (button);
if (val == HIGH){
    state=0; //переменная для разделения цилов при длительном нажатии и кратковременном
    time= millis();   // засекаем время 
    while(val == HIGH){   //до тех пор, пока кнопка 1 нажата            
        val = digitalRead(button);   // считываем состояние кнопки
        if (millis() - time > 3000){
            val = LOW;  
            for (i=0; i<7; i++){
                tone (buzer, BuzerTone[i]);
                morganie(Led[i],LedHerz[i],vrem);
                noTone(buzer);
                state=1;}}}
                
    if (state == 0){
    tone (buzer, BuzerTone[j]);
    morganie(Led[j],LedHerz[j],vrem);
    noTone(buzer);
    j=j+1; // увеличение переменной для ноты при однократном нажатии
    if (j>6){j=0;} //если j больше 6, то сбрасываем ее на 0. Больше 6 так как отсчет идет с нуля. Итого 7 значений.
  }}}
  
