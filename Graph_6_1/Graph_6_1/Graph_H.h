//Graph_H.h
#pragma once
//图的邻接矩阵存储表示
#define MaxInt 32767			//表示极大值，即无穷
#define MVNum 100				//最大顶点数
#define OK true
#define ERROR false
typedef bool Status;
typedef char VerTexType;		//假设顶点的数据为字符型
typedef int ArcType;			//假设边 的权值类型为整型
typedef struct {
	VerTexType vexs[MVNum];		//顶点表
	ArcType arcs[MVNum][MVNum];	//邻接矩阵
	int vexnum, arcnum;			//图的当前点数和边数
}AMGraph;


//图的邻接表存储表示
typedef struct ArcNode {		//边节点
	int adjvex;					//该边所指向的顶点的位置
	struct ArcNode * nextArc;	//指向下一条边的指针
	//和边相关的其他信息
}AecNode ,*LAecNode;
typedef struct VNode {			//顶点信息
	VerTexType data;			//存放顶点名称或其他信息
	ArcNode *firstArc;			//指向第一条依附该顶点的边的指针
}VNode ,AdjList[MVNum];			//AdjList表示邻接表的类型
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;			//图的当前顶点数和边数
}ALGraph;

//普里姆算法辅助数组,用来记录从顶点集U到V-U的权值最小的边
typedef struct CLOSEDGE{
	VerTexType adjvex;			//最小边在U中的那个顶点
	ArcType lowcost;			//最小边上的权值
}Closedge;


//采用邻接矩阵表示法，创建无向网G
Status CreateUDN_Matrix(AMGraph &G);
//遍历顶点数组，获取确定一条边的两个顶点的下标
int LocateVex(AMGraph G, char v);
//遍历输出邻接矩阵
void TraverseMatrix(AMGraph G);

//采用邻接表表示法创建无向图
Status CreateUDN_List(ALGraph &G);
//(邻接表表示法)遍历顶点数组，获取确定一条边的两个顶点的下标
int LocateVex(ALGraph G, char v);
//DFS深度优先搜索遍历邻接图
void DFS_AL(ALGraph G, int v , bool*);
//普里姆算法,无向网G以邻接矩阵的形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
void MiniSpanTree_Prim(AMGraph G, VerTexType u);



