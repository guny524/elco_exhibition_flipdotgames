#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "i2c.h"

/*
 * int wiringPiI2CSetup (int devId)
 * int wiringPiI2CWriteReg8 (int fd, int reg, int data)
 * int wiringPiI2CReadReg8 (int fd, int reg)
 */

int fd;
unsigned char address;

#if ISWINDOW
int raspi_i2c_set(unsigned char add)
{

}
int raspi_i2c_write(unsigned char *data, unsigned char length)
{
}
int raspi_i2c_read(unsigned char *data)
{
}

#else
unsigned char CalcChecksum(unsigned char *data, int leng)
{
        unsigned char csum;

        csum = 0xFF;
        for (;leng > 0;leng--)
                csum += *data++;
        return ~csum;
}

int raspi_i2c_set(unsigned char add)
{
		address = add;
        if( fd = wiringPiI2CSetup(address) == -1 ){
                printf("Unable to initialise I2C ERROR: %s\n", strerror(errno));
        }
        return fd;
}

int raspi_i2c_write(unsigned char *data, unsigned char length)
{
        wiringPiI2CWriteReg8(fd, address, 0xFF);//START BYTE
        wiringPiI2CWriteReg8(fd, address, length + 1);
        for( int i = 0;i < length;i++ ){
                wiringPiI2CWriteReg8(fd, address, data[i]);
        }
        wiringPiI2CWriteReg8(fd, address, 0xFE);//STOP BYTE
        wiringPiI2CWriteReg8(fd, address, CalcChecksum(data, length));//CHECKSUM
        return length;
}

int raspi_i2c_read(unsigned char *data)
{
        unsigned char length;
        if(wiringPiI2CReadReg8(fd, address) == 0xFF){//START BYTE
                printf("START BYTE ERROR\n");
                return -1;
        }
        length = wiringPiI2CReadReg8(fd, address);
        for( int i = 0;i < length;i++ ){
                data[i] = wiringPiI2CReadReg8(fd, address);
        }
        if(wiringPiI2CReadReg8(fd, address) == 0xFE){//STOP BYTE
                printf("STOP BYTE ERROR\n");
                return -1;
        }
        if( data[length - 1] != CalcChecksum(data, length)){//CHECKSUM
                printf("CHECKSUM ERROR\n");
                return -1;
        }
        return length;
}
#endif