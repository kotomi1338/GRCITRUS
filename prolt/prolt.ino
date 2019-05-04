#include <Arduino.h>
#include <stdlib.h>

int ledPin = PIN_LED0;
int Rock = 0, Scissors = 1, Paper = 2;
int Player = 5, CPU = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if(Serial.read() == 'r'){
    Player = Rock;
    Serial.print("Player = ");
    Serial.println(Player);
    CPU = rand() % 3;
    Serial.println(CPU);
    delay(100);
  }
  if(Serial.read() == 's'){
    Player = Scissors;
    Serial.print("Player = ");
    Serial.println(Player);
    CPU = rand() % 3;
    Serial.print("CPU = ");
    Serial.println(CPU);
    delay(100);
  }
  if(Serial.read() == 'p'){
    Player = Paper;
    Serial.print("Player = ");
    Serial.println(Player);
    CPU = 2;
    Serial.print("CPU = ");
    Serial.println(CPU);
    delay(100);
  }

  if((Player == 0 && CPU == 1) || (Player == 1 && CPU == 2) || (Player == 2 && CPU == 0)){
    Serial.println("Win!!!");

    for(int i = 0; i < 10; i++){
      analogWrite(ledPin, 255);
      delay(100);
      analogWrite(ledPin, 0);
      delay(100);
    }

  }
  else if((Player == 0 && CPU == 2) || (Player == 1 && CPU == 0) || (Player == 2 && CPU == 1)){
    Serial.println("Lose...");

    for(int i = 0; i < 3; i++){
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
        analogWrite(ledPin, fadeValue);         
        delay(10);                            
      } 
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
        analogWrite(ledPin, fadeValue);
       delay(10); 
      }
    }

    delay(30);
  }
  else if(Player == CPU){
    Serial.println("aikodesyo");

    for(int i = 0; i < 3; i++){
      analogWrite(ledPin, 255);
      delay(500);
      analogWrite(ledPin, 0);
      delay(100);
    }
  }
  else{
  }
  delay(1000);
}














