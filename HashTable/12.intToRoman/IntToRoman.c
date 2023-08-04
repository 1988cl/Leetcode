#include <stdio.h>
#include <string.h>
#include "uthash.h"
#define arr_size 13

typedef struct{
    int key;
    char *val;
    UT_hash_handle hh;
}romanHash,*romanHashP;

int keys[arr_size] = {1,5,10,50,100,500,1000,4,9,40,900,400,900};
char* vals[arr_size] = {"I","V","X","L","C","D","M","IV","IX","XL","XC","CD","CM"};

int baseGet(int num){
    int result = 1;
    
    if(num>1000){
        result = 1000;    
    }else if(num<1000&&num>500){
        result = 500;
    }else if(num<500&&num>100){
        result = 100;
    }else if(num<100&&num>50){
        result = 50;
    }else if(num<50&&num>10){
        result = 10;
    }else if(num<10&&num>5){
        result = 5;
    }else{
        result = 1;
    }
    return result;
}

char * intToRoman(int num){
    char result[20];
    int count = 0;
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

    
    while(num!=0){
        romanHashP tmp = NULL;
        HASH_FIND_INT(romanHashs,&num,tmp);
        if(tmp!=NULL){
            strcat(result,tmp->val);
            break;
        }else{
            count = num/baseGet(num);
            char strtmp[20];
            for(int i=0;i<(num/baseGet(num));i++){
                romanHashP tmp = NULL;
                HASH_FIND_INT(romanHashs,&num,tmp);
                strcat(strtmp,tmp->val);
            }
            strcat(result,strtmp);
            num = num%count;
        }
    }    
    return result;
}

void main(){
    int num = 123;
    printf("the result is %s\n",intToRoman(11));
}