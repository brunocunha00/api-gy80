#include "BMP085.h"

/* Construtor da classe BMP085*/
BMP085::BMP085(){
	i2c.setDeviceAddress(BMP085_ADDRESS);
	calibration();
}

short int BMP085::read2Registers(char address){
	short int* tmp = i2c.readNRegisters(address, 2);
	return (short int) ((tmp[0] << 8) | tmp[1]);
}

void BMP085::calibration(){

	ac1 = read2Registers(AC1_ADDRESS);
	ac2 = read2Registers(AC2_ADDRESS);
	ac3 = read2Registers(AC3_ADDRESS);
	ac4 = read2Registers(AC4_ADDRESS);
	ac5 = read2Registers(AC5_ADDRESS);
	ac6 = read2Registers(AC6_ADDRESS);
	b1 = read2Registers(B1_ADDRESS);
	b2 = read2Registers(B2_ADDRESS);
	mb = read2Registers(MB_ADDRESS);
	mc = read2Registers(MC_ADDRESS);
	md = read2Registers(MD_ADDRESS);

}

long int BMP085::getUT(){

	i2c.writeRegister(0xF4, 0x2E);
	delay(5);
	short int* tmp = i2c.readNRegisters(0xF6, 2);
	return (long int) ((tmp[0] << 8) + tmp[1]);

}

long int BMP085::getUP(){

	i2c.writeRegister(0xF4, (0x34 + (oss << 6)));
	delay(5);
	short int* tmp = i2c.readNRegisters(0xF6, 3);
	return (long int) (((tmp[0] << 16)+(tmp[1] << 8)+ tmp[2]) >> (8 - oss));

}

float BMP085::getTemperature(){
	long x1, x2;
	x1 = ((getUT() - ac6) * ac5) / pow(2,15);
	x2 = (mc * pow(2, 11)) / (x1 + md);
	b5 = x1 + x2;
	return (float) ((b5 + 8) / pow(2, 4));
}

float BMP085::getPressure(){
	long int x1, x2, x3, b3, b6, p;
	unsigned long int b4, b7;
	b6 = b5 - 4000;
	
	x1 = (b2 * ((b6* b6) / pow(2,12))) / pow(2,11);
	x2 = (ac2 * b6) / pow(2,11);
	x3 = x1 + x2;
	b3 = (((ac1 * 4) + x3) << oss + 2) / 4;
	
	x1 = (ac3 * b6) / pow(2,13);
	x2 = (b1 * ((b6* b6) / pow(2,12))) / pow(2,16);
	x3 = ((x1 + x2) + 2) / pow(2,2);
	b4 = (ac4 * (unsigned long int)(x3 + 32768)) / pow(2,15);
	
	b7 = ((unsigned long int)getUP() - b3) * (50000 >> oss);
	if(b7 < 0x80000000){
		p = (b7 * 2) / b4;
	}else{
		p = (b7 / b4) * 2;
	}
	
	x1 = (p / pow(2,8)) * (p / pow(2,8));
	x1 = (x1 * 3038) / pow(2,16);
	x2 = (-7357 * p) / pow(2,16);
	p = p + (x1 + x2 + 3791) / pow(2, 4);
	return p;
}
