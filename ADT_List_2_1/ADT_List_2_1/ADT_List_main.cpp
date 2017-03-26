#include"ADT_List_H.h"
#include"stdio.h"

int main() {
	SqList L;
	int len = MAXSIZE;
	int temp;
	InitList(L);
	for (int i = 0; i < 5; i++) {
		L.elem[i] = i + 1;
		L.length++;
	}
	printf("遍历结果：");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
	}
	printf("\n");
	GetElem(L, 2, temp);
	printf("第2个元素为：%d\n", temp);
	temp = LocateElem(L, 2);
	printf("存放数据为2的地址为：%d", temp);
	printf("\n");
	ListInsert(L, 2, 6);
	printf("在第二个位置插入元素6后遍历输出：");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
	}
	printf("\n");
	ListDelete(L, 2);
	printf("删除第二个元素，重新遍历输出：");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
	}
	printf("\n");
}