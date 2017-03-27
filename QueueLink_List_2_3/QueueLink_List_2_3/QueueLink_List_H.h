#pragma once
typedef int ElemType;
typedef bool Status;
#define OK true;
#define ERROR false;
typedef struct Node {
	ElemType data;
	struct Node* pNext;
}LNode , *PNODE;


PNODE create_QueueList();
void traverse_QueueList(PNODE pHead);
