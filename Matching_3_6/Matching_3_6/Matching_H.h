#pragma once

//
typedef char ElemType;
typedef bool Status;

#define MAXSIZE 100
#define OK true
#define ERROR false
#define OVERFLOW -1


//----------------顺序栈的存储结构--------------------------
typedef struct Stack {
	ElemType *base;
	ElemType *top;
	int stacksize;
}STACK;


//初始化顺序栈
Status InitStack(STACK &S);
//顺序栈的入栈
Status Push(STACK &S , ElemType e);
//顺序栈的出栈
Status Pop(STACK &S, ElemType &e);
//获取栈顶元素
ElemType getTop(STACK S);
//括号的匹配
Status Matching();
