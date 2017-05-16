//HuffmanDeTree_achieve
#include"HuffmanDeTree_H.h"
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	/*n代表HT数组的长度 */

	//前两个for循环找所有结点中权值最小的点（字符）
	for (int i = 1; i <= n; i++)
	{//利用for循环找出一个双亲为0的结点
		if (HT[i].parent == 0)
		{
			s1 = i;//s1初始化为i
			break;//找到一个后立即退出循环
		}
	}
	for (int i = 1; i <= n; i++)
	{/*利用for循环找到所有结点（字符）权值最小的一个
	 并且保证该结点的双亲为0*/
		if (HT[i].weight < HT[s1].weight && HT[i].parent == 0)
			s1 = i;
	}
	//后两个for循环所有结点中权值第二小的点（字符）
	for (int i = 1; i <= n; i++)
	{//利用for循环找出一个双亲为0的结点，并且不能是s1
		if (HT[i].parent == 0 && i != s1)
		{
			s2 = i;//s2初始化为i
			break;//找到一个后立即退出循环
		}
	}

	for (int i = 1; i <= n; i++)
	{/*利用for循环找到所有结点（字符）权值第二小的一个，
	 该结点满足不能是s1且双亲是0*/
		if (HT[i].weight < HT[s2].weight && HT[i].parent == 0 && i != s1)
			s2 = i;
	}

}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
	int start;
	char *cd;
	HC = new char*[n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	int i, c, f;
	for (i = 1; i <= n; ++i) {
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}      delete cd;
	cout << "HuffmanCode创建完毕" << endl;
}

//构造哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int n, int*cou)
{
	/*-----------初始化工作-------------------------*/
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; ++i)
	{//将1~m号单元中的双亲，左孩子，右孩子的下标都初始化为0
		HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		HT[i].weight = cou[i];//输入前n个单元中叶子结点的权值
	}
	/*-----------创建工作---------------------------*/
	int s1, s2;
	for (int i = n + 1; i <= m; ++i)
	{//通过n-1次的选择，删除，合并来构造哈夫曼树
		Select(HT, i - 1, s1, s2);
		/*cout << HT[s1].weight << " , " << HT[s2].weight << endl;*/
		/*将s1,s2的双亲域由0改为i (相当于把这两个结点删除了，这两个结点不再参与Select()函数)*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		//s1,与s2分别作为i的左右孩子
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		//结点i的权值为s1,s2权值之和
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//哈夫曼译码
void TranCode(HuffmanTree HT, char a[], char zf[], char b[], int n)
{
	int q = 2 * n - 1;//q初始化为根结点的下标
	int k = 0;//记录存储译出字符数组的下标
	int i = 0;
	for (i = 0; a[i] != '\0'; i++)
	{//for循环结束条件是读入的字符是结束符（二进制编码）
	 //此代码块用来判断读入的二进制字符是0还是1
		if (a[i] == '0')
		{/*读入0，把根结点(HT[q])的左孩子的下标值赋给q
		 140          下次循环的时候把HT[q]的左孩子作为新的根结点*/
			q = HT[q].lchild;
		}
		else if (a[i] == '1')
		{
			q = HT[q].rchild;
		}
		//此代码块用来判断HT[q]是否为叶子结点
		if (HT[q].lchild == 0 && HT[q].rchild == 0)
		{/*是叶子结点，说明已经译出一个字符该字符的下标就是找到的叶子结点的下标*/
			b[k++] = zf[q];//把下标为q的字符赋给字符数组b[]
			q = 2 * n - 1;//初始化q为根结点的下标
						  //继续译下一个字符的时候从哈夫曼树的根结点开始
		}
	}
	/*译码完成之后，用来记录译出字符的数组由于没有结束符输出的 时候回报错，故紧接着把一个结束符加到数组最后*/
	b[k] = '\0';
}

//菜单函数
void menu()
{
	cout << " 1.  创建哈夫曼树" << endl;
	cout << " 2.  进行哈夫曼编码 " << endl;
	cout << " 3.  进行哈夫曼译码 " << endl;
	cout << " 4.  退出程序" << endl;
	cout << endl;
}

//计算输入的字母的个数 
int Count(HuffmanTree &HT, int cou[], char* zf) {
	char word;
	int count = 0;
	char letter[27] = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o', 'p','q','r','s','t','u','v','w','x','y','z' };
	fstream SourceFile;
	SourceFile.open("F://SourceFile.txt", ios::in);
	if (!SourceFile) {
		cout << "Can't open this file" << endl;
	}
	while (!SourceFile.eof()) {
		SourceFile.get(word);
		if (word >= 'A'&&word <= 'Z') {
			word = word + 32;
		}
		int i = word - 96;
		cou[i]++;
	}
	SourceFile.close();
	cout << "letter" << '\t' << '\t' << "频率为" << endl;
	for (int j = 1; j <= 26; j++) {
		if (cou[j] != 0) {
			cout << letter[j] << '\t' << '\t' << cou[j] << endl;
			zf[count + 1] = letter[j];
			count++;
		}
	}
	cout << "文件读取完毕。" << endl;
	CreateHuffmanTree(HT, count, cou);//调用创建哈夫曼树的函数
	cout << "创建哈夫曼成功！,下面是该哈夫曼树的参数输出：" << endl;
	cout << endl;
	cout << "结点i" << "\t" << "字符" << "\t" << "权值" << "\t" << "双亲" << "\t" << "左孩子" << "\t" << "右孩子" << endl;
	for (int i = 1; i <= count * 2 - 1; i++)
	{
		cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
	}
	cout << endl;
	return count;
}