//
// Created by Administrator on 2022/3/27.
//

#ifndef INC_2023_HTREE_H
#define INC_2023_HTREE_H

typedef char HTreeElemType;
typedef int WeightType;

typedef struct HTNode HTNode, *HTree;

HTree hTreeConstruct(HTreeElemType data[], WeightType weight[], int len);

void hTreePreOrder(HTree tree);

char *huffmanCoding(HTree tree, HTreeElemType elem);

#endif //INC_2023_HTREE_H


