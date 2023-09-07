#include "2048.h"

int test_arr[10] = {2,2,2,2,2,2,2,2,4,4};
int a[4][4] = {0};
int a1[4][4] = {0};
int b[16] = {0}; // 确保每次出现的都是不同的位置，且判断图区是否已满



int main(int argc,char *argv[]){

    struct fb_var_screeninfo fvs;
    struct fb_var_screeninfo ffs;


    // 栈
    sqStack sq;
    InitStack(&sq);

    // 打开lcd驱动文件
    int lcd = open("/dev/fb0",O_RDWR);
    if(lcd == -1){
        perror("open lcd error");
        return 0;
    }

    // 获取硬件参数信息
    ioctl(lcd,FBIOGET_VSCREENINFO,&fvs);
    ioctl(lcd,FBIOGET_FSCREENINFO,&ffs);
    lcd_x = fvs.xres;
    lcd_y = fvs.yres;
    bpp = fvs.bits_per_pixel;

    // 映射文件到存储区中
    screen_base =  mmap(NULL,1024*600*2,PROT_WRITE,MAP_SHARED,lcd,0);
    if(screen_base == MAP_FAILED){
        perror("mmap lcd error");
        close(lcd);
        return 0;
    }

    // 画2048游戏棋盘
    c_screen();
    draw_cboard();
    set_arr();
    // 游戏循环
    int index = -1;
    int i =1;
    while(1){
        is_win();
        set_arr();
        PushStack(&sq,a);
        print_arr();
        printf_b();
        draw_arr();
        index = get_direction();
        switch(index)
        {
        case 5:
            //上移
            up();
            PushStack(&sq,a);
            draw_arr();
            break;
        case 1:
            // 左移
            left();
            PushStack(&sq,a);
            draw_arr();
            break;
        case 2:
            // 下移
            down();
            PushStack(&sq,a);
            draw_arr();
            break;
        case 3:
            // 右移
            right();
            PushStack(&sq,a);
            draw_arr();
            break;      
        }
       
    }   
   
}