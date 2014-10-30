#include <Time.h> 

int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  setTime(16, 43, 0, 28, 9, 2014);
  //setTime(6, 25, 0, 28, 9, 2014);
}

void loop() {
  delay(1000);               // wait for a second
  if(pilltime()){
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)    
  } else {
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW 
  }
}

boolean pilltime(){
  if(hour() == 6){
   if(minute() >= 20 && minute() <= 35){
     return true;
   } 
  }
  return false;
}
