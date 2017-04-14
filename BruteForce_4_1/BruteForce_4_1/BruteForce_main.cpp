#include"BruteForce_H.h"
#include<stdio.h>
#include<string.h>

int main() {
	SSTRING S, T;
	int pos = 0;
	int index;
	strcpy(S.ch, "abcdefg");
	S.length = strlen(S.ch);
	strcpy(T.ch, "efg");
	T.length = strlen(T.ch);
	//printf("%d %d \n", S.length, T.length);
	pos = Index_BF(S , T , pos);
	if (pos == 0) {
		printf("匹配失败！\n");
	}
	else
	printf("匹配成功，从第%d开始配对。\n", pos);
	return 0;
}