#define MAXSIZE 100	//顺序表可能达到的最大长度
#define  OVERFLOW -1
#define OK true;
#define ERROR false;
typedef bool Status;
typedef int ElemType;


typedef struct {
	ElemType *elem;	//存储空间的基地址
	int length;		//当前长度
}SqList , *PSqList;			//顺序表的结构类型为SqList

Status InitList(SqList &L);//初始化顺序表
Status GetElem(SqList L, int i, ElemType &e);//从顺序表中取值
Status LocateElem(SqList L, ElemType e);	//顺序表的查找
Status ListInsert(SqList &L, int i, ElemType e);//在顺序表L中的第i个位置之前插入新的元素e，i的合法范围是1 <= i <= L.length + 1
Status ListDelete(SqList &L, int i);//顺序表的删除



