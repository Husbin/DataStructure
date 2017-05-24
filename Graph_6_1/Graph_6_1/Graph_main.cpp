//Graph_main.cpp
#include"Graph_H.h"
#include<stdio.h>
#include<string.h>
int main() {

	AMGraph AMG;
	CreateUDN_Matrix(AMG);
	TraverseMatrix(AMG);
	printf("最小生成树的边集如下：\n");
	MiniSpanTree_Prim(AMG, '1');
	printf("\n");
	static bool visited[MVNum];//访问标志数组，其初值为false
	memset(visited, false, sizeof(bool) * MVNum);
	ALGraph ALG;
	CreateUDN_List(ALG);
	printf("从第1个顶点深度优先搜索遍历图G如下：\n");
	DFS_AL(ALG, 0 ,visited);
	printf("\n");
	return OK;
}