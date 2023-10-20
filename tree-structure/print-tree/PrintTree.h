//
// Created by Administrator on 2023/10/20.
//

#ifndef DSA_PRINTTREE_H
#define DSA_PRINTTREE_H

#define treeDeep(lNodeName, rNodeName, tree) ({ \
    int deep=0;                                            \
    if(tree!=NULL){                          \
        int leftDeep=treeDeep(lNodeName, rNodeName,tree->lNodeName);         \
        int rightDeep=treeDeep(lNodeName, rNodeName,tree->rNodeName);        \
        deep=leftDeep > rightDeep ? leftDeep + 1 : rightDeep + 1;\
    }                                           \
})

#define fillArray(lNodeName, rNodeName, tree, arr, start, end, width, height) {\
    int ti, tj;\
    if (tree != NULL) {\
        *(arr + (start * width) + end) = tree->data;\
        if (tree->lNodeName != NULL) {\
            for (ti = start + 1, tj = end - 1; tj > end - (height - start + 1) / 2; tj--) {\
                *(arr + ((ti) * width) + tj) = (void *) (-1);\
                ti++;\
            }\
        }\
        if (tree->rNodeName) {\
            for (ti = start + 1, tj = end + 1; tj < end + (height - start + 1) / 2; tj++) {\
                *(arr + ((ti) * width) + tj) = (void *) (-2);\
                ti++;\
            }\
        }\
        fillArray(lNodeName, rNodeName, tree->lNodeName, arr, ti, end - (height - start + 1) / 2, width, height);\
        fillArray(lNodeName, rNodeName, tree->rNodeName, arr, ti, end + (height - start + 1) / 2, width, height);\
    }\
}

#define printTree(lNodeName, rNodeName, dataType, formatString, tree) {\
    int deep = treeDeep(lNodeName,rNodeName,tree);\
    int width = (2 << deep) - 3;\
    int height = (2 << (deep - 1)) - 1;\
    void **arr = calloc(width * height, sizeof(void *));\
    for (int i = 0; i < height; i++) {\
        for (int j = 0; j < width; j++) {\
            *(arr + (i * width) + j) = (void *) (-3);\
        }\
    }\
    fillArray(lNodeName,rNodeName,tree, arr, 0, (width - 1) / 2, width, height);\
    for (int i = 0; i < height; i++) {\
        for (int j = 0; j < width; j++) {\
            if (*(arr + (i * width) + j) == (void *) (-1)) {\
                printf("/");\
            } else if (*(arr + (i * width) + j) == (void *) (-2)) {\
                printf("\\");\
            } else if (*(arr + (i * width) + j) == (void *) (-3)) {\
                printf(" ");\
            } else {\
                printf(#formatString, *((dataType *) *(arr + (i * width) + j)));\
            }\
        }\
        printf("\n");\
    }\
}

#endif //DSA_PRINTTREE_H
