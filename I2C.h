#include <Wire.h>

#ifndef I2C_H
#define I2C_H

class I2C
{
	public:
		I2C();
		void writeRegister(char address, char val);
		short int* readNRegisters(char address, short int numBytes);
		char getDeviceAddress();
		void setDeviceAddress(char address);
		
	private:
		char deviceAddress;
		
};

#endif
