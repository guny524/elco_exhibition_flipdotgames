#include"osname.h"
#include "i2c.h"
#include "frame.h"

char pre_arr[MAP_COL][MAP_ROW] = { 0, };

void frame_change(char arr[MAP_COL][MAP_ROW])
{
        unsigned char arr_def[144] = {0,};
        int arr_def_len;

        for( int i = 0;i < MAP_COL;i++ ){
                for(int j = 0;j < MAP_ROW;j++ ){
                        if( pre_arr[i][j] != arr[i][j] ){
                                pre_arr[i][j] = arr[i][j];
                                arr_def[arr_def_len++] = (i << 4) | j;
                        }
                }
        }
        raspi_i2c_write(arr_def, arr_def_len);
		/*
        for( int i = 0;i < arr_def_len;i = 0){
                printf("( %d , %d )", arr_def[i] >> 4, arr_def[i] & 0x0F);
                arr_def[i] = 0;
        }
        printf("\n");
		*/
}