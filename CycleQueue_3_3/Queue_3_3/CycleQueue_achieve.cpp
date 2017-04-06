#include "CycleQueue_H.h"
#include<stdio.h>
#include<stdlib.h>

Status InitQueue(SqQueue &Q) {
	Q.base = new QElemType[MAXQSIZE];		//为队列分配一个最大容量为MAXQSIZE的数组空间
	if (!Q.base) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;					//头指针和尾指针置为零，队列为空
	return OK;
}

int QueueLength(SqQueue Q) {
	//返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElemType e) {
	//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) {
		printf("循环队列已满！\n");
		return ERROR;
	}
	Q.base[Q.rear] = e;						//新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE;		//队尾指针加一
	return OK;
}

Status DeQueu(SqQueue &Q, QElemType &e) {
	//删除Q的队头元素，用e返回
	if (Q.front == Q.rear) {
		printf("队空！\n");
		return ERROR;
	}
	e = Q.base[Q.front];					//保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE;		//队头指针加一
	return OK;
}

QElemType getHead(SqQueue Q) {
	//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear)			//队列非空
		return Q.base[Q.front];		//返回队头元素的值，队头指针不变
}

Status traverse_Queue(SqQueue Q) {
	printf("循环队列遍历结果如下:\n");
	if (Q.front == Q.rear) {
		printf("队空！\n");
		return ERROR;
	}
	int count = Q.front;
	while (count != Q.rear) {
		printf("%d  ", Q.base[count]);
		count = (count + 1) % MAXQSIZE;
	}
	printf("\n");
}