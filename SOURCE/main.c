#include <mygraph.h>
#include "page.h"
#include "listbase.h"
#include<stdio.h>
#include"draw.h"
#include"bite.h"
#include"key.h"

int main(void)
{	
    struct My_filenode *p0;				  //此电脑指针，作为父级读取的终点指针，
	//struct My_filenode *p0_for_dir;		  //此电脑目录指针，作为父级读取的终点指针
	struct My_filenode *p0_for_paste;	  //此电脑粘贴板指针，作为父级读取的终点指针
	struct My_filenode *ph;				  // C盘指针，相当于根目录，但是只是一个根
	//struct My_filenode *ph_for_dir;		  // C盘所有目录指针，是所有目录链表的头节点指针
	struct My_filenode *ph_for_paste;	  //后端操作，指向被复制处的指针，从而将pc_for_paste所指内容复制到此处
	struct My_filenode *pc;				  // 对于主文件区显示
	//struct My_filenode *pc_for_dir;		  // C盘所有目录
	struct My_filenode *pc_for_paste;	  //暂时的粘贴板指针，用到粘贴板的时候建立链表，不用就释放
	struct My_filenode *cf=NULL;				  
	struct My_filenode *bf=NULL;
	struct My_filenode *nf=NULL;
	struct My_filenode *searh_name=NULL;
	//struct My_vector_ *search;		//保存搜索结果，保存链表的头结点的指针
	struct My_vector_ *paste;		//粘贴板，指向粘贴板链表头节点的指针
	//struct My_vector_ *history;		//历史记录，指向历史记录（对于打开的目录的历史）的头结点指针
	//struct My_vector_ *currenthead; //指向history链的当前显示的目录对应的history节点，记录绝对路径
	char* buffer="\0";
	char name[15]={0};
    //char sort_way=0 ; //排序方式
	int n=0;
	int num_cf=0;
	int paste_prime=0;
	int search_num=0;
	initscreen();
   	initmouse(1);
	show_mouse(); 
	s_one();
   	My_init(&p0, &ph, &pc, &p0_for_paste, &ph_for_paste, &pc_for_paste, &paste);
    find_all_file(pc);
	cf=pc;

	getmouse();
	while(1)
	{	
		if(pd(0,77,30,30)&&M_s==1&&cf->father!=NULL&&cf->father!=pc)
			{
				//cf=该文件夹上一级
				//nf=该文件夹
				bf=NULL;
				nf=cf;
				cf=nf->father;
				drawfile(cf,0);
				delay(150);
			}
		if(pd(31,77,30,30)&&M_s==1&&nf!=NULL)
			{
				bf=cf;
				cf=nf;
				nf=NULL;
				drawfile(cf,0);
				delay(150);
			}
		if(pd(505,80,150,20)&&M_sc > 0)//搜索
		{
			strcpy(name,key(506,80,634,100,0));
			setcolor(BLACK);
			settextstyle(SMALL_FONT, HORIZ_DIR, 4);
			if(find_name(cf->son_list_head, name)==1)
			{
				searh_name=find_file_by_name(cf->son_list_head,name,&search_num);
				//printf("%d",search_num);
				set1onebit(&(searh_name->flag),1);
				drawfile(cf,search_num);		
			}
			else
			{
				unselect_all(cf->son_list_head);
				drawfile(cf,0);
			}
			search_num=0;
		}
		
		while(pd(0,118,700,500))
		{	
			if(cf!=pc&&(cf->flag&16)==0)
			{
				find_all_file(cf);
				drawfile(cf,0);
				set1onebit(&(cf->flag),4);
			}
			if(M_s==2&&pd(0,115,140,10))
			{
				//if(bf!=pc)
				//{
				//	free_list(bf->son_list_head);
				//	free_son_list_head(bf);
				//}
				//set0onebit(&(cf->flag),4);
				bf=cf;
				//cf=pc->son_list_head->next;
				cf=get_node_by_name(pc->son_list_head,"BORLANDC");
				drawfile(cf,0);
			}
			else if(M_s==2&&pd(0,125,140,10))
			{
				//if(bf!=pc)
				//{
				//	free_list(bf->son_list_head);
				//	free_son_list_head(bf);
				//}
				//set0onebit(&(cf->flag),4);
				bf=cf;
				cf=get_node_by_name(pc->son_list_head,"TEST");
				drawfile(cf,0);
			}
			if(cf!=pc)
			{
				if(M_s==2&&pd(140,115,500,365))
				{
					n=getnum(M_x,M_y);
					if(count_to_node(cf->son_list_head,n)->flag & 64&& count_nodes(cf->son_list_head)>=n)
					{
						bf=cf;
						cf=count_to_node(bf->son_list_head,n);
						delay(150);
						drawfile(cf,0);
					}
				}
			}
			while(M_s==1)
			{
				if(pd(140,118,700,500))
				{
					if(cf==pc)
					{
						break;
					}
					else
					{
						n=getnum(M_x,M_y);
						if(n<=count_nodes(cf->son_list_head))
						{
							unselect_all(cf->son_list_head);
							set1onebit(&(count_to_node(cf->son_list_head,n)->flag),1);
							if(getonebit(count_to_node(cf->son_list_head,n)->flag,1))
							{
								drawfile(cf,n);
							}	
						}
						else
						{
							unselect_all(cf->son_list_head);
							drawfile(cf,0);
						}
					}
				}
				getmouse();
			}
			getmouse();
		}
		while(pd(0,0,700,76))
		{
			top_side(pc,cf,paste,ph_for_paste,&paste_prime);
			if(M_s==1)
			{
				if(pd(610,0,29,25))
				{
					free_list(pc->son_list_head);
					free_son_list_head(pc);
					close_init(p0,ph,pc,p0_for_paste,ph_for_paste,pc_for_paste,paste);
					return 0;
				}
			}
			getmouse();
		}
		getmouse();
	}
	free_list(pc->son_list_head);
	free_son_list_head(pc);
	close_init(p0,ph,pc,p0_for_paste,ph_for_paste,pc_for_paste,paste);
    return 0;
}