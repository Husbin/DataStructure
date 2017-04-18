#pragma once
//串的存储结构
//---------------------串的定长顺序存储结构-----------------
//下标为0的元素弃用。
#define MAXSIZE 255
typedef struct {
	char ch[MAXSIZE + 1];
	int length;
} SSTRING;

int Index_KMP(SSTRING S, SSTRING T, int pos);
void get_Next(SSTRING T, int next[]);