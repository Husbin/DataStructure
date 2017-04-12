#pragma once

#define OK true
#define ERROR false
#define OVERFLOW -1
#define MAXSIZE 100

typedef bool Status;

//--------------------跳舞者的个人信息--------------

typedef struct {
	char name[20];			//姓名
	char sex;				//性别，F表示女性，M表示男性
}Person;


//---------------------队列的顺序存储结构--------------
typedef struct{
	Person *base;			//队列中数据元素的类型为Person
	int front;				//队头指针
	int rear;				//队尾指针
}SqQueue;

//SqQueue Mdancers, Fdancers;	//分别存放男士和女士入队者队列

Status InitQueue(SqQueue &Q);	//初始化栈

Status EnQueue(SqQueue &Q , Person p);		//入队

Status DeQueue(SqQueue &Q , Person &p);		//出队

Status QueueEmpty(SqQueue Q);				//判断队列是否为空

Person GetHead(SqQueue Q);					//取队头元素

void DancePartner(Person dancer[], int num);//结构数组dancer中存放跳舞的男女，num是跳舞的总人数

