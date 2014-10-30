

boolean morning_pilltime(){
//  if(hour() == 6){
//   if(minute() >= 10 && minute() <= 45){
//     return true;
//   } 
//  }
  if(hour() == 6){
    if(minute() >= 40 && minute() < 60){
      return true;
    } 
  }
  if(hour() == 7){
    if(minute() >= 0 && minute() < 35){
      return true;
    } 
  }
  return false;
}


boolean evening_time(){
  if(hour() >= 19 && hour() < 23){
    return true;
  }
  if(hour() == 18 && minute() > 15){
    return true;
  }
  return false;
}

int special_days(int originalDay){
  // birthday
  if(day() == 9 && month() == 11){
   return 119;
  }
  // halloween time
  if(day() > 28 && day() <=31  && month() == 10){
   return 31;
  }  
  // christmas time
  if(day() > 10 && day() < 26 && month() == 12){
   return 25;
  }
  return originalDay;
}

void digitalTime(){
  // digital clock display of the time
  Serial.println(); 
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());  
  Serial.println("-----"); 
}

void addMinutesToClock(int minutes){
  adjustTime(minutes * 60);
}

