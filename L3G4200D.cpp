#include "L3G4200D.h"

L3G4200D::L3G4200D(){
	i2c.setDeviceAddress(L3G4200D_ADDRESS);
}

void L3G4200D::begin(){
	i2c.writeRegister(CTRL_REG1, 0b00001111);
	i2c.writeRegister(CTRL_REG2, 0b00000000);
	i2c.writeRegister(CTRL_REG3, 0b00001000);
	setScale(250);
	i2c.writeRegister(CTRL_REG4, 0b00000000);
}

void L3G4200D::setScale(short int scale){
	
	switch(scale){
		case 250:
			i2c.writeRegister(CTRL_REG4, 0b00000000);
			break;
		case 500:
			i2c.writeRegister(CTRL_REG4, 0b00010000);
			break;
		case 2000:
			i2c.writeRegister(CTRL_REG4, 0b00110000);
			
	}
	
}

void L3G4200D::update(){
	short int* buffer;
	short int* msb = i2c.readNRegisters(0x29, 1);
	short int* lsb = i2c.readNRegisters(0x28, 1);

  	x = (msb[0] << 8) | lsb[0];
  	y = (buffer[3] << 8) | buffer[2];
  	z = (buffer[5] << 8) | buffer[4];
}

short int L3G4200D::getX(){
	return x;
}

short int L3G4200D::getY(){
	return y;
}

short int L3G4200D::getZ(){
	return z;
}
