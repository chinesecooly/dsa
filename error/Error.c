//
// Created by Administrator on 2022/3/24.
//

#include "Error.h"

jmp_buf env={};
struct Error error = {0,0,NULL,NULL,NULL};

void stdErr(){
    printf("%s %s  %d %s\n",error.date,error.file,error.line,error.msg);
}







