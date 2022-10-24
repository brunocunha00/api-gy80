#include <Wire.h>
#include "L3G4200D.h"

L3G4200D accel = L3G4200D();

void setup(){
  Serial.begin(9600);

}

void loop(){

    accel.update();
    Serial.print("X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    delay(200);

}


