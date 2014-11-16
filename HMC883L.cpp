#include "HMC883L.h"

HMC883L::HMC883L(){
	i2c.setDeviceAddress(HMC883L_ADDRESS);
	
}

void HMC883L::begin(){
	m_Scale = 0.73;
	setMeasurementMode(MEASUREMENT_CONTINUOUS); // Default: Measurement Continuous
	setScale(1.3); // Default: 1.3
}

void HMC883L::update(){
	short int* buffer = i2c.readNRegisters(ADDRESS_AXIS, NUMBER_REGISTERS);
  	x = ( (buffer[0] << 8) | buffer[1]) * m_Scale;
  	y = ( (buffer[2] << 8) | buffer[3]) * m_Scale;
  	z = ( (buffer[4] << 8) | buffer[5]) * m_Scale;
}

void HMC883L::setMeasurementMode(char mode){
	i2c.writeRegister(MODE_REGISTER, mode);
}

void HMC883L::setScale(float gauss){
	
	char regValue = 0x00;
	if(gauss == 0.88)
	{
		regValue = 0x00;
		m_Scale = 0.73;
	}
	else if(gauss == 1.3)
	{
		regValue = 0x01;
		m_Scale = 0.92;
	}
	else if(gauss == 1.9)
	{
		regValue = 0x02;
		m_Scale = 1.22;
	}
	else if(gauss == 2.5)
	{
		regValue = 0x03;
		m_Scale = 1.52;
	}
	else if(gauss == 4.0)
	{
		regValue = 0x04;
		m_Scale = 2.27;
	}
	else if(gauss == 4.7)
	{
		regValue = 0x05;
		m_Scale = 2.56;
	}
	else if(gauss == 5.6)
	{
		regValue = 0x06;
		m_Scale = 3.03;
	}
	else if(gauss == 8.1)
	{
		regValue = 0x07;
		m_Scale = 4.35;
	}
	regValue = regValue << 5;
	i2c.writeRegister(CONFIGURATION_REGISTERB, regValue);
}

float HMC883L::getDegrees(){
	update();
	float heading = atan2(y, x);
  	heading += declinationAngle;
	if(heading < 0) heading += 2*PI;
  	if(heading > 2*PI) heading -= 2*PI;

  	return heading * 57.2957795; //radians to degrees
}

void HMC883L::setDeclinationAngle(float declination){
	declinationAngle = declination;
}
float HMC883L::getDeclinationAngle(){
	return declinationAngle;
}
