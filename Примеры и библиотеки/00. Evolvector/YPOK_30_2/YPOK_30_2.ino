//Урок 30. Технология передачи инфракрасных сигналов.

#define M11 5
#define M12 6
#define M21 9
#define M22 10
#include "IRremote.h"
IRrecv irrecv(11); // Указываем пин, к которому подключен приемник
decode_results results;
int res;
float time; 
void setup()
{Serial.begin(9600); 
pinMode(M11, OUTPUT);
pinMode(M12, OUTPUT);
pinMode(M21, OUTPUT);
pinMode(M22, OUTPUT);
irrecv.enableIRIn(); // Запускаем прием
}
 
void loop() {
 if (irrecv.decode(&results)) // Если данные пришли 
  {
  res=results.value;
  time = millis();
   switch (res) {
        
     case 0x629D:// Если нажата кнопка 
      goPered(255);
     break;
     
     case 0xFFFFA857:// Если нажата кнопка 
      goNazad(255);
     break;
     
     case 0x22DD:// Если нажата кнопка 
      goLevo(255);
     break;
     
     case 0xFFFFC23D:// Если нажата кнопка 
      goPravo(255);
     break;
    }
  
     irrecv.resume(); // Принимаем следующую команду
}
else { 
if (millis()-time > 200){
goStop();
}}}

int goPered(int Skorost){analogWrite(M12,LOW);
    analogWrite(M21,LOW);
    analogWrite(M11,Skorost);
    analogWrite(M22,Skorost);}
int goNazad(int Skorost){analogWrite(M11,LOW);
    analogWrite(M22,LOW); 
      analogWrite(M12,Skorost);
    analogWrite(M21,Skorost);}
int goLevo(int Skorost){analogWrite(M12,LOW);
   analogWrite(M22,LOW); 
    analogWrite(M11,Skorost);
    analogWrite(M21,Skorost);}
int goPravo(int Skorost){digitalWrite(M11,LOW);
    analogWrite(M21,LOW); 
    analogWrite(M12,Skorost);
   analogWrite(M22,Skorost);}
void goStop(){digitalWrite(M12,LOW);
    digitalWrite(M21,LOW);
    digitalWrite(M11,LOW);
    digitalWrite(M22,LOW);}
