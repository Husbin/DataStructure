#pragma once
#define OK true;
#define ERROR false;
typedef int ElemType;
typedef bool Status;


/*---单链表的存储结构---*/
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;


/*---单链表基本操作---*/

//单链表的初始化
Status InitList(LinkList &L);
//单链表的创建（后插法），时间复杂度O（n）
LinkList CreateList_Rear();
//单链表的创建（前插法）,时间复杂度O（n）
LinkList CreateList_Front();
//单链表的取值,时间复杂度为O（n）
Status GetElem(LinkList L, int i, ElemType &e);
//单链表的按值查找,时间复杂度为O（n）
int LocateElem(LinkList L, ElemType e);
//求单链表的长度
int LinkList_Length(LinkList L);
//遍历单链表
void traverse_LinkList(LinkList L);
//判断单链表是否为空
Status isEmpty(LinkList L);
//单链表的插入时间复杂度为O（n）
Status ListInsert(LinkList &L, int i, ElemType e);
//单链表的删除,时间复杂度为O（n）
Status ListDelete(LinkList &L, int i,ElemType &e);

