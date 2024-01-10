/**************************
 * 关于Flag量的定义和相关函数
 * 以及按位运算的函数
 * ************************/

#ifndef _BITV_H_
#define _BITV_H_

#include "flag.h"

/**************************
 * 关于Flag的说明
 * Flag是一个unsigned char型，按位存储信息的量
 * 其各个位置的信息为
 *  _ _ _ _ _ _ _ _
 * |_|_|_|_|_|_|_|_|
 *  1 2 3 4 5 6 7 8
 * > 1 是否处于选中状态
 * > 2 是否为文件夹
 * > 3 是否为头节点
 * > 4~8 类型记录
 * % % 值 % %
 * bool量，0表示否，1表示是
 * 非bool量，按照枚举定义
 ******************************/

typedef unsigned char Flag;

/********************************
 * FUNCTION:get_file
 * DESCRIPTION:获取Flag表示的文件类型
 * INPUT:Flag变量地址
 * RETURN:char型变量（可用于同枚举比较）
 * OTHERS:无
 ********************************/
char get_file(Flag flag);

#endif

#ifndef _STATE_

#define _STATE_

/**********************
 * 关于按位类型State的说明
 * State是一个unsigned char型，按位存储信息的量
 * 其各个位置的信息为
 *  _ _ _ _ _ _ _ _
 * |_|_|_|_|_|_|_|_|
 *  1 2 3 4 5 6 7 8
 * > 1 （按键）此次循环是否可以点击（是否变灰/变亮）
 * > 2 此次循环鼠标在/不在状态      //鼠标是否在此按键范围内（是否颜色加深/背景变蓝）
 * > 3 上次循环鼠标在/不在状态      //是否再画一遍
 * > 4 是否用图标画过一次			//点击文件（选中）时功能模块需要改变这个值
 * > 5 这次循环是否选中该按键		//功能模块需要改变其值
 * > 6 上次循环是否选中该按键
 * > 7
 *
 * bool量，0表示否，1表示是
 * ********************/
typedef unsigned char State;

enum state_bit
{
	IFP_N = 1, //此次循环是否可以点击
	IFH_N,	   //上次循环鼠标在不在这里
	IFH_L,	   //这次循环鼠标在不在这里
	IFD_1,	   //是否显示过一次
	IFC_N,	   //这次循环是否选中该按键
	IFC_L,	   //上次循环是否选中该按键
	IFP_L,	   //上次循环是否可以点击
};

typedef unsigned char Bit;

/********************************
 * FUNCTION:getonebit
 * DESCRIPTION:按位获取量,自左边数
 * INPUT:按位量，取位数
 * RETURN:1或0（该位的值）
 * OTHERS:无
 ********************************/
char getonebit(unsigned char bit, char num);

/********************************
 * FUNCTION:getonebit
 * DESCRIPTION:通过一个首地址，按位将第几位内容读取出来
 * INPUT:char型指s针【指向连续的几个按位量（比如数组）】，第几位（可以是大于8的数）
 * RETURN:该位的值（0或1）
 * OTHERS:重载
 ********************************/
char getonebit(unsigned char *pbit, char num);

/********************************
 * FUNCTION:setonebit
 * DESCRIPTION:按位赋值函数
 * INPUT:按位量地址，设置位数，将赋的值(1或0)
 * RETURN:无
 * OTHERS:无
 ********************************/
void setonebit(unsigned char *pbit, char num, char value);

/********************************
 * FUNCTION:reverseonebit
 * DESCRIPTION:按位取反函数
 * INPUT:按位量地址，取反位数
 * RETURN:无
 * OTHERS:无
 ********************************/
void reverseonebit(unsigned char *pbit, char num);

/********************************
 * FUNCTION:set1onebit
 * DESCRIPTION:按位置1函数
 * INPUT:按位量地址，置1位数
 * RETURN:无
 * OTHERS:无
 ********************************/
void set1onebit(unsigned char *pbit, char num);

/********************************
 * FUNCTION:set0onebit
 * DESCRIPTION:按位置0函数
 * INPUT:按位量地址，置0位数
 * RETURN:无
 * OTHERS:无
 ********************************/
void set0onebit(unsigned char *pbit, char num);

#endif