#include <iostream>
#include<stdio.h>
#include <stdlib.h>

typedef int ElementType;

/*树的定义*/
typedef struct TreeNode *BinTree;
typedef BinTree Position ;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
void PreorderTraversal(BinTree BT);//先序
void InorderTraversal(BinTree BT);//中序
void PostorderTraversal(BinTree BT);//后序
BinTree BuildTree();//构造二叉树
/*队列的定义*/
#define MaxQSize 100
typedef struct QNode *PtrToQNode;
struct QNode {
    Position *PtrData;//树的地址数组
    int Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
Queue CreateQueue(int MaxSize); /*创建队列*/
bool IsEmptyQ(Queue Q); /*判断队列是否为空*/
bool AddQ(Queue Q, BinTree BT); /*入队操作*/
Position DeleteQ(Queue Q); /*出队操作*/
int main(){
    BinTree BT;
    BT = BuildTree();
    printf("先序遍历结果：\n");
    PreorderTraversal(BT);//先序
    printf("\n");
    printf("中序遍历结果：\n");
    InorderTraversal(BT);//中序
    printf("\n");
    printf("后序遍历结果：\n");
    PostorderTraversal(BT);//后序
    return 0;
}
BinTree BuildTree(){
    BinTree BT,T;
    ElementType Data;
    Queue Q = CreateQueue(MaxQSize);
//建立根结点
    printf("请按层序依次输入结点：\n");
    scanf("%d", &Data);
    if(Data !=0){
        BT = (BinTree)malloc(sizeof(struct TreeNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q, BT);//结点地址入队
    }
    else
        return NULL;//返回空树
    while (!IsEmptyQ(Q))
    {
        T = DeleteQ(Q);//队列中取出一个结点地址
        scanf("%d", &Data);//读入左子结点
        if(Data == 0)
            T->Left = NULL;
        else{
            T->Left = (BinTree)malloc(sizeof(struct TreeNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        scanf("%d", &Data);//读入右子结点
        if(Data==0)
            T->Right = NULL;
        else{
            T->Right = (BinTree)malloc(sizeof(struct TreeNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
    }
    return BT;
}
void PreorderTraversal( BinTree BT )//递归先序遍历
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}
void InorderTraversal( BinTree BT )//递归中序遍历
{
    if( BT ) {
        InorderTraversal( BT->Left );
        printf("%d ", BT->Data);
        InorderTraversal( BT->Right );
    }
}
void PostorderTraversal( BinTree BT )//递归后序遍历
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}
Queue CreateQueue( int MaxSize ) //创建队列
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->PtrData = (Position*)malloc(MaxSize * sizeof(Position));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
bool IsEmptyQ(Queue Q)
{
    return (Q->Rear==Q->Front);
}
bool AddQ( Queue Q, Position BT ) //插入操作
{
    Q->Rear = (Q->Rear+1) % (Q->MaxSize);
    Q->PtrData[Q->Rear] = BT;
    return true;
}
Position DeleteQ( Queue Q ) //删除操作
{
    if(!IsEmptyQ(Q)) {
        Q->Front =(Q->Front+1) % (Q->MaxSize);
        return Q->PtrData[Q->Front];
    }
    return NULL;
}
