#include "func.h"

/********************************
 * FUNCTION:
 * DESCRIPTION:刷新
 * INPUT:ch,ph
 * RETURN:
 * OTHERS:
 ********************************/
void func_refresh(My_filenode *headnode_current, My_filenode *ph)
{
	if (headnode_current != ph)
	{
		My_filenode *ttnode;
		ttnode = end_of_list(headnode_current);
		new_file(headnode_current, "_reflsh_", 0,NULL);
		delet_next_node(ttnode);
	}
}

/********************************
 * FUNCTION:
 * DESCRIPTION:复制
 * INPUT:ch,paste
 * RETURN:
 * OTHERS:
 ********************************/
void func_copy(My_filenode *headnode_current, My_vector_ *paste)
{
	My_filenode *ttnode;
	free_vector_list(paste);
	for (ttnode = (headnode_current)->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			add_to_vector_(paste, ttnode);
		}
	}
}

/********************************
 * FUNCTION:
 * DESCRIPTION:粘贴
 * INPUT:ch,ph_for_paste,paste,粘贴模式判断量
 * RETURN:
 * OTHERS:
 ********************************/
void func_paste(My_filenode *headnode_current, My_filenode *ph_for_paste, My_vector_ *paste, int judge_paste)
{
	if (judge_paste == 1)
	{
		My_paste(paste, headnode_current, ph_for_paste);
	}
	else if (judge_paste == 2)
	{
		My_cut(paste, headnode_current, ph_for_paste);
	}
}

/********************************
 * FUNCTION:
 * DESCRIPTION:剪切
 * INPUT:pc,paste
 * RETURN:
 * OTHERS:
 ********************************/
void func_cut(My_filenode *headnode_current, My_vector_ *paste)
{
	My_filenode *ttnode;
	free_vector_list(paste);
	for (ttnode = (headnode_current)->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			add_to_vector_(paste, ttnode);
		}
	}
}

/********************************
 * FUNCTION:
 * DESCRIPTION:删除
 * INPUT:pc
 * RETURN:
 * OTHERS:
 ********************************/
void func_delete(My_filenode *headnode_current)
{
	My_filenode *ttnode_1, *ttnode_2;
	ttnode_1 = headnode_current;
	ttnode_2 = ttnode_1->next;
	do
	{
		if (getonebit(ttnode_2->flag, 1) == 1)
		{
			delet_next_node(ttnode_1);
			if (ttnode_1->next == ttnode_2)
			{
				return;
			}
			ttnode_2 = ttnode_1->next;
		}
		else
		{
			ttnode_1 = ttnode_1->next, ttnode_2 = ttnode_2->next;
		}
	} while (ttnode_2 != NULL);
}