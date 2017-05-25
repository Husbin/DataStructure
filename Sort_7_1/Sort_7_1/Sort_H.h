#pragma once


#define MAXSIZE 10		//顺序表的最大长度
#define Status bool		
#define OK true
#define ERROR false
typedef struct STUDENT {
	char no[8];
	char name[20];
	int age;
	int score;
}Student , *pStudent;

typedef struct {
	Student s[MAXSIZE+1];	//s[0]闲置或用哨兵单元
	int length;
}SqList;
//输入学生信息
Status InputStuMsg(SqList &SL);
//输出学生信息
Status TraverseStuMsg(SqList SL);
//获取学生数据长度
Status GetLength(SqList &SL);

//获得一轮排序后的排序结果
Status GetSortSatus(SqList SL);


//直接插入排序
void InsertSort(SqList &SL);


//折半插入排序
void BInsertSort(SqList &SL);