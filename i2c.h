#ifndef I2C_H__

#define I2C_H__

#include "osname.h"

#define I2C_SLAVE_ADDRESS 0x68

void raspi_i2c_set();
int raspi_i2c_write(unsigned char *data, unsigned char length);
int raspi_i2c_read(unsigned char *data);

#endif