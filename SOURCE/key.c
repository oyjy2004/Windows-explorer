#include<bios.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <mygraph.h>
#include<mouse.h>
#include<time.h>

/*
    作用：读取键盘上的键位
    输入：输入框位置
    返回值：输入的字符串
*/
char* key(int x1,int y1,int x2,int y2,int n)
{   
    setbuf(stdin, NULL);
    fflush(stdin); 
    rewind(stdin);
    int b;
    clock_t start_t, end_t;
    float time;
    char key3[100]={0};
    char key1[28][2]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    char key2[28][2]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    char key4[12][2]={"0","1","2","3","4","5","6","7","8","9"};
    char key5[2][2]={"."};
    setfillstyle(1, WHITE);
    bar(x1+1,y1+1+n*15,x2-1,y2-1+n*15);
    setcolor(BLACK);
    line(x1+6*strlen(key3),y1,x1+6*strlen(key3),y2);
    //itoa(b,key3,10);
    //outtextxy(507+7*i,83,key3);
    hide_mouse();
    while(b!=13&&strlen(key3)<12){
    start_t=clock();  
    b=bioskey(0);
    end_t=clock();
    time=(float)(end_t - start_t) / CLOCKS_PER_SEC;
    if(time<0.002)
    {
        b=0;
    }
    b=b<<8>>8;
    if(b==8)
    {
        key3[strlen(key3)-1]='\0';
    }
    if(b>=97&&b<123)
    {
        strcat(key3,key1[b-97]);
    }
    if(b>=65&&b<91)
    {
        strcat(key3,key2[b-65]);
    } 
    if(b>=48&&b<58)
    {
        strcat(key3,key4[b-48]);
    } 
    if(b==46)
    {
        strcat(key3,key5[0]);
    }
    setfillstyle(1, WHITE);
    bar(x1,y1+1,x2,y2-1);
    settextstyle(SMALL_FONT, HORIZ_DIR, 4);
    outtextxy(x1,y1,key3);
    setcolor(BLACK);
    line(x1+6*strlen(key3),y1+1,x1+6*strlen(key3),y2-1);
    }
    setcolor(WHITE);
    line(x1+6*strlen(key3),y1+1,x1+6*strlen(key3),y2-1);
    show_mouse();
    return key3;
}
