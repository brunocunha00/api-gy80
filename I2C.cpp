#include "I2C.h"

// Construtor que recebe como parametro o endereço do dispositivo
I2C::I2C(){
	Wire.begin();
}

void I2C::setDeviceAddress(char address){
	deviceAddress = address;
}

char I2C::getDeviceAddress(){
	return deviceAddress;
}

void I2C::writeRegister(char address, char val){
	Wire.beginTransmission(getDeviceAddress()); 
	Wire.write(address);             
	Wire.write(val);                 
	Wire.endTransmission();         
}

short int* I2C::readNRegisters(char address, short int numBytes){
	
	short int buffer[numBytes];
	Wire.beginTransmission(getDeviceAddress());
	Wire.write(address);
	Wire.endTransmission();
	Wire.requestFrom(getDeviceAddress(), numBytes);
	short int i = 0;
	while(Wire.available())
	{ 
		buffer[i] = Wire.read();
		i++;
	}
	Wire.endTransmission();
	
	return buffer;
}
