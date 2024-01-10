#ifndef _LISTSET_H_
#define _LISTSET_H_

/***********
该文件用于声明一些常用的数据结构
***********/
#include "flag.h"

struct My_filenode
{
	unsigned char flag;                //有关flag的值详见flag.h
	char name[13];
	struct My_filenode *next;          //指向下一个节点
	struct My_filenode *father;		   //同一条链用同一个父节点（为了做返回上一级功能）
	struct My_filenode *son_list_head; //一个父节点拥有子链的头节点地址
};

struct Filetime
{
	int s, min, h, d, month, y;
};

struct My_vector_
{
	char path[50];
	char name[13];
	struct My_vector_* next;
};

#endif