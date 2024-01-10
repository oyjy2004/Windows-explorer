#ifndef _DRAW_H_
#define _DRAW_H_
/* 
	函数功能：畫左边的文件夾
	参数：起始的X,Y,底色color,显示的字串
	返回值：无
*/
void mousein(int x,int y,int color, char *s);


/* 
	函数功能：上側的高亮和功能
	参数：當前鏈表，當前文件數
	返回值：无
*/
void top_side(struct My_filenode* pc,struct My_filenode* fatherNode,struct My_vector_ *paste,struct My_filenode* ph_for_paste,int *paste_prime);


/* 
	函数功能：右側的高亮和功能
	参数：當前鏈表，當前文件數
	返回值：无
*/
void right_side(struct My_filenode* fatherNode,int *num);



/* 
	函数功能：左側的高亮和功能
	参数：BORLANDC
	返回值：无
*/
void left_side(struct My_filenode* fatherNode,struct My_filenode* temp,int*n);


/* 
	函数功能：畫右边的文件夾
	参数：要畫的頭結点,num是第几個文件要高亮,不需要填0
	返回值：畫了多少個(文件數)
*/
int drawfile(struct My_filenode* fatherNode,int num);
/* 
	函数功能：新建文件或文件夾
	参数：建文件的父結点,當前有有多少個文件显示了,filetype為0時建文件,為1建文件夾
	返回值：畫了多少個(文件數)
*/
int draw_all_file(struct My_filenode* fatherNode);

int new_draw_file(struct My_filenode* fatherNode,int n,int filetype);

void draw_attribute(struct My_filenode* fatherNode);


int getnum(int x,int y);

void new_name(struct My_filenode* fatherNode,int n);

void refleshfile();

int pop_error(int pop_type, char *func_name, char *cause, char *object_name);
#endif