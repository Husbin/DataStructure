//HuffmanDeTree_main

#include<iostream>
#include<fstream>
#include"HuffmanDeTree_H.h"
using namespace std;
void main()
{
	HuffmanTree HT = NULL;//初始化树为空数
	int falg;//记录要编码的字符个数
	char a[MAX_MA];//储存输入的二进制字符
	char b[MAX_ZF];//存储译出的字符
	char zf[MAX_ZF];//储存要编码的字符
	HuffmanCode HC = NULL;//初始化编码表为空表
	ofstream output_Code;
	menu();
	while (true)
	{
		int num;
		cout << "请选择功能: ";
		cin >> num;
		switch (num)
		{
		case 1:
			int cou[100];
			for (int i = 0; i < 100; i++) {
				cou[i] = 0;
			}
			falg = Count(HT , cou , zf);
			break;
		case 2:
			CreatHuffmanCode(HT, HC, falg);//调用创建哈夫曼编码表的函数
			cout << endl;
			cout << "生成哈夫曼编码表成功！,下面是该编码表的输出：" << endl;
			cout << endl;
			cout << "结点i" << "\t" << "字符" << "\t" << "权值" << "\t" << "编码" << endl;
			for (int i = 1; i <= falg; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HC[i] << endl;
			}
			output_Code.open("F:\\Code.txt");
			if (!output_Code) {
				cout << "can'toenfile!" << endl;
				return ;
			}
			for (int i = 1; i <= falg; i++)
			{
				output_Code << "(" << zf[i] << HC[i] << ")";
			}
			output_Code.close();
			cout << "赫夫曼树已经创建完毕，并且已经放入Code.txt文件中!" << endl;
			cout << endl;
			break;
		case 3:
			cout << "请输入想要翻译的一串二进制编码：";
			/*这样可以动态的直接输入一串二进制编码，因为这样输入时最后系统会自动加一个结束符*/
			cin >> a;
			TranCode(HT, a, zf, b, falg);//调用译码的函数，
			/*这样可以直接把数组b输出，因为最后有在数组b添加输出时遇到结束符会结束输出*/
			cout << endl;
			cout << "译码成功！翻译结果为：" << b << endl;
			cout << endl;
			break;
		case 4:
			cout << endl;
			cout << "退出成功！" << endl;
			exit(0);
		default:
			break;
		}
	}

}