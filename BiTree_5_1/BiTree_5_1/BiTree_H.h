#pragma once
typedef char ElemType;

#define MAXSIZE 100

//------------------二叉树的二叉链表存储表示------------------
typedef struct BiTNode {
	ElemType data;						//结点数据域
	struct BiTNode *lchild, *rchild;	//左右孩子指针
}BiTNode , *BiTree;

//先序遍历的顺序建立二叉链表
char CreateBiTree(BiTree &T);
//中序遍历二叉树
void InOrderTraverse(BiTree T);