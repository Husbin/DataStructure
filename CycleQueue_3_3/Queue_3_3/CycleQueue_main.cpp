#include"CycleQueue_H.h"
#include<stdio.h>

int main() {
	SqQueue Q;
	int length;	
	QElemType val;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	length = QueueLength(Q);
	traverse_Queue(Q);
	printf("循环队列长度：%d\n", length);
	val = getHead(Q);
	printf("队列的头元素为：%d \n" , val);

	DeQueu(Q, val);
	printf("出队的元素为：%d\n", val);
	traverse_Queue(Q);
	printf("循环队列长度：%d", length);
	val = getHead(Q);
	return OK;
}