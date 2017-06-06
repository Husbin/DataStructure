//Tickets_main.cpp
#include"Tickets_H.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
	char operation;
	//初始化队列
	InitQueue(queue);
	//初始化哈希表
	InitHashTab(hashTable);
	//初始化队伍，当前队伍有26人(默认互不为朋友)，分别为aaaa到zzzz
	InitLine(queue, hashTable);

	printf("1、Show The Line.\n");
	printf("2、Someone Dequeue.\n");
	printf("3、Someone Enqueue.\n");
	printf("4、Clean The Dos.\n");
	printf("5、Exit The Program.\n");
	printf("Please input the operation:");
	scanf("%*[\t\n\r]");
	while (scanf("%c", &operation)) {
		//对operation进行判断
		if (!(operation >= '1' && operation <= '5')) {
			printf("Parameter operation Error.\n");
			printf("Please input the next operation:");
			scanf("%*[\t\n\r]");
			continue;
		}
		switch (operation) {
		case '1':
			TraverseQueue(queue, hashTable);
			break;
		case '2':
			//买票完毕，出队，哈希码置空
			DeQueue(queue, hashTable, hashVal , name);
			printf("%d %s has already bought the tickets!\n", hashVal, name);
			break;
		case '3':
			//插队
			printf("Enter your name(format:char name[20]):");
			scanf("%*[\t\n\r]");
			scanf("%s", name);
			//判断输入的名字是否存在
			//SearchHash(queue, hashTable, name);
			//if (queue.base[SearchHash(queue, hashTable, name)]) {
			//if(flag != 0){
			//	printf("%s is in the line.\n", name);
			//	printf("Please input the next operation:");
			//	flag = 0;
			//	scanf("%*[\t\n\r]");
			//	continue;
			//}
			printf("Has Friend in line? (Enter:Y/N):  ");
			scanf("%*[\t\n\r]");
			scanf("%c", &hasFriend);
			switch (hasFriend) {
			case 'y':
			case 'Y':
				//计算散列值
				hashVal = HashVal(queue, hashTable, name);
				//printf("%d", hashVal);
				hashTable[hashVal].flag = true;
				printf("How many friends in line(no more than 9):  ");
				scanf("%*[\t\n\r]");
				scanf("%d", &friendNum);
				char ch_FriendNum ;
				ch_FriendNum = '0' + friendNum;
				if (!(ch_FriendNum >= '0' && ch_FriendNum <= '9')) {
					printf("Input Friends Number Error!\n");
					printf("Please input the next operation:");
					scanf("%*[\t\n\r]");
					continue;
				}
				if (friendNum)
					for (int i = 0; i < friendNum; i++) {
						printf("Friend %d Name:", i + 1);
						scanf("%s", name);
						//获取下表数组
						friendIndex[i] = queue.base[SearchHash(queue, hashTable, name)];
						//printf("%d\n", friendIndex[i]);
					}
				//排序取最后一个
				maxIndex = Sort(friendIndex, friendNum);
				//printf("%d", maxIndex);
				//将插队的人插入index为maxIndex后面
				EnQueue(queue, hashTable, hashVal, hashTable[hashVal].flag, maxIndex);
				TraverseQueue(queue, hashTable);
				break;
			case 'n':
			case 'N':
				//计算散列值
				hashVal = HashVal(queue, hashTable, name);
				hashTable[hashVal].flag = false;
				EnQueue(queue, hashTable, hashVal, hashTable[hashVal].flag, 0);
				TraverseQueue(queue, hashTable);
				break;
			default:
				printf("Please Enter Y(y) or N(n).\n");
				break;
			}
			break;
		case '4':
			system("cls");
			printf("1、Show The Line.\n");
			printf("2、Someone Dequeue.\n");
			printf("3、Someone Enqueue.\n");
			printf("4、Clean The Dos.\n");
			printf("5、Exit The Program.\n");
			break;
		case '5':
			exit(OVERFLOW);
		default:
			printf("Parameter operation Error.\n");
			break;
		}
		printf("Please input the next operation:");
		scanf("%*[\t\n\r]");
	}
}
