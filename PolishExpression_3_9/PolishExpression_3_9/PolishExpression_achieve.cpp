#include "PolishExpression_H.h"
#include<stdio.h>
#include<stdlib.h>


Status InitStack(STACK &S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	S.top = S.base;
	return OK;
}

Status StackFull(STACK S) {
	if (S.top - S.base == MAXSIZE) {
		return OK;
	}
	else return ERROR;
}

Status Push(STACK &S, ElemType e) {
	if (StackFull(S)) {
		printf("栈满！\n");
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status StackEmpty(STACK S) {
	if (S.base == S.top) {
		return OK;
	}
	else return ERROR;
}

ElemType Pop(STACK &S) {
	if (StackEmpty(S)) {
		return ERROR;
	}
	ElemType e;
	S.top--;
	e = *S.top;
	return e;
}
//逆波兰表达式(即后缀表达式)求值规则如下：设立运算数栈OPND, 对表达式从左到右扫描(读入)，当表达式中扫描到数时，压入OPND栈。
//当扫描到运算符时，从OPND退出两个数，进行相应运算，结果再压入OPND栈。这个过程一直进行到读出表达式结束符$，这时OPND栈中只有一个数，就是结果。
//以$符作为输入结束，操作数之间用空格分隔,
//操作符只可能有 + 、 - 、*、 / 四种运算。例如：234 34 + 2 * $。
void PolishExpression() {
	static int i = 0;
	STACK OPND;
	InitStack(OPND);
	static char ch[30];
	printf("请输入表达式（以$符作为输入结束，操作数之间用空格分隔）：\n");
	scanf("%c", &ch[i]);

	float num = 0.00;
	float scale = 0.00;
	float x1 = 0.00, x2 = 0.00;
	while (ch[i] != '$') {
		while ((ch[i] >= '0' && ch[i] <= '9') || ch[i] == '.') {  //拼数
			if (ch[i] != '.' && ch[i] != ' ') {				//处理整数
				num = num * 10 + (ch[i] - '0');
				i++;
				scanf("%c", &ch[i]);
			}
			if (ch[i] == '.') {									//处理小数部分。
				scale = 10.0;
				i++;
				scanf("%c", &ch[i]);
				while (ch[i] >= '0' && ch[i] <= '9') {
					num = num + (ch[i] - '0') / scale;
					scale = scale * 10;
					i++;
					scanf("%c", &ch[i]);
				}
			}
		}
		Push(OPND, num);
		num = 0.0;//数压入栈，下个数初始化
		scale = 10.0;
		if (ch[i] == '+') {
			Push(OPND, Pop(OPND) + Pop(OPND));
		}
		if (ch[i] == '-') {
			x1 = Pop(OPND); x2 = Pop(OPND); Push(OPND, x2 - x1);
		}
		if (ch[i] == '*') {
			Push(OPND, Pop(OPND)* Pop(OPND));
		}
		if (ch[i] == '/') {
			x1 = Pop(OPND); x2 = Pop(OPND); Push(OPND, x2 / x1);
		}
		i++;
		scanf("%c", &ch[i]);//读入表达式中下一个字符。
	}
	printf("后缀表达式的值为: %.2f", Pop(OPND));
	printf("\n");
}

