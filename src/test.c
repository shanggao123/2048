#include "../include/tools.h"
#include "../include/test.h"

static int test_arr[] = {2,2,2,2,2,2,2,2,4,4};
static int a[4][4] = {0};
static int a1[4][4] = {0};
static int b[16] = {0}; // 确保每次出现的都是不同的位置，且判断图区是否已满

// 输出数组
void print_arr(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}

// 从左到右是否输了
int is_lose(){
    int flag = 1;
    int i;
    int j;
    for(i = 0;i<4;i++){
        for(j= 0;j<4;j++){
            if(a[i][j] == a[i][j+1] || a[j][i] == a[i][j+1]){
                flag = 0;
                return flag;
            }
        }
    }
    return flag;
}

// 设置图片
void set_arr(){
    int index = get_num(10);
    int x =get_num(4);
    int y =get_num(4);
    int i = 0;
    if(!is_empty()){
        // 图片还没满
        while(a[x][y] != 0){
            // 显示位置已经被显示
            get_index(&x,&y);
            printf("%d\n",i++);  
        }
        a[x][y] = test_arr[index];
        change_b();
    }else{
        //图片已满，判断是否输了
        if(is_lose()){ // 无法移动已经输了
            printf("你输了\n");
            exit(-1);
        }
    }
}

//每次合并清零时改变b数组的值
void change_b(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(a[i][j] == 0){
                b[i*4+j] = 0;
            }else{
                b[i*4+j] = 1;
            }
        }
    }
}

// 输出b数组
void printf_b(){
    for(int i = 0;i<16;i++){
        printf("%d",b[i]);
    }
    printf("\n");  
}

// 获取下子的位置
void get_index(int *x,int *y){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(b[i*4+j] == 0){
                *x = i;
                *y = j;
            }
        }
    }
}

// 判断棋盘是否已经满了
int is_empty(){
    int flag = 1;
    for(int i = 0;i<16;i++){
        if(b[i] == 0){
            flag = 0;
            return flag;
        }
    }
    return flag;
}


// 上移
void up(){
    up_clear(); // 清零
    change_b();
    up_add(); // 第二次合并
    change_b();
    up_clear(); // 清零
    change_b();
}

// 下移
void down(){
    down_clear();
    change_b();
    down_add();
    change_b();
    down_clear();
    change_b();
}
// 左移
void left(){
    left_clear();
    change_b();
    left_add();
    change_b();
    left_clear();
    change_b();
}
// 右移
void right(){
    right_clear();
    change_b;
    right_add();
    change_b();
    right_clear();
    change_b;
}

int main(){
    int index = -1;
    while(1){
        set_arr();


        printf("请输入一个数:\n");
        scanf("%d",&index);
        switch(index)
        {
        case 5:
            //上移
            up();
            break;
        case 1:
            // 左移
            left();
            break;
        case 2:
            // 下移
            down();
            break;
        case 3:
            // 右移
            right();
            break;
        }
        
    }   
   
}

// a1数组清零
void a1_zero(){
    for(int j = 0;j<4;j++){
        for(int i= 0;i<4;i++){
          a1[i][j] = 0;
        }
    }
}
// a数组清零
void a_zero(){
    for(int j = 0;j<4;j++){
        for(int i= 0;i<4;i++){
          a[i][j] = 0;
        }
    }
}

// 上移合并
void up_add(){
    for(int j = 0;j<4;j++){
        for(int i= 0;i<3;i++){
            if(a[i][j] == a[i+1][j]){
                a[i][j] += a[i+1][j];
                a[i+1][j] = 0;
            }
        }
    }
}

// 下移合并
void down_add(){
    for(int j = 0;j<4;j++){
        for(int i=3;i>0;i--){
            if(a[i][j] == a[i-1][j]){
                a[i][j] += a[i-1][j];
                a[i-1][j] = 0;
            }
        }
    }
}

// 左移合并
void left_add(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<3;j++){
            if(a[i][j] == a[i][j+1]){
                a[i][j] += a[i][j+1];
                a[i][j+1] = 0; 
            }
        }
    }
}

// 右移合并
void right_add(){
    for(int i=0;i<4;i++){
        for(int j = 3;j>0;j--){
            if(a[i][j] == a[i][j-1]){
                a[i][j] += a[i][j-1];
                a[i][j-1] = 0;
            }
        }
    }
}

// 上移清零
void up_clear(){
    a1_zero();
    for(int j = 0;j<4;j++){
        int k = 0;
        for(int i= 0;i<4;i++){           
           if(a[i][j] != 0){
                a1[k][j] = a[i][j];
                k++;
           }
        }
    }
    copy_arr();
}

// 下移清零
void down_clear(){
    a1_zero();
    for(int j = 0;j<4;j++){
        int k = 3;
        for(int i =3;i>=0;i--){
            if(a[i][j] != 0){
                a1[k][j] = a[i][j];
                k--;
            }
        }
    }
    copy_arr();
}

// 左移清零
void left_clear(){
    a1_zero();
    for(int i = 0;i<4;i++){
        int k = 0;
        for(int j =0;j<4;j++){
            if(a[i][j] != 0){
                a1[i][k] = a[i][j];
                k++;
            }
        }
    }
    copy_arr();
}

// 右移清零
void right_clear(){
    a1_zero();
    for(int i = 0;i<4;i++){
        int k = 3;
        for(int j = 3;j>=0;j--){
            if(a[i][j] != 0){
                a1[i][k] = a[i][j];
                k--;
            }
        }
    }
    copy_arr();
}
void copy_arr(){
    for(int i = 0;i<4;i++){
        for(int j= 0;j<4;j++){
           a[i][j] = a1[i][j];
        }
    }
}






/*  错误清零
// 上移_正向清零
void up_clear1(){
    for(int j = 0;j<4;j++){
        for(int i= 3;i>0;i--){
            if(a[i-1][j] == 0&&a[i][j]!=0){
               a[i-1][j] = a[i][j];
               a[i][j] = 0;
            }
        }
    }
}

// 上移_反向清零
void up_clear2(){
    for(int j = 0;j<4;j++){
        for(int i= 0;i<3;i++){
            if(a[i][j] == 0 && a[i+1][j] != 0){
                a[i][j] = a[i+1][j];
                a[i+1][j] = 0;
            }
        }
    }
}



// 下移_正向清零
void down_clear1(){
    for(int j = 0;j<4;j++){
        for(int i= 0;i<3;i++){
            if(a[i][j] != 0 && a[i+1][j] == 0){
                a[i+1][j] = a[i][j];
                a[i][j] = 0;
            }
        }
    }
}

// 下移_反向清零
void down_clear2(){
    for(int j = 0;j<4;j++){
        for(int i= 3;i>0;i--){
            if(a[i][j] == 0 && a[i-1][j]!=0){
                a[i][j] = a[i-1][j];
                a[i-1][j] = 0;
            }
        }
    }
}

*/

