#pragma once
typedef bool Status;

#define MAXSIZE 100		//学生最大容量
#define OK true
#define ERROR false
#define OVERFLOW -1


//学生信息的定义
typedef struct {
	char no[8];			//8位学号
	char name[20];		//姓名
	int price;			//成绩
}Student;

//顺序表的定义
typedef struct {
	Student *elem;		//指向数据元素的基地址
	int length;			//线性表的当前长度
}SqList;

//链表的定义
typedef struct LNode{
	Student data;		//数据域
	struct LNode *next;	//指针域
}LNode ,*LinkList;

//初始化顺序表
Status InitSqList(SqList &SL);
//录入学生信息
Status InputInformation(SqList &SL);
//遍历学生信息
Status TraverseInformation(SqList SL);
//根据姓名进行查找，返回此学生的学号和成绩
Status SearchByName(SqList SL, char* name);
//根据指定的位置可返回相应的学生信息（学号，姓名，成绩）
Status SerchByPos(SqList SL, int pos);
//给定一个学生信息，插入到表中指定的位置
Status InsertInformation(SqList &SL, int pos);
//删除指定位置的学生记录(pos - 1位)
Status DeleteInformation(SqList &SL, int pos);
//统计表中学生个数
int SqListLength(SqList SL);

//初始化链表
Status InitLinkList(LinkList &L);