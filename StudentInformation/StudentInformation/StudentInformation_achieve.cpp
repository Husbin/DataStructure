#include"StudentInformation_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


Status InitSqList(SqList &SL) {
	int len;						//设置学生个数
	printf("请输入学生个数：");
	scanf("%d", &len);
	SL.elem = new Student[MAXSIZE];
	if (SL.elem == NULL) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	SL.length = len;
	return OK;
}

Status InputInformation(SqList &SL) {
	int i;
	for ( i = 0; i < SL.length; i++) {
		char ch_no[8];
		char ch_name[20];
		int price = 0;
		printf("请输入第%d个学生的信息：\n", i + 1);
		printf("学号：");
		scanf("%s", ch_no);
		strcpy(SL.elem[i].no,ch_no);
		printf("姓名：");
		scanf("%s", ch_name);
		strcpy_s(SL.elem[i].name,ch_name);
		printf("成绩：");
		scanf("%d", &price);
		SL.elem[i].price = price;
	}
	printf("录入信息完成！\n");
	return OK;
}

Status TraverseInformation(SqList SL) {
	if (SL.elem == NULL) {
		printf("顺序表数据为空，输出失败！\n");
		return ERROR;

	}
	for (int i = 0; i < SL.length; i++) {
		printf("输出第%d个学生信息：\n", i + 1);
		printf("学号：%s  姓名：%s  成绩：%d\n", SL.elem[i].no, SL.elem[i].name, SL.elem[i].price);
	}
	printf("信息输出完毕！\n");
	return OK;
}

Status SearchByName(SqList SL, char* name) {
	int count = SL.length;	//统计学生数
	if (SL.elem == NULL) {
		printf("顺序表数据为空，查找失败！\n");
		return ERROR;
	}
	for (int i = 0; i < SL.length; i++) {
		if (strcmp(SL.elem[i].name , name) == 0) {
			printf("%s的信息如右：学号：%s  成绩：%d\n", SL.elem[i].name, SL.elem[i].no, SL.elem[i].price);
			count--;
		}
	}
	if (count == SL.length) {
		printf("顺序表中无此人信息！\n");
		return OK;
	}
}

Status SerchByPos(SqList SL, int pos) {
	if (pos > SL.length || pos < 1) {
		printf("输入的指定位置非法！\n");
		return ERROR;
	}
	else {
		printf("输出第%d个学生信息：\n", pos);
		printf("学号：%s  姓名：%s  成绩：%d\n", SL.elem[pos - 1].no, SL.elem[pos - 1].name, SL.elem[pos - 1].price);
		return OK;
	}
}
//S为要插入的数据，在pos之前插入S元素。
Status InsertInformation(SqList &SL, int pos) {		
	if (pos < 1 || pos > SL.length + 1) {
		printf("输入的指定位置非法！\n");
		return ERROR;
	}
	Student S;
	printf("请输入第%d个学生的信息：\n", pos);
	printf("学号：");
	scanf("%s", S.no);
	printf("姓名：");
	scanf("%s", S.name);
	printf("成绩：");
	scanf("%d", &S.price);
	for (int j = SL.length - 1; j >= pos - 1; j--) {
		strcpy(SL.elem[j + 1].name, SL.elem[j].name);
		strcpy(SL.elem[j + 1].no, SL.elem[j].no);
		SL.elem[j + 1].price = SL.elem[j].price;
	}
	strcpy(SL.elem[pos - 1].name, S.name);
	strcpy(SL.elem[pos - 1].no, S.no);
	SL.elem[pos - 1].price = S.price;
	SL.length++;
	printf("插入成功！\n");
	return OK;
}

Status DeleteInformation(SqList &SL, int pos) {
	if (pos > SL.length - 1 || pos < 1) {
		printf("输入的指定位置非法！\n");
		return ERROR;
	}
	for (int i = pos - 1; i < SL.length; i++) {
		strcpy(SL.elem[i].name, SL.elem[i + 1].name);
		strcpy(SL.elem[i].no, SL.elem[i + 1].no);
		SL.elem[i].price = SL.elem[i + 1].price;
	}
	SL.length--;
	printf("删除成功！\n");
	return OK;
}

int SqListLength(SqList SL) {
	return SL.length;
}