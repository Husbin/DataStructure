#pragma once
//用链栈实现表达式求值
#define true 1   
#define false 0   
#define OPSETSIZE 8   
typedef int Status;
typedef struct StackChar
{
	char c;
	struct StackChar *next;
}SC;       //StackChar类型的结点SC  

typedef struct StackFloat
{
	float f;
	struct StackFloat *next;
}SF;       //StackFloat类型的结点SF  

float EvaluateExpression(char* MyExpression);
