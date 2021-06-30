//
// Created by HAOMING CHEN on 2021/6/20.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
/*链表定义*/
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Insert( List L, ElementType X)
{
    PtrToNode pre=L; //pre 指向插入节点之前
    PtrToNode InsertNode = (PtrToNode)malloc(sizeof(struct Node));
    InsertNode->Data=X;
    InsertNode->Next=NULL;
    if(pre->Next==NULL) { // insert first node
        InsertNode->Next=pre->Next;
        pre->Next=InsertNode;
        return L;
    }
    else{
        while (X > (pre->Next)->Data) {
            pre=pre->Next;
            if(pre->Next==NULL) break;
        }
        InsertNode->Next=pre->Next; //insert node in middle
        pre->Next=InsertNode;
        return L;
    }
}

List Read()
{
/*读取要输入的数据个数*/
    int num;
    printf("要输入数据个数：");
    scanf("%d", &num);
    int i;
//int a[num];
    int* const a = (int*)malloc(sizeof(int)*num);
    printf("输入数据：");
/*依次读取数据*/
    for(i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
/*建立头结点*/
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    p->Data = -1;
    p->Next = NULL;
    List L = p;
/*将数据依次插入*/
    for(i = 0; i < num; i++)
    {
        L = Insert(L, a[i]);
    }
    return L;
}

/*依次打印链表结点*/
void Print( List L )
{
/* 你的代码 2 */
    PtrToNode P=L->Next;
    printf("输出结果：");
    while (P != NULL)
    {
        printf("%d ", P->Data);
        P = P->Next;
    }
    printf("\n");
}

int main()
{
    List L;
    ElementType X;
    printf("不使用头结点的情况\n");
    L = Read();
    Print(L);
    return 0;
}
