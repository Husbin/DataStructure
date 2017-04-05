#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"QueueLink_List_H.h"

PNODE create_QueueList() {
	int len;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(LNode));
	if (pHead == NULL) {
		printf("内存分配失败，循环链表创建失败。\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;//避免节点个数为0，程序崩溃。
	printf("请输入创建循环链表的节点数：");
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		PNODE pNew = (PNODE)malloc(sizeof(LNode));
		if (pNew == NULL) {
			printf("内存分配失败，新节点创建失败。\n");
			exit(-1);
		}
		printf("请输入第%d个节点的数据：", i + 1);
		scanf("%d", &val);
		pNew->data = val;
		pTail->pNext = pNew;//后插法，将新节点插到尾节点后面
		pNew->pNext = pHead;//新节点的指针域指向头节点
		pTail = pNew;		//将可移动的尾节点重新指向最后一个节点。
	}
	return pHead;
}

void traverse_QueueList(PNODE pHead) {
	int count = 0;
	printf("遍历结果如下：\n");
	if (pHead->pNext == NULL) {
		printf("循环链表为空。\n");
		exit(-1);
	}
	PNODE p = pHead->pNext;
	while (p != pHead) {
		printf("%d ", p->data);
		p = p->pNext;
		count++;
	}
	printf("\n");
}