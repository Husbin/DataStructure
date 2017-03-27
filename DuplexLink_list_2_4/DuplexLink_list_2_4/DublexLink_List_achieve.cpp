#include"DublexLink_List_H.h"
#include"malloc.h"
#include"stdlib.h"
#include"stdio.h"

PDULNODE create_dubleLink_List() {
	int len;
	int val;
	PDULNODE pHead = (PDULNODE)malloc(sizeof(DULNODE));
	if (pHead == NULL) {
		printf("双向链表创建失败！\n");
		exit(-1);
	}
	pHead->prior = NULL;
	printf("请输入要创建的节点个数：");
	scanf("%d", &len);
	PDULNODE pTail = pHead;
	pTail->pnext = NULL;
	pTail->prior = NULL;
	for (int i = 0; i < len; i++) {
		PDULNODE pNew = (PDULNODE)malloc(sizeof(DULNODE));
		if (pNew == NULL) {
			printf("新节点创建失败！\n");
			exit(-1);
		}
		printf("请输入第%d个节点的数据：", i + 1);
		scanf("%d", &val);
		pNew->data = val;
		pTail->pnext = pNew;
		pNew->prior = pTail;
		pNew->pnext = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_duleLink_List(PDULNODE pHead) {
	printf("双向链表遍历如下：\n");
	PDULNODE p = pHead->pnext;
	if (p == NULL) {
		printf("双向链表为空。\n");
	}
	int i = 1;
	while (p != NULL) {
		printf("第%d个节点的结点数据域：%d\n", i, p->data);
		if (p->prior != pHead) {		
			printf("第%d个节点的前驱结点数据域：%d\n", i, p->prior->data);
		}
		else {
			printf("第%d个节点的前驱结点数据域：NULL\n", i);
		}
		if (p->pnext != NULL) {
			printf("第%d个节点的后驱结点数据域：%d\n", i, p->pnext->data);
		}
		else {
			printf("第%d个节点的后驱结点数据域：NULL\n", i);
		}
		p = p->pnext;
		i++;
	}
	printf("\n");
}

Status insertElem(PDULNODE pHead, int index, ElemType e) {
	PDULNODE p = (PDULNODE)malloc(sizeof(DULNODE));
	int count = 0;
	p = pHead->pnext;
	while (p && count < index - 1) {
		count++;
		p = p->pnext;
	}
	if (!p || count > index - 1)return ERROR;
	PDULNODE pNew = (PDULNODE)malloc(sizeof(DULNODE));
	pNew->data = e;
	/*pNew->pnext = p->pnext;
	pNew->prior = p;
	p->pnext = pNew;*/
	pNew->prior = p->prior;
	p->prior->pnext = pNew;
	pNew->pnext = p;
	p->prior = pNew;
	return OK;
}

Status deleteElem(PDULNODE &pHead, int index) {
	PDULNODE p = (PDULNODE)malloc(sizeof(DULNODE));
	int count = 0;
	p = pHead->pnext;
	while (p && count < index - 1) {
		count++;
		p = p->pnext;
	}
	if (!p || count > index - 1)return ERROR;
	p->prior->pnext = p->pnext;		//修改被删除节点的前驱结点的后继指针
	p->pnext->prior = p->prior;		//修改被删除节点的后继节点的前驱指针
	free(p);
	return OK;
}