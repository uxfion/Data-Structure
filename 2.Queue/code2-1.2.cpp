#include <stdio.h>
#include <stdlib.h>
#define MaxQSize 1000
#define NA 2
#define NB 1
typedef int ElementType;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
Queue CreateQueue(int MaxSize); /*创建队列*/
bool IsEmptyQ(Queue Q); /*判断队列是否为空*/
bool AddQ(Queue Q, ElementType X); /*入队操作*/
ElementType DeleteQ(Queue Q); /*出队操作*/
int main()
{
    int N, Customer, i;
    Queue A, B;
    A = CreateQueue(MaxQSize);
    B = CreateQueue(MaxQSize);
/*按照输入格式依次读取数据并入队*/
    printf("要输入数据的个数：");
    scanf("%d", &N);
    printf("输入入队元素：");
    for (i = 0; i < N;i++){
        scanf("%d", &Customer);
        if(Customer % 2 == 1)
            AddQ(A, Customer);
        if(Customer % 2 == 0)
            AddQ(B, Customer);
    }
/*输出顾客编号*/
    printf("输出结果：");
    while (N)
    {
        for (i = 0; i < NA;i++){
            if (!IsEmptyQ(A))
            {
                printf("%d ", DeleteQ(A));
                N--;
            }
            if(IsEmptyQ(A)){
                while (N--)
                    printf("%d ", DeleteQ(B));
                return 0;
            }
        }
        for (i = 0; i < NB;i++){
            if (!IsEmptyQ(B))
            {
                printf("%d ", DeleteQ(B));
                N--;
            }
            if(IsEmptyQ(B)){
                while (N--)
                    printf("%d ", DeleteQ(A));
                return 0;
            }
        }
    }
    return 0;
}
Queue CreateQueue( int MaxSize ) //创建队列
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
bool IsEmptyQ(Queue Q)
{
    return (Q->Rear==Q->Front);
}
bool AddQ( Queue Q, ElementType X ) //插入操作
{
    Q->Rear = (Q->Rear+1) % (Q->MaxSize);
    Q->Data[Q->Rear] = X;
    return true;
}
ElementType DeleteQ( Queue Q ) //删除操作
{
    if(!IsEmptyQ(Q)) {
        Q->Front =(Q->Front+1) % (Q->MaxSize);
        return Q->Data[Q->Front];
    }
}
