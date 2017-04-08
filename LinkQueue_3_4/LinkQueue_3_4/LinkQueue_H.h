#pragma once
typedef int ElemType;
typedef bool Status;

#define OK true;
#define ERROR false;
#define OVERFLOW -1;

//------------------队列的链式存储结构-------------------------
typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode , *QueuePtr;

typedef struct {
	QueuePtr front;			//队列头指针
	QueuePtr rear;			//队列尾指针
}LinkQueue;

//初始化链式队列
Status InitQueue(LinkQueue &Q);
//链式队列的入队
Status EnQueue(LinkQueue &Q, ElemType e);
//链式队列的出队
Status DeQueue(LinkQueue &Q, ElemType &e);
//取链式队列的头元素
ElemType GetHead(LinkQueue Q);
//链式队列的遍历
Status traverse_LinkQueue(LinkQueue Q);



