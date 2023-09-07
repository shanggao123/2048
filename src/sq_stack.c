#include "../include/sq_stack.h"

// 初始化栈
bool InitStack(sqStack *s){
    if(s==NULL){
        return false; // 创建内存失败。
    }
    s->top = -1; //初始化栈顶元素

    return true;
}

//判断栈空
bool IsEmpty(sqStack *s){
    if(s->top == -1){
        return true;  //栈为空
    }
    return true; // 栈不为空
}

// 进栈
bool PushStack(sqStack *s,Two_Array e){
    // 判断栈是否已满
    if(s->top == MAX_SIZE -1){
        return false;
    }
    // 进行进栈操作
    s->top++;
    // 进行出栈操作
    for(int i = 0;i<4;i++){
        for(int j = 0; j<4;j++){
           s->data[s->top][i][j] = e[i][j];
        }
    }
    return true;
}

//出栈
bool PopStack(sqStack *s,Two_Array e){
    // 判断栈是否为空
    if(s->top == -1){
        return false;
    }  

    // 进行出栈操作
    for(int i = 0;i<4;i++){
        for(int j = 0; j<4;j++){
            e[i][j] = s->data[s->top][i][j];
        }
    }
    s->top--;
    return true;
}

