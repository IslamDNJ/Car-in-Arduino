// Урок 29 Танец робота
#define M11 5
#define M12 6
#define M21 9
#define M22 10
#define buzer 12


void setup(){
pinMode(M11, OUTPUT);
pinMode(M12, OUTPUT);
pinMode(M21, OUTPUT);
pinMode(M22, OUTPUT);
pinMode(buzer, OUTPUT);
}

void loop (){
 goPered(255);
  tone(buzer, 440, 300);delay(300); // проигрывается мелодия "в траве сидел кузнечик"
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
goStop();            
            delay(600);
goNazad(255);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 330, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
goStop();            
            delay(600);
goLevo(255);            
           tone(buzer, 440, 300);delay(300);
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 494, 100);delay(100);
            tone(buzer, 494, 100);delay(100);
            tone(buzer, 494, 300);delay(300);
goStop();            
            delay(100);
goPravo(255); 
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 523, 100);delay(100);
            tone(buzer, 523, 100);delay(100);
            tone(buzer, 523, 300);delay(300);
goStop();            
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 523, 300);delay(300);
            tone(buzer, 494, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
            tone(buzer, 415, 300);delay(300);
            tone(buzer, 440, 300);delay(300);
delay (1500);
}

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
