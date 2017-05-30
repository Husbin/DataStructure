#include"Tickets_H.h"
#include<stdio.h>
#include<string.h>
int main() {	
	Queue queue;
	HashTable *hashTable;
	int currNum;		//当前队伍人数
	long int hashVal;	//存储出队人的哈希值
	char name[20];		//插队人姓名
	char hasFriend;
	int friendNum;		//朋友数量
	long int friendIndex[FriendNum];//通过获取朋友的哈希值，得到朋友在队伍中的位置
	long int maxIndex;	//获取最后面朋友的下标
	//初始化队列
	InitQueue(queue);
	//初始化哈希表
	InitHashTab(hashTable);
	//初始化队伍，当前队伍有26人(默认互不为朋友)，分别为aaaa到zzzz
	InitLine(queue, hashTable);

	TraverseQueue(queue, hashTable);

	//买票完毕，出队，哈希码置空
	DeQueue(queue, hashTable, hashVal);
	printf("%d %s has already bought the tickets!\n" , hashVal , hashTable[hashVal].name);
	TraverseQueue(queue, hashTable);
	//插队
	printf("Enter your name:");
	scanf("%*[\t\n\r]");
	scanf("%s", name);
	printf("Has Friend in line? (Enter:Y/N):  ");
	scanf("%*[\t\n\r]");
	scanf("%c", &hasFriend);
	switch (hasFriend) {
	case 'y':
	case 'Y':
		//计算散列值
		hashVal = HashVal(queue ,hashTable, name);
		//printf("%d", hashVal);
		hashTable[hashVal].flag = true;
		printf("How many friends in line:  ");
		scanf("%*[\t\n\r]");
		scanf("%d", &friendNum);
		if(friendNum)
		for (int i = 0; i < friendNum; i++) {
			printf("Friend %d Name:", i + 1);
			scanf("%s", name);
			//获取下表数组
			friendIndex[i] = queue.base[SearchHash(queue ,hashTable, name)];
			//printf("%d\n", friendIndex[i]);
		}
		//排序取最后一个
		maxIndex = Sort(friendIndex, friendNum);
		//printf("%d", maxIndex);
		//将插队的人插入index为maxIndex后面
		EnQueue(queue, hashTable, hashVal , hashTable[hashVal].flag , maxIndex);
		TraverseQueue(queue, hashTable);
		break;
	case 'n':
	case 'N':
		//计算散列值
		hashVal = HashVal(queue,hashTable, name);
		hashTable[hashVal].flag = false;
		EnQueue(queue,hashTable, hashVal, hashTable[hashVal].flag ,0);
		TraverseQueue(queue, hashTable);
		break;
	default:
		printf("Please Enter Y(y) or N(n).\n");
	}
}


//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#include <iostream>
//#define TabSize 2000003           /*散列表大小TabSize 是大于表最大空间的素数*/
//#define Max 1000001              /*队列空间最大值*/
//using namespace std;
//
//class hashtab                     /*散列表数据结构*/
//{
//public:
//	char name[5];                 /*名字*/
//	int group;                    /*属于哪个朋友组*/
//	char info;                    /*标志位，该单元是否被占用*/
//};
//class PtrToHash :public hashtab {};
//
//class Que                         /*队列数据结构*/
//{
//public:
//	long int HashVal;             /*散列值*/
//	long int Index;               /*在中的队列序号*/
//};
//class PtrToQue :public Que {};
//
//int hashedx = 0;                    /*标记元素是否已经在散列表里*/
//long int Findf(PtrToHash *hash, char *c) /*查找在散列表中的位置*/
//{
//	char *key;
//	long int CurrentPos, CollisionNum;
//
//	key = c;
//	for (CurrentPos = 0; *key; ++key)               /*散列函数，计算散列值*/
//		CurrentPos = (CurrentPos << 6) + *key;
//	CurrentPos %= TabSize;                   /*散列值*/
//	CollisionNum = 0;
//	/*如果当前单元被占用：单元内的元素与当前操作的名字不同，使用平方探测法解决冲突；
//	与当前操作的名字相同，则直接返回在散列中的位置*/
//	while ((hash[CurrentPos].info) && (strcmp(hash[CurrentPos].name, c)))
//	{   /*平方探测法*/
//		CurrentPos += 2 * (++CollisionNum) - 1;
//		if (CurrentPos >= TabSize)
//			CurrentPos -= TabSize;
//	}
//	if ((hash[CurrentPos].info) && (strcmp(hash[CurrentPos].name, c) == 0)) /*元素已经在散列表里*/
//		hashedx = 1;
//	else /*元素不在散列表里*/
//		hashedx = 0;
//	return CurrentPos;/*返回在散列表中的位置*/
//}
//
//void main()
//{
//	long int Find(PtrToHash *hash, char *c);   /*查找在散列表中的位置*/
//
//	PtrToHash *hash;                          /*散列表*/
//	PtrToQue *queue;                          /*队列*/
//	int *grouppos;                    /*记录每个朋友组的最后一位，即插队数组*/
//	int n;                                   /*测试用例数目*/
//	int num;                                 /*当前测试用例序号*/
//	long int i, ii, j, key, temp;
//	long int head, last;                     /*队列的头和尾*/
//	char c[8], tempc[8];                     /*名字*/
//	hash = (PtrToHash*)malloc(sizeof(hashtab)*TabSize);
//	queue = (PtrToQue*)malloc(sizeof(Que)*Max);
//	grouppos = (int *)malloc(sizeof(int) * 1000);
//
//	for (i = 0, j = 1; i<Max; ++i, ++j) /*初始化队列，queue[i]的后继单元是queue[i＋1]*/
//		queue[i].Index = j;
//	queue[i - 1].Index = 0; /*最后一个单元的后继单元是第0个，形成环*/
//
//	num = 0;
//	cout << "输入当前测试用例的朋友组数:" << endl;
//	for (cin >> n; n; cin >> n)/*输入当前测试用例的朋友组数*/
//	{
//		if (n<1 || n>1000)      /*处理异常输入n*/
//		{
//			cout << "n is out of range!" << endl;
//		}
//		num++;
//		if (num != 1)                    /*两个测试用例间输入一空行*/
//			cout << "\n";
//		for (i = 0; i<TabSize;)
//			hash[i++].info = 0;         /*初始化散列表，标记位置0*/
//		for (i = 0; i<n; ++i)              /*对每一组朋友*/
//		{
//			cout << "当前组里的人数:" << endl;
//			cin >> j;      /*当前组里的人数*/
//			if (j<1 || j>1000)  /*处理异常输入j*/
//			{
//				cout << "j is out of range!" << endl;
//			}
//			for (; j; --j)
//			{
//				cout << "输入名字:" << endl;
//				cin >> c;    /*输入名字*/
//				for (ii = 0; ii<sizeof(tempc); ii++) /*tempc清空，处理异常输入名字*/
//					tempc[ii] = '\0';
//				strcpy(tempc, c);
//				ii = 0;
//				while (tempc[ii] != '\0')      /* 是否由四个以内字母组成*/
//				{
//					if (tempc[ii]<'A' || ('Z'<tempc[ii] && tempc[ii]<'a') || tempc[ii]>'z' || ii>4)
//					{
//						cout << "Group" << i << ":Not standard name" << endl;
//					}
//					ii++;
//				}
//				key = Find(hash, c); /*找到在散列表中的位置*/
//				if (hashedx == 1) /*重名*/
//				{
//					cout << "Repeated name" << " " << c << endl;
//				}
//				else
//				{
//					strcpy(hash[key].name, c);/*插入散列表*/
//					hash[key].info = 1;      /*标记置1，该单元被占用*/
//					hash[key].group = i;     /*记录他属于哪个组*/
//				}
//			}
//		}
//		for (i = 0; i<1000;)
//			grouppos[i++] = 0; /*初始化插队数组*/
//		head = 0;/*初始化队列头、尾标记*/
//		last = 0;
//		for (cout << "输入命令:I入队/O出队" << endl, cin >> c;; cout << "输入命令:I入队/O出队" << endl, cin >> c) /*输入命令*/
//		{
//
//			if (*c == 'I' || *c == 'i')/*入队命令*/
//			{
//				cout << "输入名字" << endl;
//				cin >> c;    /*输入名字*/
//				key = Find(hash, c);/*查找在散列表中的位置*/
//
//				if (hashedx == 0) /*散列表里没这个人*/
//				{
//					cout << "no" << c << endl;
//				}
//
//				temp = queue[0].Index;   /*队列第0个位置记录队尾的后继单元*/
//				queue[0].Index = queue[temp].Index; /*在队列中申请一个新单元，队尾标记后移一个位置 */
//				queue[temp].HashVal = key; /*入队*/
//				if (!head) /*如果是队列里的第一个元素 */
//					last = head = temp; /*队头、队尾标记指向第一个元素*/
//				if (!grouppos[hash[key].group]) /*如果队列里没朋友*/
//				{
//					queue[temp].Index = 0; /*队尾指向对头，形成环*/
//					queue[last].Index = temp;/*前一次队尾的后继元素是当前元素*/
//					last = temp;           /*队尾标记指向当前元素*/
//					grouppos[hash[key].group] = temp;/*插队数组记录该朋友组里已入队的最后一位*/
//				}
//				else/*如果队列中已经有他的朋友*/
//				{
//					queue[temp].Index = queue[grouppos[hash[key].group]].Index;
//					/*插队到朋友的后面*/
//					queue[grouppos[hash[key].group]].Index = temp;
//					/*插队到朋友后面一位的前面*/
//					grouppos[hash[key].group] = temp;
//					/*替换插队数组里该组的元素为当前元素*/
//					if (hash[queue[last].HashVal].group == hash[key].group)
//						/*如果当前元素和前一元素是朋友，队尾标志指向当前元素*/
//						last = temp;
//				}
//			}
//			else if (*c == 'O' || *c == 'o') /*出队命令*/
//			{
//				if (last == 0)     /*不能对空队列执行出队命令*/
//				{
//					cout << "Empty queue!\nCan't execute DEQUEUE!" << endl;
//				}
//				else
//				{
//					cout << hash[queue[head].HashVal].name << endl;/*输出队头元素到文件*/
//					temp = head;
//					head = queue[temp].Index;   /*队列第一位出队，队头标记后移一位*/
//					queue[temp].Index = queue[0].Index;  /*队列第0个元素后移一位*/
//					queue[0].Index = temp;               /*释放空间*/
//					if (grouppos[hash[queue[temp].HashVal].group] == temp)
//						/*当前删除的元素是该朋友组在队列里的最后一位*/
//						grouppos[hash[queue[temp].HashVal].group] = 0;
//					if (last == temp)            /*出队后，队列为空*/
//						last = 0;
//				}
//			}
//			else                        /*输入 "STOP"*/
//				break;                  /*测试结束*/
//		}
//	}
//}