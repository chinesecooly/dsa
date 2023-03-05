//
// Created by Administrator on 2022/3/24.
//

#include "Error.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

jmp_buf jmpBuf;
int val;

static int iLen(int i){
    if(i==0){
        return 1;
    }
    int len=0;
    for(;i!=0;){
        i/=10;
        len++;
    }
    return len;
}

static char * getInfo(int len) {
    char *temp= calloc(sizeof (char ),len+1);
    FILE *log= fopen("error.log","r");
    fseek(log,(-1)*len,SEEK_END);
    fgets(temp,len,log);
    fclose(log);
    return temp;
}

void stdErr(int len) {
    char *temp= getInfo(len);
    printf("%s\n", temp);
    free(temp);
}

int info(char *date, char *time, char *filename, int lineNumber, char *msg) {
    char *str = calloc(sizeof(char), iLen(lineNumber)+1);
//    itoa(lineNumber,str,10);
    size_t infoLen=strlen(date)+ strlen(time)+strlen(filename)+ strlen(str)+ strlen(msg)+8;
    char *info= calloc(sizeof (char ), infoLen);
    strcat(info,date);
    strcat(info," ");
    strcat(info,__TIME__);
    strcat(info," ");
    strcat(info,filename);
    strcat(info," ");
    strcat(info,str);
    strcat(info," ");
    strcat(info,":");
    strcat(info," ");
    strcat(info,msg);
    strcat(info,"\n");
    FILE *log= fopen("error.log","a+");
    fputs(info,log);
    fclose(log);
    free(str);
    free(info);
    return (int)infoLen;
}


