#include <stdio.h>
#include <stdlib.h>
/*
0 3
0 4
2 0
3 1
3 2
1 5
5 2
4 5
5 6
*/

#define MaxVertexNum 100

#define MaxQSize 1000

typedef int ElementType;
typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
    ElementType* Data;
    Position Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
/*创建队列*/
Queue CreateQueue(int MaxSize)
{
    Queue tempQ = (Queue)malloc(sizeof(struct QNode));
    tempQ->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    tempQ->Front = tempQ->Rear = 0;
    tempQ->MaxSize = MaxSize;
    return tempQ;
}
/*判断队列是否为空*/
int IsEmptyQ(Queue Q)
{
    return (Q->Front == Q->Rear);
}
/*入队操作*/
int AddQ(Queue Q, ElementType X)
{
    if (Q->Rear == Q->MaxSize)
    {
        printf("Error0:Queue Full!");
        return 0;
    }
    else
    {
        Q->Rear = Q->Rear + 1;
        Q->Data[Q->Rear] = X;
        return 1;
    }
}
/*出队操作*/
ElementType DeleteQ(Queue Q)
{
    if (IsEmptyQ(Q))
    {
        return 0;
    }
    else
    {
        Q->Front = Q->Front + 1;
        return Q->Data[Q->Front];
    }
}

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct GNode* PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    int visited[MaxVertexNum];
    WeightType G[MaxVertexNum][MaxVertexNum];

};
typedef PtrToGNode MGraph;

typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1, V2;

}; typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)
{
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
    {
        Graph->visited[V] = 0;
    }
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = 1;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    printf("输入顶点个数：");
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    printf("输入边数：");
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));

        printf("输入边：\n");
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d", &E->V1, &E->V2);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

void BFS(MGraph Graph, Vertex V, Queue Q)
{
    Vertex W;
    printf("搜索路径：");
    while (!IsEmptyQ(Q))
    {
        V = DeleteQ(Q);
        printf("%d ", V);
        Graph->visited[V] = 1;
        for (W = 0; W < Graph->Nv; W++)
        {
            if ((Graph->G[V][W]) == 1 && !(Graph->visited[W]))
                AddQ(Q, W);
        }
    }
}
int main()
{
    MGraph G1 = BuildGraph();
    int start_num;
    printf("输入起始顶点：");
    scanf("%d", &start_num);
    Queue Q = CreateQueue(20);
    AddQ(Q, start_num);
    BFS(G1, start_num, Q);
    return 0;
}