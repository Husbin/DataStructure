#include"Sort_H.h"
#include<stdio.h>
#include<string.h>

//输入学生信息
Status InputStuMsg(SqList &SL) {
	GetLength(SL);		//给SL.length赋值
	if (SL.s == NULL) {
		printf("学生表为空，请先初始化！");
		return ERROR;
	}
	strcpy(SL.s[1].no, "111");
	strcpy(SL.s[1].name, "qqq");
	SL.s[1].age = 11;
	SL.s[1].score = 11;

	strcpy(SL.s[2].no, "999");
	strcpy(SL.s[2].name, "ooo");
	SL.s[2].age = 99;
	SL.s[2].score = 99;

	strcpy(SL.s[3].no, "555");
	strcpy(SL.s[3].name, "ttt");
	SL.s[3].age = 55;
	SL.s[3].score = 55;

	strcpy(SL.s[4].no, "444");
	strcpy(SL.s[4].name, "rrr");
	SL.s[4].age = 44;
	SL.s[4].score = 44;

	strcpy(SL.s[5].no, "888");
	strcpy(SL.s[5].name, "iii");
	SL.s[5].age = 88;
	SL.s[5].score = 88;

	strcpy(SL.s[6].no, "666");
	strcpy(SL.s[6].name, "yyy");
	SL.s[6].age = 66;
	SL.s[6].score = 66;

	strcpy(SL.s[7].no, "222");
	strcpy(SL.s[7].name, "www");
	SL.s[7].age = 22;
	SL.s[7].score = 22;

	strcpy(SL.s[8].no, "777");
	strcpy(SL.s[8].name, "uuu");
	SL.s[8].age = 77;
	SL.s[8].score = 77;

	strcpy(SL.s[9].no, "100");
	strcpy(SL.s[9].name, "ppp");
	SL.s[9].age = 100;
	SL.s[9].score = 100;

	strcpy(SL.s[10].no, "333");
	strcpy(SL.s[10].name, "eee");
	SL.s[10].age = 33;
	SL.s[10].score = 33;

	//for (int i = 1; i < SL.length; i++) {
	//	printf("请输入第%d个学生的信息：\n", i);
	//	//scanf("%*[\t\n\r]");				//清除io缓存
	//	printf("请输入学号：");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%s", SL.s[i].no);
	//	printf("请输入姓名：");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%s", SL.s[i].name);
	//	printf("请输入年龄：");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%d", &SL.s[i].age);
	//	printf("请输入成绩：");
	//	//scanf("%*[\t\n\r]");
	//	scanf("%d", &SL.s[i].score);
	//}
	return OK;
}
//输出学生信息
Status TraverseStuMsg(SqList SL) {
	if (SL.s == NULL) {
		printf("学生表为空，请先初始化！");
		return ERROR;
	}
	printf("--------------------输出学生信息如下----------------------------\n");
	printf("学号\t\t姓名\t\t年龄\t\t分数\t\t\n");
	for (int i = 1; i < SL.length; i++) {	
		printf("%s\t\t%s\t\t%d\t\t%d\t\t\n" , SL.s[i].no,SL.s[i].name,SL.s[i].age,SL.s[i].score);
	}
}

//获取学生数据长度
Status GetLength(SqList &SL) {
	if (SL.s == NULL) {
		printf("学生表为空，请先初始化！");
		return ERROR;
	}
	else {
		SL.length = MAXSIZE + 1;
		//printf("%d\n", SL.length);
	}
}
//获得一轮排序后的排序结果
Status GetSortSatus(SqList SL) {
	if (SL.s == NULL) {
		printf("学生表为空，请先初始化！");
		return ERROR;
	}
	printf("排序过程输出：\n");
	for (int i = 1; i < SL.length; i++) {
		printf("%d\t", SL.s[i].score);
	}
	printf("\n");
}
//均为升序排序
//直接插入排序法
void InsertSort(SqList &SL) {
	if (SL.s == NULL) {
		printf("学生表为空，请先初始化！");
		return ;
	}
	for (int i = 2; i < SL.length; i++) {
		int j;
		if (SL.s[i].score < SL.s[i - 1].score) {		//"<"，需将s[i]插入有序子表
			SL.s[0] = SL.s[i];							//将待插入的记录暂存到监视哨中
			SL.s[i] = SL.s[i - 1];						//将s[i - 1]后移
			for (j = i - 2; SL.s[0].score < SL.s[j].score; j--) {	//从后向前寻找插入位置
				SL.s[j + 1] = SL.s[j];					//记录逐个后移，直到找到插入位置
			}
			SL.s[j + 1] = SL.s[0];						//将s[0]即原r[i]，插入到正确位置
		}		
		GetSortSatus(SL);
	}
}

//折半插入排序法
void BInsertSort(SqList &SL) {
	if (SL.s == NULL) {
		printf("学生表为空，请先初始化！");
		return;
	}
	//对顺序表SL做折半插入排序
	for (int i = 2; i < SL.length; i++) {
		SL.s[0] = SL.s[i];								//将待插入的记录暂存到监视哨中
		int low = 1;									//置查找区间初值
		int high = i - 1;
		while (low <= high) {							//在r[low...high]中折半查找插入的位置
			int m = (low + high) / 2;					//折半
			//插入点在前一子表
			if (SL.s[0].score < SL.s[m].score)high = m - 1;
			//插入点在后一子表
			else low = m + 1;
		}
		//记录后移
		for (int j = i - 1; j >= high + 1; j--) {
			SL.s[j + 1] = SL.s[j];
		}
		//将SL.s[0]即原SL.s[i]，插入到正确的位置
		SL.s[high + 1] = SL.s[0];
		GetSortSatus(SL);
	}
}
