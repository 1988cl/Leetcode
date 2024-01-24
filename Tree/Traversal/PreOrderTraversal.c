#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <helper.h>

void preOrderTraversalMorris(struct TreeNode* node,int* result,int* returnSize){
    struct TreeNode* pre1 = node;
    struct TreeNode* pre2 = NULL;
    
    while(pre1!=NULL){ 
        pre2 = pre1->left;
        if(pre2!=NULL){
            while(pre2->right!=NULL&&pre2->right!=pre1){
                pre2 = pre2->right;
            }
            
            if(pre2->right == NULL){
                pre2->right = pre1;
                result[(*returnSize)++] = pre1->val;    
                pre1 = pre1->left;
            }else{
                pre1 = pre1->right; 
                pre2->right = NULL;
            }
        }else{
            result[(*returnSize)++] = pre1->val;
            pre1 = pre1->right;
        }  
    }
}

void preOrderTraversalIteration(struct TreeNode* node,int* result,int* returnSize){
    
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*)*MAXSIZE);
    int top = 0;
    while(node!=NULL||!isEmpty(&top)){
        if(node!=NULL){
            result[(*returnSize)++] = node->val;
            push(stack,node,&top);
            node = node->left;
        }else{
            struct TreeNode* tmp = pop(stack,&top);
            node = tmp->right;
        } 
    }    
}

void preOrderTraversalRecrusion(struct TreeNode* node,int* result,int* returnSize){
    if(node == NULL) return;
    result[(*returnSize)++] = node->val;
    preOrderTraversalRecrusion(node->left,result,returnSize);
    preOrderTraversalRecrusion(node->right,result,returnSize);
}

int* preOrderTraversal(struct TreeNode* root,int* returnSize){
    
    if(root==NULL) return NULL;

    int* result = malloc(sizeof(int)*MAXSIZE);
    if(result == NULL){
        puts("malloc failed");
        exit(EXIT_FAILURE);
    }
    preOrderTraversalRecrusion(root,result,returnSize);
    preOrderTraversalIteration(root,result,returnSize);
    preOrderTraversalMorris(root,result,returnSize);

    return result;
}