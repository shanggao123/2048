#ifndef __2048_H__
#define __2048_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "draw.h"
#include "jpeglib.h"
#include "sq_stack.h"


typedef unsigned int u_int; // 无符号整型
typedef unsigned short u_short; // 无符号短整型


u_short *screen_base;
u_int lcd_x;
u_int lcd_y;
u_int lcd_size;
u_int bpp;

typedef struct{
    u_int x0; // 
    u_int y0;
    u_int x;
    u_int y;
}boxes;

// 记录数值
unsigned int img_arr[4][4]; 
// 图片的路径
static char *img_path[] = {"./img/2.jpg","./img/4.jpg","./img/8.jpg","./img/16.jpg",
                           "./img/32.jpg","./img/64.jpg","./img/128.jpg","./img/256.jpg",
                           "./img/512.jpg","./img/1024.jpg","./img/2048.jpg","./img/bg.jpg"};

int test_arr[10]; // 存储选取2或者4的数组
int a[4][4];    // 操作图片的数组
int a1[4][4];   // 清零工具数组
int b[16];  // 记录a数组是否已满

#endif