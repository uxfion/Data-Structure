//
// Created by HAOMING CHEN on 2021/6/30.
//

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef char ElemType;
typedef struct BtNode* position;
typedef position tree;
struct BtNode {
    struct BtNode* leftchild;
    struct BtNode* rightchild;
    ElemType data;
}BtNode, * BinaryTree;

tree CreateTreePI(char ps[], char is[], int n)
{
    if (n <= 0) {
        return NULL;
    }
    tree p = (tree)malloc(sizeof(BtNode));
    int i = 0;
    int m;
    while (i < n) {
        if (ps[0] == is[i]) {
            m = i;
            break;
        }
        ++i;
    }
    if (i >= n) {
        return NULL;
    }
    p->data = ps[0];
    p->leftchild = CreateTreePI(ps + 1, is, m);
    p->rightchild = CreateTreePI(ps + m + 1, is + m + 1, n - m - 1);
    return p;
}
void hou(tree t) {
    if (t) {
        hou(t->leftchild);
        hou(t->rightchild);
        cout << t->data;
    }
}
int main()
{
    tree p;
    char ps[1000];
    char is[1000];
    printf("输入先序\n");
    cin.getline(ps, 1000);
    printf("输入中序\n");
    cin.getline(is, 1000);
    int len = strlen(ps);
    p = CreateTreePI(ps, is, len);
    printf("输出后序\n");
    hou(p);
}
