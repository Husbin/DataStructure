#include"KMP_H.h"
#include<stdio.h>

int Index_KMP(SSTRING S, SSTRING T, int pos) {
	//利用模式串T的next函数求T在主串S中的第pos个字符之后的位置
	//其中T非空， 1<=pos<=S.length
	int i = 1; 
	pos = i;
	int j = 1;
	int next[30];
	while (i <= S.length && j <= S.length) {	//两个串均未比较到串尾
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++; j++;
			if ((j - 1) == T.length) {
				break;
			}
		}

		else {
			get_Next(T, next);
			j = next[j];
		}
	}
	if (j > T.length) {
		printf("匹配成功！\n");
		pos = i - T.length;
		return pos;
	}
	else {
		printf("匹配失败！\n");
		return 0;
	}
}

void get_Next(SSTRING T, int next[]) {
	//求模式串T的next函数值并存入数组next
	int j = 0;
	int i = 1;
	next[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}