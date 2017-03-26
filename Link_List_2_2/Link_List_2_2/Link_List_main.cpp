#include"Link_List_H.h"
#include"stdio.h"

int main() {
	LinkList L;
	int val;
	int cout;
	InitList(L);
	printf("后插法创建单链表。\n");
	L = CreateList_Rear();//后插法
	//printf("前插法创建单链表。\n");
	//L = CreateList_Front();//前插法
	printf("遍历单链表如下：\n");
	traverse_LinkList(L);
	GetElem(L, 2, val);
	printf("取出的数据为：%d\n", val);
	cout = LocateElem(L, 2);
	printf("数据域为2的节点位于第%d个节点。\n", cout);
	cout = LinkList_Length(L);
	printf("单链表的长度为：%d\n", cout);
	printf("执行插入操作：");
	ListInsert(L, 4, 7);
	printf("遍历单链表如下：\n");
	traverse_LinkList(L);
	printf("执行删除操作：");
	ListDelete(L, 4, val);
	printf("删除的数据为%d\n", val);
	printf("遍历单链表如下：\n");
	traverse_LinkList(L);

}