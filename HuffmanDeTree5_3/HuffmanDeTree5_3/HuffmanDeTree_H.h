#pragma once
//HuffmanDeTree_H.h
#include<iostream>
#include<fstream>
#define MAX_MA 1000
#define MAX_ZF 100
using namespace std;
typedef struct
{
	int weight;  //结点的权值
	int parent, lchild, rchild;//双亲，左孩子，右孩子的下标
}HTNode, *HuffmanTree;  //动态分配数组来储存哈夫曼树的结点

						//哈夫曼编码表的储存表示
typedef char **HuffmanCode;//动态分配数组存储哈夫曼编码

void Select(HuffmanTree HT, int n, int &s1, int &s2);

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n);

void CreateHuffmanTree(HuffmanTree &HT, int n, int*cou);

void TranCode(HuffmanTree HT, char a[], char zf[], char b[], int n);

void menu();

int Count(HuffmanTree &HT, int cou[], char* zf);
