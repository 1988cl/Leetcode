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
    if(strcmp(s,"")==0){
        return 0;
    }
    stringItemP stringItems = NULL;
    int len = 0;
    int result = 1;
    char* sp = s;
    char* start = s;
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
        }else{
            start = tmp->val + 1;
            stringItemP tmp1 = (stringItemP)malloc(sizeof(stringItem));
            tmp1->key = ckey;
            tmp1->val = sp;
            HASH_REPLACE_INT(stringItems,key,tmp1,tmp);
        }
        
        len = sp - start+1;
        result = result>=len?result:len;
        sp++;
    }   
    return result;
}

void main(){
    char* test = "asdasd";
    printf("len is %d\n",lengthOfLongestSubstring(test));
   
}

