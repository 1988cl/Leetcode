#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <helper.h>

void inorderTraversalMorris(struct TreeNode* node,int* result, int* returnSize){
    struct TreeNode* pre1 = node;
    struct TreeNode* pre2 = NULL;
    
    while(pre1 != NULL){
        pre2 = pre1->left;
        if(pre2!=NULL){
            while(pre2->right!=NULL&&pre2->right!=pre1){
                pre2 = pre2->right;
            }
        
            if(pre2->right==NULL){
                pre2->right = pre1;
                pre1 = pre1->left;
            }else{
                result[(*returnSize)++] = pre1->val;
                pre1 = pre1->right;
                pre2->right = NULL;
            }
        }else{
            result[(*returnSize)++] = pre1->val;
            pre1 = pre1->right;
        }
    }   
}

void inorderTraversalIteration(struct TreeNode* node,int* result, int* returnSize){
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*)*MAXSIZE);
    if(stack == NULL){
        puts("malloc failed");
        exit(EXIT_FAILURE);
    }
    int top = 0;
    while(node!=NULL||!isEmpty(&top)){
        if(node != NULL){
            push(stack,node,&top);
            node = node->left;
        }else{
            struct TreeNode* tmp = pop(stack,&top);
            result[(*returnSize)++] = tmp->val;
            node = tmp->right;
        }
    }
}

void inorderTraversalRecrusion(struct TreeNode* node,int* result, int* returnSize){
    if(node == NULL) return;
    inorderTraversalRecrusion(node->left,result,returnSize);
    result[(*returnSize)++] = node->val;
    inorderTraversalRecrusion(node->right,result,returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root==NULL) return NULL;

    int* result = malloc(sizeof(int)*MAXSIZE);
    if(result == NULL){
        puts("malloc failed");
        exit(EXIT_FAILURE);
    }
    postOrderTraversalRecrusion(root,result,returnSize);
    postOrderTraversalIteration(root,result,returnSize);
    postOrderTraversalMorris(root,result,returnSize);

    return result;
}