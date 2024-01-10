#include<mygraph.h>
#include"mouse.h"
#include"hanzi.h"
#include"draw.h"
#include"key.h"
#include"listbase.h"
#include"flag.h"
#include"bite.h"
#include"listcopy.h"
#include"listsort.h"
#include"func.h"

/*
    作用：获取文件的时间
    输入：当前父节点
    返回值：时间的字符串
*/
char *flie_time(struct My_filenode* fatherNode)
{
    struct Filetime* temp1;
    char day[5],month[5],year[5],hour[5],min[5],time[20]={0},temp[3]={"0"};
    temp1=get_file_time(fatherNode);
    if(temp1->y<10)
    {
        itoa(temp1->y,year,10);
        strcat(temp,year);
        strcat(time,temp);
        strcat(time,"/");
        temp[1]='\0';
    }
    else
    {
        itoa(temp1->y,year,10);
        strcat(time,year);
        strcat(time,"/");
    }
    if(temp1->month<10)
    {
        itoa(temp1->month,month,10);
        strcat(temp,month);
        strcat(time,temp);
        strcat(time,"/");
        temp[1]='\0';
    }
    else
    {
        itoa(temp1->month,month,10);
        strcat(time,month);
        strcat(time,"/");
    }
    if(temp1->d<10)
    {
        itoa(temp1->d,day,10);
        strcat(temp,day);
        strcat(time,temp);
        strcat(time," ");
        temp[1]='\0';
    }
    else
    {
        itoa(temp1->d,day,10);
        strcat(time,day);
        strcat(time," ");
    }

    if(temp1->h<10)
    {
        itoa(temp1->h,hour,10);
        strcat(temp,hour);
        strcat(time,temp);
        strcat(time,":");
        temp[1]='\0';
    }
    else
    {
        itoa(temp1->h,hour,10);
        strcat(time,hour);
        strcat(time,":");
    }

    if(temp1->min<10){
        itoa(temp1->min,min,10);
        strcat(temp,min);
        strcat(time,temp);
        temp[1]='\0';
    }
    else
    {
        itoa(temp1->min,min,10);
        strcat(time,min);
    }
    return time;
}

/*
    作用：绘制所打开文件夹的文件
    输入：父节点，要高亮的文件num
    返回值：所画的文件数目
*/
int drawfile(struct My_filenode* fatherNode,int num)
{
    int x=160,y=115,n=1,size=0;
    char time1[20]={0},path[20]={0},fsize[6]={0};
    setfillstyle(1,WHITE);
    bar(71,81,499,99);
    setcolor(BLACK);
    get_path(fatherNode,path);
    outtextxy(75,85,path);
    hide_mouse();
    setfillstyle(1,WHITE);
    bar(x-15,y-2,700,500);
    if(fatherNode->son_list_head==NULL)
    {
        show_mouse();
        return 0;
    }
    struct My_filenode* temp=fatherNode->son_list_head;
    struct Filetime* temp1;
    for(temp;temp->next!=NULL;temp=temp->next)
    {  
        if(n>23)
        {
            break;
        }
        if(temp->next->flag&64&&num==n)
        {
            setfillstyle(1,LIGHTCYAN);
            bar(x-15,y,600,y+15);
            strcat(time1,flie_time(temp->next));
            setfillstyle(1,BROWN);
            bar(x-15,y,x-2,y+10);
            setcolor(WHITE);
            line(x-8,y,x-2,y);
            line(x-8,y+1,x-2,y+1);
            setcolor(BLACK);
            outtextxy(x,y,temp->next->name);
            outtextxy(x+200,y,time1);
            if(get_file_bsize(temp->next)<=0)
            {
                itoa(get_file_kbsize(temp->next),fsize,10);
                strcat(fsize,"kb");
            }
            else
            {
                itoa(get_file_bsize(temp->next),fsize,10);
                strcat(fsize,"b");
            }
            outtextxy(x+400,y,fsize);
            fsize[0]='\0';
            time1[0]='\0';
            y+=15;
            n+=1;
        }
        else if(temp->next->flag&64&&num!=n)
        {
            setfillstyle(1,WHITE);
            bar(x-15,y,600,y+15);
            strcat(time1,flie_time(temp->next));
            setfillstyle(1,BROWN);
            bar(x-15,y,x-2,y+10);
            setcolor(WHITE);
            line(x-8,y,x-2,y);
            line(x-8,y+1,x-2,y+1);
            setcolor(BLACK);
            outtextxy(x,y,temp->next->name);
            outtextxy(x+200,y,time1);
            if(get_file_bsize(temp->next)<=0)
            {
                itoa(get_file_kbsize(temp->next),fsize,10);
                strcat(fsize,"kb");
            }
            else
            {
                itoa(get_file_bsize(temp->next),fsize,10);
                strcat(fsize,"b");
            }
            outtextxy(x+400,y,fsize);
            fsize[0]='\0';
            time1[0]='\0';
            y+=15;
            n+=1;
        }
        else if(num==n)
        {
            setfillstyle(1,LIGHTCYAN);
            bar(x-15,y,600,y+15);
            strcat(time1,flie_time(temp->next));
            outtextxy(x,y,temp->next->name);
            line(x-8,y,x-2,y);
            line(x-8,y+1,x-2,y+1);
            outtextxy(x,y,temp->next->name);
            outtextxy(x+200,y,time1);
            if(get_file_bsize(temp->next)<=0)
            {
                itoa(get_file_kbsize(temp->next),fsize,10);
                strcat(fsize,"kb");
            }
            else
            {
                itoa(get_file_bsize(temp->next),fsize,10);
                strcat(fsize,"b");
            }
            outtextxy(x+400,y,fsize);
            fsize[0]='\0';
            time1[0]='\0';
            y+=15;
            n+=1;
        }
        else if(num!=n)
        {
            setfillstyle(1,WHITE);
            bar(x-15,y,600,y+15);
            strcat(time1,flie_time(temp->next));
            outtextxy(x,y,temp->next->name);
            line(x-8,y,x-2,y);
            line(x-8,y+1,x-2,y+1);
            outtextxy(x,y,temp->next->name);
            outtextxy(x+200,y,time1);
            if(get_file_bsize(temp->next)<=0)
            {
                itoa(get_file_kbsize(temp->next),fsize,10);
                strcat(fsize,"kb");
            }
            else
            {
                itoa(get_file_bsize(temp->next),fsize,10);
                strcat(fsize,"b");
            }
            outtextxy(x+400,y,fsize);
            fsize[0]='\0';
            time1[0]='\0';
            y+=15;
            n+=1;
        }
    }
    show_mouse();
    delay(100);
    return n-1;
}

/*
    作用：绘制文件类型
    输入：该节点
    返回值：无
*/
void draw_attribute(struct My_filenode* theNode)
{
    char path[30],time1[30]={0},size[10]={0};
    int type;
    setfillstyle(1,WHITE);
    bar(250,115,600,350);
    setcolor(BLACK);
    line(250,115,600,115);
    line(250,350,600,350);
    line(250,115,250,350);
    line(600,115,600,350);
    setcolor(BLACK);
    outtextxy(270,130,"Name:");
    outtextxy(320,130,theNode->name);
    get_path(theNode,path);
    outtextxy(270,150,"Path");
    outtextxy(320,150,path);
    outtextxy(270,170,"type");
    set0onebit(&(theNode->flag),1);
    type=theNode->flag;
    //printf("%d",type);
    switch (type)
    {
        case 3:
            outtextxy(320,170,"TXT");
            break;
        case 4:
            outtextxy(320,170,"C");
            break;
        case 5:
            outtextxy(320,170,"CPP");
            break;
        case 6:
            outtextxy(320,170,"H");
            break;
        case 7:
            outtextxy(320,170,"OBJ");
            break;
        case 8:
            outtextxy(320,170,"EXE");
            break;
        case 9:
            outtextxy(320,170,"JPG");
            break;
        case 10:
            outtextxy(320,170,"PNG");
            break;
        case 11:
            outtextxy(320,170,"DOC");
            break;
        case 12:
            outtextxy(320,170,"XLS");
            break;
        case 13:
            outtextxy(320,170,"PPT");
            break;
        case 14:
            outtextxy(320,170,"PDF");
            break;
        case 15:
            outtextxy(320,170,"OTHER");
            break;
        case 66:
            outtextxy(320,170,"DIR");
            break;
        default:
            break;
    }
    outtextxy(270,190,"Time:");
    strcat(time1,flie_time(theNode));
    outtextxy(320,190,time1);
    outtextxy(270,210,"Size:");
    if(get_file_bsize(theNode)<=0)
    {
        itoa(get_file_kbsize(theNode),size,10);
        strcat(size,"kb");
    }
    else
    {
        itoa(get_file_bsize(theNode),size,10);
        strcat(size,"b");
    }
    outtextxy(320,210,size);
}

/*
    作用：实现全选时的图画绘制
    输入：当前的父节点
    返回值：所画的文件数
*/
int draw_all_file(struct My_filenode* fatherNode)
{
    
    int x=160,y=115,n=1,size=0;
    char time1[20]={0},path[20]={0};
    setfillstyle(1,WHITE);
    bar(71,81,499,99);
    setcolor(BLACK);
    get_path(fatherNode,path);
    outtextxy(75,85,path);
    hide_mouse();
    setfillstyle(1,WHITE);
    bar(x-15,y,700,500);
    if(fatherNode->son_list_head==NULL)
    {
        show_mouse();
        return 0;
    }
    struct My_filenode* temp=fatherNode->son_list_head;
    struct Filetime* temp1;
     
    for(temp;temp->next!=NULL;temp=temp->next)
    {  
        if(n>23)
        {
            break;
        }
        if(temp->next->flag&64)
        {
            setfillstyle(1,LIGHTCYAN);
            bar(x-15,y,600,y+15);
            strcat(time1,flie_time(temp->next));
            setfillstyle(1,BROWN);
            bar(x-15,y,x-2,y+10);
            setcolor(WHITE);
            line(x-8,y,x-2,y);
            line(x-8,y+1,x-2,y+1);
            setcolor(BLACK);
            outtextxy(x,y,temp->next->name);
            outtextxy(x+200,y,time1);
            time1[0]='\0';
            y+=15;
            n+=1;
        }
        else 
        {
            setfillstyle(1,LIGHTCYAN);
            bar(x-15,y,600,y+15);
            strcat(time1,flie_time(temp->next));
            outtextxy(x,y,temp->next->name);
            line(x-8,y,x-2,y);
            line(x-8,y+1,x-2,y+1);
            outtextxy(x,y,temp->next->name);
            outtextxy(x+200,y,time1);
            time1[0]='\0';
            y+=15;
            n+=1;
        }
    }
    show_mouse();
    delay(100);
    return n-1;
}

/*
    作用：绘制新建时的图画
    输入：当前父节点
    返回值：所画的文件数目
*/
int new_draw_file(struct My_filenode* fatherNode,int n,int filetype)
{
    int x=160,y=115,u=0;
    char new_file_name[20]={0};
    strcat(new_file_name,key(x-8,y+n*15,x+100,y+n*15+10,n));
    fflush(stdin);
    setbuf(stdin, NULL);
    rewind(stdin);
    
    if(new_file_name[0]!=' '&&new_file_name[0]!='\0')
    {
        new_file(fatherNode->son_list_head,new_file_name,filetype,NULL);
        setcolor(WHITE);
        bar(150,110,700,500);
        u=drawfile(fatherNode,0);
        new_file_name[0]='\0';
    }
    else{
        setcolor(WHITE);
        bar(150,110,700,500);
        u=drawfile(fatherNode,0);
        new_file_name[0]='\0';
    }
    return u;
}

/*
    作用：页面上方功能的实现
    输入：pc，当前父节点，paste, ph_for_paste, 粘贴模式
    返回值：无
*/
void top_side(struct My_filenode* pc,struct My_filenode* fatherNode,struct My_vector_ *paste,struct My_filenode* ph_for_paste,int *paste_prime)
{ 
    struct My_filenode* temp=NULL,*temp1=NULL;
    int x=160,y=115,num=count_nodes(fatherNode->son_list_head),n_cf;
    char keyword[20]={0};
    //功能
    if(fatherNode==pc)
    {
        return;
    }
    else
    {
        if(pd(505,80,150,5)&&M_sc > 0)//搜索
        {
            strcat(keyword,key(506,82,634,97,0));
            setcolor(BLACK);
            settextstyle(SMALL_FONT, HORIZ_DIR, 4);
            //outtextxy(300,200,keyword);
        }
        else if(pd(278,25,70,50)&&M_sc > 0)//新建文件夾功能
        {
            setcolor(BLACK);
            line(x-10,y-2+num*15,x+2+100,y-2+num*15);
            line(x-10,y+2+num*15+10,x+2+100,y+2+num*15+10);
            line(x-10,y-2+num*15,x-10,y+2+num*15+10);
            line(x+2+100,y-2+num*15,x+2+100,y+2+num*15+10);
            new_draw_file(fatherNode,num,1);
        }
        else if(pd(350,25,49,50)&&M_sc > 0)//新建文件功能
        {
            setcolor(BLACK);
            line(x-10,y-2+num*15,x+2+100,y-2+num*15);
            line(x-10,y+2+num*15+10,x+2+100,y+2+num*15+10);
            line(x-10,y-2+num*15,x-10,y+2+num*15+10);
            line(x+2+100,y-2+num*15,x+2+100,y+2+num*15+10);
            new_draw_file(fatherNode,num,0);
        }
        else if(pd(211,25,65,50)&&M_sc > 0)//重名命功能
        {
            temp=fatherNode->son_list_head;
            for(temp;temp!=NULL;temp=temp->next)
            {
                if(getonebit(temp->flag,1)==1)
                {
                    temp1=temp;
                    break;
                }
            }
            if(temp1!=NULL)
            {
                n_cf=count_the_node(fatherNode->son_list_head,temp1)-1;
                setfillstyle(1,WHITE);
                bar(x,y-2+n_cf*15,700,y-2+n_cf*15+18);
                line(x,y-2+n_cf*15,x+2+100,y-2+n_cf*15);
                line(x,y+2+n_cf*15+10,x+2+100,y+2+n_cf*15+10);
                line(x,y-2+n_cf*15,x,y+2+n_cf*15+10);
                line(x+2+100,y-2+n_cf*15,x+2+100,y+2+n_cf*15+10);
                My_rename(temp1,key(x+1,y-2+n_cf*15,x+1+100,y+2+n_cf*15+10,0));
                drawfile(fatherNode,0);
                //unselect_all(fatherNode->son_list_head);
            }
            else
            {

            }
        }
        else if(pd(158,25,51,50)&&M_sc > 0)//删除功能
        {
            temp=fatherNode->son_list_head;
            for(temp;temp!=NULL;temp=temp->next)
            {
                if(getonebit(temp->flag,1)==1)
                {
                    temp1=temp;
                    break;
                }
            }
            if(temp1!=NULL)
            {
                n_cf=count_the_node(fatherNode->son_list_head,temp1)-1;
                delet_next_node(count_to_node(fatherNode->son_list_head,n_cf));
                drawfile(fatherNode,0);
                //unselect_all(fatherNode->son_list_head);
            }
            else
            {
                
            }
        }
        else if(pd(505,25,50,50)&&M_sc > 0)//英文升序功能
        {
            sort_by_name1(fatherNode->son_list_head);
            drawfile(fatherNode,0);
        }
        else if(pd(557,25,55,50)&&M_sc > 0)//英文降序功能
        {
            sort_by_name2(fatherNode->son_list_head);
            drawfile(fatherNode,0);
        }
        else if(pd(453,25,50,50)&&M_sc > 0)//都选功能
        {
            //*select_all_prime=1;
            //select_all(fatherNode->son_list_head);
            draw_all_file(fatherNode);
        }
        else if(pd(0,25,52,50)&&M_sc > 0)//復制功能
        {
            func_copy(fatherNode->son_list_head,paste);
            *paste_prime=1;
            drawfile(fatherNode,0);
        }
        else if(pd(105,25,50,50)&&M_sc > 0)//剪切功能
        {
            func_cut(fatherNode->son_list_head,paste);
            *paste_prime=2;

            temp=fatherNode->son_list_head;
            for(temp;temp!=NULL;temp=temp->next)
            {
                if(getonebit(temp->flag,1)==1)
                {
                    temp1=temp;
                    break;
                }
            }
            if(temp1!=NULL)
            {
                n_cf=count_the_node(fatherNode->son_list_head,temp1)-1; 
                free_next_node(count_to_node(fatherNode->son_list_head,n_cf));
                drawfile(fatherNode,0);
                //unselect_all(fatherNode->son_list_head);
            }
            else
            {
                
            }

        }
        else if(pd(52,25,50,50)&&M_sc > 0)//貼上功能
        {
            func_paste(fatherNode->son_list_head, ph_for_paste, paste, *paste_prime);
            *paste_prime=0;
            drawfile(fatherNode,0);
        }
        else if(pd(401,25,51,50)&&M_sc > 0)//属性功能
        {
            temp=fatherNode->son_list_head;
            for(temp;temp!=NULL;temp=temp->next)
            {
                if(getonebit(temp->flag,1)==1)
                {
                    temp1=temp;
                    break;
                }
            }
            if(temp1!=NULL)
            {   
                draw_attribute(temp1);
                //unselect_all(fatherNode->son_list_head);
            }
            else
            {
                
            }
            //drawfile(fatherNode,0);
        }    
    }
}

/*
    作用：获取右侧显示框点击的文件在该链表下的num
    输入：鼠标的位置
    返回值：无
*/
int getnum(int x,int y)
{
    return (y-115)/15+1;
}