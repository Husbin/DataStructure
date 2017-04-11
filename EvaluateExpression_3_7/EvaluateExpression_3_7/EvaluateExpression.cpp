//http://blog.csdn.net/hackbuteer1/article/details/6683095

#include "EvaluateExpression_H.h"
#include<stdio.h>  
#include"stdlib.h"    
int main(void)
{
	char s[128];
	puts("请输入表达式:");
	gets_s(s);
	puts("该表达式的值为:");
	printf("%s\b=%g\n", s, EvaluateExpression(s));
	system("pause");
	return 0;
}