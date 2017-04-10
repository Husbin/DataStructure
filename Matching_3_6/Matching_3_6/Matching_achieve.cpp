#include "Matching_H.h"
#include "stdio.h"
#include "stdlib.h"

Status InitStack(STACK &S) {
	S.base = new ElemType[MAXSIZE];
	if (S.base == NULL) {
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(STACK &S , ElemType e) {
	if (S.top - S.base == MAXSIZE) {
		printf("栈满！\n");
		return ERROR;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(STACK &S, ElemType& e) {
	if (S.top == S.base) {
		printf("栈空！\n");
		return ERROR;
	}
	S.top--;
	e = *S.top;
	return OK;
}

ElemType getTop(STACK S) {
	//取栈顶元素
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}

Status Matching() {
	//检验表达式中所含有括号是否正确匹配，如果匹配，返回true，否则返回false
	//表达式以 # 结束
	STACK S;
	char ch ;					//输入字符
	char x;
	InitStack(S);
	int flag = 1;					//标记匹配结果以控制循环及返回结果
	scanf("%c", &ch);
	while (ch != '#' && flag == 1) {		//表达式以 # 结尾
		switch (ch) {
		case '(':					//若是左括号，则将其压入栈
		case '[':
			Push(S, ch);
			break;
		case ')':					//若是“）”，则根据当前栈顶元素的值分情况考虑
			if (S.base != S.top && getTop(S) == '(') {
				Pop(S, x);			//若栈非空且栈顶元素是“（”，则正确匹配
				//printf("%c", getTop(S));
				//printf("%c\n", x);
			}
			else flag = 0;			//若栈空或栈顶元素不是“（”，则错误匹配
			break;
		case ']':					//若是“]”，则根据当前站定元素的值分情况考虑
			if (S.base != S.top && getTop(S) == '[') {
				Pop(S, x);			//若栈非空且栈顶元素是“[”，则正确匹配
				//printf("%c", getTop(S));
				//printf("%c\n", x);
			}
			else flag = 0;			//若栈空或栈顶元素不是“[”，则错误匹配
			break;
		}
		scanf("%c", &ch);
	}
	if (S.base == S.top && flag == 1) {
		printf("匹配成功！\n");
		return true; 
	}
	else {
		printf("匹配失败！\n");
		return false;
	}
}