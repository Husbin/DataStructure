#include"Conversion_H.h"
#include"stdlib.h"
#include"stdio.h"

Status InitStack(SQ_STACK &S) {
	S.base = new ElemType[MAXSIZE];			//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	if (!S.base) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	S.top = S.base;							//top初始化为base,空栈
	S.stacksize = MAXSIZE;					//stacksize置为栈的最大容量MAXSIZE
	return OK;
}

Status Push(SQ_STACK &S, ElemType e) {
	//判断栈是否为栈，满则返回ERROR
	if (S.top - S.base == S.stacksize) {
		printf("栈满，压栈失败！\n");
			return ERROR;
	}
	//元素e压入栈顶，栈顶指针加1
	//*S.top ++= e;
	*S.top = e;
	S.top++;
}

Status Pop(SQ_STACK &S, ElemType &e) {
	if (S.top == S.base) {
		printf("栈空！\n");
		exit(OVERFLOW);
	}
	S.top--;
	e = *S.top;
	return OK;
}

void conversion(int N) {
	SQ_STACK S;
	int e;
	InitStack(S);
	while (N) {
		Push(S, N % 2);
		N = N / 2;
	}
	while (S.base != S.top) {
		Pop(S, e);
		printf("%d ", e);
	}
	printf("\n");
}