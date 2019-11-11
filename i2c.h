#ifndef I2C_H__

#define I2C_H__

int raspi_i2c_set();
int raspi_i2c_write(int fd, unsigned char address, unsigned char *data, unsigned char length);
int raspi_i2c_read(int fd, unsigned char address, unsigned char *data)

#endif

    