# 数据结构实验


[TOC]


## 实验一：数据结构实现基础

### 1.1递增的整数序列链表的插入

#### 实验目的：

（1） 熟练掌握循环控制语句
（2） 熟练理解和掌握链表的构造方法以及结点插入方法

#### 实验内容：

本题要求实现一个函数，在递增的整数序列链表（带头结点）中插入一个新整数，并保持该序列的有序性。

函数接口：

```c
List Insert(List L, ElementType X);
```

L是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Insert要将X插入L，并保持该序列的有序性，返回插入后的链表头指针。

```c
void Print( List L );
```

依次打印链表L中的各结点

#### 测试用例：

| 序号 | 依次插入的数据 | 输出结果    |
|------|----------------|-------------|
| 0    | 1 4 2 6 5 3    | 1 2 3 4 5 6 |
| 1    | 10 -1          | -1 10       |
| 2    | 1 2 3 4 5      | 1 2 3 3 4 5 |
| 3    | 233            | 233         |


#### 实验分析：

在链表中插入结点的关键是要找到它的前驱结点。由于是递增序列，新插入结点的位置应该是，前驱结点值比它小，后继结点值比它大。所以，可以从链表的第一个结点开始比较，当遇到第一个比插入值X大的结点时，就可以插入到该结点之前了，或者说需要插入到该结点之前了，或者说需要插入到该结点前驱结点之后。

以Pre指向待比较结点的前一个结点，也就是X是与Pre的下一结点比较，而不是直接与Pre比较。这样，当找到比X大的结点时，Pre就是插入结点的前驱结点。

如果第1个数据就比X大，则Pre应指向第1个数据结点的前驱。由于使用了带头结点的单链表，Pre此时指向的就是头结点，而不会是一个空指针。这样头结点就优雅地解决了这个特殊情况的处理。另外，由于头结点的存在，空链表也不再特殊——这就是头结点存在的意义：虽然额外占用了一个结点的空间，但可以把程序需要处理的各种特殊情况都统一处理，使得代码更为清晰。

#### 实验报告要求：

1. 将代码补充完整，并对重要代码进行简要介绍。
2. 展示各测试案例的输出结果。
3. 自行设计测试案例，说明所针对的情况，并给出输出结果。
4. 分析不使用头结点的情况，修改程序并得到输出正确的输出结果。
5. 在附录中展示全部代码。

#### 实验结果及测试

### 1.2两个有序链表序列的合并

#### 实验目的：

（1） 熟练掌握循环控制语句
（2） 熟练掌握构造新链表方法
（3） 熟练掌握链表的遍历查找操作与结点插入操作

#### 实验内容：

本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

函数接口：

```c
List Merge(List L1, List L2);
```

L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

#### 测试用例：

| 序号 | 传入参数值 |             | 返回                |     |     |
|------|------------|-------------|---------------------|-----|-----|
| 0    | L1         | 1 3 5       | L3                  | L1  | L2  |
|      | L2         | 2 4 6 8 10  | 1 2 3 4 5 6 8 10    | 空  | 空  |
| 1    | L1         | 1 2 3 4 5   | L3                  | L1  | L2  |
|      | L2         | 1 2 3 4 5   | 1 1 2 2 3 3 4 4 5 5 | 空  | 空  |
| 2    | L1         | 空          | L3                  | L1  | L2  |
|      | L2         | 空          | 空                  | 空  | 空  |
| 3    | L1         | 1 8 12      | L3                  | L1  | L2  |
|      | L2         | 24 28 33 45 | 1 8 12 24 28 33 45  | 空  | 空  |
| 4    | L1         | 24 28 33 45 | L3                  | L1  | L2  |
|      | L2         | -1 8 12     | -1 8 12 24 28 33 45 | 空  | 空  |



#### 问题分析：

设序列L1和L2的长度分别为N1和N2。求并集可从两序列的列首开始比较，不断将较小值从原序列取下，移入新序列，并更新下一次要比较的结点指针。最坏情况下，需O(N1+N2）时间。当某个序列遍历完，即L1或L2的头结点指向为空时，需继续将另一个序列的剩余链表复制到并集序列L3的末尾。

复制结点时，注意用malloc函数申请内存；由于每次总是插入L3末尾，可以用指针变量Rear指向L3尾结点，添加新结点时插入Rear结点之后并更新Rear.使用带空头结点的链表结构，可以简化对特殊情况的处理。

#### 实验报告要求：

1. 自行设计读取及输入函数。
2. 展示各测试案例的输出结果。
3. 自行设计测试案例，说明所针对的情况，并给出输出结果。
4. 在附录中展示全部代码。

#### 实验结果及测试：

## 实验二：线性结构

### 2.1银行业务队列简单模拟

#### 实验目的：

熟练掌握队列的基本操作，理解队列的应用。

#### 实验内容：

设某银行有A，B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍，即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。给定到达银行的顾客序列，请按业务完成的顺序输出客户序列。假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。

**输入说明：**输入为一行正整数，其中第1个数字N(<=1000)为顾客总数，后面跟着N位顾客的编号。编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分割。

**输出说明：**按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。

#### 测试用例：

| 序号 | 输入                 | 输出               |
|------|----------------------|--------------------|
| 0    | 8 2 1 3 9 4 11 13 15 | 1 3 2 9 11 4 13 15 |
| 1    | 8 2 1 3 9 4 11 12 16 | 1 3 2 9 11 4 12 16 |
| 2    | 1 6                  | 6                  |
| 3    | 1000个顾客的随机序列 | 略                 |

#### 实验分析：

首先需要针对A和B业务设计两个循环队列，分别处理两类业务请求；然后根据输入序列整数的奇偶性将各个整数分发到这两个队列中。另外，需要设计针对两个队列处理过程的流程，这是一个循环。在循环中，先从A队列中输出两个元素，然后再从B队列中输出一个元素。当发现某一队列为空时，输出另一个队列的所有元素。

采用统一的循环队列函数处理两个队列的操作；注意对队列满、空情况的判断。

#### 实验报告要求：

1. 在代码框架中填入相应的代码，完成对应功能；
2. 完成测试用例，自行生成3号测试用例（可以不用手动输入的方式）；
3. 如果将A队列和B队列的处理速度比N_A:N_B作为变量在程序运行时作为参数输入，该如何修改代码？

#### 实验结果及测试：

## 实验三：树

### 3.1递归实现树的先序、中序及后序遍历

#### 实验目的：

1. 熟练掌握二叉树的遍历及应用
2. 理解递归函数实现过程

#### 实验内容：

构造二叉树，并分别实现函数，进行二叉树的先序、中序及后续遍历，其中访问函数定义为打印该结点数值。 

函数接口： 

```c
void PreOrderTraversal( BinTree BT );/*先序遍历*/
void PostOrderTraversal( BinTree BT );/*后序遍历*/
void InOrderTraversal( BinTree BT );/*中序遍历*/
BinTree BuildTree() /*构造二叉树*/ 
```

其中 BinTree 结构定义如下：

```c
typedef struct TNode *Position; 
typedef Position BinTree; 
struct TNode{ 
    ElementType Data; 
    BinTree Left; 
    BinTree Right; 
}; 
```

如果 T 是二叉搜索树，则函数返回 true，否则返回 false。 

#### 测试用例

#### 实验分析：

树的遍历是指按某种顺序依次访问树的每个结点，且每个结点仅被访问一次。二叉树的遍历可按二叉树的构成以及访问结点的顺序分为四种方式，即先序遍历、中序遍历、后序遍历和层序遍历。

中序遍历访问过程如下： 
① 中序遍历其左子树； 
② 访问根节点； 
③ 中序遍历其右子树。 

先序遍历访问过程如下： 
① 访问根节点； 
② 先序遍历其左子树； 
③ 先序遍历其右子树。 

后序遍历访问过程如下： 
① 后序遍历其左子树； 
② 后序遍历其右子树；
③ 访问根节点。

#### 实现要点： 

根据上述算法思想，采用递归的方式可以快速实现各遍历算法。在遍历算法实现之前需要建立所输入的二叉树，自行设计函数进行树的构建。

#### 实验报告要求：

1. 自行设计二叉树生成算法，并说明算法思想
2. 将代码补充完整，并介绍关键语句，展示测试用例输出结果
3. 将全部代码附在附录中

#### 实验结果及测试：

### 3.2根据后序和中序遍历输出先序遍历

#### 实验目的：

1. 熟练掌握二叉树存储结构
2. 熟练掌握二叉树的遍历及应用

#### 实验内容：

根据给定的一棵二叉树的后续遍历和中序遍历结果，构建该树，并输出该树的前序遍历结果。

**输入说明：**第一行给出正整数N（N\<=
30）,是树中结点的个数。随后两行，每行给出N个整数，分别对应后序遍历和中序遍历结果，数字间以空格分隔。题目保证输入正确对应一棵二叉树。

**输出说明：**在一行中输出“Preorder:
”以及该树的前序遍历结果。数字间有1个空格，行末不得有多余空格。

函数接口： 

```c
nTree BuildTree(int Inorder[], int Postorder[], int N)
void PreorderTraversal(BinTree BT);
```
Inorder是中序遍历序列，Postorder是后序遍历序列，N是树中所包含的结点数
二叉树BT的先序遍历，采用打印的方式进行访问

#### 测试用例：

#### 实验分析：
**本题需要解决两个子问题：**

1. 通过输入给定的后续遍历和中序遍历两个序列构建出对应的二叉树。由于后续遍历序列的最后一个结点必然是根结点，可以在中序遍历序列中找到这个跟结点的位置p（下标从0开始），于是就知道在中序遍历序列中，根结点左边的所有结点一定属于左子树，右边的所有结点一定属于右子树。根据这个判断，可以从中序遍历序列中知道左、右子树分别有p和（N-p-1）个结点，它们必然对应存储在后序遍历序列中从第0个结点开头以及从第p个结点开头的两段。于是可以对左、右子树递归地解决这个问题，直到生成整个二叉树。
2. 前序遍历生成的二叉树，把遍历中的“访问”操作定义为“打印”即可。

#### 实现要点： 

树形结构用一般教材中介绍的链表结构存储，结点结构体存储该结点的数值以及左右子树的指针。在构建二叉树的过程中，须注意递归终止的条件。

#### 实验报告要求：

1. 将代码补充完整，并介绍关键语句，展示测试用例输出结果
2. 自行设计测试用例，说明所针对的情况，展示输出结果
3. 如果题目改为给定前序和中序遍历结果，输出后序遍历，求解思路如何？（只介绍思路即可，不需要编程实现）
4. 将全部代码附在附录中

#### 实验结果及测试：

## 实验四：图

### 4.1 邻接矩阵存储图的深度优先遍历

#### 实验目的：

1. 熟练掌握图的邻接矩阵存储结构。
2. 熟练掌握图的深度优先遍历方法。

#### 实验内容：

实现邻接矩阵存储图的深度优先遍历(访问函数设定为输出当前顶点值)。

接口函数：

```c
Void DFS(MGraph Graph, Vertex V);
```

其中MGraph是邻接矩阵存储的图，定义如下：

```c
struct GNode{
	int Nv;  /*顶点数*/
	int Ne;  /*边数*/
	int G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

```

函数DFS应从第V个顶点出发递归地深度优先遍历图Graph,遍历时用提前定义的函数Visit访问每个顶点。当访问邻接点时，要求按序号递增的顺序。题目保证V是图中的合法顶点。

#### 测试用例：

#### 实验分析：

深度优先遍历是树的前序遍历的推广，基本步骤是先处理当前顶点，然后递归处理其尚未被访问过的相邻顶点。不同的存储方法决定了搜索相邻顶点的效率。本题给定了邻接矩阵存储的图，对任一顶点V，要遍历所有与之相邻的顶点，只能通过检查邻接矩阵的第V行的每个元素来实现，这一步的时间复杂度固定是O（Nv）。

#### 实现要点：

对于无权图要判断两个顶点V和W之间是否有边，只要判断是否有Graph->G[V][W] != 0。

#### 实验报告要求：

1. 将代码补充完整，并介绍关键语句，展示测试用例(0,1)的输出结果
2. 将全部代码附在附录中
3. （附加）优化代码，使其适用于测试用例2，并展示输出结果

#### 实验结果及测试：

### 4.2邻接表存储图的广度优先遍历

#### 实验目的：

1. 熟练掌握图的邻接表存储结构。
2. 熟练掌握图的广度优先遍历方法。

#### 实验内容：

实现邻接表存储图的广度优先遍历(访问函数设定为输出当前顶点值)。

函数接口：

```c
Void BFS(LGraph Graph, Vertex S);
```

函数BFS应从第S个顶点出发对邻接表存储的图Graph进行广度优先搜索，遍历时用提前定义的函数Visit访问（本实验用直接采用打印的方式）每个顶点。当访问邻接点时，要求按邻接表顺序访问。题目保证S是图中的合法顶点。

#### 测试用例：

#### 实验分析：

广度优先遍历是树的层序遍历的推广，基本步骤是先处理当前顶点，后将其入列，开始进行遍历循环。当队列不为空时，弹出一个顶点，再顺次将其尚未访问国的相邻顶点入列。不同的存储方法决定了搜索相邻顶点的效率。本题给定了邻接表存储的图，对任一顶点V，要遍历所有与之相邻的顶点，只要扫描邻接表存储的图，对任一顶点V，要遍历所有与之相邻的顶点，只要扫描邻接表的第V个链表即可，时间复杂度与V的度数成正比，而不必固定检查所有Nv个顶点。

#### 实现要点：

广度优先遍历需要借助一个队列来完成，队列中存放的是Vertex类型。如何引用其他文件中定义的类型？

#### 实验报告要求：

1. 将代码补充完整，并介绍关键语句，展示测试用例(0,1)的输出结果
2. 将全部代码附在附录中
3. （附加）优化代码，使其适用于测试用例2，并展示输出结果

#### 实验结果及测试：






