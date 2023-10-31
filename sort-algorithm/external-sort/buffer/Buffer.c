//
// Created by Administrator on 2023/10/28.
//

#include "Buffer.h"

struct Buffer {
    SingleLinkedList dataList;
    int size;
    int length;
};

Buffer bufferConstructor(int size) {
    Buffer buffer = malloc(sizeof(struct Buffer));
    buffer->dataList = singleLinkedListConstructor();
    buffer->size = size;
    buffer->length = 0;
    return buffer;
}

void put(Buffer buffer, int data) {
}

int get(int index) {

}


