#include <unistd.h>			
#include <fcntl.h>		        
#include <sys/ioctl.h>			
#include <linux/i2c-dev.h>		

#include "i2c.h"

unsigned char CalcChecksum(unsigned char *data, int leng)
{
        unsigned char csum;

        csum = 0xFF;
        for (;leng > 0;leng--)
                csum += *data++;
        return ~csum;
}

int i2c_write(int fd, unsigned char *data, int length)
{
        int arg;
        
        if (arg = write(fd, data, length) != length)		
		printf("Failed to write to the i2c bus.\n");

        return arg;
}

int i2c_read(int fd, unsigned char *data, int length)
{
        int arg;

        if (read(fd, data, length) != length)
		printf("Failed to read from the i2c bus.\n");
        
        return arg;
}   

int raspi_i2c_set()
{
        int fd_i2c;
        char *filename = (char*)"/dev/i2c-1";

	if ((fd_i2c = open(filename, O_RDWR)) < 0)
		printf("Failed to open the i2c bus");

        if (ioctl(fd_i2c, I2C_SLAVE, I2C_SLAVE_ADDRESS) < 0)
		printf("Failed to acquire bus access and/or talk to slave.\n");
        
        return fd_i2c;
}

int raspi_i2c_write(int fd, unsigned char *data, unsigned char length)
{
        unsigned char buffer[length + 4];

        buffer[0] = 0xFF;
        buffer[1] = length;
        for( int i = 0;i < length;i++ ){
                buffer[i+2] = data[i];
        }
        buffer[length + 2] = CalcChecksum(data, length);
        buffer[length + 3] = 0xFE;
        //i2c write
        i2c_write(fd, buffer, length+4);

        return length;
}

int raspi_i2c_read(int fd, unsigned char *data)
{
        unsigned char buffer[254] = {0,};
        int length;
        int i;

        i2c_read(fd, buffer, 2);
        length = buffer[1];
        i2c_read(fd, buffer+2, length +2);
        for(i = 0;i < length;i++){
                data[i] = buffer[i+2];
        }
        if( data[length + 2] != CalcChecksum(data, length)){                                                                                                                                                                                 //CHECKSUM
                printf("CHECKSUM ERROR\n");
                for(i = 0;i < (length + 4); i++){
                        printf("%x ", data[i]);
                }
                printf("\n");
        }

        return length;
}
