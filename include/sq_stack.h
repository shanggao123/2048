#ifndef __SQSTACK_H__
#define __SQSTACK_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAX_SIZE 100
typedef int Two_Array[4][4];

typedef struct sqStack{
    Two_Array data[MAX_SIZE];  // 栈
    int top; //指向栈顶 
}sqStack;

// 初始化栈
bool InitStack(sqStack *);
//判断栈空
bool IsEmpty(sqStack *);
// 进栈
bool PushStack(sqStack *,Two_Array);
//出栈
bool PopStack(sqStack *,Two_Array);

#endif