#include"KMP_H.h"
#include<stdio.h>
#include<string.h>

int main() {
	SSTRING S, T;
	int pos = 0;
	S.ch[1] = 'A'; S.ch[2] = 'B'; S.ch[3] = 'C'; S.ch[4] = 'A'; S.ch[5] = 'B'; S.ch[6] = ' '; S.ch[7] = ' '; S.ch[8] = 'A'; S.ch[9] = 'B';
	S.ch[10] = 'C'; S.ch[11] = 'D'; S.ch[12] = 'A'; S.ch[13] = 'B'; S.ch[14] = 'F'; S.ch[15] = 'G';
	T.ch[1] = 'A'; T.ch[2] = 'B'; T.ch[3] = 'C'; T.ch[4] = 'D'; T.ch[5] = 'A'; T.ch[6] = 'B';
	//strcpy(S.ch, "ABCAB ABCDABDE");
	//strcpy(T.ch, "ABCD");
	S.length = 15;
	T.length = 6;
	//S.length = strlen(S.ch);
	//T.length = strlen(T.ch);
	pos = Index_KMP(S, T, pos);
	printf("∆•≈‰Œª÷√£∫%d\n", pos);
	return 0;
}