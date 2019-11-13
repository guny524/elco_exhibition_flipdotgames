#ifndef I2C_H__

#define I2C_H__

#include"osname.h"

int raspi_i2c_set();
int raspi_i2c_write(int fd, unsigned char address, unsigned char *data, unsigned char length);
int raspi_i2c_read(int fd, unsigned char address, unsigned char *data);
unsigned char CalcChecksum(unsigned char *data, int leng);

#if ISNWINDOW
#include <WiringPi.h>
#include <wiringPiI2C.h>
#endif

#endif