#include <stdio.h>
#include <string.h>
#include <uthash.h>
#define arr_size 8

typedef struct{
    char* key;
    char* val;
    UT_hash_handle hh;
}letterHash,*letterHashP;

char* keys[arr_size] = {"2","3","4","5","6","7","8","9"};
char* vals[arr_size] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){

    letterHashP romanHashs = NULL;
    
    while(*digits!='\0'){

        digits++;
    }
}

void main(){
    char* digits = "234";
}