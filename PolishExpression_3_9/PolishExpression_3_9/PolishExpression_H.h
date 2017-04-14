#pragma once
//用栈实现兰波表达式求值
#define OK true
#define ERROR false
#define OVERFLOW -1
#define MAXSIZE 100

typedef float ElemType;
typedef bool Status;



typedef struct Stack {
	ElemType *base;
	ElemType *top;
	int stacksize;
}STACK;

Status InitStack(STACK &S);
Status StackFull(STACK S);
Status Push(STACK &S, ElemType e);
Status StackEmpty(STACK S);
ElemType Pop(STACK &S);
void PolishExpression();



//（4）从键盘上输入一个后缀表达式，试编写算法计算表达式的值。规定：逆波兰表达式的长度不超过一行，以$符作为输入结束，操作数之间用空格分隔, 
//操作符只可能有 + 、 - 、*、 / 四种运算。例如：234 34 + 2 * $。
//[题目分析]
//逆波兰表达式(即后缀表达式)求值规则如下：设立运算数栈OPND, 对表达式从左到右扫描(读入)，当表达式中扫描到数时，压入OPND栈。
//当扫描到运算符时，从OPND退出两个数，进行相应运算，结果再压入OPND栈。这个过程一直进行到读出表达式结束符$，这时OPND栈中只有一个数，就是结果。
//[算法描述]
//float expr()
//从键盘输入逆波兰表达式，以‘$’表示输入结束，本算法求逆波兰式表达式的值。
//｛
//float OPND[30];   // OPND是操作数栈。
//init(OPND);       //两栈初始化。
//float num = 0.0;    //数字初始化。
//cin >> x;//x是字符型变量。
//while (x != ’$’)
//{
//	switch
//	{case‘0’ <= x <= ’9’:
//	while ((x >= ’0’&&x <= ’9’) || x == ’.’)  //拼数
//		if (x != ’.’)   //处理整数
//		{
//			num = num * 10 + （ord(x) - ord(‘0’)）; cin >> x;
//		}
//		else           //处理小数部分。
//		{
//			scale = 10.0; cin >> x;
//			while (x >= ’0’&&x <= ’9’)
//			{
//				num = num + (ord(x) - ord(‘0’) / scale;
//				scale = scale * 10;  cin >> x;
//			}
//		}//else
//	push(OPND, num); num = 0.0;//数压入栈，下个数初始化
//	case x = ‘ ’ : break;  //遇空格，继续读下一个字符。
//	case x = ‘ + ’:push(OPND, pop(OPND) + pop(OPND)); break;
//	case x = ‘ - ’:x1 = pop(OPND); x2 = pop(OPND); push(OPND, x2 - x1); break;
//	case x = ‘*’:push(OPND, pop(OPND)*pop(OPND)); break;
//	case x = ‘ / ’:x1 = pop(OPND); x2 = pop(OPND); push(OPND, x2 / x1); break;
//	default:       //其它符号不作处理。
//	}//结束switch
//	cin >> x;//读入表达式中下一个字符。
//}//结束while（x！=‘$’）
//cout << “后缀表达式的值为” << pop(OPND);
//}//算法结束。
//[算法讨论]假设输入的后缀表达式是正确的，未作错误检查。算法中拼数部分是核心。若遇到大于等于‘0’且小于等于‘9’的字符，认为是数。
//这种字符的序号减去字符‘0’的序号得出数。对于整数，每读入一个数字字符，前面得到的部分数要乘上10再加新读入的数得到新的部分数。
//当读到小数点，认为数的整数部分已完，要接着处理小数部分。小数部分的数要除以10（或10的幂数）变成十分位，百分位，千分位数等等，与前面部分数相加。
//在拼数过程中，若遇非数字字符，表示数已拼完，将数压入栈中，并且将变量num恢复为0，准备下一个数。
//这时对新读入的字符进入‘ + ’、‘ - ’、‘*’、‘ / ’及空格的判断，因此在结束处理数字字符的case后，不能加入break语句。
