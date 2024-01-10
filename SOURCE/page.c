#include "page.h"
#include "draw.h"
#include "key.h"

void g_one(void)
{
    hide_mouse();
    FILE *hz;
    unsigned hz1[2]={0x5f00 , 0x59cb};//开始

    barxy(0,0,640,480,LIGHTBLUE);
    setfillstyle(1, WHITE);
    bar(270,355,380,400);

    sethzmode(hz, "FS32");
    put_s_hz(290,360,hz1,2,hz,BLACK);
    //settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    //button(240,335,165,40,"Log in");
    //button(240,380,165,40,"Log out");

    setcolor(WHITE);
    setfillstyle(1, WHITE);
    bar(240,140,320,220);
    bar(330,140,410,220);
    bar(240,230,320,310);
    bar(330,230,410,310);
    //button(240,160,80,80);
    //button(325,160,80,80);
    //button(240,245,80,80);
    //button(325,245,80,80);
    show_mouse();
}

void s_one(void)
{
    g_one();
    getmouse();
    while(1)
    {
        if(M_sc > 0)
        {

            if(pd(270,355,110,45))
            {
                g_three();
                break;
            }

        }
        getmouse();
    }
}


/*
    本函数对页面切换后的不变部分进行绘制
*/
void g_three()
{
    hide_mouse();
    int th=VGA,ty=VGAHI;
    initgraph(&th,&ty,"C:\\BORLANDC\\BGI");
    barxy(0,0,640,480,WHITE);
    setcolor(BLUE);
    line(0,25,639,25);
    setfillstyle(1, BLUE);
    bar(0,0,639,25);
    setfillstyle(1, RED);
    bar(610,0,639,25);
    setcolor(WHITE);
    line(615,5,634,20);
    setcolor(WHITE);
    line(634,5,615,20);
    unsigned int hzk3[5]={0x8d44 ,0x6e90 ,0x7ba1 ,0x7406 ,0x5668 };//"资源管理器"
    unsigned int hzk4[2]={0x590d ,0x5236 };//"复制"
    unsigned int hzk5[2]={0x7c98 ,0x8d34 };//"粘贴"
    unsigned int hzk6[2]={0x526a ,0x5207 };//"剪切"
    unsigned int hzk7[2]={0x5220 ,0x9664 };//"删除"
    unsigned int hzk8[3]={0x91cd ,0x547d ,0x540d };//"重命名"
    unsigned int hzk9[2]={0x65b0 ,0x5efa };//"新建"
    unsigned int hzk10[3]={0x6587 ,0x4ef6 ,0x6863 };//"文件档"
    unsigned int hzk11[2]={0x6587 ,0x4ef6 };//"文件"
    unsigned int hzk12[2]={0x5c5e ,0x6027 };//"属性"
    unsigned int hzk13[2]={0x90fd ,0x9009 };//"都选"
    unsigned int hzk14[2]={0x82f1 ,0x6587 };//"英文"
    unsigned int hzk15[2]={0x5347 ,0x5e8f };//"升序"
    unsigned int hzk16[2]={0x964d ,0x5e8f };//"降序"
    //unsigned int hz1[4]={0x4f60, 0x597d, 0x4e16, 0x754c};
    char name[100][100]={"you.txt","me.txt"};
    FILE *hz;
    sethzmode(hz, "FS16");
    put_s_hz(3,3,hzk3,5,hz, WHITE);
    //绘制功能框
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    setfillstyle(1, LIGHTGRAY);
    bar(0,25,639,75);
    //绘制分隔线
    setcolor(BLACK);
    line(52,25,52,75);
    line(104,25,104,75);
    line(156,25,156,75);
    line(210,25,210,75);
    line(277,25,277,75);
    line(349,25,349,75);
    line(400,25,400,75);
    line(452,25,452,75);
    line(504,25,504,75);
    line(556,25,556,75);
    line(612,25,612,75);
    line(0,76,660,76);
    line(140,105,140,475);
    //填充汉字
    sethzmode(hz, "FS16");
    put_s_hz(10,40,hzk4,2,hz,BLACK);
    put_s_hz(62,40,hzk5,2,hz,BLACK);    
    put_s_hz(114,40,hzk6,2,hz,BLACK);
    put_s_hz(166,40,hzk7,2,hz,BLACK);
    put_s_hz(218,40,hzk8,3,hz,BLACK);
    put_s_hz(296,35,hzk9,2,hz,BLACK);
    put_s_hz(286,50,hzk10,3,hz,BLACK);
    put_s_hz(359,35,hzk9,2,hz,BLACK);
    put_s_hz(359,50,hzk11,2,hz,BLACK);
    put_s_hz(411,40,hzk12,2,hz,BLACK);
    put_s_hz(463,40,hzk13,2,hz,BLACK);
    put_s_hz(515,35,hzk14,2,hz,BLACK);
    put_s_hz(515,50,hzk15,2,hz,BLACK);
    put_s_hz(567,35,hzk14,2,hz,BLACK);
    put_s_hz(567,50,hzk16,2,hz,BLACK);
    //绘制上一页与下一页的箭头
    setcolor(BLACK);
    line(20,90,10,90);
    line(40,90,50,90);
    line(10,90,15,85);
    line(10,90,15,95);
    line(50,90,45,95);
    line(50,90,45,85);
    //绘制地址栏
    setcolor(BLACK);
    rectangle(70,80,500,100);
    //绘制搜索栏
    setcolor(BLACK);
    rectangle(505,80,635,100);
    //绘制虚拟盘里的文件
    settextstyle(SMALL_FONT, HORIZ_DIR, 4);
    line(10,123,5,118);
    line(10,123,15,118);
    outtextxy(20,115,"BORLANDC");
    line(10,138,5,133);
    line(10,138,15,133);
    outtextxy(20,130,"TEST");
    show_mouse();
}