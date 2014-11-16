#include "I2C.h"
#include <cmath>
#include <Arduino.h>

#ifndef BMP085_H
#define BMP085_H

#define BMP085_ADDRESS 0x77
#define AC1_ADDRESS 0xAA
#define AC2_ADDRESS 0XAC
#define AC3_ADDRESS 0XAE
#define AC4_ADDRESS 0XB0
#define AC5_ADDRESS 0XB2
#define AC6_ADDRESS 0XB4
#define B1_ADDRESS 0XB6
#define B2_ADDRESS 0XB8
#define MB_ADDRESS 0XBA
#define MC_ADDRESS 0XBC
#define MD_ADDRESS 0XBE


class BMP085
{
	public:
		BMP085();
		
		float getTemperature();
		float getPressure();
		

	private:
		I2C i2c;
		short int ac1, ac2, ac3, b1, b2, mb, mc, md, oss;
		unsigned short int ac4, ac5, ac6;
		long int b5;
		void calibration();
		long int getUT();
		long int getUP();
		short int read2Registers(char address);
};

#endif
