//Tickets_achieve.cpp
#include"Tickets_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//初始化队列
Status InitQueue(Queue &queue) {
	queue.base = new long int[MaxSize];
	if (queue.base == NULL) {
		printf("Memory allocation failed ! And the Queue intialize failed !\n");	//分配内存失败，队列初始化失败！
		return ERROR;
	}
	queue.front = queue.rear = 0;
	return OK;
}

//初始化哈希表
Status InitHashTab(HashTable* &hashTable) {
	hashTable = new HashTable[MaxSize];
	if (hashTable == NULL) {
		printf("Memory allocation failed ! And the HashTable intialize failed !\n");//分配内存失败，哈希表初始化失败！
		return ERROR;
	}
	return OK;
}




//计算散列值
long int HashVal(Queue &queue ,HashTable* &hashTab , char *name) {
	if (hashTab == NULL) {
		printf("Parameter hashTable NULL , calculate hash value failed !\n");
		return ERROR;
	}
	if (name == NULL) {
		printf("Parameter name NULL , calculate hash value failed failed !\n");
		return ERROR;
	}
	int key = name[0] - 'a';
	//该地址单元未被占用
	if (hashTab[key].status == false) {
		strcpy(hashTab[key].name, name);
		hashTab[key].status = true;
		//printf("%d\t", key);
		//printf("%d\t", currentNum);
		return key;
	}
	//该地址单元已被占用
	else {
		int d = 1;
		while (hashTab[(key + d) % (MaxSize - 1)].status) {
			//key = (key + d) % (MaxSize - 1);
			//printf("%d\t", d);
			d++;
		}
		int newKey = (key + d) % (MaxSize - 1);
		strcpy(hashTab[newKey].name, name);
		hashTab[newKey].status = true;
		//printf("%d\t%s\t", newKey , hashTab[newKey].name);
		return newKey;
	}
}

//队列入队
Status EnQueue(Queue &queue, HashTable* &hashTab,long int hashVal, bool hasFriend, long int maxIndex) {
	if (queue.hashVal == NULL) {
		printf("Parameter queue NULL , enter Line failed !\n");
		return ERROR;
	}
	if (hashTab == NULL) {
		printf("Parameter hashTable NULL , enter Line failed !\n");
		return ERROR;
	}
	if (maxIndex < 0 || maxIndex > MaxSize) {
		printf("Error:Friends maxIndex Overflow! EnQueue Error!\n");
		return ERROR;
	}
	//判断队是否满
	if ((queue.rear + 1) % MaxSize == queue.front) {
		printf("Queue Fulling!\n");
		return ERROR;
	}
	//若队伍中没有朋友，或者输入时有朋友，但是查找队伍最终标志位flag为0
	if (!hasFriend || flag == 0) {
		queue.base[queue.rear] = hashVal;
		hashTab[hashVal].index = queue.rear;		//记录哈希元素在队伍中的位置
		queue.rear = (queue.rear + 1) % MaxSize;	//队尾指针加一
	}
	else {
		queue.rear = (queue.rear + 1) % MaxSize;	//队尾指针加一
		queue.base[queue.rear] = hashVal;
		for (int i = queue.rear - 1 ; i > maxIndex; i--) {
			queue.base[i] = queue.base[i - 1];
			//hashTab[hashVal].index = queue.rear;
			//printf("%d\t%d\t\n", queue.base[i], queue.base[i - 1]);
			//printf("%s\t%s\t\n", hashTab[i].name, hashTab[i - 1].name);
		}
		queue.base[maxIndex + 1] = queue.base[queue.rear];
		hashTab[hashVal].index = queue.rear;
		//queue.rear = (queue.rear + 1) % MaxSize;	//队尾指针加一
		flag = 0;									//清除静态标志位
	}
	currentNum++;
	return OK;
}


//队列出队
Status DeQueue(Queue &queue, HashTable* &hashTab ,long int &hashVal , char *name) {
	if (queue.hashVal == NULL) {
		printf("Parameter queue NULL , out Line failed !\n");
		return ERROR;
	}
	if (queue.front == queue.rear) {
		printf("Queue Empty!\n");
		return ERROR;
	}
	hashVal = queue.base[queue.front];	//保存元素值
	strcpy(name, hashTab[hashVal].name);//保存姓名

	//清空哈希值
	strcpy(hashTab[hashVal].name , "");
	hashTab[hashVal].status = false;
	hashTab[hashVal].flag = false;
	hashTab[hashVal].index = -1;
	queue.front = (queue.front + 1) % MaxSize;//队头指针加一
	currentNum--;
	return OK;
}

//队列的遍历
Status TraverseQueue(Queue queue , HashTable* hashTab) {
	if (queue.base == NULL) {
		printf("Parameter queue NULL , Traverse Line failed !\n");
		return ERROR;
	}
	printf("The ranks are arranged as follows ：\n");
	printf("HashVal\tname\t\t\n");
	if (queue.front == queue.rear) {
		printf("Queue Empty！\n");
		return ERROR;
	}
	int count = queue.front;
	while (count != queue.rear) {
		printf("%d\t%s\t\t", queue.base[count], hashTab[queue.base[count]].name);
		//printf("%s\t", hashTab[count].name);
		count = (count + 1) % MaxSize;
	}
	printf("\n");
}


//初始化队伍，当前队伍有26人(默认互不为朋友)，分别为aaa到zzz
//初始化队伍
Status InitLine(Queue &queue, HashTable* &hashTable) {
	if (queue.hashVal == NULL) {
		printf("Parameter queue NULL , intialize Line failed !\n");
		return ERROR;
	}
	if (hashTable == NULL) {
		printf("Parameter hashTable NULL , intialize Line failed !\n");
		return ERROR;
	}
	//初始化队伍，当前队伍有26人(默认互不为朋友)，分别为aaa到zzz
	int hashVal;
	hashVal = HashVal(queue ,hashTable, "aaaa");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal ,hashTable[currentNum].flag ,0);
	hashVal = HashVal(queue, hashTable, "bbbb");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "cccc");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "dddd");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "eeee");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "ffff");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "gggg");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "hhhh");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "iiii");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "jjjj");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "kkkk");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "llll");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "mmmm");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "nnnn");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "oooo");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "pppp");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "qqqq");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "rrrr");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "ssss");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "tttt");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "uuuu");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "vvvv");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "wwww");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "xxxx");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "yyyy");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal( queue, hashTable, "zzzz");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);

	hashVal = HashVal(queue, hashTable, "aabb");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "bbcc");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "gghh");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
}

//散列表的查找
long int SearchHash(Queue queue , HashTable* hashTab, char* name) {
	if (hashTab == NULL) {
		printf("Parameter hashTab NULL , Search Friend failed !\n");
		return ERROR;
	}
	if (name == NULL) {
		printf("Parameter name NULL , Search Friend failed !\n");
		return ERROR;
	}
	int key = name[0] - 'a';
	if (strcmp(name , hashTab[key].name) == 0) {
		flag++;
		return key;
	}
	else {
		for (int i = 1; i < (MaxSize - 1); i++) {
			int newKey = (key + i) % (MaxSize - 1);
			if (hashTab[newKey].name == NULL) {
				printf("The Hash Element Null , search fail!\n");
				return ERROR;
			}
			else if(strcmp(hashTab[newKey].name, name) == 0){
				flag++;
				return newKey;
			}
		}
	}
	if (flag == 0) {
		printf("%s is no in the line.\n" , name);
		return OK;
	}
}

//排序，获取队伍中最后一个朋友的位置
long int Sort(long int* friendIndex, int friendNum) {
	if (friendIndex == NULL || friendNum == 0) {
		printf("Size of friendArray Error , sort and get MaxIndex Error!\n");
		return ERROR;
	}
	int temp = 0;
	for (int i = 0; i < friendNum; i++) {
		for (int j = i + 1; j < friendNum; j++) {
			if (friendIndex[i] > friendIndex[j]) {
				temp = friendIndex[i];
				friendIndex[i] = friendIndex[j];
				friendIndex[j] = temp;
			}
		}
	}
	return friendIndex[friendNum - 1];
}