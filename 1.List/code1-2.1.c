//
// Created by HAOMING CHEN on 2021/6/29.
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

List Insert( List L, ElementType X )
{
/* 你的代码 1 */
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
    printf("要输入数据的个数：");
    scanf("%d", &num);
    int i;
//int a[num];
    int* const a = (int*)malloc(sizeof(int)*num);
    printf("输入数据：");
/*依次读取数据*/
    for(i = 0; i < num; i++)
        scanf("%d", &a[i]);
/*建立头结点*/
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    p->Data = num;//头结点的 data 为链表长度
    p->Next = NULL;
    List L = p;
/*将数据依次插入*/
    for(i = 0; i < num; i++)
        L = Insert(L, a[i]);
    return L;
}

List Merge(List L1, List L2)
{
    List L3,Ptr;
    L3=(List)malloc(sizeof(struct Node));
    L3->Data=-1;	//设置L3头结点
    L3->Next=NULL;
    Ptr=L1;
    while(Ptr->Next != NULL)	//依次从L1中提出数据，并插入L3
    {
        Ptr=Ptr->Next;
        L3=Insert(L3, Ptr->Data);
    }
    Ptr=L2;
    while(Ptr->Next != NULL)//依次从L2中提出数据，并插入L3
    {
        Ptr=Ptr->Next;
        L3=Insert(L3, Ptr->Data);
    }
    L1->Next=NULL;	//清空L1和L2
    L2->Next=NULL;
    return L3;
}

/*依次打印链表结点*/
    void Print( List L )
    {
/* 你的代码 2 */
        PtrToNode P=L->Next;
        while (P != NULL)
        {
            printf("%d ", P->Data);
            P = P->Next;
        }
        printf("\n");
    }

int main()
{
    List L1,L2;
    ElementType X;

    printf("L1：\n");
    L1 = Read();
    printf("L2：\n");
    L2 = Read();
    printf("合并后 L3：\n");
    Print(Merge(L1, L2));
    return 0;
}
