#include "I2C.h"
#include <Arduino.h>

#ifndef HMC883L_H
#define HMC883L_H

#define HMC883L_ADDRESS 0x1E
#define NUMBER_REGISTERS 6  // Número de registros a serem lidos

#define CONFIGURATION_REGISTERB 0x01

#define MODE_REGISTER 0x02
#define MEASUREMENT_CONTINUOUS 0x00
#define MEASUREMENT_SINGLESHOT 0x01
#define MEASUREMENT_IDLE 0x03
#define ADDRESS_AXIS 0x03

class HMC883L
{
	public:
		HMC883L();
		void begin();
		
	  	
	  	float getDegrees();
	  	void setDeclinationAngle(float declination);
	  	float getDeclinationAngle();
	  	
	private:
		void setScale(float gauss);
		void setMeasurementMode(char mode);
		float x, y, z, m_Scale,  declinationAngle;
		I2C i2c;
		void update();
};

#endif
