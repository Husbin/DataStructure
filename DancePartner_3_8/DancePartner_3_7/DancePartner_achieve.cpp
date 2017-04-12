#include "DancePartner_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Status InitQueue(SqQueue &Q) {
	Q.base = new Person[MAXSIZE];
	if (!Q.base) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue &Q , Person p) {
	//判断是否队满
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		printf("队满！\n");
		return ERROR;
	}

	strcpy(Q.base[Q.rear].name, p.name);
	Q.base[Q.rear].sex = p.sex;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q, Person &p) {
	//判断是否队空
	if (Q.rear == Q.front) {
		printf("队空！\n");
		return ERROR;
	}
	strcpy(p.name , Q.base[Q.front].name);
	p.sex = Q.base[Q.front].sex;
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return OK;
	else return ERROR;
}

Person GetHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

void DancePartner(Person dancer[], int num) {
	//结构数组dancer中存放跳舞的男女，num是跳舞的总人数
	SqQueue Mdancers, Fdancers;	//分别存放男士和女士入队者队列
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	Person p;
	for (int i = 0; i < num; i++) {
		p = dancer[i];
		if (p.sex == 'F') {
			//插入女队
			EnQueue(Fdancers, p);
		}
		else {
			//插入男队
			EnQueue(Mdancers, p);
		}

		//printf("The dancing partners are : \n");
		while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
			//依次输出男女舞伴的姓名
			DeQueue(Fdancers, p);
			printf("女伴 ： %s ", p.name);
			DeQueue(Mdancers, p);
			printf("男伴 ： %s ", p.name);
			printf("\n");
		}
	}
	if (!QueueEmpty(Mdancers)) {
		p = GetHead(Mdancers);
		printf("The first man is %s!\n", p.name);
	}
	if (!QueueEmpty(Fdancers)) {
		p = GetHead(Fdancers);
		printf("The first female is %s!\n", p.name);
	}
}