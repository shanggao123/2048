#ifndef __DARW_H__
#define __DARW_H__
typedef unsigned int u_int; // 无符号整型
typedef unsigned short u_short; // 无符号短整型


void draw_point(u_int,u_int,u_short);// 画点函数
void draw_line(u_int,u_int,u_int,u_int);// 划线函数
void draw_jpg(char*,int,int); //画2048元素图
void draw_cboard();// 画2048棋盘函数
void c_screen();// 清屏
void draw_arr(); // 画一张图片
void draw_one(int,int); // 将数组中数字对应图片显示在屏幕上



#endif