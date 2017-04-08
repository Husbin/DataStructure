#include "LinkQueue_H.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"


//队列初始化
Status InitQueue(LinkQueue &Q) {
	//构造一个空队列
	Q.front = Q.rear = new QNode;		//生成新节点作为头节点，队头和队尾指针指向次节点
	Q.front->next = NULL;				//头节点的指针域置空
	return OK;
}

//入队
Status EnQueue(LinkQueue &Q, ElemType e) {
	//链式队列入队不需要判断是否已满，只需要新增一个节点。
	//插入元素e为Q的新的队尾元素。
	//QNode p;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));//为入队元素分配节点空间，用指针p指向
	p->data = e;								//将新节点的数据域置为e
	p->next = NULL;								//将新节点插入队尾
	Q.rear->next = p;
	Q.rear = p;									//修改队尾指针
	return OK;
}

//出队
Status DeQueue(LinkQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) {
		printf("队空!\n");
		return ERROR;
	}
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q.front->next;							//p指向对头元素
	e = p->data;								//e保存队头元素的值
	Q.front->next = p->next;					//修改头指针
	if (Q.rear == p)Q.rear = Q.front;			//最后一个元素被删，队尾指针指向头节点
	free(p);									//释放原队头元素空间
	return OK;
}
//取队头元素
ElemType GetHead(LinkQueue Q) {
	//返回队头元素，不修改队头指针
	if (Q.front != Q.rear)
		return Q.front->next->data;
}
//遍历
Status traverse_LinkQueue(LinkQueue Q) {
	printf("链式队列遍历结果如下：\n");
	if (Q.front == Q.rear) {
		printf("队空！\n");
		return ERROR;
	}
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q.front;
	while (p != Q.rear) {
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}