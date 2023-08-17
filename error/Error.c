//
// Created by Administrator on 2022/3/24.
//

#include "Error.h"

jmp_buf env;
struct Error error = {NULL, 0, NULL, NULL, NULL};

void stdErr() {
    printf("\033[1;31m %s %s  %d %s .\033[0m\n", error.date, error.file, error.line, error.msg);
}

void stdInfo() {
    printf("%s %s  %d %s \n", error.date, error.file, error.line, error.msg);
}

void stdWarn() {
    printf("\033[1;33m %s %s  %d %s .\033[0m\n", error.date, error.file, error.line, error.msg);
}






