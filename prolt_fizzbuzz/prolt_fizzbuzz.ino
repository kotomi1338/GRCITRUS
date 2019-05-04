#include <Arduino.h>

int ledPin = PIN_LED0;
int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  if(value % 15 == 0){
    Serial.println("FizzBuzz");
    
    for(int i = 0; i < 10; i++){
      analogWrite(ledPin, 255);
      delay(50);
      analogWrite(ledPin, 0);
      delay(50);
    }
    
  }else if(value % 5 == 0){
    Serial.println("Buzz");
    
    for(int i = 0; i < 5; i++){
      analogWrite(ledPin, 255);
      delay(100);
      analogWrite(ledPin, 0);
      delay(100);
    }
    
  }else if(value % 3 == 0){
    Serial.println("Fizz");
    
    for(int i = 0; i < 2; i++){
      analogWrite(ledPin, 255);
      delay(250);
      analogWrite(ledPin, 0);
      delay(250);
    }
    
  }else{
    Serial.println(value);
    delay(1000);
  }
  value++;
}
