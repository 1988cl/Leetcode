#include <stdio.h>
#include <string.h>
#include "uthash.h"

#define arr_size 8

typedef struct{
    char* key;
    char* val;
    UT_hash_handle hh;
}letterHash,*letterHashP;

char* keys[arr_size] = {"2","3","4","5","6","7","8","9"};
char* vals[arr_size] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

letterHashP hashInit(letterHashP romanHashs){
    for(int i=0;i<arr_size;i++){
        letterHashP tmp = (letterHashP)malloc(sizeof(letterHash));
        if(tmp == NULL){
            exit(1);
        }
        tmp->key = keys[i];
        tmp->val = vals[i];
        HASH_ADD_STR(romanHashs,key,tmp);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char* digitsTmp = digits;
    letterHashP romanHashs = NULL;
    for(int i=0;i<arr_size;i++){
        letterHashP tmp = (letterHashP)malloc(sizeof(letterHash));
        if(tmp == NULL){
            exit(1);
        }
        tmp->key = keys[i];
        tmp->val = vals[i];
        HASH_ADD_STR(romanHashs,key,tmp);
    }
    int count = 1;
    char tmp[2];    
    while(*digits!='\0'){
        tmp[0] = *digits;
        tmp[1] = '\0';
        letterHashP HashTmp;
        HASH_FIND_STR(romanHashs,tmp,HashTmp);
        if(HashTmp != NULL){
            count *= strlen(HashTmp->val);
        }
        digits++;
    }

    char** strArr = (char**)malloc(count*3);
    char** result = strArr;
    if(strArr == NULL){
        exit(1);
    }
    char resultElement[3];

    while(*digitsTmp!='\0'){
        tmp[0] = *digitsTmp;
        tmp[1] = '\0';
        letterHashP HashTmp;
        HASH_FIND_STR(romanHashs,tmp,HashTmp);
        if(HashTmp != NULL){
            char* digitsTmp1 = digitsTmp + 1;
            while(*digitsTmp1!='\0'){
                char tmp1[2];
                tmp1[0] = *digitsTmp1;
                tmp1[1] = '\0';
                letterHashP HashTmp1;
                HASH_FIND_STR(romanHashs,tmp1,HashTmp1);
                if(HashTmp1!=NULL){ 
                    for(int j = 0;j<strlen(HashTmp->val);j++){                   
                        for(int i =0;i<strlen(HashTmp1->val);i++){
                            resultElement[0] = (HashTmp->val)[j];
                            resultElement[1] = (HashTmp1->val)[i];
                            resultElement[2] = '\0';
                            //printf("the res element is %s\n",resultElement);
                            *strArr = resultElement;
                            printf("the strArr address %p\n",strArr);
                            printf("the strArr is %s\n",*strArr);
                            strArr = strArr + 1;
                        }
                    }
                }
                digitsTmp1++;
            }
        }
        digitsTmp++;
    }
    *returnSize = count;
    for(int i=0;i<count;i++){
        printf("the res address is %p\n",result);
        printf("the str is %s\n",*result);
        result = result + 1;
    }
    return result;
}


void main(){
    char* digits = "234";
    int returnSize = 0;
    int* returnSizeP = &returnSize ;
    char ** res =  letterCombinations(digits,returnSizeP);
    
    // printf("the returnSize is %d\n",returnSize);
    // for(int i=0;i<*returnSizeP;i++){
    //     printf("the res address is %p\n",res);
    //     printf("the str is %s\n",*res);
    //     res = res + 1;
    // }
}