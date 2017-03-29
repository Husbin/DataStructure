#include "Stack_H.h"
#include"stdio.h"
#include"stdlib.h"


//初始化
Status InitStack(SQ_STACK &S) {
	S.base = new SElemType[MAXSIZE];		//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	if (!S.base) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	S.top = S.base;						//top初始化为base，空栈
	S.stacksize = MAXSIZE;				//stacksize置为栈的最大容量MAXSIZE
	return OK;
}

//入栈
Status Push(SQ_STACK &S, SElemType e) {
	//判断栈是否为满，满则返回ERROR
	if (S.top - S.base == S.stacksize) {
		printf("栈满，压栈失败！");
		return ERROR;
	}
	//元素e压入栈顶，栈顶指针加1
	//*S.top++ = e;
	*S.top = e;
	S.top++;
}

//出栈
Status Pop(SQ_STACK &S, SElemType &e) {
	//判断栈是否为空，空返回ERROR
	if (S.base == S.top) {
		printf("栈满！\n");
		return ERROR;
	}
	S.top--;
	e = *S.top;
	return OK;
}
//取栈顶元素
SElemType GetTop(SQ_STACK S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}

//遍历
void traverse_Stack(SQ_STACK S) {
	printf("遍历结果如下：\n");
	if (S.top == S.base) {
		printf("栈空，遍历失败！\n");
		return;
	}
	//SQ_STACK sq;
	//sq.top = S.top;
	while (S.top != S.base) {
		S.top--;
		printf("%d ", *S.top);
		
	}
	printf("\n");
}