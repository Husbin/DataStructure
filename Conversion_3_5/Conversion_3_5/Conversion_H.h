#pragma once
//顺序栈实现进制转化
#define MAXSIZE 100		//顺序栈存储空间的初始化分配量
#define OK true
#define ERROR false
#define OVERFLOW -1
typedef int ElemType;
typedef bool Status;


//-----------------------顺序栈的存储结构---------------------
typedef struct Stack {
	ElemType *base;			//栈底指针
	ElemType *top;			//栈底指针
	int stacksize;			//栈可容纳的最大容量
}SQ_STACK;

//顺序栈的初始化
Status InitStack(SQ_STACK &S);
//顺序栈的入栈，在栈顶插入一个新元素
Status Push(SQ_STACK &S, ElemType e);
//顺序栈的出栈，在栈顶删除一个元素
Status Pop(SQ_STACK &S, ElemType &e);
//数制转换,十进制转化为八进制
void conversion(int N);