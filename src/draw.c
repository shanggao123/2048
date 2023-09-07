#include "../include/2048.h"

// 画点函数
void draw_point(u_int x,u_int y,u_short color){

    if(x > lcd_x){
        x = lcd_x-1;
    }
    if (y > lcd_y)
    {
        y = lcd_y -1;
    }
    
    screen_base[lcd_x*y + x] = color;
}

// 划线函数
void draw_line(u_int x0,u_int y0,u_int x,u_int y){
       
    for(u_int i = x0;i<x;i++){
        for(u_int j = y0;j<y;j++){
            draw_point(i,j,0x8010);
        }
    }

}

// 画2048棋盘函数
void draw_cboard(){
    draw_line(0,0,584,4);
    draw_line(0,144,584,149);
    draw_line(0,289,584,294);
    draw_line(0,434,584,439);
    draw_line(0,579,584,584);

    draw_line(0,0,4,584);
    draw_line(144,0,149,584);
    draw_line(289,0,294,584);
    draw_line(434,0,439,584);
    draw_line(579,0,584,584);
}

// 清屏
void c_screen(){
    for(int i = 0;i<1024;i++){
        for(int j = 0;j<600;j++){
            draw_point(i,j,0x0000);
        }
    }
}


// 画图函数
void draw_jpg(char* path,int x,int y){
    unsigned int out_width; //输出图像的宽度
    unsigned int out_height; // 输出图像的高度
    unsigned int out_components; //每个像素所占字节数
    struct jpeg_decompress_struct cinfo; // 解压结构体，存储解压后的jpg图片信息
    struct jpeg_error_mgr jerr; // 处理错误的对象

    unsigned short *addr_pre = screen_base;
    addr_pre +=(5*(y+1) + y*140 + 1024*(x*140 + (x+1)*5));
    unsigned char *line_buf; // 存储图片一行信息
    unsigned short *pic_buf; // rbg565信息存储数组

    //绑定默认错误处理函数
    cinfo.err = jpeg_std_error(&jerr);

    // 创建解码对象
    jpeg_create_decompress(&cinfo);
    // 设置解码的数据源
    //printf("%s\n",path);
    FILE *jpg = fopen(path,"r+");
    if(jpg == NULL){
        perror("fopen *.jpg error");
        jpeg_destroy_decompress(&cinfo);
        return;
    }
    jpeg_stdio_src(&cinfo,jpg);
    // 读取jpeg的文件头信息
    jpeg_read_header(&cinfo,TRUE);
    // 开始解码
    jpeg_start_decompress(&cinfo);
    out_width = cinfo.output_width;
    out_height = cinfo.output_height;
    out_components = cinfo.output_components;

    unsigned short blue,green,red;

    line_buf = malloc(out_width*out_components);
    pic_buf = malloc(out_width*2);
    // 读取数据
    while (cinfo.output_scanline < out_height)
        {
            jpeg_read_scanlines(&cinfo,&line_buf,1);
            for(int i = 0;i<out_width;i++){
                blue = line_buf[i*3+0] >> 3;
                green = line_buf[i*3+1] >> 2;
                red = line_buf[i*3+2] >> 3;

                pic_buf[i] = blue << 11 | green << 5 | red; 
            }
            memcpy(addr_pre,pic_buf,out_width*2);
            addr_pre += lcd_x; 
        }
           
    

    //解码完成
    jpeg_finish_decompress(&cinfo);

    //销毁解码对象
    jpeg_destroy_decompress(&cinfo);
    
    free(line_buf);
    free(pic_buf);

    //关闭文件
    fclose(jpg);

    
}



// 画一张图片
void draw_one(int x,int y){
    switch (a[x][y])
    {
    case 0:
        draw_jpg(img_path[11],x,y);
        break;
    case 2:
        draw_jpg(img_path[0],x,y);
        break;
    case 4:
        draw_jpg(img_path[1],x,y);
        break;
    case 8:
        draw_jpg(img_path[2],x,y);
        break;
    case 16:
        draw_jpg(img_path[3],x,y);
        break;
    case 32:
        draw_jpg(img_path[4],x,y);
        break;
    case 64:
        draw_jpg(img_path[5],x,y);
        break;
    case 128:
        draw_jpg(img_path[6],x,y);
        break;
    case 256:
        draw_jpg(img_path[7],x,y);
        break;
    case 512:
        draw_jpg(img_path[8],x,y);
        break;
    case 1024:
        draw_jpg(img_path[9],x,y);
        break;
    case 2048:
        draw_jpg(img_path[10],x,y);
        break;
    }   
}

// 将数组中数字对应图片显示在屏幕上
void draw_arr(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            draw_one(j,i);
        }
    }
}
