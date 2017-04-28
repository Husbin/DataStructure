#include"StudentInformation_H.h"
#include<stdio.h>
int main() {
	printf("*******************顺序表操作************************\n");
	SqList SL;
	char name[10];			//按名查找学生信息
	int pos;				//按index查找、插入、删除学生信息
	//InitSqList(SL);
	//InputInformation(SL);
	//TraverseInformation(SL);
	//printf("顺序表按姓名查找，请输入查找的学生姓名：");
	//scanf("%s", name);
	//SearchByName(SL, name);
	//printf("输出指定位置的学生信息，请输入学生的位置：");
	//scanf("%d", &pos);
	//SerchByPos(SL, pos);
	//printf("插入学生信息，请输入插入位置：");
	//scanf("%d", &pos);
	//InsertInformation(SL,pos);
	//TraverseInformation(SL);
	//printf("删除学生信息，请输入删除位置：");
	//scanf("%d", &pos);
	//DeleteInformation(SL, pos);
	//TraverseInformation(SL);
	//pos = SqListLength(SL);
	//printf("顺序表中的数据个数：%d\n" , pos);



	printf("*******************单链表操作************************\n");
	int len;
	LinkList L;
	LinkList pHead;
	InitLinkList(L);
	pHead = CreateList(L);
	TraverseLinkList(pHead);
	printf("单链表按姓名查找，请输入查找的学生姓名：");
	scanf("%s", name);
	LserchByName(pHead, name);
	printf("输出指定位置的学生信息，请输入学生的位置：");
	scanf("%d", &pos);
	LserchByPos(pHead, pos);
	printf("插入学生信息，请输入插入位置：");
	scanf("%d", &pos);
	Insert(pHead, pos);
	TraverseLinkList(pHead);
	printf("删除学生信息，请输入删除位置：");
	scanf("%d", &pos);
	Delete(pHead, pos);
	TraverseLinkList(pHead);
	len = LinkListLength(pHead);
	printf("数据中学生信息有%d个。\n", len);
	return OK;
}