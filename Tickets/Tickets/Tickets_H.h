//Tickets_H.h
#pragma once
//在每个队伍允许插队的情况下，若你在排队，有一个以上的朋友要求插队，你可以安排他们的顺序，
//每次一个人入队，并且如果这个入队的人发现队伍中有自己的朋友，则可以插入到这个朋友的后面，
//当队伍中的朋友不止一个时，这个人会排在最后一个朋友的后面。若队伍中没有朋友，则排在队伍的最后面。
//每一个入队的人都先进行上述判断。当队伍前面的人买到票后，依次出队。

/**基本思路：除留余数法创建哈希表，开放地址法_线性探索法解决冲突。
***1、初始化队伍（依次输入当前队伍的人名，先放入散列表，再入队）
***2、插队（队伍中是否有朋友：无（放入散列表，入队），有（朋友数量，获取哈希值，获取在队列中的索引，找最大，入队））
***3、出队
*/
typedef bool Status;
#define OK true
#define ERROR false
#define OVERFLOW -1
#define MaxSize 2000	//设置队伍最大长度为2000人
#define FriendNum 100	//假设朋友数量不超过100个
static int currentNum = 0;//计算完散列值，入队之后currentNum+1
static int flag = 0;	//判断队伍中是否有此人的标志位,用完即归0


typedef struct HASHTABLE {
	char name[20];		//哈希表的Key为name[0]
	bool flag = false;	//队列中是否有朋友，有为true，没有为false,默认值为false
	bool status = false;//标志位，该单元是否被占用,初始化为false，占用了为true
	long int index;		//记录该key在队列中的索引（入队后赋值）
}HashTable;

//------------队列的顺序存储结构--------------
typedef struct {
	long int *base;		//存储空间的基地址
	int front;			//头指针
	int rear;			//尾指针
	long int hashVal;
}Queue;

//初始化队列
Status InitQueue(Queue &queue);

//初始化哈希表
Status InitHashTab(HashTable *&hashTable);

//计算散列值
long int HashVal(Queue &queue , HashTable* &hashTab, char *name);

//队列入队
Status EnQueue(Queue &queue, HashTable* &hashTab, long int hashVal , bool hasFriend , long int maxIndex);

//队列出队
Status DeQueue(Queue &queue , HashTable* &hashTab ,long int &hashVal , char *name);

//队列的遍历
Status TraverseQueue(Queue queue , HashTable *hashTab);

//初始化队伍
Status InitLine(Queue &queue, HashTable* &hashTable);

//散列表的查找,返回在队伍中的下标
long int SearchHash(Queue queue , HashTable* hashTab, char* name);

//排序，获取队伍中最后一个朋友的位置
long int Sort(long int* friendIndex, int friendNum);
