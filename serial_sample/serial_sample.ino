void setup() {
  Serial.begin(9600);
}
  
void loop() {
  static int oldtime = 0;
  if((millis() - oldtime) > 1000){
    Serial.println("Hello World");
    oldtime = millis();
  }
   
  if(Serial.available()){
    if(Serial.read() == 'a'){
      Serial.println("Hi, I'm CITRUS!");
    }
  }
}
