#include "include.h"
#include "listset.h"
#include "listbase.h"

/*
	函数功能：初始化变量
	参数：三条文件链表的初始节点，三个vector链表头节点
	返回值：无
*/
void My_init(struct My_filenode **p0, struct My_filenode **ph, struct My_filenode **pc,  struct My_filenode **p0_for_paste, struct My_filenode **ph_for_paste, struct My_filenode **pc_for_paste, struct My_vector_ **paste)
{
	*p0 = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	*ph = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	*pc = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	*p0_for_paste = (struct My_filenode *)malloc(sizeof(struct My_filenode));  
	*ph_for_paste = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	*pc_for_paste = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	*paste = (struct My_vector_ *)malloc(sizeof(struct My_vector_));

	(*p0)->flag = IS_DIR;
	(*p0)->flag += THIS_PC;
	strcpy((*p0)->name, "cidiannao");
	(*p0)->next = NULL;
	(*p0)->father = NULL;
	(*p0)->son_list_head = (*ph);

	(*ph)->flag = H_NODE;
	strcpy((*ph)->name, "headNode");
	(*ph)->next = (*pc);
	(*ph)->father = (*p0);
	(*ph)->son_list_head = NULL;

	(*pc)->flag = IS_DIR;
	(*pc)->flag += C_DISK;
	strcpy((*pc)->name, "C:");
	(*pc)->next = NULL;
	(*pc)->father = (*p0);
	(*pc)->son_list_head = NULL;

	(*p0_for_paste)->flag = IS_DIR;
	(*p0_for_paste)->flag += THIS_PC;
	strcpy((*p0_for_paste)->name, "cidiannao");
	(*p0_for_paste)->next = NULL;
	(*p0_for_paste)->father = NULL;
	(*p0_for_paste)->son_list_head = (*ph_for_paste);

	(*ph_for_paste)->flag = H_NODE;
	strcpy((*ph_for_paste)->name, "headNode");
	(*ph_for_paste)->next = (*pc_for_paste);
	(*ph_for_paste)->father = (*p0_for_paste);
	(*ph_for_paste)->son_list_head = NULL;

	(*pc_for_paste)->flag = IS_DIR;
	(*pc_for_paste)->flag += C_DISK;
	strcpy((*pc_for_paste)->name, "C:");
	(*pc_for_paste)->next = NULL;
	(*pc_for_paste)->father = (*p0_for_paste);
	(*pc_for_paste)->son_list_head = NULL;

	strcpy((*paste)->name, "pheadNode");
	(*paste)->path[0] = '\0';
	(*paste)->next = NULL;

}

/*
	函数功能：结束初始化
	参数：三条文件链表的初始节点，三个vector链表头节点
	返回值：无
*/
void close_init(struct My_filenode *p0, struct My_filenode *ph, struct My_filenode *pc,  struct My_filenode *p0_for_paste, struct My_filenode *ph_for_paste, struct My_filenode *pc_for_paste, struct My_vector_ *paste)
{
	free_vector_list(paste);
	free(p0);
	free(ph);
	free(pc);
	free(p0_for_paste);
	free(ph_for_paste);
	free(pc_for_paste);
	free(paste);
}
/*
	函数功能：为节点的flag赋值
	参数：节点的flag指针，文件名
	返回值：无
*/
void add_type(char *flagp, char *filename)
{
    int i=0;               //计数器
    char type[4]="\0";     //储存文件类型字符串
    for(i=0;filename[i]!='.'&&filename[i]!='\0';)
    {
        i++;
    }
    if(strlen(filename+i+1)>3)
    {

    }
    else
    {
        strcpy(type,filename+i+1);
    }
    if(My_strcmp(type,"TXT")==0)
    {
        *flagp+=TXT;
    }
    else if(My_strcmp(type,"C")==0)
    {
        *flagp+=C;
    }
    else if(My_strcmp(type,"CPP")==0)
    {
        *flagp+=CPP;
    }
    else if(My_strcmp(type,"H")==0)
    {
        *flagp+=H;
    }
    else if(My_strcmp(type,"OBJ")==0)
    {
        *flagp+=OBJ;
    }
    else if(My_strcmp(type,"EXE")==0)
    {
        *flagp+=EXE;
    }
    else if(My_strcmp(type,"PNG")==0)
    {
        *flagp+=PNG;
    }
    else if(My_strcmp(type,"DOC")==0)
    {
        *flagp+=DOC;
    }
    else if(My_strcmp(type,"JPG")==0)
    {
        *flagp+=JPG;
    }
    else if(My_strcmp(type,"PDF")==0)
    {
        *flagp+=PDF;
    }
    else if(My_strcmp(type,"XLS")==0)
    {
        *flagp+=XLS;
    }
    else if(My_strcmp(type,"PPT")==0)
    {
        *flagp+=PPT;
    }
    else
	{
		*flagp += OTHER;
	}
}

/*
	函数功能：清空节点后的vector链表
	参数：不清除的最后一个节点
	返回值：无
*/
void free_vector_list(struct My_vector_ *theNode)
{
	if (theNode == NULL)
	{
		return;
	}
	struct My_vector_ *temp = theNode;
	if (temp->next != NULL)
	{
		free_vector_list(temp->next);
	}
	free_next_node(temp);
}

/*
	函数功能：可以忽略大小写的字符串比较函数
	参数：两个字符串指针
	返回值：1为两个字符串不相等，0为相等
*/
int My_strcmp(char *str1, char *str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return 1;
	}
	int i=0;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] = str1[i] - 32;
		}
		if (str2[i] >= 'a' && str2[i] <= 'z')
		{
			str2[i] = str2[i] - 32;
		}
		if (str1[i] != str2[i])
		{
			return 1;
		}
	}
	return 0;
}

/*
	函数功能：把字符串中所有小写改成大写
	参数：字符串
	返回值：无
*/
void to_capital(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
}


/*
	函数功能：获取任意节点所在链表的表尾节点指针
	参数：任意节点指针
	返回值：所在链表尾部节点指针
*/
struct My_filenode *end_of_list(struct My_filenode *theNode)
{
    struct My_filenode* temp=theNode;
    if(theNode==NULL)
        return NULL;
    for(temp;temp->next!=NULL;)
    {
        temp=temp->next;
    }
    return temp;
}

/*
	函数功能：获取路径并存入buffer字符串
	参数：结构指针，字符串
	返回值：无
*/
//2023.3.13：第一版调试时发现出错
void get_path(struct My_filenode *theNode, char *buffer)
{
    int len=0;
    if(theNode==NULL)
        return;
    strcat(buffer,strrev(theNode->name));
	strrev(theNode->name);
    if(theNode->father->father!=NULL)//如果该节点不是c盘
    {
        strcat(buffer, "\\");
		get_path(theNode->father, buffer);
		strrev(buffer);              //第一次调试时漏了该语句，导致出错
    }
    strrev(buffer);
    len=strlen(buffer);
    buffer[len]='\0';
    return;
}

/*
	函数功能：把一个节点加入剪切版
	参数：节点指针
	返回值：无
*/
struct My_vector_ *add_to_vector_(struct My_vector_ *vhead, struct My_filenode *theNode)
{
	if (theNode == NULL)
	{
		return NULL;
	}
	while (count_nodes(vhead) >= 10)
	{
		free_next_node(vhead);
	}
	struct My_vector_ *tempNode;
	struct My_vector_ *newNode = (struct My_vector_ *)malloc(sizeof(struct My_vector_));
	if (newNode == NULL)
	{
		//pop_error(-1, "ADD_TO_VECTOR:", "malloc return NULL pointer.");
		return NULL;
	}
	for (tempNode = vhead; tempNode->next != NULL; tempNode = tempNode->next)
	{

	}
	char buffer[80];
	buffer[0] = '\0';
	get_path(theNode->father, buffer);
	if (strlen(buffer) == 2)
	{
		strcat(buffer, "\\");
	}
	strcpy(newNode->path, buffer);
	strcpy(newNode->name, theNode->name);
	newNode->next = NULL;
	tempNode->next = newNode;
	return newNode;
}

/*
	函数功能：为一个C盘或文件夹父节点创建其子链头节点
	参数：父节点指针
	返回值：建立的子链头节点
*/
struct My_filenode *creat_son_list(struct My_filenode *fatherNode)
{
    if(fatherNode==NULL)
    {
        return NULL;
    }
    if((fatherNode->flag & IS_DIR)==0)
    {
        return NULL;
    }
    struct My_filenode *temp=(struct My_filenode *)malloc(sizeof(struct My_filenode));
    fatherNode->son_list_head=temp;
    temp->father=fatherNode;
    temp->next=NULL;
    temp->son_list_head=NULL;
    temp->flag=H_NODE;
    strcpy(temp->name,"HeadNode");
    return temp;
}

/*
	函数功能：在任意节点末尾接上一个节点并赋值
	参数：任意节点指针
	返回值：新建的尾部节点指针
*/
struct My_filenode *add_at_end(struct My_filenode *theNode, struct ffblk *ff)
{
    if(theNode==NULL)
    {
        return NULL;
    }
    struct My_filenode *end;
    struct My_filenode *temp=(struct My_filenode*)malloc(sizeof(struct My_filenode));
    if(temp==NULL)
    {
       // pop_error(-1, "ADD_AT_END:", "malloc return NULL pointer.");
		return NULL;
    }
    if(theNode->next==NULL)
    {
        end=theNode;
    }
    else
    {
        end=end_of_list(theNode);
    }
    if (ff->ff_attrib & FA_DIREC)
	{
		temp->flag = IS_DIR;
		temp->flag += DIC;
	}
    else
    {
        temp->flag=0;
        add_type(&(temp->flag),ff->ff_name);
    }
    end->next = temp;
    temp->next=NULL;
    temp->son_list_head=NULL;
    temp->father=end->father;
    strcpy(temp->name, ff->ff_name);
    return temp;
}

/*
	函数功能：为一个父节点删除子链头节点
	参数：父节点指针
	返回值：无
*/
void free_son_list_head(struct My_filenode *fatherNode)
{
    free(fatherNode->son_list_head);
	fatherNode->son_list_head = NULL;
}

/*
	函数功能：释放链表(不包括头节点)
	参数：头节点指针
	返回值：无
*/
void free_list(struct My_filenode *headNode)
{
    if (headNode == NULL)
	{
		return;
	}
	if (headNode->next == NULL)
	{
		return;
	}
	if (headNode->next->son_list_head != NULL) //如果删除的节点拥有子链，就对该节点使用此函数，然后把此函数无法删除的头节点释放
	{
		free_list(headNode->next->son_list_head);
		free_son_list_head(headNode->next);
	}
	if (headNode->next->next != NULL)
	{
		free_list(headNode->next);
	}
	free_next_node(headNode);
	headNode->next = NULL;
}

/*
	函数功能：释放参数节点的下一个节点
	参数：上一个节点指针
	返回值：无
*/
void free_next_node(struct My_filenode *frontNode)
{
	if (frontNode == NULL)
	{
		return;
	}
	if (frontNode->next == NULL)
	{
		return;
	}
	struct My_filenode *temp = frontNode->next;
	frontNode->next = temp->next;
	if (temp->son_list_head != NULL)
	{
		free_list(temp->son_list_head);
		free_son_list_head(temp);
	}
	free(temp);
}

void free_next_node(struct My_vector_ *frontNode)
{
	if (frontNode == NULL)
	{
		return;
	}
	if (frontNode->next == NULL)
	{
		return;
	}
	struct My_vector_ *temp = frontNode->next;
	frontNode->next = temp->next;
	free(temp);
}

/*
	函数功能：删除参数节点的下一个节点
	参数：上一个节点指针
	返回值：无
*/
void delet_next_node(struct My_filenode *frontNode)
{
	if (frontNode == NULL)
	{
		return;
	}
	if (frontNode->next == NULL)
	{
		return;
	}
	struct My_filenode *temp = frontNode->next;
	struct ffblk ff;
	int done;
	if (temp->flag & IS_DIR)
	{
		char buffer[80];
		buffer[0] = '\0';
		get_path(temp, buffer);
		done = findfirst(buffer, &ff, FA_DIREC);
		if (done == -1)
		{
			//pop_error(-1, "DELET_NEXT_NODE:", "failed to find file:", temp->name);
			return;
		}
		find_all_sub_file(temp);
		delet_list(temp->son_list_head);
		buffer[0] = '\0';
		get_path(temp->father, buffer);
		if (strlen(buffer) == 2)
		{
			strcat(buffer, "\\");
		}
		done = chdir(buffer);
		if (done == -1)
		{
			//pop_error(-1, "DELET_NEXT_NODE:", "chdir failed:", buffer);
			return;
		}
		done = rmdir(temp->name);
		if (done == -1)
		{
			//pop_error(-1, "DELET_NEXT_NODE:", "rmdir failed:", temp->name);
			return;
		}
	}
	else
	{
		char buffer[80];
		buffer[0] = '\0';
		get_path(temp, buffer);
		done = findfirst(buffer, &ff, FA_DIREC);
		if (done == -1)
		{
			//pop_error(-1, "DELET_NEXT_NODE:", "failed to find file:", temp->name);
			return;
		}
		buffer[0] = '\0';
		get_path(temp->father, buffer);
		if (strlen(buffer) == 2)
		{
			strcat(buffer, "\\");
		}
		done = chdir(buffer);
		if (done == -1)
		{
			//pop_error(-1, "DELET_NEXT_NODE:", "chdir failed:", buffer);
			return;
		}
		done = remove(temp->name);
		if (done == -1)
		{
			//pop_error(-1, "DELET_NEXT_NODE:", "remove failed:", temp->name);
			return;
		}
	}

	frontNode->next = temp->next;
	free_list(temp->son_list_head);
	free_son_list_head(temp);
	free(temp);
}

/*
	函数功能：删除此头节点后所有文件和节点
	无法释放参数头节点，与free_son_list_head一起用
	参数：头节点指针
	返回值：无
*/
void delet_list(struct My_filenode *headNode)
{
	if (headNode == NULL)
	{
		return;
	}
	if (headNode->next == NULL)
	{
		return;
	}
	if (headNode->next->son_list_head != NULL) //如果删除的节点拥有子链，就对该节点使用此函数，然后把此函数无法删除的头节点释放
	{
		delet_list(headNode->next->son_list_head);
		free_son_list_head(headNode->next);
	}
	if (headNode->next->next != NULL)
	{
		delet_list(headNode->next);
	}

	delet_next_node(headNode);
}

/*
	函数功能：为一个父节点查找并创建子链
	参数：父节点指针
	返回值：无
*/
void find_all_file(struct My_filenode *fatherNode)
{
    if(fatherNode==NULL)
    {
        return;
    }
    if((fatherNode->flag) & (IS_DIR)==0)
    {
        return;
    }
    struct My_filenode *temp = (struct My_filenode*)malloc(sizeof(struct My_filenode));
    if(fatherNode->son_list_head!=NULL)
    {
        free_list(fatherNode->son_list_head);
        temp=fatherNode->son_list_head;
    }
    else
    {
        temp=creat_son_list(fatherNode);
    }
    int count=0;                  //用来记录节点数
    char buffer[80]="\0";       //用来记录文件地址
    struct ffblk ff;            //用来记录文件数据
    get_path(fatherNode,buffer);
    if(strlen(buffer)==2)
    {
        strcat(buffer,"\\");
    }
    if(chdir(buffer)==0)
    {

    }
    else
    { 
        return;
    }
    findfirst("*.*",&ff,FA_DIREC);
    findnext(&ff);                      //排除.和..文件
    while(findnext(&ff)==0&&count<1000)
    {
        temp = add_at_end(temp, &ff);
		count++;
		/*if (count == 1000)
		{
			if (pop_error(0, "FIND_ALL_FILE:", "1000 file scanned,coninue?", fatherNode->name))
			{
				count = 0;
			}
		}*/
    }
}

void seach_all_file(struct My_filenode *fatherNode)
{
	if (fatherNode == NULL)
	{
		return;
	}
	if ((fatherNode->flag & IS_DIR)==0)
	{
		return;
	}
	struct My_filenode *temp;
	if (fatherNode->son_list_head != NULL)
	{
		free_list(fatherNode->son_list_head);
		temp = fatherNode->son_list_head;
	}
	else
	{
		temp = creat_son_list(fatherNode);
	}
	struct ffblk ff;
	int count = 0;
	char buffer[80];
	buffer[0] = '\0';
	get_path(fatherNode, buffer);
	if (strlen(buffer) == 2)
	{
		strcat(buffer, "\\");
	}
	if (chdir(buffer) == 0)
	{

	}
	else
	{
		return;
	}
	findfirst("*.*", &ff, FA_DIREC); 
	findnext(&ff);					   //排除.和..文件
	while (findnext(&ff) == 0 && count < 100)
	{
		temp = add_at_end(temp, &ff);
		count++;
	}
}

/*
	函数功能：计算文件夹下的文件数目
	参数：父节点指针
	返回值：文件数目
*/
int count_all_file(struct My_filenode *fatherNode)
{
	if (fatherNode == NULL)
	{
		return 0;
	}
	if (!(fatherNode->flag & IS_DIR))
	{
		return 0;
	}
	struct My_filenode *temp;
	struct ffblk ff;
	int done, count = 0;
	char buffer[80];
	buffer[0] = '\0';
	get_path(fatherNode, buffer);
	if (strlen(buffer) == 2)
	{
		strcat(buffer, "\\");
	}
	done = chdir(buffer);
	if (done == -1)
	{
		return 0;
	}
	findfirst("*.*", &ff, FA_DIREC); 
	findnext(&ff);					   //排除.和..文件 
	while (findnext(&ff) == 0)
	{
		count++;
	}
	return count;
}

/*
	函数功能：为一个父节点查找并创建所有子链和子链的子链
	参数：父节点指针
	返回值：无
*/
void find_all_sub_file(struct My_filenode *fatherNode)
{
    if(fatherNode==NULL)
    {
        return;
    }
    if(fatherNode->flag & IS_DIR==0)
    {
        return;
    }
    struct My_filenode* temp;
    if(fatherNode->son_list_head!=NULL)
    {
        free_list(fatherNode->son_list_head);
        temp=fatherNode->son_list_head;
    }
    else
    {
        temp=creat_son_list(fatherNode);
    }
    struct ffblk ff;
	char buffer[80]="\0";
	get_path(fatherNode, buffer);
	if (strlen(buffer) == 2)
	{
		strcat(buffer, "\\");
	}
	if (chdir(buffer) == 0)
	{

	}
	else
	{
		return;
	}
	findfirst("*.*", &ff, FA_DIREC); 
	findnext(&ff);					 //排除.和..文件
	while (findnext(&ff) == 0)
	{
		temp = add_at_end(temp, &ff);
		if (!(temp == fatherNode->son_list_head))
		{
			//当前目录遇到一个文件夹就为它创建子链，创建完成后继续上一级的while创建之后的文件节点
			if (temp->flag & IS_DIR)
			{
				find_all_sub_file(temp);
			}
		}
	}
}

void find_max_sub_file(struct My_filenode *fatherNode, int *count, int max)
{
    if (fatherNode == NULL)
	{
		return;
	}
	if ((fatherNode->flag & IS_DIR)==0)
	{
		return;
	}
	struct My_filenode *temp;
	if (fatherNode->son_list_head != NULL)
	{
		free_list(fatherNode->son_list_head);
		temp = fatherNode->son_list_head;
	}
	else
	{
		temp = creat_son_list(fatherNode);
	}
	struct ffblk ff;
	char buffer[80]="\0";
	get_path(fatherNode, buffer);
	if (strlen(buffer) == 2)
	{
		strcat(buffer, "\\");
	}
	if (chdir(buffer) == 0)
	{

	}
	else
	{
		return;
	}
	findfirst("*.*", &ff, FA_DIREC); 
	findnext(&ff);					 //排除.和..文件
	while (findnext(&ff) == 0)
	{
		if ((*count) >= max)
		{
			break;
		}
		temp = add_at_end(temp, &ff);
		(*count)++;
		if (!(temp == fatherNode->son_list_head))
		{
			//当前目录遇到一个文件夹就为它创建子链，创建完成后继续上一级的while创建之后的文件节点
			if (temp->flag & IS_DIR)
			{
				find_max_sub_file(temp, count, max);
			}
		}
	}
}

/*
	函数功能：为一个父节点查找文件夹并创建子链
	参数：父节点指针
	返回值：无
*/
void find_all_dir(struct My_filenode *fatherNode)
{
	if (fatherNode == NULL)
	{
		return;
	}
	if (!(fatherNode->flag & IS_DIR))
	{
		return;
	}
	struct My_filenode *temp;
	if (fatherNode->son_list_head != NULL)
	{
		free_list(fatherNode->son_list_head);
		temp = fatherNode->son_list_head;
	}
	else
	{
		temp = creat_son_list(fatherNode);
	}
	struct ffblk ff;
	char buffer[80];
	buffer[0] = '\0';
	get_path(fatherNode, buffer);
	if (strlen(buffer) == 2)
	{
		strcat(buffer, "\\");
	}
	if (chdir(buffer) == 0)
	{
	}
	else
	{
		return;
	}
	findfirst("*.*", &ff, FA_DIREC);
	findnext(&ff);
	while (findnext(&ff) == 0)
	{
		if (ff.ff_attrib & FA_DIREC)
		{
			temp = add_at_end(temp, &ff);
		}
	}
}

/*
	函数功能：查找是否有同名文件
	参数：被查找链表的头节点，查找的文件名
	返回值：存在同名文件返回1，不存在返回0，出错返回-1
*/
int find_name(struct My_filenode *headNode, char *filename)
{
    if(headNode==NULL)
    {
        return -1;
    }
    struct My_filenode* temp=headNode->next;
    for(temp;temp != NULL;temp=temp->next)
    {
        if(My_strcmp(filename, temp->name)==0)
        {
            return 1;
        }
    }
    return 0;
}

struct My_filenode *find_file_by_name(struct My_filenode *headNode, char *filename,int *num)
{
    if(headNode==NULL)
    {
        return NULL;
    }
    struct My_filenode* temp=headNode->next;
    for(temp;temp != NULL;temp=temp->next)
    {
		*num=count_the_node(headNode,temp);
        if(My_strcmp(filename, temp->name)==0)
        {
            return temp;
        }
    }
    return NULL;
}

/*
	函数功能：复制文件内容
	参数：目的文件，被复制文件
	返回值：无
*/
void copy_file_content(struct My_filenode *destNode, struct My_filenode *srcNode)
{
	if (destNode == NULL)
	{
		return;
	}
	if (srcNode == NULL)
	{
		return;
	}
	FILE *dest, *src;
	char dpath[80];
	char spath[80];
	dpath[0] = '\0';
	get_path(destNode, dpath);
	spath[0] = '\0';
	get_path(srcNode, spath);
	dest = fopen(dpath, "wb");
	src = fopen(spath, "rb");
	if (dest == NULL || src == NULL)
	{
		//pop_error(-1, "COPY_FILE_CONTENT:", "open file failed.");
		fclose(dest);
		fclose(src);
		return;
	}
	void *buf;
	buf = malloc(1);
	if (buf == NULL)
	{
		//pop_error(-1, "COPY_FILE_CONTENT:", "malloc return NULL pointer:", srcNode->name);
		free(buf);
		fclose(dest);
		fclose(src);
		return;
	}
	while (fread(buf, 1, 1, src) != 0)
	{
		fwrite(buf, 1, 1, dest);
	}
	free(buf);
	fclose(dest);
	fclose(src);
}

/*
	函数功能：新建文件或文件夹
	参数：要新建在的目录的节点的子链头节点，文件名，文件类型（1是文件夹，0是文件），src文件指针（默认为NULL，默认则不复制内容，反之把src文件的内容复制进新文件中）
	返回值：新建的节点
*/
struct My_filenode *new_file(struct My_filenode *headNode, char *filename, int filetype, struct My_filenode *srcNode)
{
	
	if (headNode == NULL)
	{
		
		delay(1000);
		return NULL;
	}
	int prime, done;
	char add[3];
	char tempn[13];
    to_capital(filename);
	strcpy(tempn, filename);
	struct My_filenode *newNode = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	if (newNode == NULL)
	{
		//printf("aaaaa");
		//pop_error(-1, "NEW_FILE:", "malloc return NULL pointer.");
		return NULL;
	}
	if (filetype == 1)
	{
		char buffer[80];
		buffer[0] = '\0';
		get_path(headNode->father, buffer);
		if (strlen(buffer) == 2)
		{
			strcat(buffer, "\\");
		}
		done = chdir(buffer);
		if (done == -1)
		{
			//pop_error(-1, "NEW_FILE:", "chdir failed:", buffer);
			return NULL;
		}
		while (1) //查找是否有同名文件
		{
			prime = find_name(headNode, tempn);
			if (prime == -1)
			{
				return NULL;
			}
			else if (prime == 0)
			{
				break;
			}
			else
			{
				strcat(tempn, "-C");   //如果同名加-C（C代表COPY副本）（真正的文件管理器是加-副本）
				if (strlen(tempn) > 8) //可以重复加直到文件名超过8个字符
				{
					return NULL;
				}
			}
		}
		strcpy(filename, tempn);
		done = mkdir(filename);
		if (done == -1)
		{
			//pop_error(-1, "NEW_FILE:", "mkdir failed:", filename);
			return NULL;
		}
		struct My_filenode *endNode;

		if (headNode->next != NULL)
		{
			endNode = end_of_list(headNode);
		}
		else
		{
			endNode = headNode;
		}
		endNode->next = newNode;
		newNode->next = NULL;
		newNode->father = endNode->father;
		newNode->son_list_head = NULL;
		strcpy(newNode->name, filename);
		newNode->flag = IS_DIR;
		newNode->flag += DIC;
	}
	else
	{
		int have_typ = 0;
		char typ[4]; //存储文件后缀名
		int i=0;
		for (i = 0; i < 12 && filename[i] != '\0' && filename[i] != '.'; i++)
			;
		if (filename[i] == '.' && strlen(&filename[i + 1]) <= 3 && strlen(&filename[i + 1]) != 0)
		{
			have_typ = 1;
			strcpy(typ, &filename[i + 1]);
		}
		else
		{
			typ[0] = '\0';
		}
		char buffer[80];
		buffer[0] = '\0';
		get_path(headNode->father, buffer);
		if (strlen(buffer) == 2)
		{
			strcat(buffer, "\\");
		}
		done = chdir(buffer);
		if (done == -1)
		{
			//pop_error(-1, "NEW_FILE:", "chdir failed:", buffer);
			return NULL;
		}
		while (1)
		{
			prime = find_name(headNode, tempn);
			if (prime == -1)
			{
				return NULL;
			}
			else if (prime == 0)
			{
				break;
			}
			else
			{
				if (have_typ)
				{
					if (strlen(tempn) > 12)
					{
						return NULL;
					}
				}
				else
				{
					if (strlen(tempn) > 8)
					{
						return NULL;
					}
				}
				tempn[i] = '\0';
				strcat(tempn, "-C");
				if (have_typ)
				{
					strcat(tempn, ".");
					strcat(tempn, typ);
				}
				i += 2;
				if (i >= 8)
				{
					return NULL;
				}
			}
		}
		strcpy(filename, tempn);
		done = creatnew(filename, 0);
		
		if (done == -1)
		{
			//pop_error(-1, "NEW_FILE:", "creatnew failed:", filename);
			return NULL;
		}
		else
		{
			close(done);
		}
		struct My_filenode *endNode;
		if (headNode->next != NULL)
		{
			endNode = end_of_list(headNode);
		}
		else
		{
			endNode = headNode;
		}
		endNode->next = newNode;
		newNode->next = NULL;
		newNode->father = endNode->father;
		newNode->son_list_head = NULL;
		strcpy(newNode->name, filename);
		newNode->flag = 0;
		add_type(&newNode->flag, filename);
	}
	if (srcNode != NULL && filetype == 0)
	{
		copy_file_content(newNode, srcNode);
	}
	return newNode;
}

/*
	函数功能：通过路径找目录
	参数：绝对路径（如"c:\\code\\a"）
	返回值：如果找不到则返回NULL，如果路径终点不是文件夹返回NULL，如果成功返回该目录子链头节点
*/
struct My_filenode *find_node_by_path(struct My_filenode *ph, char *apath)
{
	if (apath[0] == '\0')
	{
		return ph;
	}
	if (ph == NULL)
	{
		return NULL;
	}
	if (strlen(apath) > 50)
	{
		return ph;
	}
	char tempbuf[81];
	tempbuf[0] = '\0';
	strcpy(tempbuf, apath);
	if (strlen(tempbuf) == 2)
	{
		strcat(tempbuf, "\\");
	}
	tempbuf[strlen(tempbuf) + 2] = '\0';
	char *tpath = tempbuf;
	char *pmove = tempbuf;
	int n, i = 0;
	struct My_filenode *fpmove;
	struct My_filenode *temph;
	struct My_filenode *findres = ph;
	while (*tpath != '\0')
	{
		for (n = 0; pmove[i] != '\\' && pmove[i] != '\0' && n < 14; i++, n++)
			;
		if (n == 14)
		{
			return ph;
		}
		pmove[i] = '\0';
		fpmove = findres;
		temph = findres;
		n = count_nodes(findres);
		for (; n > 0; n--)
		{
			fpmove = fpmove->next;
			if (My_strcmp(fpmove->name, tpath) == 0)
			{
				free_list(fpmove);
				free_except_end(fpmove->father->son_list_head);
				find_all_file(fpmove);
				findres = fpmove->son_list_head;
				tpath = &pmove[i + 1];
				pmove = tpath;
				i = 0;
				break;
			}
		}
		if (temph == findres)
		{
			return findres;
		}
	}
	return findres;
}

void free_except_end(struct My_filenode *headNode)
{
	while (count_nodes(headNode) > 1)
	{
		free_next_node(headNode);
	}
}

/*
	函数功能：计算链表的节点数
	参数：链表头节点
	返回值：节点数
*/
int count_nodes(struct My_filenode *headNode)
{
    int num=0;
    struct My_filenode *temp = headNode;
    for(temp;temp->next!=NULL;temp=temp->next)
    {
        num++;
    }
    return num;
}

int count_nodes(struct My_vector_ *headNode)
{
	int n = 0;
	int limit = 0;
	struct My_vector_ *temp = headNode;
	for (; temp->next != NULL; temp = temp->next)
	{
		n++;
		limit++;
		if (limit > 800)
		{
			return 0;
		}
	}
	return n;
}

/*
	函数功能：计算该节点是此链的第几个
	参数：该链头节点，计算节点
	返回值：第几个，如果找不到则返回0
*/
int count_the_node(struct My_filenode *headNode, struct My_filenode *theNode)
{
    if (headNode == NULL)
	{
		return 0;
	}
    int n=0;
    struct My_filenode*temp=headNode;
    for (temp; temp->next != NULL; temp = temp->next)
	{
		n++;
		if (temp->next == theNode)
            return n;
	}
	return 0;
}

int count_the_node(struct My_vector_ *headNode, struct My_vector_ *theNode)
{
	if (headNode == NULL)
	{
		return 0;
	}
	int c = 0;
	struct My_vector_ *temp = headNode;
	for (; temp->next != NULL; temp = temp->next)
	{
		c++;
		if (temp->next == theNode)
		{
			return c;
		}
	}
	return 0;
}

/*
	函数功能：一直数到第几个节点
	参数：头节点指针，第几个
	返回值：第几个节点的指针
*/
struct My_filenode *count_to_node(struct My_filenode *headNode, int n)
{
    
	int i=0;
	struct My_filenode *temp=headNode;
    if(n>count_nodes(headNode))
    {
        return NULL;
    }
    for(i=0 ; i<n ; i++)
    {
        temp=temp->next;
    }
    return temp;
}

struct My_vector_ *count_to_node(struct My_vector_ *headNode, int n)
{
	struct My_vector_ *temp = headNode;
	if (n > count_nodes(headNode))
	{
		return NULL;
	}
	int i=0;
	for (i = 0; i < n; i++)
	{
		if (temp->next == NULL)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

/*
	函数功能：获得文件大小以b返回
	参数：文件节点指针
	返回值：字节数
*/
int get_file_bsize(struct My_filenode *theNode)
{
	struct ffblk ff;
	char buffer[80];
	buffer[0] = '\0';
	get_path(theNode, buffer);
	findfirst(buffer, &ff, FA_DIREC);
	return (int)ff.ff_fsize;
}

/*
	函数功能：获得文件大小以kb返回
	参数：文件节点指针
	返回值：kb数
*/
long int get_file_kbsize(struct My_filenode *theNode)
{
	struct ffblk ff;
	long int s;
	char buffer[80];
	buffer[0] = '\0';
	get_path(theNode, buffer);
	findfirst(buffer, &ff, FA_DIREC);
	s = (long int)ff.ff_fsize / 1024;
	if ((long int)ff.ff_fsize % 1024)
	{
		s++;
	}
	//if (s < 0)
	//{
	//	s = 0;
	//}
	return s;
}

/*
	函数功能：获得文件时间存在结构中
	参数：节点指针
	返回值：文件时间结构指针
*/
struct Filetime *get_file_time(struct My_filenode *theNode)
{
	struct ffblk ff;
	struct Filetime *temp = (struct Filetime *)malloc(sizeof(struct Filetime));
	char buffer[25];
	buffer[0] = '\0';
	get_path(theNode, buffer);
	findfirst(buffer, &ff, FA_DIREC);
	temp->s = (0xF & ff.ff_ftime) * 2;
	temp->min = (0x7E0 & ff.ff_ftime) >> 5;
	temp->h = (0xf800 & ff.ff_ftime) >> 11;
	temp->d = 0x1f & ff.ff_fdate;
	temp->month = (0x1e0 & ff.ff_fdate) >> 5;
	temp->y = ((0xfe00 & ff.ff_fdate) >> 9) + 1980;
	return temp;
}

/*
	函数功能：把vector节点转化为对应的filenode节点
	参数：ph节点，vector节点
	返回值：filenode节点
*/
struct My_filenode *vector_to_filenode(struct My_filenode *ph, struct My_vector_ *vnode)
{
	struct My_filenode *temph;
	struct My_filenode *tempp;
	temph = find_node_by_path(ph, vnode->path);
	for (tempp = temph->next; tempp != NULL; tempp = tempp->next)
	{
		if (My_strcmp(tempp->name, vnode->name) == 0)
		{
			return tempp;
		}
	}
	return tempp;
}

/*
	函数功能：全不选文件
	参数：头节点
	返回值：无
*/
void unselect_all(My_filenode *headNode) 
{
	My_filenode *tempp;
	for (tempp = headNode->next; tempp != NULL; tempp = tempp->next)
	{
		tempp->flag &= 127;
	}
}

/*
	函数功能：全选文件
	参数：头节点
	返回值：无
*/
void select_all(My_filenode *headNode)
{
	My_filenode *tempp;
	for (tempp = headNode->next; tempp != NULL; tempp = tempp->next)
	{
		tempp->flag |= 128;
	}
}

/*
	函数功能：读取文件时间和大小（kb），返回时间结构，把大小存入参数指针中
	参数：文件节点，int指针
	返回值：Filetime节点指针
*/
struct Filetime *get_file_base(struct My_filenode *theNode, int *size)
{
	struct ffblk ff;
	struct Filetime *temp = (struct Filetime *)malloc(sizeof(struct Filetime));
	char buffer[25];
	buffer[0] = '\0';
	get_path(theNode, buffer);
	findfirst(buffer, &ff, FA_DIREC);
	temp->s = (0xF & ff.ff_ftime) * 2;
	temp->min = (0x7E0 & ff.ff_ftime) >> 5;
	temp->h = (0xf800 & ff.ff_ftime) >> 11;
	temp->d = 0x1f & ff.ff_fdate;
	temp->month = (0x1e0 & ff.ff_fdate) >> 5;
	temp->y = ((0xfe00 & ff.ff_fdate) >> 9) + 1980;
	(*size) = (int)ff.ff_fsize / 1024;
	if ((int)ff.ff_fsize % 1024)
	{
		(*size)++;
	}
	if ((*size) < 0)
	{
		(*size) = 0;
	}
	return temp;
}

/*
	函数功能：在该链表通过节点名称得到该节点
	参数：链表头节点，节点名称
	返回值：所需节点
*/
struct My_filenode* get_node_by_name(struct My_filenode*headNode,char* name)
{
	struct My_filenode*temp=headNode->next;
	for(temp;temp!=NULL;temp=temp->next)
	{
		if(strcmp(name,temp->name)==0)
		{
			break;
		}
	}
	return temp;
}