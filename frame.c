#include <stdio.h>

#include "i2c.h"
#include "frame.h"

#define MAP_ROW 12
#define MAP_COL 16

extern char g_arr[MAP_COL][MAP_ROW];
extern char g_arr_new[MAP_COL][MAP_ROW];

void frame_change(int fd, unsigned char address)
{
        unsigned char arr_def[144] = {0,};
        int i,j;
        int arr_def_len;

        for( i = 0;i < MAP_COL;i++ ){
                for(j = 0;j < MAP_ROW;j++ ){
                        if( g_arr[i][j] != g_arr_new[i][j] ){
                                g_arr[i][j] = g_arr_new[i][j]; 
                                arr_def[arr_def_len++] = (i << 4) | j;
                        }
                }
        }
        raspi_i2c_write(fd, address, arr_def, arr_def_len);
        for( i = 0;i < arr_def_len;i = 0)
                arr_def[i] = 0;
}