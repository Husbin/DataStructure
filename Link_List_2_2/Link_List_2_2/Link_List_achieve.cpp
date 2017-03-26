#include "Link_List_H.h"
#include<stdio.h>
#include"malloc.h"
#include"stdlib.h"
//单链表的初始化
Status InitList(LinkList &L) {
	//构造一个空链表
	L = new LNode;	//生成新节点作为头节点，用头指针L指向头节点
	L->next = NULL;	//头节点的指针域置空
	return OK;
}
//单链表的创建，后插法
LinkList CreateList_Rear() {
	int len;
	int val;
	LinkList pHead = (LinkList)malloc(sizeof(LNode));	//建立头节点
	pHead->next = NULL;
	LinkList rear = pHead;								//尾节点指向头节点
	printf("请输入创建链表的长度:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		LinkList pNew = (LinkList)malloc(sizeof(LNode));//建立新节点
		printf("请输入第%d个节点的数据：", i + 1);
		scanf("%d", &val);
		pNew->data = val;								//数据域赋值
		pNew->next = NULL;
		rear->next = pNew;								//将新节点插入尾节点rear之后
		rear = pNew;									//rear指向新的尾节点pNew
	}
	return pHead;
}
//单链表的创建，前插法
LinkList CreateList_Front() {
	int len;
	int val;
	LinkList pHead = (LinkList)malloc(sizeof(LNode));
	pHead->next = NULL;
	printf("请输入创建链表的长度：");
	scanf("%d", &len);
	for(int i = 0; i < len; i++) {
		LinkList pNew = (LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个节点的数据：", i + 1);
		scanf("%d", &val);
		pNew->data = val;
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	return pHead;
}
//单链表的取值
Status GetElem(LinkList L, int i, ElemType &e) {
	//在带头节点的单链表L中根据序号i获取元素的值，用e返回L中第i个数据元素的值
	LinkList p = L->next;	//初始化，p指向首节点
	int j = 1;				//计数器j初值赋为1
	while (p && j < i) {
		//顺链域向后扫描，直到p为空域或者p指向第i个元素
		p = p->next;
		j++;
	}
	if (!p || j > i){
		//i的取值不合法，i>n或n<=0
		printf("ERROR index!");
		return ERROR;	
	}
	e = p->data;			//取值
	return OK;
}

//单链表的按值查找
int LocateElem(LinkList L, ElemType e) {
	//在带头节点的单链表L中查找值为e的元素
	int cout = 1;
	LinkList p = L->next;	//初始化，p指向头节点
	while (p && p->data != e) {
		p = p->next;
		cout++;
	}
	return cout;
}

//求单链表的长度
int LinkList_Length(LinkList L) {
	int len = 0;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p = L->next;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//遍历单链表
void traverse_LinkList(LinkList L) {
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//判断单链表是否为空
Status isEmpty(LinkList L) {
	if (L->next == NULL) {
		return OK;
	}
	else return ERROR;
}

//单链表的插入
Status ListInsert(LinkList &L, int i, ElemType e) {
	//在头节点为L的单链表中的第i个位置插入值为e的新节点
	LinkList p = (LinkList)malloc(sizeof(LNode));
	int j = 0;
	p = L->next;
	while (p && (j < i - 1)) {
		p = p->next;
		j++;
	}
	//判断index是否合理。
	if (!p || j > i - 1)return ERROR;

	LinkList pNew = (LinkList)malloc(sizeof(LNode));
	pNew->data = e;
	pNew->next = p->next;	//新节点的指针域指向p的下一个节点
	p->next = pNew;			//将p的指针域指向新节点pNew
	return OK;
}

//单链表的删除
Status ListDelete(LinkList &L, int i, ElemType &e) {
	//在头节点为L的链表中，删除第i个元素
	LinkList p = (LinkList)malloc(sizeof(LNode));
	int j = 0;
	p = L;
	//查找第i-1个节点，p指向该节点
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		j++;
	}
	//判断i是否合理。
	if (!(p->next) || (j > i - 1))return ERROR;
	LinkList temp = (LinkList)malloc(sizeof(LNode));	//初始化临时节点，被删节点为p的下一个节点。
	e = p->next->data;
	temp = p->next;										//临时保存被删节点的地址以备释放
	p->next = temp->next;								//改变删除节点的前驱结点的指针域
	free(temp);
	return OK;
}
