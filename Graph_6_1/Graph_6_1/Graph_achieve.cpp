//Graph_achieve.cpp
#include"Graph_H.h"
#include<stdio.h>
#include<stdlib.h>

//(邻接矩阵表示法)遍历顶点数组，获取确定一条边的两个顶点的下标
int LocateVex_1(AMGraph G, char v) {
	int flag = 0;
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i]== v) {
			flag++;
			return i;
		}
	}
	if (flag == 0) {
		printf("输入有误，找不到%c点。\n", v);
		return ERROR;
	}
}
//(邻接表表示法)遍历顶点数组，获取确定一条边的两个顶点的下标
int LocateVex_2(ALGraph G, char v) {
	int flag = 0;
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == v) {
			flag++;
			return i;
		}
	}
	if (flag == 0) {
		printf("输入有误，找不到%c点。\n", v);
		return ERROR;
	}
}

//采用邻接矩阵表示法，创建无向网G
Status CreateUDN_Matrix(AMGraph &G) {
	//
	printf("-------------邻接矩阵表示法创建无向图--------------\n");
	printf("输入图的总点数（不超过100）：");
	scanf("%d", &G.vexnum);
	printf("输入图的总边数：");
	scanf("%d", &G.arcnum);
	//初始化输入顶点的信息
	for (int i = 0; i < G.vexnum; i++) {
		//fflush(stdin); 不能用
		printf("请输入第%d个顶点：", i + 1);
		//scanf("%*[^\n]");不能用
		//scanf(" %c", &G.vexs[i]);逼格低
		scanf("%*[\t\n\r]");//高逼格
		scanf("%c", &G.vexs[i]);
	}
	//初始化邻接矩阵，边的权值均置为极大值MaxInt
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	//构造邻接矩阵
	//一条边依附的定点以及权值
	char v1, v2;
	int weight;
	for (int k = 0; k < G.arcnum; k++) {
		printf("请依次输入确定第%d条边的两个顶点：" ,k + 1);
		scanf("%*[\t\n\r]");
		scanf("%c%c", &v1, &v2);
		//确定v1和v2在G中的位置，即顶点数组的下标
		int i = LocateVex_1(G, v1);
		int j = LocateVex_1(G, v2);
		printf("请输入边<%c , %c>的权值：",v1, v2);
		scanf("%*[\t\n\r]");
		scanf("%d", &weight);
		G.arcs[i][j] = weight;
		//无向图，邻接矩阵对称
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

//遍历输出邻接矩阵
void TraverseMatrix(AMGraph G) {
	printf("邻接矩阵输出如下：\n");
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			printf("%d\t\t", G.arcs[i][j]);
		}
		printf("\n\n");
	}
}
//采用邻接表表示法创建无向图
Status CreateUDN_List(ALGraph &G) {
	printf("-------------邻接表表示法创建无向图--------------\n");
	//输入总顶点数，总边数
	printf("输入图的总点数（不超过100）：");
	scanf("%d", &G.vexnum);
	printf("输入图的总边数：");
	scanf("%d", &G.arcnum);
	//输入各个顶点的值，构造表头节点表
	for (int i = 0; i < G.vexnum; i++) {
		printf("请输入第%d个顶点：", i + 1);
		scanf("%*[\t\n\r]");
		scanf("%c", &G.vertices[i].data);	//输入顶点的值
		G.vertices[i].firstArc = NULL;		//初始化表头节点的指针域为NULL
	}
	//输入各边，构造邻接表
	//一条边依附的定点以及权值
	char v1, v2;
	int weight;
	for (int k = 0; k < G.arcnum; k++) {
		printf("请依次输入确定第%d条边的两个顶点：", k + 1);
		scanf("%*[\t\n\r]");
		scanf("%c%c", &v1, &v2);
		//确定v1和v2在G中的位置，即顶点G.vertics中的序号
		int i = LocateVex_2(G, v1);
		int j = LocateVex_2(G, v2);
		LAecNode p1 = (LAecNode)malloc(sizeof(ArcNode));//生成一个新节点*p1
		p1->adjvex = j;									//邻接点序号为j
		//将新节点*p1插入定点vi的边表头部
		p1->nextArc = G.vertices[i].firstArc;
		G.vertices[i].firstArc = p1;

		AecNode *p2 = new AecNode();//生成一个新节点*p2
		p2->adjvex = i;									//邻接点序号为i
		//将新节点*p2插入定点vj的变表头部
		p2->nextArc = G.vertices[j].firstArc;
		G.vertices[j].firstArc = p2;	
	}
	return OK;
}
//DFS深度优先搜索遍历邻接图
void DFS_AL(ALGraph G, int v, bool* visited) {
	//从第v个顶点出发深度搜索有限遍历图G
	//printf("从第%d个顶点深度优先搜索遍历图G如下：\n" , v);
	visited[v] = true;
	AecNode *p = new AecNode();
	p = G.vertices[v].firstArc;//p指向v的边链表的第一个边节点
	printf("%c\t\t", G.vertices[v].data);
	while (p != NULL) {		//边节点非空
		int w = p->adjvex;	//表示w是v的邻接点
		if (!visited[w]) {	//如果w未访问，则递归调用DFS_AL
			DFS_AL(G, w , visited);
		}
		p = p->nextArc;		//p指向下一个节点
	}
}
void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
	Closedge closedge[MVNum];
	int k = LocateVex_1(G, u);				//k为顶点u的下标
	for (int j = 0; j < G.vexnum; j++) {	//对V-U的每一个顶点vj，初始化closedge[j]
		if (j != k) {
			closedge[j] = { u , G.arcs[k][j] };//{adjvex , lowcost}
		}
	}
	closedge[k].lowcost = 0;				//初始化，U = {u}
	//选择其余n-1个顶点，生成n-1条边，（n = G.vexnum）
	for (int i = 1; i < G.vexnum; i++) {
		//k = Min(closedge);
		int min = MaxInt;
		int j = 1;
		int k = 0;
		while (j < G.vexnum)
		{
			//如果两个顶点之间存在边并且权值小于min  
			if (closedge[j].lowcost != 0 && closedge[j].lowcost<min)
			{
				min = closedge[j].lowcost;
				k = j;
			}
			++j;
		}	
		//求出下一个节点：第K个定点，closedge[k]中存有当前最小的边
		char u = closedge[k].adjvex;		//u为最小边的一个顶点
		char v = G.vexs[k];					//v为最小边的另一个顶点
		printf(" < %c , %c > ", u, v);			//输出当前最小边
		closedge[k].lowcost = 0;			//第k个顶点并入U集
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost) {//新顶点并入U后重新选择最小边
				closedge[j] = { G.vexs[k] , G.arcs[k][j] };
			}
		}
	}
}