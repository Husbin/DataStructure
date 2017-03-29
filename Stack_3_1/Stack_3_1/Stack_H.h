#pragma once

#define MAXSIZE 100			//顺序栈存储空间的初始分配量
#define OK true
#define ERROR false
#define OVERFLOW -1
typedef int SElemType;
typedef bool Status;

//----------------顺序栈的存储结构----------------
typedef struct Stack {
	SElemType *base;		//栈底指针
	SElemType *top;			//栈顶指针
	int stacksize;			//栈可容纳的最大容量
}SQ_STACK;

//顺序栈的初始化
Status InitStack(SQ_STACK &S);
//顺序栈的入栈，在栈顶插入一个新元素
Status Push(SQ_STACK &S , SElemType e);
//顺序栈的出栈，在栈顶删除一个元素
Status Pop(SQ_STACK &S, SElemType &e);
//取栈顶元素
SElemType GetTop(SQ_STACK S);
//顺序栈的遍历
void traverse_Stack(SQ_STACK S);