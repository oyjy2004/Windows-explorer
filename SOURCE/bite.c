/**************************
 * 关于Flag量的定义和相关函数
 * 以及按位运算的函数
 *
 * > 1st 2023/3/14 创建相关定义和说明
 * > 2nd 2023/3/19 加入并修改一些按位操作函数
 * ************************/

#include "bite.h"

/********************************
 * FUNCTION:get_file
 * DESCRIPTION:获取Flag表示的文件类型
 * INPUT:Flag变量地址
 * RETURN:char型变量（可用于同枚举比较）
 * OTHERS:无
 ********************************/
char get_file(Flag flag)
{
	char t;
	t = flag & 31;
	return (t);
}

/********************************
 * FUNCTION:getonebit
 * DESCRIPTION:按位获取量,自左边数
 * INPUT:按位量，取位数
 * RETURN:1或0（该位的值）
 * OTHERS:无
 ********************************/
char getonebit(unsigned char bit, char num)
{
	char t;
	switch (num)
	{
	case 1:
		t = ((bit & 128) >> 7);
		break;
	case 2:
		t = ((bit & 64) >> 6);
		break;
	case 3:
		t = ((bit & 32) >> 5);
		break;
	case 4:
		t = ((bit & 16) >> 4);
		break;
	case 5:
		t = ((bit & 8) >> 3);
		break;
	case 6:
		t = ((bit & 4) >> 2);
		break;
	case 7:
		t = ((bit & 2) >> 1);
		break;
	case 8:
		t = (bit & 1);
		break;
	default:
		t = 0;
		break;
	}
	return t;
}

/********************************
 * FUNCTION:getonebit
 * DESCRIPTION:通过一个首地址，按位将第几位内容读取出来
 * INPUT:char型指s针【指向连续的几个按位量（比如数组）】，第几位（可以是大于8的数）
 * RETURN:该位的值（0或1）
 * OTHERS:重载
 ********************************/
char getonebit(unsigned char *pbit, char num)
{
	int num_num; //第几个char数据
	int num_bit; //那个char数据对应的第几位
	int t;
	num_num = (num - 1) / 8;
	num_bit = (num - 1) % 8 + 1;
	t = getonebit(pbit[num_num], num_bit);
	return t;
}

/********************************
 * FUNCTION:set1onebit
 * DESCRIPTION:按位置1函数
 * INPUT:按位量地址，置1位数
 * RETURN:无
 * OTHERS:无
 ********************************/
void set1onebit(unsigned char *pbit, char num)
{
	if (num <= 8)
	{
		switch (num)
		{
		case 1:
			*pbit = *pbit | 128;
			break;
		case 2:
			*pbit = *pbit | 64;
			break;
		case 3:
			*pbit = *pbit | 32;
			break;
		case 4:
			*pbit = *pbit | 16;
			break;
		case 5:
			*pbit = *pbit | 8;
			break;
		case 6:
			*pbit = *pbit | 4;
			break;
		case 7:
			*pbit = *pbit | 2;
			break;
		case 8:
			*pbit = *pbit | 1;
			break;
		default:
			break;
		}
	}
	else
	{
		int num_num; //第几个char数据，从0开始
		int num_bit; //那个char数据对应的第几位

		num_num = (num - 1) / 8;
		num_bit = (num - 1) % 8 + 1;

		switch (num_bit)
		{
		case 1:
			*(pbit + num_num) = *(pbit + num_num) | 128;
			break;
		case 2:
			*(pbit + num_num) = *(pbit + num_num) | 64;
			break;
		case 3:
			*(pbit + num_num) = *(pbit + num_num) | 32;
			break;
		case 4:
			*(pbit + num_num) = *(pbit + num_num) | 16;
			break;
		case 5:
			*(pbit + num_num) = *(pbit + num_num) | 8;
			break;
		case 6:
			*(pbit + num_num) = *(pbit + num_num) | 4;
			break;
		case 7:
			*(pbit + num_num) = *(pbit + num_num) | 2;
			break;
		case 8:
			*(pbit + num_num) = *(pbit + num_num) | 1;
			break;
		default:
			break;
		}
	}
}

/********************************
 * FUNCTION:set0onebit
 * DESCRIPTION:按位置0函数
 * INPUT:按位量地址，置0位数
 * RETURN:无
 * OTHERS:无
 ********************************/
void set0onebit(unsigned char *pbit, char num)
{
	if (num <= 8)
	{
		switch (num)
		{
		case 1:
			*pbit = *pbit & 127;
			break;
		case 2:
			*pbit = *pbit & 191;
			break;
		case 3:
			*pbit = *pbit & 223;
			break;
		case 4:
			*pbit = *pbit & 239;
			break;
		case 5:
			*pbit = *pbit & 247;
			break;
		case 6:
			*pbit = *pbit & 251;
			break;
		case 7:
			*pbit = *pbit & 253;
			break;
		case 8:
			*pbit = *pbit & 254;
			break;
		default:
			break;
		}
	}
	else
	{
		int num_num; //第几个char数据，从0开始
		int num_bit; //那个char数据对应的第几位

		num_num = (num - 1) / 8;
		num_bit = (num - 1) % 8 + 1;

		switch (num_bit)
		{
		case 1:
			*(pbit + num_num) = *(pbit + num_num) & 127;
			break;
		case 2:
			*(pbit + num_num) = *(pbit + num_num) & 191;
			break;
		case 3:
			*(pbit + num_num) = *(pbit + num_num) & 223;
			break;
		case 4:
			*(pbit + num_num) = *(pbit + num_num) & 239;
			break;
		case 5:
			*(pbit + num_num) = *(pbit + num_num) & 247;
			break;
		case 6:
			*(pbit + num_num) = *(pbit + num_num) & 251;
			break;
		case 7:
			*(pbit + num_num) = *(pbit + num_num) & 253;
			break;
		case 8:
			*(pbit + num_num) = *(pbit + num_num) & 254;
			break;
		default:
			break;
		}
	}
}

/********************************
 * FUNCTION:setonebit
 * DESCRIPTION:按位赋值函数
 * INPUT:按位量地址，设置位数，将赋的值(1或0)
 * RETURN:无
 * OTHERS:无
 ********************************/
void setonebit(unsigned char *pbit, char num, char value)
{
	switch (value)
	{
	case 1:
		set1onebit(pbit, num);
		break;
	case 0:
		set0onebit(pbit, num);
		break;
	}
}

/********************************
 * FUNCTION:reverseonebit
 * DESCRIPTION:按位取反函数
 * INPUT:按位量地址，取反位数
 * RETURN:无
 * OTHERS:无
 ********************************/
void reverseonebit(unsigned char *pbit, char num)
{
	if (num <= 8)
	{
		switch (num)
		{
		case 1:
			*pbit = *pbit ^ 128;
			break;
		case 2:
			*pbit = *pbit ^ 64;
			break;
		case 3:
			*pbit = *pbit ^ 32;
			break;
		case 4:
			*pbit = *pbit ^ 16;
			break;
		case 5:
			*pbit = *pbit ^ 8;
			break;
		case 6:
			*pbit = *pbit ^ 4;
			break;
		case 7:
			*pbit = *pbit ^ 2;
			break;
		case 8:
			*pbit = *pbit ^ 1;
			break;
		default:
			break;
		}
	}
	else
	{
		int num_num; //第几个char数据，从0开始
		int num_bit; //那个char数据对应的第几位

		num_num = (num - 1) / 8;
		num_bit = (num - 1) % 8 + 1;

		switch (num_bit)
		{
		case 1:
			*(pbit + num_num) = *(pbit + num_num) ^ 128;
			break;
		case 2:
			*(pbit + num_num) = *(pbit + num_num) ^ 64;
			break;
		case 3:
			*(pbit + num_num) = *(pbit + num_num) ^ 32;
			break;
		case 4:
			*(pbit + num_num) = *(pbit + num_num) ^ 16;
			break;
		case 5:
			*(pbit + num_num) = *(pbit + num_num) ^ 8;
			break;
		case 6:
			*(pbit + num_num) = *(pbit + num_num) ^ 4;
			break;
		case 7:
			*(pbit + num_num) = *(pbit + num_num) ^ 2;
			break;
		case 8:
			*(pbit + num_num) = *(pbit + num_num) ^ 1;
			break;
		default:
			break;
		}
	}
}