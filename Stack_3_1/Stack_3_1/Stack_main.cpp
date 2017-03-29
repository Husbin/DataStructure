#include"Stack_H.h"
#include<stdio.h>

int main() {
	SQ_STACK S;
	int val;
	int topVal;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	Push(S, 6);
	topVal = GetTop(S);
	printf("栈顶的元素是%d\n", topVal);
	traverse_Stack(S);
	Pop(S , val);
	printf("执行出栈操作，出栈的元素是：%d\n", val);
	traverse_Stack(S);
	topVal = GetTop(S);
	printf("栈顶的元素是%d\n", topVal);
	return 0;
}