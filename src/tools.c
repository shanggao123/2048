#include "../include/tools.h"
#include "../include/2048.h"


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
    // 返回1代表输，返回0代表还没输
    int flag = 1;
    int i;
    int j;
    for(i = 0;i<4;i++){
        for(j= 0;j<4;j++){
            if(i<3&&(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j])){
                flag = 0;
            }else if(a[i][j] == a[i][j+1]){
                flag = 0;
            }
        }
    }
    
    return flag;
}

// 放置图片的位置
void set_arr(){
    int index = get_num(10);
    int x =get_num(4);
    int y =get_num(4);
    if(!is_empty()){
        // 图片还没满
        if(a[x][y] != 0){
            // 显示位置已经被显示
            get_index(&x,&y);   
        }
        a[x][y] = test_arr[index];
        change_b();
    }else{
        //图片已满，判断是否输了
        if(is_lose()){ // 无法移动已经输了
            printf("你输了\n");
            exit(0);
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
    up_clear(); //第一次清零
    change_b();
    up_add(); // 合并
    change_b();
    up_clear(); // 第二次清零
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

// 数组复制函数
void copy_arr(){
    for(int i = 0;i<4;i++){
        for(int j= 0;j<4;j++){
           a[i][j] = a1[i][j];
        }
    }
}



// 随机生成n以内的随机数
int get_num(int n){
    srand(clock());
    int i = rand() % n;
    return i;
}

// 判断输赢
void is_win(){
    for(int i = 0;i<4;i++){
        for(int j= 0;j<4;j++){
            if(a[i][j] == 2048){
                printf("你赢了\n");
                exit(0);
            }
        }
    }
}


// 获取滑动方向
int get_direction(){

    int x = 0; // 记录x的坐标值
    int y = 0; // 记录y的坐标值
    int x0 = 0; // 记录x坐标的初始位置
    int y0 = 0; // 记录x坐标的初始位置
    int i = 1; 
    struct input_event in_en = {0}; // input事件存储结构体
    // 打开文件
    int fd = open("/dev/input/event1",O_RDONLY);
    if(fd == -1){
        perror("open error");
        exit(-1);
    }
    while (1)
    {   
        // 读取文件信息
        if(sizeof(struct input_event)>read(fd,&in_en,sizeof(struct input_event))){
            perror("read error");
            exit(-1);
        }
        // 获取打印信息，从而输出触屏状态
        switch(in_en.type){
            case  EV_ABS:
                if(in_en.code ==  53 && i == 1){ //获取x0的值
                    x0 = in_en.value;             
                }else if (in_en.code ==  54 && i==1)
                { // 获取y0的值
                    y0 = in_en.value;
                    i++;
                }
                if(in_en.code == 53){ //如果移动的是x
                    x = in_en.value;
                }else if (in_en.code == 54)
                { // 获取移动的y值
                    y = in_en.value;
                }
                if(in_en.value == -1){

                    if(abs(x0-x)>abs(y0-y) && x0-x>0){
                        printf("左移\n");
                        i = 1;
                        return 1;
                        
                    // 如果|x|的偏移量，大于|y|的偏移量，且x的值大于零，为左移
                    }
                    if(abs(x0-x)>abs(y0-y) && x0-x<0){
                    // 如果|x|的偏移量，大于|y|的偏移量，且x的值小于零，为右移
                        printf("右移\n");
                        i = 1;
                        return 3;
                       
                    }
                    if(abs(x0-x)<abs(y0-y) && y0-y>0){
                    // 如果|x|的偏移量，小于|y|的偏移量，且y的值大于零，为上移
                        printf("上移\n");
                        i = 1;
                        return 5;
                        
                    }
                    if(abs(x0-x)<abs(y0-y) && y0-y<0){
                    // 如果|x|的偏移量，小于|y|的偏移量，且y的值小于零，为下移
                        printf("下移\n");
                        i = 1;
                        return 2;                        
                    }
                    
                }
                break;

        }

    }
    close(fd);
    return 0;
}
