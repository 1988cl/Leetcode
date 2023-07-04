#include <stdio.h>
#include <String.h>
#include "uthash.h"

typedef struct {
    int key;
    char* val;
    UT_hash_handle hh;
}stringItem,*stringItemP;

stringItemP stringItems = NULL;

int lengthOfLongestSubstring(char * s){
    int len = 0;
    int result = 1;
    char* sp = s;
    while((*sp)!= '\0'){
        stringItemP tmp = NULL;
        int ckey = *sp;
        HASH_FIND_INT(stringItems,&ckey,tmp);                
        if(tmp==NULL){
            tmp = (stringItemP)malloc(sizeof(stringItem));    
            if(tmp==NULL){
                exit(1);
            }
            tmp->key = ckey;
            tmp->val = sp;
            HASH_ADD_INT(stringItems,key,tmp);
            len++;
            sp++;
        }else{
            if(tmp->val!=sp){
                len = 0;
                sp = tmp->val + 1;
                stringItemP tmp1 = (stringItemP)malloc(sizeof(stringItem));
                tmp1->key = ckey;
                tmp1->val = sp;
                HASH_REPLACE_INT(stringItems,key,tmp1,tmp);
            }else{
                sp++;
                len++;
            }
        }
        result = result>=len?result:len;
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

