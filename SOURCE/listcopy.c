#include "listbase.h"
#include "listcopy.h"
#include "include.h"

/*
	函数功能：复制节点到目录下
	参数：目标目录头节点，被复制节点
	返回值：0表示操作成功，-1表示操作失败
*/
int paste_node_to_dir(struct My_filenode *headNode, struct My_filenode *copyNode)
{
	if (headNode == NULL)
	{
		return -1;
	}
	if (copyNode == NULL)
	{
		return -1;
	}
	int t = 0;
	if (copyNode->flag & IS_DIR)
	{
		t = 1;
	}
	int n = 0;
	int r = 0;
	if (t == 1)
	{
		n = count_nodes(copyNode->son_list_head);
		if(n>10)
		{
			n=10;
		}
	}
	char tempc[13];
	strcpy(tempc, copyNode->name);
	//struct My_filenode *temp = new_file(headNode, tempc, t, copyNode);
	struct My_filenode *temp = new_file(headNode, tempc, t, NULL);
	if (temp == NULL)
	{
		//pop_error(0, "PASTE_NODE_TO_DIR:", "failed to new file:", tempc);
		r = -1;
		return r;
	}
	struct My_filenode *temph;
    //如果该节点是目录，则将该节点下的所有文件也复制过去
	if (t == 1)
	{
		temph = creat_son_list(temp);
		paste_list_to_dir(temph, copyNode->son_list_head, n);
	}
	return r;
}

/*
	函数功能：把一个目录复制到另一个目录下
	参数：目标目录头节点，被复制目录头节点
	返回值：0表示操作成功，-1表示操作失败
*/
int paste_list_to_dir(struct My_filenode *headNode, struct My_filenode *copyheadNode, int n)
{
	if (headNode == NULL || copyheadNode == NULL)
	{
		return -1;
	}
	if (copyheadNode->next == NULL)
	{
		return -1;
	}
	struct My_filenode *temp = copyheadNode->next;
	int r = 0;
	for (int i = 0; i < n; i++, temp = temp->next)
	{
		paste_node_to_dir(headNode, temp);
	}
	return r;
}

/*
	//复制内容到剪切板->把复制的内容粘贴到目标文件夹->同时保留原版记录
	函数功能：把剪切板的内容复制到目录
	参数：目录头节点
	返回值：0表示操作成功，-1表示操作失败
*/
int My_paste(struct My_vector_ *paste, struct My_filenode *headNode, struct My_filenode *ph_for_paste)
{
	int count, max = 20;
	int r = 0;
	struct My_vector_ *temppv = paste->next;
	struct My_filenode *tempp;
	creat_son_list(ph_for_paste->next);
	for (; temppv != NULL; temppv = temppv->next)
	{
		count = 0;
		tempp = vector_to_filenode(ph_for_paste, temppv);
		find_max_sub_file(tempp, &count, max);
		r = paste_node_to_dir(headNode, tempp);
		if (r == -1)
		{
			free_list(ph_for_paste->next->son_list_head);
			free_son_list_head(ph_for_paste->next);
			return -1;
		}
		free_list(ph_for_paste->next->son_list_head);
	}
	free_son_list_head(ph_for_paste->next);
	return r;
}

/*
	//复制到剪切板->把复制的内容粘贴到目标文件夹->删除原版
	函数功能：剪切剪切板内容到目录
	参数：目录头节点
	返回值：无
*/
void My_cut(struct My_vector_ *paste, struct My_filenode *headNode, struct My_filenode *ph_for_paste)
{
	if (headNode == NULL)
	{
		return;
	}

	int n, r = 0;
	struct My_filenode *tempf;
	struct My_filenode *tempp;
	struct My_vector_ *temppv;
	char *path1 = (char *)malloc(80);
	char *path2 = (char *)malloc(80);
	if (path1 == NULL || path2 == NULL)
	{
		//pop_error(-1, "My_cut:", "malloc return NULL pointer.");
		free(path1);
		free(path2);
		return;
	}
	for (tempf = headNode->father; tempf->father != NULL; tempf = tempf->father)
	{
		for (temppv = paste->next; temppv != NULL; temppv = temppv->next)
		{
			tempp = vector_to_filenode(ph_for_paste, temppv);
			path1[0] = '\0';
			path2[0] = '\0';
			get_path(tempf, path1);
			get_path(tempp, path2);
			if (strcmp(path1, path2) == 0)
			{
				free_vector_list(paste);
				free(path1);
				free(path2);
				return;
			}
		}
	}
	free(path1);
	free(path2);
	r = My_paste(paste, headNode, ph_for_paste);
	if (r == -1)
	{
		free_vector_list(paste);
		return;
	}
	for (temppv = paste->next; temppv != NULL; temppv = temppv->next)
	{
		tempp = vector_to_filenode(ph_for_paste, temppv);
		n = count_the_node(tempp->father->son_list_head, tempp);
		if (n == 0)
		{
			free_vector_list(paste);
			return;
		}
		delet_next_node(count_to_node(tempp->father->son_list_head, n - 1));
		//printf("%d",count_nodes(tempp->father->son_list_head));
	}
	free_vector_list(paste);
}

/*
	函数功能：重命名文件
	参数：文件节点，新文件名
	返回值：无
*/
void My_rename(struct My_filenode *theNode, char *newname)
{
	if (theNode == NULL)
	{
		return;
	}
	if (My_strcmp(theNode->name, newname) == 0)
	{
		return;
	}
	int n = 0;
	to_capital(newname);
	struct My_filenode *temph = theNode->father->son_list_head;
	if (theNode->flag & IS_DIR)
	{
		//find_all_sub_file(theNode);
		struct My_filenode *temp = new_file(temph, newname, 1,NULL);
		if (temp == NULL)
		{
			//pop_error(0, "My_rename", "New name illegal:", newname);
			return;
		}
		creat_son_list(temp);
		n = count_nodes(theNode->son_list_head);
		if (n > 20)
		{
			n = 20;
		}
		paste_list_to_dir(temp->son_list_head, theNode->son_list_head, n);
		n = count_the_node(temph, theNode);
		delet_next_node(count_to_node(temph, n - 1));
	}
	else
	{
		//struct My_filenode *temp = new_file(temph, newname, 0, theNode);
		struct My_filenode *temp = new_file(temph, newname, 0, NULL);
		if (temp == NULL)
		{
			//pop_error(0, "My_rename", "New name illegal:", newname);
			return;
		}
		n = count_the_node(temph, theNode);
		delet_next_node(count_to_node(temph, n - 1));
	}
}