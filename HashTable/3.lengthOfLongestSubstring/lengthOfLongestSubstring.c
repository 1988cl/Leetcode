#include <stdio.h>
#include <String.h>
#include "uthash.h"

typedef struct {
    char key;
    char* val;
    UT_hash_handle hh;
}stringItem,*stringItemP;

stringItemP stringItems = NULL;

int lengthOfLongestSubstring(char * s){
    int index = 0;
    int len = 1;
    int result = 1;
    while((*s)!=NULL){
        int len = 1;
        stringItemP tmp = NULL;
        char ckey = *s;
        HASH_FIND_STR(stringItems,&ckey,tmp);
        if(tmp==NULL){
            tmp = (stringItemP)malloc(sizeof(stringItem));
            if(tmp==NULL){
                exit(1);
            }
            tmp->key = ckey;
            tmp->val = s;
            HASH_ADD_STR(stringItems,key,tmp);
        }
    }
    
    return result;
}

void main(){
    char* test = "asdasd";
    printf("test len is %d\n",strlen(test));
    printf("test len is %d\n",sizeof(test));
    char test1[] = "asdasdsad";
    printf("test1 len is %d\n",strlen(test1));
    printf("test1 len is %d\n",sizeof(test1));
}

