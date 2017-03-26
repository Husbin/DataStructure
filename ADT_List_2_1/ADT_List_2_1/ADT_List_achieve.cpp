#include"ADT_List_H.h"
#include<stdlib.h>


//构造一个空的顺序链表
Status InitList(SqList &L) {
	L.elem = new ElemType[MAXSIZE];//为顺序链表分配一个大小为MAXSIZE的数组空间
	if (!L.elem) exit(OVERFLOW);	//分配失败
	L.length = 0;					//空链表长度为0
	return OK;
}

// 从顺序表中取值
Status GetElem(SqList L, int i, ElemType &e) {
	if (i < 1 || i >L.length)return ERROR;	//判断i值是否合理，若不合理，返回ERROR
	e = L.elem[i - 1];						//elem[i-1]单元储存第i个数据元素
	return OK;
}

//顺序表的查找
Status LocateElem(SqList L, ElemType e) {
	//在顺序表中查找值为e的数据元素，返回其序号
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)return i + 1;		
	}
	return 0;
}

//在顺序表L中的第i个位置之前插入新的元素e，i的合法范围是1 <= i <= L.length + 1
Status ListInsert(SqList &L, int i, ElemType e) {
	if ((i < 1) || (i > L.length + 1))return ERROR;		//i值不合法
	if (L.length == MAXSIZE) return ERROR;				//当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];						//插入位置之后的元素后移
	}
	L.elem[i - 1] = e;									//将新元素e放在第i个位置
	L.length++;											//表长+1
	return OK;
}

//顺序表的删除
Status ListDelete(SqList &L, int i) {
	//在顺序表L中删除第i个元素，i的合法范围为1 <= i <= L.length
	if (i < 1 || i > L.length)return ERROR;
	if (i == MAXSIZE) return ERROR;
	for (int j = i; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
