#include <Wire.h>
#include <BMP085.h>

BMP085 bmp085;

void setup(){
  Serial.begin(9600);
  bmp085.calibration();
}
void loop(){
  Serial.print("Temperatura:");
  Serial.println(bmp085.getTemperature());
  Serial.print("Pressão:");
  Serial.println(bmp085.getPressure());
  delay(1000);
}

