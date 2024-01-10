#ifndef _LISTSORT_H_
#define _LISTSORT_H_

#include "listset.h"

void swap_node(struct My_filenode *frontNode1, struct My_filenode *frontNode2);
void sort_by_name1(struct My_filenode *headnode);
void sort_by_name2(struct My_filenode *headnode);
void My_sort(struct My_filenode *headNode, char sort_way);

#endif