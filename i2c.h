#ifndef I2C_H__

#define I2C_H__

#include"osname.h"

#if ISNWINDOW
#include <wiringPi.h>
#include <wiringPiI2C.h>
#endif

int raspi_i2c_set(unsigned char add);
int raspi_i2c_write(unsigned char *data, unsigned char length);
int raspi_i2c_read(unsigned char *data);

#endif