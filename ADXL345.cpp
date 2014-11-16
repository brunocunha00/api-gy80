#include "ADXL345.h"



ADXL345::ADXL345(){
	i2c.setDeviceAddress(ADXL345_ADDRESS);
}

void ADXL345::begin(){
	// Data Format:
	// 00 - 2g
	// 01 - 4g
	// 10 - 8g
	// 11 - 16 g
	i2c.writeRegister(DATA_FORMAT, 0x11);
	i2c.writeRegister(POWER_CTL, 0x08);	
}

short int ADXL345::getX(){
	return x;
}
short int ADXL345::getY(){
	return y;
}
short int ADXL345::getZ(){
	return z;
}
void ADXL345::update(){
	short int* buffer = i2c.readNRegisters(REGISTER_DATAX0, NUMBER_REGISTERS);
	x = (short int)((buffer[1]) << 8) | buffer[0];
	y = (short int)((buffer[3]) << 8) | buffer[2];
	z = (short int)((buffer[5]) << 8) | buffer[4];
}



