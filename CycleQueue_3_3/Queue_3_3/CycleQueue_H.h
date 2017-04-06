#pragma once

#define MAXQSIZE 100		//队列可能可能达到的最大长度
#define OK true
#define ERROR false
#define OVERFLOW -1
typedef bool Status;
typedef int QElemType;

//------------队列的顺序存储结构--------------
typedef struct {
	QElemType *base;		//存储空间的基地址
	int front;				//头指针
	int rear;				//尾指针
}SqQueue;

//循环队列的初始化
Status InitQueue(SqQueue &Q);

//求循环队列的长度
int QueueLength(SqQueue Q);

//入队
Status EnQueue(SqQueue &Q, QElemType e);

//出队
Status DeQueu(SqQueue &Q, QElemType &e);

//取循环队列队头元素
QElemType getHead(SqQueue Q);

//遍历循环队列
Status traverse_Queue(SqQueue Q);
