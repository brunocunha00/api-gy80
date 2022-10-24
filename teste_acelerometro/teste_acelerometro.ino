#include <Wire.h>
#include "ADXL345.h"

ADXL345 accel = ADXL345();

void setup(){
  Serial.begin(9600);
  accel.begin();

}

void loop(){
  Serial.println("eixo x = 0 e y = 0");
  for(int i = 0; i <100; i++){
    accel.update();
    Serial.print("X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    delay(200);
  }
  delay(15000);
  Serial.println("eixo x = 90 e y = 0");
  for(int i = 0; i <100; i++){
    accel.update();
    Serial.print("X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    delay(200);
  }
    delay(15000);
  Serial.println("eixo x = -90 e y = 0");
  for(int i = 0; i <100; i++){
    accel.update();
    Serial.print("X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    delay(200);
  }
    delay(15000);
  Serial.println("eixo x = 0 e y = 90");
  for(int i = 0; i <100; i++){
    accel.update();
    Serial.print("X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    delay(200);
  }
    delay(15000);
  Serial.println("eixo x = 0 e y = -90");
  for(int i = 0; i <100; i++){
    accel.update();
    Serial.print("X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    delay(200);
  }
  delay(1000000);

}


