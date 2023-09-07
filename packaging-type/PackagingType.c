//
// Created by Administrator on 2023/9/4.
//

#include "PackagingType.h"

union PackagingType {
    int intValue;
    float floatValue;
    double doubleValue;
    char charValue;
    bool boolValue;
};

int getIntValue(union PackagingType *element) {
    return element->intValue;
}

float getFloatValue(union PackagingType *element) {
    return element->floatValue;
}

double getDoubleValue(union PackagingType *element) {
    return element->doubleValue;
}

char getCharValue(union PackagingType *element) {
    return element->charValue;
}

bool getBoolValue(union PackagingType *element) {
    return element->boolValue;
}

PackagingTypeList intValueOf(int size, ...) {
    PackagingTypeList list = calloc(size, sizeof(union PackagingType));
    va_list argList;
    va_start(argList, size);
    for (int i = 0; i < size; ++i) {
        union PackagingType pack = {.intValue=va_arg(argList, int)};
        *(list + i) = pack;
    }
    va_end(argList);
    return list;
}

PackagingTypeList floatValueOf(int size, ...) {
    PackagingTypeList list = calloc(size, sizeof(union PackagingType));
    va_list argList;
    va_start(argList, size);
    for (int i = 0; i < size; ++i) {
        union PackagingType pack = {.intValue=va_arg(argList, float)};
        *(list + i) = pack;
    }
    va_end(argList);
    return list;
}

PackagingTypeList doubleValueOf(int size, ...) {
    PackagingTypeList list = calloc(size, sizeof(union PackagingType));
    va_list argList;
    va_start(argList, size);
    for (int i = 0; i < size; ++i) {
        union PackagingType pack = {.intValue=va_arg(argList, double)};
        *(list + i) = pack;
    }
    va_end(argList);
    return list;
}

PackagingTypeList charValueOf(int size, ...) {
    PackagingTypeList list = calloc(size, sizeof(union PackagingType));
    va_list argList;
    va_start(argList, size);
    for (int i = 0; i < size; ++i) {
        union PackagingType pack = {.intValue=va_arg(argList, char)};
        *(list + i) = pack;
    }
    va_end(argList);
    return list;
}

struct Person {
    int age;
    float height;
};

PackagingTypeList boolValueOf(int size, ...) {
    struct Person person1 = {1, 2.0f};

    struct Person person2=person1;

    PackagingTypeList list = calloc(size, sizeof(union PackagingType));
    va_list argList;
    va_start(argList, size);
    for (int i = 0; i < size; ++i) {
        union PackagingType pack = {.intValue=va_arg(argList, bool)};
        *(list + i) = pack;
    }
    va_end(argList);
    return list;
}






