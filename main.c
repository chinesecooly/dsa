#include "error/Error.h"

#define TEST_ERROR_1
#define TEST_ERROR_1_TYPE 1
#define TEST_ERROR_2
#define TEST_ERROR_2_TYPE 2

void func(int);

int main() {
    try {
        func(1); //f1
        func(2); //f2
        func(3); //f3
    } catch(TEST_ERROR_1_TYPE) {
        stdErr();
    } catch(TEST_ERROR_2_TYPE) {
        stdErr();
    }finally{
        printf("finally\n");
    };
    return 0;
}

void func(int a)throws TEST_ERROR_1 TEST_ERROR_2 {
    if (a == 1) {
        throw Error(TEST_ERROR_1_TYPE, "测试错误1");
    } else if (a == 2) {
        throw Error(TEST_ERROR_2_TYPE, "测试错误2");
    } else {
        printf("无错误\n");
    }
}

