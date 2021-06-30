#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef int ElemType;
typedef struct BtNode* position;
typedef position tree;
struct BtNode {
    struct BtNode* leftchild;
    struct BtNode* rightchild;
    ElemType data;
}BtNode, * BinaryTree;

tree CreateTreePI(int ps[], int is[], int n)
{
    if (n <= 0) {
        return NULL;
    }
    tree p = (tree)malloc(sizeof(BtNode));
    int i = 0;
    int m;
    while (i < n) {
        if (ps[n - 1] == is[i]) {
            m = i;
            break;
        }
        ++i;
    }
    if (i >= n) {
        return NULL;
    }
    p->data = ps[n - 1];
    p->leftchild = CreateTreePI(ps, is, m);
    p->rightchild = CreateTreePI(ps + m, is + m + 1, n - m - 1);
    return p;
}

void pre(tree t) {
    if (t) {
        cout << t->data  << ' ';
        pre(t->leftchild);
        pre(t->rightchild);
    }
}

int main()
{
    int i;
    int n;
    printf("输入节点个数：");
    scanf("%d", &n);
    tree p;
    int ps[1000];
    int  is[1000];
    printf("输入后序遍历：");
    for (i = 0; i < n; i++)
        scanf("%d", &ps[i]);
    printf("输入中序遍历：");
    for (i = 0; i < n; i++)
        scanf("%d", &is[i]);
    p = CreateTreePI(ps, is, n);

    printf("先序遍历结果：");
    pre(p);
    printf("\n");
}