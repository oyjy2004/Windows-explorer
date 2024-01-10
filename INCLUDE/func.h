#ifndef _FUNC_H_
#define _FUNC_H_

#include "listset.h"
#include"draw.h"
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

void func_refresh(My_filenode *headnode_current, My_filenode *ph);
void func_copy(My_filenode *headnode_current, My_vector_ *paste);
void func_paste(My_filenode *headnode_current, My_filenode *ph_for_paste, My_vector_ *paste, int judge_paste);
void func_cut(My_filenode *headnode_current, My_vector_ *paste);
void func_delete(My_filenode *headnode_current);

#endif