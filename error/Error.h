//
// Created by Administrator on 2022/3/24.
//

#ifndef DSA_ERROR_H
#define DSA_ERROR_H

#include <setjmp.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "ErrorConstant.h"

#define try if(!(setjmp(env)))
#define catch(TYPE) else if(strcmp(#TYPE,error.type)==0)
#define finally
#define throw
#define throws
#define Error(TYPE, MSG) do{error.type=#TYPE;error.msg=MSG;error.line=__LINE__;error.date=__DATE__;error.file=__FILE__;longjmp(env,1);}while(false)

struct Error {
    char *type;
    int line;
    char *msg;
    char *date;
    char *file;
};
extern jmp_buf env;
extern struct Error error;

/**
 * 控制台打印异常信息
 */
void stdErr();

/**
 * 控制台打印提示消息
 */
void stdInfo();

/**
 * 控制台打印警告消息
 */
void stdWarn();


#endif //DSA_ERROR_H
