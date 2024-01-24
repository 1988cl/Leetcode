#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <helper.h>

bool isEmpty(int* top){
    return (*top) == 0;
}

void push(struct TreeNode** stack,struct TreeNode* node,int* top){
    if((*top)<MAXSIZE) {
        stack[(*top)++] = node;
    }else{
        puts("out of scope");
        exit(EXIT_FAILURE);
    }
    
}

struct TreeNode* pop(struct TreeNode** stack, int* top){
    if(!isEmpty(top)){
        return stack[--(*top)];
    }
    return NULL;
}

struct TreeNode* revertList(struct TreeNode* node){
    struct TreeNode* cur = node;
    struct TreeNode* pre = NULL;
    struct TreeNode* next = NULL;
    while(cur!=NULL){
        next = cur->right;
        cur->right = pre;
        pre = cur;
        cur = next;    
    }
    return pre;
}