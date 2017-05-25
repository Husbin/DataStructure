#include"Sort_H.h"
#include<stdio.h>
#include<stdlib.h>
int main() {
	printf("-----------------------------------------------------------------\n");
	printf("输入序号执行指定操作。\n");
	printf("1、直接插入排序法。时间复杂度(O(n²)) 空间复杂度(O(1))。稳定\n");
	printf("2、折半插入排序法。时间复杂度(O(n²)) 空间复杂度(O(1))。稳定\n");
	printf("3、希尔排序法。\n");
	printf("9、清除屏幕。\n");
	printf("10、退出。\n");
	printf("-----------------------------------------------------------------\n");
	int flag;
	while (scanf("%d", &flag)) {
		SqList SL;
		switch (flag) {
		case 1:
			//初始化操作
			InputStuMsg(SL);
			TraverseStuMsg(SL);
			//直接插入排序
			InsertSort(SL);
			TraverseStuMsg(SL);
			break;
		case 2:
			//初始化操作
			InputStuMsg(SL);
			TraverseStuMsg(SL);
			//直接插入排序
			BInsertSort(SL);
			TraverseStuMsg(SL);
			break;
		case 9:
			system("cls");
			break;
		case 10:
			exit(-1);
		}
		
	}
	return OK;
}