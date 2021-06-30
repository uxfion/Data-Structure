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

List Insert(List L,ElementType X)
{
    PtrToNode p,q,t;
    int a;
    p=(PtrToNode)malloc(sizeof(struct Node));
    p->Data=X;
    p->Next=NULL;
    if(L==NULL)
        L=p;
    else if(L->Next==NULL)
    {
        L->Next=p;
        q=p;
        t=L;
        if(t->Data>q->Data)
        {
            a=t->Data;
            t->Data=q->Data;
            q->Data=a;
            t->Next=q;
            q->Next=NULL;
        }

    }
    else
    {
        q=L->Next;
        t=L;
        while(q && q->Data<X)
        {
            t=q;
            q=q->Next;
        }
        if(q==NULL)
            t->Next=p;
        else
        {
            p->Next=q;
            t->Next=p;
        }
    }
    return L;
}

List Read()
{
    //读取要输入的数据的个数//
    int num;

    scanf("%d",&num);
    int i;
    int a[num];

    //依次读取数据//
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    //建立头结点//
    PtrToNode p=(PtrToNode)malloc(sizeof(struct Node));
    if(num==0)
    {
        p=NULL;
        return p;
    }
    else
    {
        p->Data=a[0];
        p->Next=NULL;
        List L=p;

        //将数据依次插入//
        for(i=1;i<num;i++)
        {
            L=Insert(L,a[i]);
        }
        return L;
    }
}

/*依次打印链表结点*/
void Print(List L)
{
    printf("链表输出为：\n");
    List p;
    p = L;
    while(p)
    {
        printf("%d\t",p->Data);
        p=p->Next;
    }
}


int main()
{
    List L;
    ElementType X;
/**/
    L = Read();
//    scanf("%d", &X);
//    L = Insert(L, X);
    Print(L);
    return 0;
}

