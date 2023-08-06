#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "uthash.h"
#define arr_size 13
typedef struct{
    char * key;
    int val;
    UT_hash_handle hh;
}romanHash,*romanHashP;

int vals[arr_size] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
char* keys[arr_size] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

int romanToInt(char * s){
    
    int len = strlen(s);
    int result = 0;
    romanHashP romanHashs = NULL;
    for(int index=0;index<arr_size;index++){
        romanHashP tmp = (romanHashP)malloc(sizeof(romanHash));
        if(tmp==NULL){
            exit(1);
        }
        tmp->key = keys[index];
        tmp->val = vals[index];
        HASH_ADD_STR(romanHashs,key,tmp);
    }
    printf("the count is %d\n",HASH_COUNT(romanHashs));
    
    char tmp[3];  
    
    while(*s!='\0'){
        tmp[0] = *s;
        tmp[1] = *(s+1);
        romanHashP HashTmp = NULL;
        HASH_FIND_STR(romanHashs,tmp,HashTmp);
        if(HashTmp==NULL){
            tmp[1] = '\0';
            HASH_FIND(hh,romanHashs,tmp,sizeof(char)*strlen(tmp),HashTmp);
            if(HashTmp!=NULL){
                result += HashTmp->val;
                s++;
            }
        }else{
            result += HashTmp->val;
            if(*(s+1)=='\0'){
                break;
            }
            s = s + 2;
        }
        
    }
    return result;
}

void main(){    
    printf("the vals is %d\n",romanToInt("MCMXCIV"));    
}
