#include "include.h"
#include "listsort.h"
#include "listbase.h"

/*
	函数功能：相邻两个节点交换
	参数：两个节点中，前一个交换节点对应的前一个节点，后一个交换节点对应的前一个节点
	返回值：无
*/
void swap_node(struct My_filenode *frontNode1, struct My_filenode *frontNode2)
{
    if(frontNode1->next==NULL||frontNode2->next==NULL)
        return;
    else
    {
        struct My_filenode *temp1=frontNode1->next;
        struct My_filenode *temp2=frontNode2->next;

        frontNode1->next=frontNode2->next;
        temp1->next=temp2->next;
        temp2->next=temp1;
    }
}

/*
	函数功能：用名字排序链表（ABC顺叙）
	参数：头节点
	返回值：无
*/
void sort_by_name1(struct My_filenode *headNode)
{
    int n=count_nodes(headNode);
	int i,j,k;
    struct My_filenode *temp1=NULL;
	struct My_filenode *temp2=NULL;
    for(i=2;i<=n;i++)
    {
        j=1;
		temp1 = count_to_node(headNode, i);
		temp2 = count_to_node(headNode, j);
        while(strcmp(temp1->name,temp2->name)>0 && i>j)
        {
            temp2 = count_to_node(headNode, ++j);
        }
        if(i!=j)
        {
            for (k=i;k>j;k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				swap_node(temp2, temp1);
			}
        }
    }
}

/*
	函数功能：用名字排序链表（ABC倒叙）
	参数：头节点指针
	返回值：无
*/
void sort_by_name2(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	int i=2;
	for (i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		temp2 = count_to_node(headNode, j);
		while (strcmp(temp1->name, temp2->name) < 0 && j < i)
		{
			temp2 = count_to_node(headNode, ++j);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				swap_node(temp2, temp1);
			}
		}
	}
}

/*
	函数功能：文件排序
	参数：头节点指针，char（1ABC顺序 2ABC倒序 0默认排序）
	返回值：无
*/
void My_sort(struct My_filenode *headNode, char sort_way)
{
	switch (sort_way)
	{
	case 1:
		sort_by_name1(headNode);
		break;
	case 2:
		sort_by_name2(headNode);
		break;
	default:
		break;
	}
}