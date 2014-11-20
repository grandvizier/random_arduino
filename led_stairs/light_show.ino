#include <math.h> 

void off() {
  uint32_t c = strip.Color(0, 0, 0); 
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(10);
  }
}

//****************************

void pill_trails(int d) {
  int dayOfWeek = special_days(d);
  uint32_t main = strip.Color(0, 100, 0); // Weekend is green
  uint32_t alt = strip.Color(50, 255, 50);
  switch (d) {
    case 2: // Monday
      main = strip.Color(255, 0, 0);   // Red
      alt = strip.Color(255, 50, 50);   
      break;
    case 3: // Tuesday
      main = strip.Color(0, 0, 255);   // Blue
      alt = strip.Color(100, 100, 255);   
      break;
    case 4: // Wednesday
      main = strip.Color(200, 200, 0); // Yellow
      alt = strip.Color(250, 250, 50);   
      break;
    case 5: // Thursday
      main = strip.Color(0, 200, 200); // Cyan
      alt = strip.Color(100, 255, 255);   
      break;
    case 6: // Friday
      main = strip.Color(70, 0, 150); // Purple
      alt = strip.Color(150, 50, 255);   
      addMinutesToClock(d);          // add 6 minutes to the clock
      break;
  }
  colorWipe(main, alt, 70);
}

void colorWipe(uint32_t mainColor, uint32_t altColor, uint8_t wait) {
  for(uint16_t i=strip.numPixels(); i>0; i--) {
      strip.setPixelColor(i, mainColor);
      strip.setPixelColor(i-1, altColor);
      strip.setPixelColor(i-2, altColor);
      strip.show();
      delay(wait);
  }
}


//****************************

void evening_art(int hourForWait) {
  int specialDay = special_days(1);
  if(specialDay == 31){
    halloweenFlash(hourForWait);
  } else if(specialDay == 25){
    christmasLights(hourForWait);
  } else{
    int exponetiatHour = (int)pow(hourForWait, 3);
    exponetiatHour = ((exponetiatHour > 5000) ? exponetiatHour - 4000 : exponetiatHour);
    slowRainbowCycle(exponetiatHour);
  }
}


void slowRainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void halloweenFlash(uint8_t wait) {
  uint32_t orange = strip.Color(230, 60, 0); // Orange
  uint32_t black = strip.Color(0, 0, 0); // Black
  uint16_t allPixels = strip.numPixels();
  uint16_t third = allPixels / 3;
  uint16_t start = 0;  
  uint16_t endPixel = start + third;  

  for(uint16_t j=0; j<3; j++) {
    for(uint16_t i=allPixels; i>0; i--) {
      if(i < start || i >= endPixel){
        strip.setPixelColor(i, orange);
      } else {
        strip.setPixelColor(i, black);
      }
      strip.show();
    }
    if(start >= (allPixels-1)){
      start = 0; 
    } else {
      start += third; 
    }
    endPixel = start + third;
    delay(wait*60);
  }

}



void christmasLights(uint8_t wait) {
  rainbowCycle(wait);
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

