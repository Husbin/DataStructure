#include "LinkQueue_H.h"
#include "stdio.h"

int main() {
	LinkQueue Q;
	int val;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	val = GetHead(Q);
	traverse_LinkQueue(Q);
	printf("队头元素为：%d\n", val);
	
	DeQueue(Q, val);
	printf("出队的元素为：%d\n", val);
	val = GetHead(Q);
	printf("队头元素为：%d\n", val);
	traverse_LinkQueue(Q);

	return OK;
}