//
// Created by Administrator on 2023/10/28.
//

#include "ExternalSort.h"

/**
 * 整数转字符串
 * @param val
 * @return
 */
char *intToString(int val) {
    int length = 1;
    while (val / pow(10, length) != 0) {
        length++;
    }
    char *str = calloc(length + 1, sizeof(char));
    sprintf(str, "%d", val);
    return str;
}

/**
 * 生成块名称
 * @param numb
 * @return
 */
char *createBlockName(int numb) {
    char *blockName = calloc(20, sizeof(char));
    strcat(strcat(strcat(blockName, "./disk/block"), intToString(numb)), ".txt");
    return blockName;
}

/**
 * 创建块文件
 * @param count
 * @param keyCount
 */
void createBlock(int count, int keyCount) {
    for (int i = 1; i <= count; ++i) {
        FILE *block = fopen(createBlockName(i), "a");
        srand(i);
        for (int j = 1; j <= keyCount; ++j) {
            fputs(intToString(rand()), block);
            putc('\n', block);
        }
    }
}

void readBlock(int numb) {

}

void externalSort() {
    int blockNum = 16, blockSize = 3;
    createBlock(blockNum, blockSize);
    Buffer inputBuffer1 = bufferConstructor(blockSize);
    Buffer inputBuffer2 = bufferConstructor(blockSize);
    Buffer outputBuffer = bufferConstructor(blockSize);
    while (blockNum != 0) {

    }
}
