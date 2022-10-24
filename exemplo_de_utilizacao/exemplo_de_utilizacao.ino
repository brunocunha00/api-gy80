#include <Wire.h>
#include <HMC883L.h>
#include <L3G4200D.h>
#include <BMP085.h>
#include <ADXL345.h>

ADXL345 accel = ADXL345();
HMC883L comp = HMC883L();
L3G4200D accel = L3G4200D();
BMP085 bmp085 = BM085();

void setup(){
  Serial.begin(9600);
  accel.begin();
  comp.setDeclinationAngle(-0.3335);
  comp.begin();
}

void loop(){
    giro.update();
    accel.update();
    Serial.println("********");
    Serial.print("Giro X:");
    Serial.print(giro.getX());
    Serial.print("; Y:");
    Serial.print(giro.getY());
    Serial.print("; Z:");
    Serial.println(giro.getZ());
    Serial.print("Acelerometro X:");
    Serial.print(accel.getX());
    Serial.print("; Y:");
    Serial.print(accel.getY());
    Serial.print("; Z:");
    Serial.println(accel.getZ());
    Serial.print("Rotação:");
    Serial.println(comp.getDegrees());
    Serial.print("Temperatura:");
    Serial.println(bmp085.getTemperature());
    Serial.print("Pressão:");
    Serial.println(bmp085.getPressure());
    delay(200);
}
