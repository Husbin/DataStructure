#include"DublexLink_List_H.h"
int main() {
	PDULNODE pHead = create_dubleLink_List();
	traverse_duleLink_List(pHead);
	insertElem(pHead, 2, 9);
	traverse_duleLink_List(pHead);
	deleteElem(pHead, 2);
	traverse_duleLink_List(pHead);
	return 0;
}