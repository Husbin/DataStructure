#pragma once
typedef int ElemType;
typedef bool Status;
#define OK true;
#define ERROR false;
typedef struct Node {
	ElemType data;
	struct Node* pNext;
}LNode , *PNODE;


PNODE create_CycleList();
void traverse_CycleList(PNODE pHead);
