#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MaxSzie 20


//顺序查找
void SequentialSearch(int *numArray , int searchNum , int len);
//执行折半查找之前的排序
void Sort(int* &numArray , int len);
//折半查找
void Search_Bin(int *numArray, int searchNum, int len);
//遍历数组
void TraverseArray(int *numArray, int len);

int main() {
	
	printf("请输入随机整数的个数n：");
	int num;				//随机数的个数
	int numArray[MaxSzie];	//数组存储随机数
	int searchNum;			//要查找的数值
	int len;				//数组的长度
	scanf("%d", &num);
	srand((unsigned)time(NULL)); //为了提高不重复的概率
	for (int i = 0; i < num; i++) {	
		numArray[i] = rand()%(num+100);
	}
	printf("随机数组输出如下：\n");
	TraverseArray(numArray, num);
	len = num;				//获取数组长度
	printf("开始直接查找，请输入要查找的值：");
	scanf("%d", &searchNum);
	SequentialSearch(numArray, searchNum , len);
	printf("开始折半查找，请输入要查找的值：");
	scanf("%d", &searchNum);
	Search_Bin(numArray, searchNum, len);
}

void TraverseArray(int *numArray, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d\t", numArray[i]);
	}
	printf("\n");
}

void SequentialSearch(int *numArray , int searchNum , int len) {
	int status = 0;
	for (int i = 0; i < len; i++) {
		if (numArray[i] == searchNum) {
			printf("查询成功，%d在随机数组numArry的第%d个位置！\n", searchNum, i + 1);
			status++;
			return;
		}
		else {
			printf("查找未完成，此时匹配到的数字为数组中的%d。\n", numArray[i]);
		}
	}
	if (status == 0) {
		printf("查询失败，数组中没有%d这个值！\n", searchNum);
	}
}

void Sort(int* &numArray ,int len) {
	int temp = 0; 
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++){
			if (numArray[i] > numArray[j]) {
				temp = numArray[i];
				numArray[i] = numArray[j];
				numArray[j] = temp;
			}
		}
	}
}

void Search_Bin(int *numArray, int searchNum, int len) {
	int status = 0;
	//查找之前先排序
	Sort(numArray, len);
	printf("排序后的随机数组输出如下：\n");
	TraverseArray(numArray, len);
	//置查找区间初值
	int low = 1;
	int high = len;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (searchNum == numArray[mid]) {
			printf("查询成功，%d在随机数组numArry的第%d个位置！\n", searchNum, mid + 1);
			status++;
			return;
		}
		//继续在前一子表进行查找
		else if (searchNum < numArray[mid]) {
			high = mid - 1;
			printf("查询未完成，继续往前一子表查找：");
			TraverseArray(numArray, high);
		}
		//继续在后一子表进行查找
		else { 
			low = mid + 1;
			printf("查询未完成，继续往后一子表查找：");
			TraverseArray(numArray, low);
		}
	}
	if (status == 0) {
		printf("查询失败，数组中没有%d这个值！\n", searchNum);
	}
}