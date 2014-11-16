#include "I2C.h"

#ifndef L3G4200D_H
#define L3G4200D_H

#define L3G4200D_ADDRESS 0x69
#define NUMBERS_REGISTERS 6
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x25
#define ADDRESS_AXIS 0x28

class L3G4200D
{
	public:
		L3G4200D();
		void begin();
		void setScale(short int scale);
		short int getX();
		short int getY();
		short int getZ();
		void update();
	private:
		short int x, y, z;
		I2C i2c;
};

#endif
