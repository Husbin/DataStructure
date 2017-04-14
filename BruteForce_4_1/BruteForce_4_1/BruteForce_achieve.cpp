#include"BruteForce_H.h"
#include<stdio.h>
#include<stdlib.h>

int Index_BF(SSTRING S, SSTRING T, int &pos) {
	//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，返回值为0
	int i = 1;
	int j = 1;

	while (i <= S.length && j <= T.length) {	//两个串均未比较到串尾
		if (S.ch[i] == T.ch[j]) {
			//继续比较后继的字符
			i++;
			j++;
		}
		else {
			//指针后退重新开始匹配
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length) {
		pos = i - T.length;
		return pos;	//匹配成功
	}
	else return 0;							//匹配失败
}