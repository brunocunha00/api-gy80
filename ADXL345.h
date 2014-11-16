#include "I2C.h"

#ifndef ADXL345_H
#define ADXL345_H

#define ADXL345_ADDRESS (0x53)
#define NUMBER_REGISTERS 6  // Número de registros a serem lidos
#define DATA_FORMAT 0x31
#define POWER_CTL 0x2D
#define REGISTER_DATAX0 0x32
#define REGISTER_DATAX1 0x33
#define REGISTER_DATAY0 0x34
#define REGISTER_DATAY1 0x35
#define REGISTER_DATAZ0 0x36
#define REGISTER_DATAZ1 0x37

class ADXL345
{
	public:
		ADXL345();
		void begin();
		short int getX();
		short int getY();
		short int getZ();
		void update();
		
		
	private:
		short int x, y, z;
		I2C i2c;
		
};

#endif
