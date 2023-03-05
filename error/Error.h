//
// Created by Administrator on 2022/3/24.
//

#ifndef INC_2023_ERROR_H
#define INC_2023_ERROR_H

#include <setjmp.h>

#define try if(!(val=setjmp(jmpBuf)))
#define catch(jmpBuf) else
#define throws
#define error val

extern jmp_buf jmpBuf;
extern int val;

void stdErr(int);

int info(char * date,char * time,char * filename,int lineNumber,char * msg);

#endif //INC_2023_ERROR_H
