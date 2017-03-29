#include"LinkStack_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//链栈的初始化
Status InitLinkStack(LinkStackNode &S) {
	//构造一个空栈S，栈顶指针置空
	S = NULL;
	return OK;
}

//链栈的压栈
Status Link_Push(LinkStackNode &S, ElemType e) {
	//在栈顶插入元素e
	LinkStackNode pNew = (LinkStackNode)malloc(sizeof(StackNode));//生成新节点
	pNew->data = e;
	pNew->pNext = S;	//将新节点插入栈顶
	S = pNew;			//修改栈顶指针为pNew
	return OK;
}

//链栈的出栈
Status Link_Pop(LinkStackNode &S, ElemType &e) {
	//删除S的栈顶元素，用e返回其值
	if (S == NULL) {
		printf("栈空！\n");
		return ERROR;
	}
	e = S->data;			//保存栈顶数据
	LinkStackNode p = S;	//用p临时保存栈顶元素空间，以备释放
	S = S->pNext;			//修改栈顶指针
	free(p);				//释放原栈顶元素的空间
	return OK;
}

//取链栈的栈顶元素
ElemType GetTop(LinkStackNode S) {
	if (S != NULL) {
		return S->data;
	}
	printf("栈空！\n");
}

//链栈的遍历
void traverse_LinkStack(LinkStackNode S) {
	if (S == NULL) {
		printf("栈空！\n");
		return ;
	}
	LinkStackNode p;
	p = S->pNext;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}