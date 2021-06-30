#include<stdio.h>
#include<stdlib.h>

/*
 *
0 2
0 3
0 4
3 2
3 1
1 5
2 5
4 5
5 6
 */

typedef int Vertex;
#define MaxVertexNum 10
typedef struct GNode *PtrToGNode;//定义图的邻接矩阵
struct GNode{
    int Nv; /*顶点数*/
    int Ne; /*边数*/
    int G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;
typedef struct ENode *PtrToENode;//定义图的边
struct ENode{
    Vertex V1, V2;
};
typedef PtrToENode Edge;
int Visited[MaxVertexNum]={0};/*记录某个顶点是否被访问过*/
void DFS(MGraph Graph, Vertex V);
MGraph CreateGraph(int VertexNum);
MGraph BuildGraph();

int main() {
/*待补充代码 2*/
    Vertex V;
    MGraph Graph=BuildGraph();
    printf("\n 出发顶点:\n");
    scanf("%d", &V);
    DFS(Graph, V);
}

void DFS(MGraph Graph, Vertex V) {
    Vertex W;
    int i;
    printf("%d ", V);
    Visited[V] = 1;
/*待补充代码 1*/
    for (i = 0; i < MaxVertexNum;i++){
        if(Graph->G[V][i]==1){
            W = i;
            if(Visited[W]==0)
                DFS(Graph, W);
        }
    }
}

MGraph CreateGraph(int VertexNum){
    Vertex V, W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = 0;
    return Graph;
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex v1,v2;
    int Nv,w, i;
    printf("请输入顶点个数:\n");
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    printf("请输入边的个数:\n");
    scanf("%d", &(Graph->Ne));
    printf("两两输入有邻边的顶点:\n");
    if(Graph->Ne!=0){
        for (i = 0; i < Graph->Ne;i++){
            scanf("%d %d", &v1, &v2);
            Graph->G[v1][v2] = 1;
            Graph->G[v2][v1] = 1;
        }
    }
    return Graph;
}
