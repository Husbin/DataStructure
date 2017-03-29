#pragma once
typedef int ElemType;
typedef bool Status;
#define OK true
#define ERROR false
#define OVERFLOW -1
//-------------链栈的存储结构---------------
typedef struct StackNode {
	ElemType data;
	struct StackNode *pNext;
}StackNode , *LinkStackNode;

//链栈的初始化
Status InitLinkStack(LinkStackNode &S);

//链栈的压栈
Status Link_Push(LinkStackNode &S, ElemType e);

//链栈的出栈
Status Link_Pop(LinkStackNode &S, ElemType &e);

//取链栈的栈顶元素
ElemType GetTop(LinkStackNode S);

//链栈的遍历
void traverse_LinkStack(LinkStackNode S);