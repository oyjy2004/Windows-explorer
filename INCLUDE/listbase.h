#ifndef _LISTBASE_H_
#define _LISTBASE_H_

#include "listset.h"

void My_init(struct My_filenode **p0, struct My_filenode **ph, struct My_filenode **pc,  struct My_filenode **p0_for_paste, struct My_filenode **ph_for_paste, struct My_filenode **pc_for_paste, struct My_vector_ **paste);
void close_init(struct My_filenode *p0, struct My_filenode *ph, struct My_filenode *pc,  struct My_filenode *p0_for_paste, struct My_filenode *ph_for_paste, struct My_filenode *pc_for_paste, struct My_vector_ *paste);
void free_vector_list(struct My_vector_ *theNode);
void add_type(char *flagp, char *filename);
int My_strcmp(char *str1, char *str2);
void to_capital(char *str);
struct My_filenode *end_of_list(struct My_filenode *theNode);
void get_path(struct My_filenode *theNode, char *buffer);
struct My_vector_ *add_to_vector_(struct My_vector_ *vhead, struct My_filenode *theNode);
struct My_filenode *creat_son_list(struct My_filenode *fatherNode);
int count_the_node(struct My_filenode *headNode, struct My_filenode *theNode);
int count_the_node(struct My_vector_ *headNode, struct My_vector_ *theNode);
int count_nodes(struct My_filenode *headNode);
int count_nodes(struct My_vector_ *headNode);
struct My_filenode *count_to_node(struct My_filenode *headNode, int n);
struct My_vector_ *count_to_node(struct My_vector_ *headNode, int n);
struct My_filenode *add_at_end(struct My_filenode *theNode, struct ffblk *ff);
void free_son_list_head(struct My_filenode *fatherNode);
void free_next_node(struct My_filenode *frontNode);
void free_next_node(struct My_vector_ *frontNode);
void free_list(struct My_filenode *headNode);
void delet_next_node(struct My_filenode *frontNode);
void delet_list(struct My_filenode *headNode);
void find_all_file(struct My_filenode *fatherNode);
void seach_all_file(struct My_filenode *fatherNode);
int count_all_file(struct My_filenode *fatherNode);
void find_all_sub_file(struct My_filenode *fatherNode);
void find_max_sub_file(struct My_filenode *fatherNode, int *count, int max);
void find_all_dir(struct My_filenode *fatherNode);
int find_name(struct My_filenode *headNode, char *filename);
struct My_filenode *find_file_by_name(struct My_filenode *headNode, char *filename,int *num);
struct My_filenode *find_node_by_path(struct My_filenode *ph, char *apath);
void free_except_end(struct My_filenode *headNode);
void copy_file_content(struct My_filenode *destNode, struct My_filenode *srcNode);
struct My_filenode *new_file(struct My_filenode *headNode, char *filename, int filetype, struct My_filenode *srcNode);
long int get_file_kbsize(struct My_filenode *theNode);
int get_file_bsize(struct My_filenode *theNode);
struct Filetime *get_file_time(struct My_filenode *theNode);
struct My_filenode *vector_to_filenode(struct My_filenode *ph, struct My_vector_ *vnode);
void unselect_all(My_filenode *headNode);
void select_all(My_filenode *headNode);
struct Filetime *get_file_base(struct My_filenode *theNode, int *size);
struct My_filenode* get_node_by_name(struct My_filenode*headNode,char* name);

#endif