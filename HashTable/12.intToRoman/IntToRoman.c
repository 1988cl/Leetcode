#include <stdio.h>
#include <string.h>
#include "uthash.h"
#define arr_size 13

typedef struct{
    int key;
    char *val;
    UT_hash_handle hh;
}romanHash,*romanHashP;

int keys[arr_size] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
char* vals[arr_size] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

int baseGet(int num){
    int result = 1;
    for(int i=0;i<arr_size;i++){
        if(num>=keys[i]){
            result=keys[i];
            break;
        }
    }    
    return result;
}

char * intToRoman(int num){
    char* result = (char*)malloc(sizeof(char)*16);
    if(result == NULL){
        exit(1);
    }
    memset(result, '\0', sizeof(result));
    romanHashP romanHashs = NULL;
    for(int index=0;index<arr_size;index++){
        romanHashP tmp = (romanHashP)malloc(sizeof(romanHash));
        if(tmp==NULL){
            exit(1);
        }
        tmp->key = keys[index];
        tmp->val = vals[index];
        HASH_ADD_INT(romanHashs,key,tmp);
    }
    int count = 0;
    int base = 1;
    while(num!=0){
        base = baseGet(num);
        count = num/base;
        char strtmp[4];
        memset(strtmp, '\0', sizeof(strtmp));
        for(int i=0;i<count;i++){
            romanHashP tmp = NULL;
            HASH_FIND_INT(romanHashs,&base,tmp);
            strcat(strtmp,tmp->val);
        }
        strcat(result,strtmp);
        num = num%base;        
    }    
    return result;
}

void main(){
    int num = 123;
    printf("the result is %s\n",intToRoman(12));
}