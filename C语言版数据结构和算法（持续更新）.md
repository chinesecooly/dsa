
# 前言
# 数据结构
数据是信息的载体，是计算机程序加工的原料，**数据元素**是数据的基本单位，**数据项**是构成数据元素的最小单位。**数据对象**是具有相同性质的数据元素的集合（强调的是数据元素性质的相同）。

![在这里插入图片描述](https://img-blog.csdnimg.cn/be63e488d9fe4b1885b4220ef8399971.png)

**数据结构**是指相互之间存在一种或多种特定关系的数据元素的集合（强调的是数据元素之间的关系）。数据结构的三要素是逻辑结构、存储结构和数据运算。

![请添加图片描述](https://img-blog.csdnimg.cn/a9eccf820a174739b14d4ed5df60b57b.png)

## 一般线性表
线性表是`n`个具有相同类型的数据元素的有限序列。线性表中存在唯一的第一元素也存在唯一的最后元素。除第一个元素外，其它元素有唯一的直接前驱，除最后元素外，其它元素有唯一的直接后继。
### 顺序表
线性表的顺序存储称为顺序表，通常使用动态数组实现顺序表，顺序表的访问是任意的。
```c
typedef int ElementType;

struct SqlList{
    ElementType * data;
    int length;
    int maxSize;
};
```
### 链表
线性表的链式存储称为链表。它由若干个节点连接而成。每个节点包括两个部分一个是存储数据元素的数据域，另一个是存储其它节点地址的指针域。链表的特点如下:
- 链表的访问是顺序的，只能通过头指针进行。
- 链表可以有一个头节点，也可以没有，头节点不存储任何数据，含有头节点的链表操作更加方便。
- 除头节点外第一个存储数据的节点称为首元节点。

![请添加图片描述](https://img-blog.csdnimg.cn/0e64939bfe0e41f1ac0625a370fc269e.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
只有一个指针域的链表称为单链表：
```c
typedef int ElementType;

struct LinkList{
    ElementType data;
    struct LinkList * next;
};
```
有两个指针域的链表称为双链表：

```c
typedef int ElementType;

struct DLinkList{
    ElementType data;
    struct DLinkList * next;
    struct DLinkList * prior;
};
```
循环链表是一种首尾相连的链表，它又可以分为循环单链表和循环双链表。
#### 合并有序链表
```java
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if (l1==null){
        return l2;
    }else if (l2==null){
        return l1;
    }else if(l1.val<l2.val){
        l1.next=mergeTwoLists(l1.next,l2);
        return l1;
    }else {
        l2.next=mergeTwoLists(l1,l2.next);
        return l2;
    }
}
```
#### 反转链表
**反转整个链表**
```java
public ListNode reverseList(ListNode head) {
    if (head==null||head.next==null){
        return head;
    }else {
        ListNode newHead=reverseList(head.next);
        head.next.next=head;
        head.next=null;
        return newHead;
    }
}
```
**反转链表的前n个元素**

```java
public ListNode end;
public ListNode reverseListN(ListNode head,int n){
    if (n==1){
        end=head.next;
        return head;
    }else {
        ListNode newHead=reverseListN(head.next,n-1);
        head.next.next=head;
        head.next=end;
        return newHead;
    }
}
```
**反转链表的任意一部分**
```java
public ListNode reverseBetween(ListNode head, int left, int right) {
    if (left==1){
        return reverseListN(head,right);
    }else {
        head.next=reverseBetween(head.next,left-1,right-1);
        return head;
    }
}
```
**k个一组反转链表**

```java
public ListNode reverseKGroup(ListNode head, int k) {
    if (k==1){
        return head;
    }else {
        ListNode right=head;
        for (int i = 1; i < k; i++) {
            if (right==null){
                return head;
            }
           right=right.next;
        }
        ListNode newHead=reverse(head,right);
        if (right!=null&&right.next!=null){
            head.next=reverseKGroup(head.next,k);
        }
        return newHead;
    }
}
public ListNode end;
public ListNode reverse(ListNode left,ListNode right){
    if (left==null||right==null||left==right){
        return left;
    } {
        end=right.next;
        ListNode newHead = reverse(left.next, right);
        left.next.next=left;
        left.next=end;
        return newHead;
    }
}
```
## 受限线性表
### 队列
队列是一种只能在表头或表尾进行插入或删除的线性表，它的特点如下：
- 插入元素的一端称为队尾
- 删除元素的一端称为队头
- 遵循先入先出原则

![请添加图片描述](https://img-blog.csdnimg.cn/99b01e3f92934b3bb79eb79bca7f62d4.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
可以使用顺序存储或链式存储的方式实现队列，但通常通过循环的顺序存储实现：

```c
#define INIT_SIZE 10
typedef int ElementType;

struct SqQueue{
    ElementType data[INIT_SIZE];
    int front;
    int rear;
};
```

```cpp
typedef int ElemType;

struct LinkNode{
    ElemType data;
    struct LinkNode *next;
};

struct LinkQueue{
    struct LinkNode * front;
    struct LinkNode * rear;
};
```
#### 循环队列
#### 双端队列
### 栈
栈是一种只能在表头或表尾进行插入和删除的线性表。它的特点如下：
- 允许插入和删除的一端称为栈顶
- 不允许插入和删除的一端称为栈底
- 遵循先入后出原则
- n个不同元素进栈，出栈元素不同排列个数为1/(n+1)C<sup>n</sup><sub>2n</sub>

![请添加图片描述](https://img-blog.csdnimg.cn/b4246ce5f8c444eb8d91ce28413c1a25.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
通过顺序存储实现的栈称为顺序栈：
```c
#define INIT_SIZE 10
typedef int ElementType;

struct SqStack{
    ElementType data[INIT_SIZE];
    int top;
};
```
通过链式存储的栈称为链栈：

```c
typedef int ElementType;

typedef struct LinkNode{
    ElementType data;
    struct LinkNode * next;
}LinkStack;
```

### 串
串是一个元素只能是字符的线性表。串中任意连续字符组成的子序列称为该串的子串，子串在主串中的位置以子串的第一个字符在主串中的位置来表示。子串包含空串，真子串是指不包含本身的子串。空格串是指由一个或多个空格组成的串。可以使用顺序存储和链式存储实现串，通常使用顺序存储实现。

```c
typedef struct {
    char *str;
    int length;
}String
```
#### BF算法
BF算法也称为简单匹配法，它采用了穷举法的思路。

```c
int BF(String src, String target) {
    if (src.length < target.length) {
        return false;
    }
    for (int i = 0; i < src.length; ++i) {
        int temp = i;
        for (int j = 0; j < target.length; ++j, ++temp) {
            if (*(src.str + temp) != *(target.str + j) ){
                break;
            }
            if (j == target.length - 1) {
                return temp-target.length + 1;
            }
        }
    }
    return -1;
}
```
#### KMP算法
与BP算法相比KMP算法可以利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配。首先弄清三个概念：
- 前缀：除最后一个字符外，字符串的所有头部子串。
- 后缀：除第一个字符外，字符串的所有尾部子串。
- 部分匹配：字符串最长相等前后缀长度。

算法开始时先求出模式串中以各个字符为结尾的子串的部分匹配值，并将这些值放到数组`next`中，这就是所谓的匹配后的失败信息：
```c
//主串：aaabaaaab
//模式串：aaaab
int next[]={0,1,2,3,0};
```
那么当匹配失败时，模式串不再相对于上一次起始的位置右移一位，而是相对于失败的位置右移`move`位，并从失败位置开始匹配，`move`由以下公式计算：
```cpp
move=已匹配子串的字符个数-已匹配子串的部分匹配值
```
从`next`数组的角度看就是当前字符匹配失败就会找它前一个字符的部分匹配值，因此最后一个字符的部分匹配值将永远用不到，所以可以将`next`数组整体向右移动一个单位，其中第一个元素右移之后的空缺用`-1`填充，因为当第一个字符匹配失败时，模式串必须相对于上一次起始的位置右移一位。
```c
next[]={-1,0,1,2,3};
```
上述公式用模式串的指针`ptr`表示为：
```c
move=ptr-1-next[ptr]
```
模式串向右移动`move`位就相当于`ptr`向左移动`ptr-move`位，那么`ptr`的当前位置是：
```cpp
ptr=next(ptr)+1
```
如果将`next`数组各个元素加1：

```cpp
next[]={0,1,2,3,4};
```
那么`ptr`的当前位置是：
```cpp
ptr=next(ptr)
```
因此最主要的任务就是求解`next`数组元素的值，设`next[ptr]=k`，当`ptr=1`时`k≡0`，那么只需要求解`next[ptr+1]`等于多少即可，这本质就是求`*(ptr+1)`部分匹配值的问题，当`*ptr==*next[ptr]`时`next[ptr+1]=next[ptr]+1`，当`*ptr!=*next[ptr]`时，就递归求解`*next[next[ptr]]`，直到`*ptr==*next[next[ptr]]`或`next[ptr]==0`，当`next[ptr]==0`时`next[ptr+1]=1`，此时说明以`*(ptr+1)`结尾的子串的部分匹配值等于0。

```cpp
int next[target.length];
next[0] = -1;
for (int ptr = 0, k = -1; ptr < target.length;) {
    if (k == -1 || charAt(target, ptr) == charAt(target, k)) {
        k++;
        ptr++;
        next[ptr] = k;
    } else {
        k = next[k];
    }
}
```
可以对`next`数组进一步优化，当计算出`next[ptr+1]`时，如果发现`*(ptr+1)==*next[ptr+1]`，那么下一次比较必将失败，此时就可以递归赋值`next[ptr+1]=next[next[ptr+1]]`，直到`*(ptr+1)！=*next[ptr+1]`为止。

```cpp
int next[target.length];
next[0] = -1;
for (int ptr = 0, k = -1; ptr < target.length;) {
    if (k == -1 || charAt(target, ptr) == charAt(target, k)) {
        k++;
        ptr++;
        if(charAt(target,ptr)!= charAt(target,k)){
            next[ptr] = k;
        } else{
            next[ptr]=next[k];
        }
    } else {
        k = next[k];
    }
}
```
完整的KMP算法如下：

```cpp
char charAt(String str, int pos) {
    return *(str.str + pos);
}

int KMP(String src, String target) {
    int next[target.length];
    next[0] = -1;
    for (int ptr = 0, k = -1; ptr < target.length;) {
        if (k == -1 || charAt(target, ptr) == charAt(target, k)) {
            k++;
            ptr++;
            if(charAt(target,ptr)!= charAt(target,k)){
                next[ptr] = k;
            } else{
                next[ptr]=next[k];
            }
        } else {
            k = next[k];
        }
    }

    for (int i = 0, j = 0; i < src.length;) {
        if (charAt(src, i) == charAt(target, j)) {
            i++;
            j++;
        } else {
            j = next[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
        if (j == target.length) {
            return i - target.length;
        }
    }
    return -1;
}
```
## 线性表推广
## 树形结构
### 树和森林
树是由n个节点组成的有限集，其中每个结点有零个或多个子结点以及零个或一个父结点，没有父结点的结点称为根结点，每一个非根结点有且只有一个父结点。除根结点外的其余结点可以分为m个互不相交的有限集，其中每个有限集本身就是一棵树，这些树又称为根的子树。森林就是m棵不相交的树的集合，树一定是森林，但森林不一定是树。
- 祖先、子孙、双亲、孩子和兄弟：A是E的祖先，E是A的子孙，A是B的双亲，B是A的孩子，有相同双亲的结点称为兄弟。
- 度：一个结点的孩子数称为该结点的度，树中结点最大的度称为树的度。度数为零的结点称为叶子结点，度数不为零的结点称为分支结点。树中的结点数就等于所有结点的度数之和加一。度为m的树第i层最多有m<sup>i-1</sup>个结点。
- 层次：结点的层次从根结点开始定义，在同一层的非兄弟结点互为堂兄弟。
- 深度：结点的深度从根节点开始向下逐层累加，树的高度就是结点的最大层数。
- 高度：结点的高度从叶子节点开始向上逐层累加，树的深度就是结点的最大层数。高度为h的m叉树至多有(m<sup>h</sup>-1)/(m-1)个结点。具有n个结点的m叉树的最小高度为⌈log<sub>m</sub>(n(m-1)+1)⌉。
- 路径长度：两个结点之间的路径，树的路径长度为根到每个结点的路径长度之和。
- 有序树和无序树：结点的每个子树是有序的不能互换的树称为有序树，否则就是无序树。

![在这里插入图片描述](https://img-blog.csdnimg.cn/dbf6ffae6f7e4a709a2b3bcedd7fead1.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
树的存储结构有很多，其中双亲表示法采用一组连续的空间存储每一个结点，同时在每个结点中增设一个伪指针，这个伪指针指向其双亲结点在连续空间中的位置：
```c
typedef struct PTNode{
    PTreeElemType data;
    int parent;
}PTNode;

typedef struct PTree{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;
```

在孩子表示法中，每个结点不再增设一个伪指针，而是增设一个存储当前结点孩子的下标的链表：

```c
typedef struct CTNode{
	CTreeElemType data;
    LinkList childIndexLinkList;
}CTNode;

typedef struct CTree{
    CTNode *nodes[MAX_TREE_SIZE];
    int n;
}CTree;
```
孩子兄弟表示法又称为二叉树表示法，它采用二叉链表作为树的存储结构，其中每个结点包含三部分内容：结点值、指向结点第一个孩子结点的指针以及指向结点下一个兄弟结点的指针，也可以增加一个指向其双亲的指针：
```c
typedef struct CSTNode{
    CSTreeElemType data;
    struct CSTNode * firstChild;
    struct CSTNode * nextSibling;
}CSTNode,*CSTree;
```
#### 与二叉树之间的转化
二叉树的结构简单、规律性最强，因此在处理树和森林时一般将它们转换成一个唯一的二叉树进行。由于树和二叉树都可以使用二叉链表表示，那么就可以以二叉链表做媒介来进行转化。
- 树转换为二叉树：每个结点左指针指向它的第一个孩子，右指针指向它在树中的相邻右兄弟，由于根节点没有兄弟，所以对应的二叉树没有右子树。
- 树转换为二叉树的画法：在兄弟结点之间加一条线；对每一个结点，只保留它与第一个孩子的连线，与其它孩子的连线全部抹掉；以树根为中心顺时针旋转四十五度。

- 森林转换为二叉树：先将森林中的每一棵树转换为二叉树，然后将第二棵二叉树作为第一棵二叉树的右子树，再将第三棵二叉树作为第二棵二叉树的右子树···依次类推。
- 森林转换为二叉树的画法：将森林中的每一棵树转换为二叉树；每棵树的根视为兄弟关系，在每棵树的根之间加一条连线；以第一棵树的根为中心顺时针旋转四十五度。

- 二叉树转换为森林：将二叉树的根及左子树视为第一棵树的二叉树形式，并将右链断开；将右子树视为一个由除第一棵树外的森林转换后的二叉树，应用相同的方法，直到最后只剩一棵没有右子树的二叉树为止；最后将每棵二叉树依次转换为树就得到了森林。

#### 遍历
树的遍历方式如下：
- 先根遍历：先访问根结点，再依次访问根结点的每棵子树，依次类推。其遍历序列对应二叉树的先序序列。
- 后根遍历：先访问根结点的每棵子树，再访问根结点，依次类推。其遍历序列对应二叉树的中序序列。

森林的遍历方式如下：
- 先根遍历：访问森林中第一棵树的根节点；先根遍历第一棵树中根结点的子树森林；先根遍历除去第一棵树之后剩余的树构成的森林；其遍历序列对应二叉树的先序序列。
- 后根遍历：后根遍历森林中第一棵树的根结点的子树森林；访问第一棵树根结点；后根遍历除第一棵树之后剩余的树构成的森林；其遍历序列对应二叉树的中序序列。
### 二叉树
二叉树是指每个结点最多只有两个子树且子树之间顺序不能颠倒的树，这两棵子树分别称为左子树和右子树。二叉树与度为二的有序树的区别如下：
- 度为2的有序树至少有三个结点，而二叉树可以为空。
- 度为2的有序树的孩子的左右次序是相对于另一个孩子而言的，如果只有一个孩子那么无需区分左右，而二叉树无论几个孩子必须区分左右。

二叉树的性质如下：
- 二叉树在第i层至多有2<sup>i-1</sup>个结点，最少有1个结点。
- 高度为h的二叉树最多有2<sup>h</sup>-1个结点，最少有h个结点。
- 对于任何一颗二叉树，如果其叶子结点数为n<sub>0</sub>，度为2的结点数为n<sub>1</sub>，那么n<sub>0</sub>=n<sub>1</sub>+1。
- 对于任意一颗二叉树，如果对其进行编号，那么结点编号所对应的二进制可以反应从根节点到该结点的路径，其中最高位是 1，其余各位从高到低表示从根节点到第 k 个节点的移动方向，0 表示移动到左子节点，1 表示移动到右子节点。

![在这里插入图片描述](https://img-blog.csdnimg.cn/c9bc6465baeb44cf9301ec053205b034.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)

二叉树的顺序存储是指用一组地址连续的存储单元依次自上而下、自左向右存储完全二叉树上的结点元素，这样树中结点的序号就可以唯一反应结点之间的关系。对于不是完全二叉树的二叉树，需要填充空结点让其每个结点与完全二叉树上的结点对应。因此非完全二叉树的二叉树通常采用链式存储，链表结点至少包含三个域：数据域、左孩子指针域和右孩子指针域。还可以增加一个指针域指向其双亲。
```c
typedef struct BiTNode{
    ElementType data;
    struct BiTNode * lChild;
    struct BiTNode * rChild;
}BiTNode,* BiTree;
```
#### 遍历
遍历一棵二叉树要决定对根节点N、、左子树L和右子树R的访问顺序，常见的访问顺序如下：
- 先序遍历（NLR）：首先访问根结点，然后遍历左子树，最后遍历右子树。

```c
void preOrder(BiTree tree) {
    if (tree != NULL) {
        visit(tree);
        preOrder(tree->lChild);
        preOrder(tree->rChild);
    }
}
```

- 中序遍历（LNR）：先遍历左子树，然后访问根结点，然后遍历右子树。

```c
void inOrder(BiTree tree) {
    if (tree != NULL) {
        inOrder(tree->lChild);
        visit(tree);
        inOrder(tree->rChild);
    }
}
```

- 后序遍历（LRN）：是先遍历左子树，然后遍历右子树，最后访问根结点。

```c
void postOrder(BiTree tree) {
    if (tree != NULL) {
        postOrder(tree->lChild);
        postOrder(tree->rChild);
        visit(tree);
    }
}
```

- 层序遍历：根据二叉树的层次层次结构，从第一层开始自上而下、自左向右访问每一个结点。

```c
void levelOrder(BiTree tree){
    LinkQueue queue= linkQueueConstruct();
    enQueue(queue,tree);
    for (; !isEmpty(queue);){
        BiTree  subTree= deQueue(queue);
        visit(subTree);
        if(subTree->lChild!=NULL){
            enQueue(queue,subTree->lChild);
        }
        if(subTree->rChild!=NULL){
            enQueue(queue,subTree->rChild);
        }
    }
    linkQueueFinalize(queue);
}
```

- morris：
#### 构造
由二叉树的先序序列和中序序列或后序序列和中序序列或层序序列和中序序列可以确定唯一一棵二叉树：
```c
//前序中序构造
BiTree preInOrderConstruct(BiTreeElemType preOrderList[],BiTreeElemType inOrderList[],int ps,int pe,int is,int ie){
    BiTNode *root= malloc(sizeof (BiTNode));
    root->data=preOrderList[ps];
    int lLen,rLen;
    for (int i = is; i <= ie; ++i) {
        if(inOrderList[i]==preOrderList[ps]){
            lLen=i-is;
            rLen=ie-i;
            break;
        }
    }
    if(lLen){
        root->lChild= preInOrderConstruct(preOrderList,inOrderList,ps+1,ps+lLen,is,is+lLen-1);
    } else{
        root->lChild=NULL;
    }
    if(rLen){
        root->rChild= preInOrderConstruct(preOrderList,inOrderList,pe-rLen+1,pe,ie-rLen+1,ie);
    } else{
        root->rChild=NULL;
    }
    return root;
}
```
如果将二叉树的某一遍历序列使用填充元素填充为满二叉树的相同遍历序列，那么也可以唯一确定一棵二叉树：
```c
BiTree  completeLevelOrderConstruct(BiTreeElemType completeLevelOrderList[],int len,BiTreeElemType filler){
    LinkQueue queue= linkQueueConstruct();
    BiTNode * root= malloc(sizeof (BiTNode));
    root->data=completeLevelOrderList[0];
    enQueue(queue,root);
    for (int i = 1; !isEmpty(queue); ++i) {
        BiTNode * node=deQueue(queue);
        if(node!=NULL){
            if((2*1-1)>=len||(2*i+1-1)>=len){
                node->lChild=NULL;
                node->rChild=NULL;
                continue;
            }
            if(completeLevelOrderList[2*i-1]!=filler){
                node->lChild= malloc(sizeof (BiTNode));
                node->lChild->data=completeLevelOrderList[2*i-1];
                enQueue(queue,node->lChild);
            } else{
                node->lChild=NULL;
                enQueue(queue,NULL);
            }
            if(completeLevelOrderList[2*i+1-1]!=filler){
                node->rChild= malloc(sizeof (BiTNode));
                node->rChild->data=completeLevelOrderList[2*i+1-1];
                enQueue(queue,node->rChild);
            } else{
                node->rChild=NULL;
                enQueue(queue,NULL);
            }
        } else{
            continue;
        }
    }
    linkQueueFinalize(queue);
    return root;
}
```
### 满二叉树
每一层的结点数都达到最大值的二叉树称为满二叉树，满二叉树的所有叶子节点都在最后一层。若对满二叉树自上而下，自左到右从1开始编号，那么对于编号为i的结点，若有双亲则其双亲编号为i/2，若有左孩子则左孩子编号为2i，若有右孩子则其编号为2i+1。
![在这里插入图片描述](https://img-blog.csdnimg.cn/943f7e4748774b11940aa15e6e5864d1.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
### 完全二叉树
一棵深度为k的有n个结点的二叉树，对树中的结点自上而下，自左到右从1开始编号，如果编号为i的结点与满二叉树中编号为i的结点在二叉树中的位置相同，则这棵二叉树称为完全二叉树。完全二叉树的性质如下：
- 若i<=⌊n/2⌋，那么结点i为分支结点，否则为叶子结点。
- 叶子节点只可能在层次最大的两层上出现，对于最大层次中的叶子结点都依次排列在该层的最左边的位置。
- 若有度为1的结点，则只可能有一个，且该结点只有左孩子而没有右孩子。
- 一但某结点i为叶子结点或只有左孩子，则编号大于i的结点均为叶子结点。
- 若n为奇数，则每个分支结点都有左孩子和右孩子；若n为偶数，则编号最大的分支结点只有左孩子没有右孩子，其余分支结点左孩子右孩子都有。
- 当i为偶数时，其双亲的编号为i/2，它是双亲的左孩子；当i为奇数时，其双亲的编号为(i-1)/2，它是双亲的右孩子。
- 当2i<=n时，结点i的左孩子编号为2i，否则无左孩子。
- 当2i+1<=n时，结点i的右孩子编号为2i+1，否则无右孩子。
- 结点i所在的层次为⌊log₂i⌋+1。
- 具有n个结点的完全二叉树的高度为⌈log₂(n+1)⌉或⌊log₂n⌋+1。


![在这里插入图片描述](https://img-blog.csdnimg.cn/41c1126d7135450ca8558b6e39874e2e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
### 线索二叉树
在含有n个结点的二叉树中，含有n+1个空指针域。线索化是指利用这些空指针域存放指向结点的前驱和后继的指针，它的规则如下：如果某个结点的左孩子为空，则将空的左孩子引用指向其前驱，如果某结点的右孩子为空，则将空的右孩子引用指向其后驱。此外还需要增加两个标志标识指针域是指向左右孩子还是指向前驱后继。
```c
typedef struct ThreadNode{
    ThreadTreeElemType data;
    struct ThreadNode *lChild;
    struct ThreadNode *rChild;
    bool lTag;
    bool rTag;
}ThreadNode,* ThreadTree;
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/670437cd4d81417789da83fa0a930960.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
#### 构造
构造一棵线索二叉树分为两步，首先使用普通二叉树的构造方法构造一棵`ThreadTree`，然后使用线索化方法将`ThreadTree`转换成一个真正的线索二叉树：
```c
//前序线索二叉树
void preOrderThread(ThreadTree tree,ThreadTree pre){
    if(tree!=NULL){
        if(tree->lChild==NULL){
            tree->lChild=pre;
            tree->lTag=true;
        }
        if(pre!=NULL&&pre->rChild==NULL){
            pre->rChild=tree;
            pre->rTag=true;
        }
        pre=tree;
        preOrderThread(tree->lChild,pre);
        preOrderThread(tree->rChild,pre);
    }
}
```
#### 遍历
线索二叉树的遍历方法如下：

```c
//前序遍历
void preOrder(ThreadTree tree){
    if(tree!=NULL){
        visit(tree);
        if(tree->rTag){
            preOrder(tree->rChild);
        } else{
            preOrder(tree->lChild);
        }
    }
}
```
### 最优二叉树（哈夫曼树）
如果给树中结点赋一个有某种含义的数值，则这个数值称为该结点的权。结点的权与结点路径长度的乘积称为结点的带权路径长度，树的带权路径长度是树中所有节点带权路径长度之和。树的带权路径长度最小的二叉树称为最优二叉树。最优二叉树的特点如下：
- 包含n个叶子节点的最优二叉树共有2n-1个结点。
- 最优二叉树结点的度要么是0要么是2。

```c
typedef struct HTNode{
    HTreeElemType data;
    WeightType weight;
    struct HTNode *lChild;
    struct HTNode *rChild;
}HTNode,*HTree;
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/8d79cdf2d841475fb676340482a35242.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)

#### 构造（哈夫曼算法）
给定n个结点以及它们的权值，那么构造过程如下：
- 构造森林全是根：将这n个结点分别作为n棵仅包含一个结点的二叉树，构成森林F。
- 选用两小造新树：构造一个新结点，在F中选择两棵根结点权值最小的树作为新结点的左右子树新结点权值即为两个孩子节点的权值之和。
- 删除两小添新人：从F中删除刚才选出的两棵树，并将新构造的二叉树加入F。
- 重复2、3剩单根：重复2和3步直至F中只剩一棵树。
```c
HTree hTreeConstruct(HTreeElemType data[], WeightType weight[], int len) {
    PriorityQueue queue = PriorityQueueConstruct();
    for (int i = 0; i < len; ++i) {
        HTNode *node = malloc(sizeof(HTNode));
        node->data = data[i];
        node->weight = weight[i];
        node->lChild = NULL;
        node->rChild = NULL;
        PriorityQueueEnQueue(queue, node, HTNodeCompare);
    }
    HTNode *node;
    for (; !PriorityQueueIsEmpty(queue);) {
        node = malloc(sizeof(HTNode *));
        node->lChild = PriorityQueueDeQueue(queue);
        node->rChild = PriorityQueueDeQueue(queue);
        node->weight = node->lChild->weight + node->rChild->weight;
        if (PriorityQueueIsEmpty(queue)) {
            PriorityQueueEnQueue(queue, node, HTNodeCompare);
            break;
        }
        PriorityQueueEnQueue(queue, node, HTNodeCompare);
    }
    HTree tree = PriorityQueueDeQueue(queue);
    PriorityQueueFinalize(queue);
    return tree;
}
```
#### 哈夫曼编码
由哈夫曼树可以得到哈夫曼编码，首先将一段文本中每个出现的字符当作一个独立的结点构造成哈夫曼树，每个字符都会出现在叶子节点，其权值为它出现的频度；然后在每条路径上标记0和1，标记为0表示转向左孩子，标记为1表示转向右孩子。那么字符的哈夫曼编码就为从根结点到该结点的路径上边标记的01序列。哈夫曼树的带权路径长度就是该文本最终编码得到的二进制编码长度。
```c
char *  huffmanCoding(HTree tree,HTreeElemType elem){
    if(tree!=NULL){
        char * lr=huffmanCoding(tree->lChild,elem);
        char * rr=huffmanCoding(tree->rChild,elem);
        if(lr!=NULL){
            return strcat(realloc(lr, strlen(lr)+1),"0");
        } else if(rr!=NULL){
            return strcat(realloc(rr, strlen(rr)+1),"1");
        } else if(tree->lChild!=NULL&&tree->lChild->lChild==NULL&&tree->lChild->rChild==NULL&&tree->lChild->data==elem){
            return strcat(calloc(sizeof (char ),2),"0");
        } else if(tree->rChild!=NULL&&tree->rChild->lChild==NULL&&tree->rChild->rChild==NULL&&tree->rChild->data==elem){
            return strcat(calloc(sizeof (char ),2),"1");
        } else{
            return NULL;
        }
    } else{
        return NULL;
    }
}
```
### 二叉排序树（BST）
二叉排序树可以是空树，或者是满足以下性质的二叉树：
- 若任意结点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
- 若任意结点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
- 任意结点的左、右子树也分别为二叉查找树；

对二叉排序树进行中序遍历可以得到一个递增有序的有序序列。
#### 插入
```c
void BSTInsert(BSTree tree, BSTreeElemType elem) {
    if (tree->data == elem) {
        return;
    } else if (tree->data > elem) {
        if(tree->lChild==NULL){
            tree->lChild= malloc(sizeof(BSTNode));
            tree->lChild->data=elem;
            tree->lChild->lChild=NULL;
            tree->lChild->rChild=NULL;
        } else{
            BSTInsert(tree->lChild, elem);
        }
    } else {
        if(tree->rChild==NULL){
            tree->rChild= malloc(sizeof(BSTNode));
            tree->rChild->data=elem;
            tree->rChild->lChild=NULL;
            tree->rChild->rChild=NULL;
        } else {
            BSTInsert(tree->rChild, elem);
        }
    }
}
```
#### 构造

```c
BSTree BSTreeConstruct(BSTreeElemType elems[],int len) {
    BSTree  tree= malloc(sizeof (BSTNode));
    for (int i = 0; i < len; ++i) {
        BSTInsert(tree,elems[i]);
    }
}
```

#### 查找
```c
BSTNode *BSTSearch(BSTree tree, BSTreeElemType elem) {
    if (tree != NULL) {
        if (tree->data == elem) {
            return tree;
        } else if (tree->data < elem) {
            return BSTSearch(tree->lChild, elem);
        } else {
            return BSTSearch(tree->rChild, elem);
        }
    } else {
        return NULL;
    }
}
```
#### 删除
二叉排序树的删除要分三种情况来处理：
- 若删除结点就是叶子结点，则直接删除。
- 若删除结点node只有一棵左子树或者右子树，则让该子树成为node父节点子树。
- 若若删除结点node左右子树都存在，则令node的直接后继或直接前驱代替node，然后从树中删除这个直接前驱或直接后继。
```c
BSTree BSTDelete(BSTree tree, BSTNode *node, BSTNode *parent, bool left) {
    if (node->lChild == NULL && node->rChild == NULL) {
        if(changeNode(parent,NULL,left)){
            return tree;
        } else{
            return NULL;
        }
    } else if (node->lChild != NULL && node->rChild == NULL) {
        if(changeNode(parent,node->lChild,left)){
            return tree;
        } else{
            return node->lChild;
        }
    } else if (node->rChild != NULL && node->lChild == NULL) {
        if(changeNode(parent,node->rChild,left)){
            return tree;
        } else{
            return node->rChild;
        }
    } else {
        BSTNode * ISNode=getImmediateSuccessor(node->rChild);
        node->data=ISNode->data;
        return BSTDelete(tree,ISNode, getParent(node->rChild,ISNode),isLeft(getParent(node->rChild,ISNode),ISNode));
    }
}
```
### 平衡二叉树（AVL）
为避免树的高度增长过快，降低二叉排序树的性能，规定在插入和删除二叉树的结点时，要保证任意节点的左子树和右子树高度差的绝对值不超过一，这样的二叉树成为平衡二叉树，结点左子树和右子树的高度差称为该结点的平衡因子。
#### 失衡调整
当对一棵平衡二叉树进行插入或删除操作时，有可能会导致平衡二叉树失衡，此时就应该调整平衡二叉树使其再次平衡。失衡类型有四种，针对不同的类型有不同的调整策略。

- LL：B结点带左子树代替A成为根结点；A结点带右子树成为B的右子树；B结点原来的右子树作为A的左子树。
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/72ec48c7768c43b79c8fb2039bc7ec45.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
- RR：B结点带右子树代替A成为根结点；A结点带左子树成为B的左子树；B结点原来的左子树作为A的右子树。
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/bcd0393451384d09964d3644c773c689.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)

- LR：C结点代替A结点成为根结点；B结点带左子树成为C的左孩子，A结点带右子树成为C的右孩子；原来C结点的左子树作为B的右子树，原来C的右子树作为A的左子树。
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/15a03de83afa4eef9739e1483766f0a9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
- RL：C结点代替A作为根结点；A结点带左子树成为C的左孩子，B结点带右子树成为C的右孩子；原来C结点的左子树作为A的右子树，原来C的右子树作为B的左子树。
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/4d546339626949ff8bcb0c52b33ad85d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6LaF57qn56eN56CB,size_20,color_FFFFFF,t_70,g_se,x_16)
#### 插入
每当在平衡二叉树插入一个结点后，检查其插入路径上的结点是否因此次操作而导致不平衡。若导致了不平衡，则先找出插入路径上离插入结点最近的平衡因子的绝对值大于一的结点，再对以该结点为根的子树进行平衡调整。
#### 删除
每当在平衡二叉树删除一个结点后，检查删除元素路径上的结点是否因此次操作而导致不平衡。若导致了不平衡，则先找出删除路径上离删除结点最近的平衡因子的绝对值大于一的结点，再对以该结点为根的子树进行平衡调整。

### 红黑树
虽然平衡二叉树可以保证二叉排序树的性能，但是频繁的平衡调整代价较大，为此在二叉平衡树上放宽了条件，引入了红黑树，红黑树是具有以下性质的二叉排序树：
- 每个结点是红色或是黑色。
- 根结点是黑色。
- 所有叶子结点（NULL结点）都是黑色。
- 红色结点的父结点和孩子结点都是黑色。
- 对于每个结点而言，其到任意叶子结点的路径都包含相同数目的黑结点，这些黑结点的数量（不含自身）称为该结点的黑高，根结点的黑高称为红黑树的黑高。

常用的结论如下：
- 从根结点到叶子结点的最长路径不大于最短路径的两倍。因为最短路径全由黑结点组成，最长路径由黑结点和红结点交替组成，而红黑节点的数量相同。
- 有n个内部结点的红黑树的高度h<=log₂(n+1)。因为从根结点到叶子结点的任意一条路径都至少有一半是黑结点。。所以根的黑高是少是h/2，
- 新插入红黑树的结点着为红色。

#### 插入
#### 删除
### B树
B树又称为多路平衡查找树，B数中所有结点的孩子个数的最大值称为B树的阶，通常用m表示，B树要么是空树，要么是满足以下条件的m叉树：
- 树中每个结点至少有m棵子树。
- 若根结点不是终端结点，则至少有两棵子树。
- 除根结点之外的非叶子结点至少有⌈m/2⌉棵子树
- 所有叶子节点都出现在同一层次上，且不带任何信息。
### B+树
### B*树
## 图状结构
图G由顶点集V和边集E组成，顶点集V一定非空。图的分类及术语如下：
- 无向图：若E为无向边的有限集合，则G为无向图，E的取值范围为0~n(n-1)/2。
- 有向图：若E为有向边的有限集合，则G为有向图，E的取值范围为0~n(n-1)。
- 简单图和多重图：如果一个图不存在重复边和顶点到自身的边，那么称图为简单图，否则称为多重图。
- 完全图：任意两个顶点之间都有一条边相连的图称为完全图，对于无向图而言，需要有n(n-1)/2条边；对于有向图而言，需有n(n-1)条边。
- 子图：顶点集V和边集E分别是某图顶点集和边集子集的图称为某图的子图。

- 路径、路径长度和回路：从一个顶点到另一个顶点之间经过的所有顶点的序列称为路径；路径上边的数目称为路径长度；起点和终点为同一个顶点的路径称为回路。
- 简单路径和简单回路：顶点不重复的路径称为简单路径；除第一个和最后一个顶点外，其余顶点不重复的回路称为简单回路。
- 连通、连通图和连通分量：在无向图中，两个不同顶点之间存在至少一条路径，则称这两个顶点是连通的。若G中任意两个顶点都是连通的，则称G为连通图，否则称为非连通图；无向图中的极大联通子图称为连通分量。
- 强连通图和强连通分量：在有向图中，两个不同顶点之间存在至少一条路径，则称这两个顶点是强连通的。若G中任意两个顶点都是连通的，则称G为强连通图，否则称为非强连通图；有向图中的极大联通子图称为强连通分量。
- 生成树和生成森林：连通图的生成树是指包含所有顶点的极小连通子图。在非连通图中，连通分量的生成树构成了非连通图的生成森林。
- 顶点的度、入度和出度：和顶点相连的所有边数称为顶点的度，无向图的全部顶点的度等于边数的两倍；以当前顶点为终点的有向边的条数称为入度，以当前顶点为始点的有向边的条数称为出度，有向图的全部入度之和与出度之和相等，并且等于边数。
- 边的权和网：为每条边标记的具有一定意义的数值称为边的权值，边上带有权值的图称为网。
- 距离：两个顶点之间的路径长度称为距离，路径不存在则距离为无穷。
- 有向树：一个顶点的入度为零，其余顶点的入度均为一的有向图称为有向树。

图的存储结构有很多，其中**邻接矩阵法**用一个一维数组存储图中的顶点信息，用一个二维数组存储图中边的信息（即顶点之间的邻接关系），这个二维数组就是邻接矩阵。顶点数为n的图的邻接矩阵是nxn的，如果a、b两个顶点之间有边，那么其对应的邻接矩阵元素(a,b)的值就为真，如果是带权图那么邻接矩阵元素的值就为权值。图的邻接矩阵表示唯一。
```c
typedef struct MGraph{
    VertexType *vex;
    EdgeType **edge;
    int vexNum;
    int edgeNum;
}*MGraph;
```
**邻接表法**为每个顶点建立一个单链表，这个链表中的结点表示依附于该顶点的边，这个单链表就称为顶点的边表。图的邻接表表示不唯一。
```c
typedef struct EdgeNode {
    int vex;
    EdgeType data;
    struct EdgeNode *next;
} EdgeNode, *EdgeList;

typedef struct VexNode {
    VertexType data;
    EdgeList edgeList;
} VexNode, *VexList;

typedef struct ALGraph{
    VexList vexList;
    int vexNum;
    int edgeNum;
} *ALGraph;
```
**十字链表法**是有向图的一种链式存储结构。图的十字链表表示不唯一，但是一个十字链表可以唯一确定一个图。
```c
typedef struct ArcNode{
    ArcType data;
    int tailVex; //弧头顶点位置
    int headVex; //弧尾顶点位置
    int headLink; //弧头相同的下一条弧
    int tailLink; //弧尾相同的下一条弧
}ArcNode;

typedef struct VexNode {
    VertexType data;
    ArcNode * firstIn; //以该顶点为弧头的第一个弧顶点
    ArcNode * firstOut; //以该顶点为为弧尾的第一个弧顶点
}VexNode,* VexList;

typedef struct OLGraph{
    VexList vexList;
    int vexNum;
    int arcNum;
}* OLGraph;
```

**邻接多重表**是无向图的一种链式存储结构。图的邻接多重表表示不唯一。
```c
typedef struct EdgeNode {
    bool mark; //是否被搜搜过
    int iVex; //该边依附的一个顶点位置
    int jVex; //该边依附的另一个顶点位置
    int iLink; //下一个依附顶点iVex的边
    int jLink; //下一个依附顶点jVex的边
} EdgeNode;

typedef struct VexNode {
    VexType data;
    EdgeNode *firstEdge; //第一个依附该顶点的边
} VexNode, *VexList;

typedef struct AMLGraph {
    VexList vexList;
    int vexNum;
    int edgeNum;
} *AMLGraph;
```
### 遍历
图的遍历是指从图中的某一顶点出发，按照某种搜索方法沿着图中的边对图中的所有顶点访问一次且仅访问一次的过程。图的遍历方式主要有以下两种：
- 广度优先搜索（BFS）：从图的某一顶点出发，依次访问该顶点的所有邻接顶；再从这些访问过的邻接顶点出发，依次访问它们的邻接顶点，直到图中所有顶点都被访问为止；若图中还有顶点尚未被访问，则选择一个尚未被访问的顶点重复上述过程。

```c
void BFSTraverse(MGraph graph){
    bool isVisited[graph->vexNum];
    for (int i = 0; i < graph->vexNum; ++i) {
        isVisited[i]=false;
    }
    for (int i = 0; i < graph->vexNum; ++i) {
        if(!isVisited[i]){
            BFS(graph,i,isVisited);
        }
    }
}

static void BFS(MGraph graph,int vex,bool isVisited[]){
    LinkQueue queue=linkQueueConstruct();
    visit(vex);
    isVisited[vex]=true;
    enQueue(queue,vex);
    for (;!isEmpty(queue);){
        vex=deQueue(queue);
        for (int i= firstNeighbor(graph,vex);i>=0;i= nextNeighbor(graph,vex,i)){
            if(!isVisited[i]){
                visit(i);
                isVisited[i]=true;
                enQueue(queue,i);
            }
        }
    }
    linkQueueFinalize(queue);
}
```

- 深度优先搜索（DFS）：从图的某一顶点出发，访问它的任一邻接顶点；再从临界顶点出发，访问邻接顶点的任一邻接顶点；如此往复直到访问到一个所有邻接顶点都被访问的顶点为止；接着回退一步，看看前一次访问的顶点是否还有其它没有被访问的邻接顶点；如果有，则访问此邻接顶点，之后再进行前述过程；如果没有，则再回退一步，重复上述过程，直到连通图中所顶点都被访问过为止。

```c
void DFSTraverse(MGraph graph){
    bool isVisited[graph->vexNum];
    for (int i = 0; i < graph->vexNum; ++i) {
        isVisited[i]=false;
    }
    for (int i = 0; i < graph->vexNum; ++i) {
        if(!isVisited[i]){
            DFS(graph,i,isVisited);
        }
    }
}

static void DFS(MGraph graph,int vex,bool isVisited[]){
    visit(vex);
    isVisited[vex]=true;
    for (int i= firstNeighbor(graph,vex);i>=0;i= nextNeighbor(graph,vex,i)){
        if(isVisited[i]){
            DFS(graph,i,isVisited);
        }
    }
}
```

### 并查集
并查集是一种简单的集合，用于解决图中两个顶点是否含有路径的问题，它包含以下三种操作：
- construct(s)：将集合s中的每个元素初始化为只有一个单元素的子集合。
- union(s,root1,root2)：把集合s中的子集合root2并入到root1，前提是root2和root1互不相交。
- find(s,x)：查找集合s中单元素x所在的子集合，并返回该子集合的根结点。

通常使用树的双亲表示法作为并查集的存储结构。每个子集合以一棵树表示，所有表示子集合的树构成表示全集和的森林，存放在数组中。通常用数组元素的下标代表元素名，用根结点的下标代表子集合名，根结点的双亲结点为负数。

```c
typedef struct UFSet {
    int * nodes;
} * UFSet;

UFSet ufSetConstruct(int len) {
    UFSet set = malloc(sizeof(struct UFSet));
    set->nodes = calloc(sizeof(int), len);
    for (int i = 0; i < len; ++i) {
        *(set->nodes + i) = -1;
    }
    return set;
}

void ufSetFinalize(UFSet set) {
    free(set->nodes);
    free(set);
}

int ufSetFind(UFSet set, int x) {
    for (; *(set->nodes + x) >= 0;) {
        x = *(set->nodes + x);
    }
    return x;
}

bool ufSetUnion(UFSet set, int root1, int root2) {
    if (ufSetFind(set, root1) == ufSetFind(set, root2)) {
        return false;
    } else {
        *(set->nodes + root2) = *(set->nodes + root1);
        return true;
    }
}
```
### 最小生成树
对于一个带权连通无向图G=(V,E)，生成树不同，每棵树的权值也可能不同，若T为权值最小的生成树，则T称为G的最小生成树（MST）。最小生成树的性质如下：
- 如果G中有权值相等的边，则最小生成树不是唯一的，若G的边数比顶点数少一，则G的生成树就是它本身。
- 最小生成树的边的权值是唯一的，且是最小的。
- 最小生成树的边数为顶点数减一。
- U是V的一个子集，若(u,v)是一条具有最小权值的边，其中u∈U，v∈V-U，则必存在一棵包含(u,v)的最小生成树。
#### 普里姆算法（Prim）
普利姆算法的步骤：初始时从图中选择一个顶点加入树T，此时树中只有这一个顶点；之后选择一个与当前T中顶点集合距离最近的顶点，并将该顶点和相应的边加入T；以此类推，直到图中所有的顶点都加入T，得到的T就是最小生成树。

```c

```

#### 克鲁斯卡尔算法（Kruskal）
克鲁斯卡尔算法的步骤：将所有顶点都加入树T，但是不加入边信息；然后在图中寻找权值最小的边，若该边依附的顶点落在树T的顶点上，且不形成环，那么就把该边加入到树T中，否则就舍弃该边；依次类推，直至T中所有顶点都连通。
```c

```
### 最短路径
在网中，把一个顶点到另一个顶点的一条路径所经过边上的权值之和称为该路径的带权路径长度，带权路径长度最短的路径称为最短路径。两点之间的最短路径一定包含路径上其它顶点之间的最短路径。
#### 迪杰斯特拉算法（Dijkstra）
- 首先找出源顶点到达其它顶点的直达路径，不能直达记为无穷大。
- 从这些路径中挑选一条长度最短的路径。并将阿该顶点加入集合S。
- 对其余的路径进行调整，若能经过找到的最短路径到达其它顶点并且该路径之和比直达路径小，那么就是用该路径替代原来的直达路径。并将该顶点加入集合S。
- 之后重复上述步骤直到所有顶点都加入到S集合。
#### 弗洛伊德算法（Floyd）
- 逐个顶点试探，选出一条路径长度最短的。
- 初始时用一个矩阵存储各个顶点之间的距离，如果存在直达路径则记录直达路径，否则记录为无穷大。
- 逐步在原直接路径中增加中间顶点，若加入中间顶点后路径变短，则修改矩阵中的值，否则矩阵中的值不变。
- 所有顶点试探完毕，算法结束。

### 有向无环图
若一个有向图中不存在环，则称该图为有向无环图，简称DAG图。若用DAG图表示一个工程的各个子工程及其相互制约的关系，其中以顶点表示活动，弧表示活动之间的优先制约关系。则将这样的图称为AOV网。AOV网的特点如下：
- 若从A到B有一条有向路径，则A是B的前驱，B是A的后继。
- 若AB是网中的有向边，则A是B的直接前驱，B是A的直接后继。

若用DAG图表示一个工程的各个子工程及其相互制约的关系，其中以弧表示活动，顶点表示活动之的开始和结束事件。则将这样的图称为AOE网。AOE网的性质如下：
- 只有在某顶点所代表的事件发生后，从该顶点出发的各有向边所代表的活动才能开始。
- 只有在进入某顶点的各有向边所代表的活动都已结束时，该顶点所代表的事件才能发生。

#### 拓扑排序
在AOV网下，我们将全部活动排列成一个线性序列，使得若AOV网中有边AB存在，则在这个序列中，A一定排在B的前面，具有这种性质的线性序列称为拓扑有序序列，相应的拓扑有序排序算法称为拓扑排序。拓扑排序的步骤如下：
- 在AOV网中选一个没有前驱的顶点，然后从图网中删除该顶点以及以这个顶点为起点的边。
- 重复上面的步骤，直到网中不存在无前驱的顶点为止。

拓扑排序可以用于检测图中是否含有环：如果拓扑序列中含有所有图中的结点，那么该图就没有环，否则就含有环。
#### 关键路径
在AOE网中，入度为零的顶点称为源点，出度为零的顶点称为汇点，关键路径是指从源点到汇点路径长度最长的路径。
# 算法
算法是为求解一个问题需要遵循的、被清楚指定的简单指令的集合。一个算法具有以下五个特性：

![请添加图片描述](https://img-blog.csdnimg.cn/d7a20bfdc9254465a5f164edb524e637.png)

一个算法的设计取决于所选定的逻辑结构，而算法的实现依赖于所采用的存储结构。
## 算法分析
一旦给定一个算法并且确认其是正确的，那么重要的一步就是对这个算法进行算法分析，算法分析主要考虑算法的效率，算法效率包含以下两方面：
- 时间效率：指算法所消耗的时间，用时间复杂度来表示。
- 空间效率：指算法执行过程中所消耗的存储空间。用空间复杂度来表示。
### 时间复杂度
一个算法的运行的时间大致可以等于计算机执行算法指令的时间（$t$）与指令执行次数（$n$）的乘积。
$$T(n)=\sum_{i=1}^{n} t_i\times n$$

由于每个指令执行的时间由计算机的硬件和软件条件决定，和算法本身没有关系，因此可以将每个指令执行的时间可以看作一个单位时间，那么讨论算法执行时间的问题就变成了讨论算法执行频度的问题：

$$T(n)=\sum_{i=1}^{n} n$$

下面分析一下选择排序算法的执行频度：

```java
public static void selectionSort(int []data){
    for (int i = 0; i < data.length-1; i++) { //n次
        int minIndex=i; //n-1次
        for (int j = i+1; j < data.length; j++) { //n(n-1)/2次
            if (data[j]<data[minIndex]){ //n(n-2)/2次
                minIndex=j; //n(n-2)/2次
            }
        }
        int temp=data[i]; //n-1次
        data[i]=data[minIndex]; //n-1次
        data[minIndex]=temp; //n-1次
    }
}
```
所以选择排序的执行频度为：
$$T(n)=3n^2\div2+5n\div2-4$$

但是这一过程也相当的繁琐并且结果难以比较，由公式
$$\lim\limits_{x\to\infty}\frac{a_nx^n+a_{n-1}x^{n-1}+\cdots+a_1x+a_0}{b_mx^m+b_{m-1}x^{m-1}+\cdots+b_1x+b_0}=\begin{cases}\frac{a_n}{b_m},n=m\\0,n<m\\\infty,n>m\end{cases}$$
可知，如果存在一个函数$f(n)$，使$$\lim\limits_{n \to \infty}\frac{T(n)}{f(n)}=C(C\ne0)$$，那么$f(n)$和$T(n)$就是同阶的，记作$T(n)=O(f(n))$，$O(f(n))$就称为算法的**时间复杂度**。那么上述选择排序的时间复杂度就为$O(n²)$。也就是说在寻找算法频度时不需要找出所有语句执行的频度，只需要找出对算法频度贡献最大的语句即可。此外，输入数据的性质会影响算法的执行频度，在这种情况下将算法的时间复杂度分为三种：
- 最坏时间复杂度：输入数据的性质使算法的执行频度很高。
- 平均时间复杂度：输入数据的性质使算法的执行频度很平均。
- 最好时间复杂度：输入数据的性质使算法的执行频度很低。

但一般只考虑最坏时间复杂度，以保证算法的运行时间不会比它更长。在计算程序的时间复杂度时，有以下两条规则：
- 加法原则：$T(n)=T_1(n)+T_2(n)=O(f(n))+O(g(n))=O(max(f(n),g(n)))$
- 乘法原则：$T(n)=T_1(n)\times T_2(n)=O(f(n))\times O(g(n))=O(f(n)\times Og(n))$

常见时间复杂度的关系为：
$$O(1)<O(log_2n)<O(n)<O(nlog_2n)<O(n^2)<O(n^3)<O(2^n)<O(n!)<O(n^n)$$
### 空间复杂度
与时间复杂度类似，算法的空间复杂度记作：
$$S(n)=O(f(n))$$

它包括算法本身要占据的空间以及使用的辅助空间。在计算空间复杂度时只需要计算辅助空间即可，比如上述的选择排序算，它仅需要一个临时变量作为辅助空间，所以它的空间复杂度为$O(1)$，当算法的空间复杂度为$O(1)$时称它在原地工作。注意，当函数递归调用时，要考虑每一次递归使用的辅助空间。
## 算法思想
### 双指针
#### 快慢指针
#### 左右指针
#### 滑动窗口
### 分治
分治思想：若要解决一个给定的问题，需要将其分解成不同的子问题，再根据子问题的解而求出原问题的解。
### 贪心算法
贪心算法是指在解决问题时总是做出在当前看来是最好的选择，也就是说，不从整体最优上加以考虑，因此省去了为找最优解要穷尽所有可能而必须耗费的大量时间。贪心算法采用自顶向下，以迭代的方法做出相继的贪心选择，每做一次贪心选择，就将所求问题简化为一个规模更小的子问题，通过每一步贪心选择，可得到问题的一个最优解。虽然每一步上都要保证能获得局部最优解，但由此产生的全局解有时不一定是最优的，所以贪心算法不要回溯。能够使用贪心算法解决的问题应该具备以下两个特征：
- 贪心选择性质：一个问题的整体最优解可通过一系列局部的最优解的选择达到，并且每次的选择可以依赖以前作出的选择，但不依赖于后面要作出的选择。这就是贪心选择性质。
- 最优子结构性质：当一个问题的最优解包含其子问题的最优解时，称此问题具有最优子结构性质。问题的最优子结构性质是该问题可用贪心法求解的关键所在。

### 动态规划（DB）
动态规划思想：若要解决一个给定的问题，需要将其分解成不同的子问题，再根据子问题的解而求出原问题的解。要想使用动态规划思想，必须要找到两个必要的条件：

**最优子结构**

最优子结构规定了子问题与原问题之间的关系，在设计算法时一般使用状态转移方程描述这种组合，所谓状态就是原问题或每个子问题的解。例如原问题的解为 `f(n)`，那么状态转移方程 `f(n) = f(n - 1) + 1`描述了一种原问题与子问题的组合关系 。

**重复子问题**

重复子问题规定了子问题与子问题之间的关系。在求解每个子问题的过程中，有可能会重复地遇到一些更小的子问题，而且这些更小的子问题会重复出现在其它子问题里，出现这样的情况，会有很多重复的计算，动态规划可以保证每个重叠的子问题只会被求解一次。当重复的问题很多的时候，动态规划可以减少很多重复的计算。
#### 线性动态规划
线性动态规划的特点是状态的推导是按照问题规模从小到大推过去的，较大规模问题的解依赖较小规模问题的解。

#### 前缀和
#### 区间动态规划
## 排序
排序算法就是将结构中所有数据按照关键字有序的过程。根据数据是否完全在内存中，可将数据分为内部排序和外部排序。

### 插入排序
插入排序的思想是每次将一个待排序的记录按其关键字大小插入前面已排好序的子序列，直到全部记录插入完成。
#### 直接插入排序
- 算法思想：边寻找无序元素插入的位置边向后移动有序序列。
- 时间复杂度：O(n)~O(n²)
- 空间复杂度：O(1)
```c
void directInsertSort(InsertSortElemType elems[],int len){
    for (int i = 1; i < len; ++i) {
        int temp=elems[i];
        for (int j = i-1; j >=0; --j) {
            if (temp<elems[j]){
                elems[j+1]=elems[j];
                if (j==0){
                    elems[j]=temp;
                    break;
                }
            } else{
                elems[j+1]=temp;
                break;
            }
        }
    }
}
```

#### 折半插入排序
- 算法思想：先用二分查找寻找无序元素的位置再向后移动有序序列。
- 时间复杂度：O(nlog₂n)~O(n²)
- 空间复杂度：O(1)

```c
void binaryInsertSort(InsertSortElemType elems[],int len){
    for (int i = 1; i < len; ++i) {
        int temp=elems[i];
        int mid,high=i-1,low=0;
        for (;low<=high;){
            mid=(high+low)/2;
            if (elems[mid]>temp){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        for (int j = i; j >=low; j--) {
            elems[j]=elems[j-1];
        }
        elems[low]=temp;
    }
}
```

#### 希尔排序
- 算法思想：取一个小于n的步长d，把序列分为d个子序列，所有距离为d的倍数的元素在同一子序列，对每个子序列进行直接插入排序，然后减小步长d并重复上述过程，直到d=1。
- 时间复杂度：O(n<sup>1.3</sup>)~O(n²)
- 空间复杂度：O(1)

```c
void shellSort(InsertSortElemType elems[], int len) {
    for (int p = len / 2; p >= 1; p /= 2) {
        for (int i = p; i < len; ++i) {
            int temp = elems[i];
            for (int j = i - p; j >= 0; j-=p) {
                if (temp < elems[j]) {
                    elems[j + p] = elems[j];
                    if (j == 0) {
                        elems[j] = temp;
                        break;
                    }
                } else {
                    elems[j + p] = temp;
                    break;
                }
            }
        }
    }
}
```

### 交换排序
交换排序的思想是根据序列中两个元素关键字的比较结果来对换这两个元素在序列中的位置。
#### 冒泡排序
- 算法思想：从前往后或从后往前两两比较相邻两元素的关键字，若为逆序则交换它们，直到序列比较完。
- 时间复杂度：O(n)~O(n²)
- 空间复杂度：O(1)
```c
void bubbleSort(SwapSortElemType elems[],int len){
    for (int i = 0; i <len; i++) {
        bool flag=false;
        for (int j = len-1; j >i; j--) {
            if (elems[j]<elems[j-1]){
                int temp=elems[j];
                elems[j]=elems[j-1];
                elems[j-1]=temp;
                flag=true;
            }
        }
        if (!flag){
            break;
        }
    }
}
```
#### 快速排序
- 算法思想：在待排序列中选择一个元素pivot作为基准，通过一趟排序将序列划分为两部分，使得第一部分的所有元素小于pivot，第二部分的所有元素大于pivot。piovt放在了其最终的位置上，这个过程为一趟快速排序。然后分别递归的对两个部分重复上述过程，直到每部分只有一个元素或空为止。
- 时间复杂度：O(nlog₂n)~O(n²)
- 空间复杂度：O(log₂n)~O(n)
```c
void quickSort(SwapSortElemType elems[],int low,int high){
    if (low<high){
        int pivotPos=partition(elems,low,high);
        quickSort(elems,low,pivotPos-1);
        quickSort(elems,pivotPos+1,high);
    }
}

int partition(SwapSortElemType elems[],int low,int high){
    int pivot=elems[low];
    for (;low<high;){
        for (;low<high&&elems[high]>=pivot;){
            high--;
        }
        elems[low]=elems[high];
        for (;low<high&&elems[low]<=pivot;){
            low++;
        }
        elems[high]=elems[low];
    }
    elems[low]=pivot;
    return low;
}
```
### 选择排序
选择排序的思想是每一趟（例如第i趟）在后面n-i+1个待排元素中选择关键字最小的元素，作为有序序列的第i个元素，直到n-1趟做完。
#### 简单选择排序
- 算法思想：第i趟从L(i...n)中选择关键字最小的元素与L(i)交换，每一趟排序都可以确定一个元素的最终位置。
- 时间复杂度：O(n²)
- 空间复杂度：O(1)

```c
void SimpleSelectSort(SelectSortElemType elems[], int len){
    for (int i = 0; i < len-1; ++i) {
        int minIndex=i;
        for (int j = i+1; j < len; ++j) {
            if (elems[j]<elems[minIndex]){
                minIndex=j;
            }
        }
        if (minIndex!=i){
            int temp=elems[i];
            elems[i]=elems[minIndex];
            elems[minIndex]=temp;
        }
    }
}
```

#### 堆排序
当一个序列满足L(i)>=L(2i)且L(i)>=L(2i+1)或L(i)<=L(2i)且L(i)<=L(2i+1)时，就称该序列是堆，可以将堆看成一棵完全二叉树，满足第一个条件的堆称为大顶堆，大顶堆的最大元素存放在根结点，且其任一非根结点的值小于等于其双亲结点的值；满足第二个条件的堆称为小顶堆，小顶堆的最小元素存放在根结点，且其任一非根结点的值大于等于其双亲结点的值。
- 算法思想：首先将序列构建成原始堆，堆顶元素就是最大或最小值，输出堆顶元素，再将剩下的元素构建成新的堆，以此往复直到堆中只剩一个元素为止。
- 原始堆构建思想：最后一个结点是第⌊n/2⌋个结点的孩子，对第⌊n/2⌋结点为根的子树进行筛选（以大顶堆为例），若根结点的关键小于左右孩子节点关键字的最大值，则交换，使该子树称为堆。之后依次对以第⌊n/2⌋-1~1结点为根的子树进行向上筛选，直到根结点。
- 堆重构思想：输出堆顶元素后将堆底元素与堆顶元素进行交换，然后以根结点为起点进行向下筛选。
- 时间复杂度：O(nlog₂n)
- 空间复杂度：O(1)
```c
void headSort(SelectSortElemType elems[], int len) {
    buildMaxHead(elems, len);
    for (int i = len; i >0; i--) {
        int temp = elems[0];
        elems[0] = elems[i - 1];
        elems[i - 1] = temp;
        headAdjust(elems, 0, i - 1);
    }
}

void buildMaxHead(SelectSortElemType elems[], int len) {
    for (int i = len / 2; i >= 0; i--) {
        headAdjust(elems, i, len);
    }
}

void headAdjust(SelectSortElemType elems[], int rootIndex, int len) {
    int root = elems[rootIndex];
    for (int i = 2 * rootIndex; i < len; i *= 2) {
        if (i + 1 < len && elems[i + 1] > elems[i]) {
            i++;
        }
        if (root >= elems[i]) {
            break;
        } else {
            elems[rootIndex] = elems[i];
            elems[i] = root;
            rootIndex = i;
        }
    }
}
```
### 归并排序
- 算法思想：将待排序列视为n个有序的子序列，然后两两（或两个以上）归并，得到⌈n/2⌉个长度为2或为1的有序序列，然后继续两两归并，直到合成一个长度为n的有序序列为止。
- 时间复杂度：O(nlog₂n)
- 空间复杂度：O(n)
- 稳定性：稳定
```c
void mergeSort(MergeSortElemType elems[],int low,int high){
    if (low<high){
        int mid=(low+high)/2;
        mergeSort(elems,low,mid);
        mergeSort(elems,mid+1,high);
        merge(elems,low,mid,high);
    }
}

void merge(MergeSortElemType elems[],int low,int mid,int high){
    MergeSortElemType temp[high+1];
    int i,j,k;
    for (k = low; k <=high; ++k) {
        temp[k]=elems[k];
    }
    for (i = low,j=mid+1,k=i; i <=mid&&j<=high; k++) {
        if (temp[i]<temp[j]){
            elems[k]=temp[i++];
        } else{
            elems[k]=temp[j++];
        }
    }
    for (;i<=mid;){
        elems[k++]=temp[i++];
    }
    for (;j<=high;){
        elems[k++]=temp[j++];
    }
}
```
### 基数排序
- 算法思想：
- 时间复杂度：O(nlog₂n)~O(n²)
- 空间复杂度：O(1)
## 查找
查找是指在数据集合中寻找满足某种条件的数据元素的过程。在查找过程中，一次查找的长度是指需要比较的关键字次数，平均查找长度是所有查找过程中进行关键字的比较次数的平均值。其数学定义为：

```c
	n
ASL=∑PⁱCⁱ //P为查找到第i个数据元素的概率，一般认为是1/n;C是找到第i个数据元素所需要进行比较的次数
	i=1
```
平均查找长度是衡量算法效率最主要的指标。
### 线性查找
```c
int seqSearch(ElemType elems[],int len,ElemType key){
    for (int i = 0; i < len; ++i) {
        if(elems[i]==key){
            return i;
        }
    }
}
```
### 二分查找
二分查找必须在结构有序的基础上进行。二分查找的思想：首先将查找值与表中中间位置的元素比较，若相等则查找成功，若不相等，则需要查找的元素只能在中间元素的前半部分或后半部分。然后缩小范围继续同样的查找，直到成功或失败为止。
```c
int binarySearch(ElemType elems[],int len,ElemType key){
    int low=0,height=len-1,mid;
    for (;low<=height;){
        mid=(height-low)/2;
        if(elems[mid]==key){
            return mid;
        } else if(elems[mid]>key){
            height=mid-1;
        } else{
            low=mid+1;
        }
    }
    return -1;
}
```
### 分块查找
分块查找的思想：将查询结构分成若干子块，快内的元素可以无序，但块之间是有序的，即第一块中的对打关键字小于第二块中的所有关键字；然后建立一张索引表，索引表中的每个元素含有各块的最大关键字和各块中第一个元素的地址，索引表按关键字有序排列；之后在索引表中确定待查记录所在的块；最后在块内顺序查找。
### 散列表
哈希表是一种散列存储的线性结构。

**原理**

哈希表的原理为：借助 哈希函数，将键映射到存储桶地址。
- 首先开辟一定长度的，具有连续物理地址的桶数组；
- 当我们插入一个新的键时，哈希函数将决定该键应该分配到哪个桶中，并将该键存储在相应的桶中；
- 当我们想要搜索一个键时，哈希表将使用哈希函数来找到对应的桶，并在该桶中进行搜索。

**负载因子**

负载因子 又叫装填因子，是哈希表的一个重要参数，它是实际利用桶的个数与桶的总数的比值，它反映了哈希表的装满程度。

#### 哈希冲突及解决措施
经过映射之后，不同的数据可能会分配到同一个桶中，这时便产生了冲突。以下是解决方法:

**线行试探法**

线性试探法，就是当插入键`key`时，如果发现桶单元 `bucket[hash(key)]` 已经被占用，则向下线性寻找，直到找到可以使用的空桶。具体说来，经过第 i 次试探之后，桶单元应为：
```java
bucket[(hash(key)+i) mod M],  i=1,2,3…
```
当查找某个键时，首先会通过哈希函数计算出桶的地址，然后比较该桶中保存的值是否为该键，如果不是，则继续向下寻找。如果查找到末尾，则会从头开始查找。而删除某个键时，为了避免查找过程中出现信息丢失，会将删除位置标记为 `deleted`，这样当进行线性查找时，遇到 `deleted` 会继续向下查找而不会中断。

**链地址法**

链地址法是指将桶内产生冲突的键串联成一个链表。这也是`HashMap` 底层解决hash冲突的方法。

**再哈希法**

再哈希法比较典型的应用是双重哈希法，即发生冲突时，通过使用另一个哈希函数来避免冲突。不难想到，另一个哈希函数在构造时，需要具备一些约束条件才能避免再次冲突。然而，双重哈希法同样存在一些问题：
- 与线性试探法相比，双重哈希法会消耗较多的时间。
- 在双重哈希法中，删除会使问题变复杂，如果逻辑删除数量太多，则应重新构造哈希表。

**公共溢出区法**

公共溢出区法就是建立另一个哈希表 `dict_overflow` 作为公共溢出区，当发生冲突时则将该键保存在该哈希表中。

#### 哈希集合和哈希映射
