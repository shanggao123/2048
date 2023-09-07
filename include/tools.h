#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

unsigned short transform();
int get_num(int);

/* 操作数组函数↓*/
int is_empty();
int is_lose();

void change_b();
void set_arr();
void get_index(int *,int *);
void copy_arr();
void a_zero();
void a1_zero();


void up();
void down();
void left();
void right();
void up_add();
void up_clear();
void down_add();
void down_clear();
void left_add();
void left_clear();
void right_add();
void right_clear();

void print_arr();
void printf_b();
/* 操作数组函数↑*/

void show();
// 获取滑动方向
int get_direction();
// 判断是否胜利
void is_win();

#endif