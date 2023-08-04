#include <stdio.h>
#include "uthash.h"
#define arr_size 13

typedef struct{
    int key;
    char *val;
    UT_hash_handle hh;
}romanHash,*romanHashP;

int keys[arr_size] = {1,5,10,50,100,500,1000,4,9,40,90,400,900};
char* vals[arr_size] = {"I","V","X","L","C","D","M","IV","IX","XL","XC","CD","CM"};

char * intToRoman(int num){
    char* result;
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
    romanHashP tmp = NULL;
    HASH_FIND_INT(romanHashs,&num,tmp);

    if(tmp!=NULL){
        result = tmp->val;
    }else{
        
    }
    return result;
}

void main(){
    int num = 123;
    while(num!=0){        
        printf("the num is %d\n",num);
        num = num/10;
    }
    //printf("the result is %s\n",intToRoman(11));
}