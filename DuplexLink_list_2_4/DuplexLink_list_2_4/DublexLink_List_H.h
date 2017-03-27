#pragma once
typedef int ElemType;
typedef bool Status;
#define OK true;
#define ERROR false;
typedef struct duLNode {
	ElemType data;			//数据域
	struct duLNode *prior;	//直接前驱
	struct duLNode *pnext;	//直接后驱
}DULNODE , *PDULNODE;

PDULNODE create_dubleLink_List();
void traverse_duleLink_List(PDULNODE pHead);
Status insertElem(PDULNODE pHead, int index, ElemType elem);
Status deleteElem(PDULNODE &pHead, int index);