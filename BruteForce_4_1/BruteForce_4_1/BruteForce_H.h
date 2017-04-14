#pragma once
//串的存储结构


//------------串的定长顺序存储结构--------------------
//静态定义，在编译时确定了串空间的大小
//顺序存储的字符串都是从下标为1的数组分量开始存储的，下标为0的分量闲置不用
#define MAXLEN 255				//串的最大长度
typedef struct {
	char ch[MAXLEN + 1];		//存储串的一维数组
	int length;					//串的当前长度
}SSTRING;

//------------串的堆式顺序存储结构--------------------
//堆（Heap）自由存储区，为每个新产生的串动态分配一块实际串长所需的存储空间
typedef struct {
	char *ch;					//若串非空串，则按串长分配存储区，否则ch为NULL
	int length;					//串的当前长度
}HSTRING;

//------------串的堆链式存储结构----------------------
#define CHUNKSIZE 80			//可由用户定义的块大小
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}CHUNK;
typedef struct {
	Chunk *head, *tail;			//串的头和尾指针
	int length;					//串的当前长度
}LSTRING;

int Index_BF(SSTRING S, SSTRING T, int &pos);