这是一个完整的由纯C语言实现的可以存储任意类型元素的数据结构的工程项目。

![在这里插入图片描述](https://img-blog.csdnimg.cn/46f6fe929bdd412f924f9ede3a3f9890.png)

- 首先是极好的工程意识，该项目是一个中大型的CMake项目，结构目录清晰，通过这个项目可以遇见许多工程问题并且可以培养自己的工程意识。
- 其次是优秀的封装性（每个数据结构的头文件中只暴漏少量的信息），以及优秀的代码风格和全面的注释，通过这个项目可以提升自己的封装技巧：

![在这里插入图片描述](https://img-blog.csdnimg.cn/135fe75fbe19419aa79c9fdea4807987.png)
- 异常处理功能：在使用C语言编写代码的时候不能使用类似Java的异常处理机制是非常难受的，所以我也简单实现了一下。详情可看[在C语言中实现类似面向对象语言的异常处理机制](http://t.csdnimg.cn/C3rH9)

![在这里插入图片描述](https://img-blog.csdnimg.cn/811f01dcb34f439996b040450d3f769d.png)

最后也是最重要的一点，数据结构的通用性和舒适的体验感，下面以平衡二叉树为例：

- 第一步：要想使用平衡二叉树，只需要引入其的头文件：

```c
#include "tree-structure/balanced-binary-tree/BalancedBinaryTree.h"
```
- 第二步：定义自己任意类型的数据，并构造插入数据（以一个自定义的结构体为例）：

```c
#include "tree-structure/balanced-binary-tree/BalancedBinaryTree.h"

int dataCompare(void *, void *);

typedef struct People {
    char *name;
    int age;
} *People;

int main(int argc, char **argv) {
    struct People dataList[] = {
            {"张三", 15},
            {"李四", 3},
            {"王五", 7},
            {"赵六", 10},
            {"田七", 9},
            {"周八", 8},
    };
    BalancedBinaryTree tree = balancedBinaryTreeConstructor(NULL, 0, dataCompare);
    for (int i = 0; i < 6; ++i) {
        balancedBinaryTreeInsert(&tree, dataList + i, dataCompare);
    }
    return 0;
}

/**
 * 根据人的年龄比较
 */
int dataCompare(void *data1, void *data2) {
    int sub = ((People) data1)->age - ((People) data2)->age;
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}
```
- 第三步：打印一下平衡二叉树：

```c
#include "tree-structure/balanced-binary-tree/BalancedBinaryTree.h"

int dataCompare(void *, void *);

void dataPrint(void *);

typedef struct People {
    char *name;
    int age;
} *People;

int main(int argc, char **argv) {
    struct People dataList[] = {
            {"张三", 15},
            {"李四", 3},
            {"王五", 7},
            {"赵六", 10},
            {"田七", 9},
            {"周八", 8},
    };
    BalancedBinaryTree tree = balancedBinaryTreeConstructor(NULL, 0, dataCompare);
    for (int i = 0; i < 6; ++i) {
        balancedBinaryTreeInsert(&tree, dataList + i, dataCompare);
        balancedBinaryTreePrint(tree, dataPrint);
        printf("-------------\n");
    }
    return 0;
}

/**
 * 根据人的年龄比较
 */
int dataCompare(void *data1, void *data2) {
    int sub = ((People) data1)->age - ((People) data2)->age;
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}

/**
 * 打印人的年龄
 * @param data
 */
void dataPrint(void *data) {
    People people = (People) data;
    printf("%d", people->age);
}
```
打印的结果如下：

![在这里插入图片描述](https://img-blog.csdnimg.cn/8524e1da11e3435a90af54a80ab20a95.png)
最后期待大佬们的点赞。