#include <Time.h> 
#include <Adafruit_NeoPixel.h>


#define PIN 6
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);
boolean alreadyOff = false;
int maxBrightness = 200;
int minBrightness = 40;
int eveningBrightness = maxBrightness;

void setup() {
  // setTime(hr, min, sec, day, month, yr); 
  setTime(20, 23, 40, 29, 10, 2014);
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

void loop() {
  if(morning_pilltime()){
    //    Serial.println(" morning time "); 
    //    digitalTime();
    strip.setBrightness(40);
    pill_trails(weekday());
    alreadyOff = false;
    eveningBrightness = maxBrightness;
  } else if (evening_time()) {
    //    Serial.println(" evening time "); 
    //    digitalTime();
    eveningBrightness = (eveningBrightness > minBrightness) ? eveningBrightness-- : minBrightness;
    strip.setBrightness(eveningBrightness);
    evening_art(hour());
    alreadyOff = false;    
  } else {
    //    Serial.print(" off state? "); 
    //    Serial.println(alreadyOff); 
    //    digitalTime();
    if(!alreadyOff){
      off(); 
      //      Serial.println(" waiting after turning off "); 
      delay(14400000UL);    // wait 4 hours
      alreadyOff = true;
    }
    delay(600000UL);    // wait 10 minutes
  }
  delay(500);            // wait for a half second
}



  
