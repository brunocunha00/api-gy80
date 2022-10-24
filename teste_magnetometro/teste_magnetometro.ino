#include <Wire.h>
#include <HMC883L.h>

HMC883L comp = HMC883L();

void setup(){
  Serial.begin(9600);
  comp.begin();
  comp.setDeclinationAngle(-0.3335);
}

void loop(){

  Serial.println(comp.getDegrees());
  delay(200);
}



