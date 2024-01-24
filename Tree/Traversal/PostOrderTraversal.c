#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <helper.h>

void revertTraversal(struct TreeNode* node, int* result, int* returnSize){
    struct TreeNode* revertNode = revertList(node);
    while(revertNode!=NULL){
        result[(*returnSize)++] = revertNode->val;
        revertNode = revertNode -> right;
    }
    revertList(revertNode);
}

void postOrderTraversalMorris(struct TreeNode* node, int* result, int* returnSize){
    struct TreeNode* pre1 = node;
    struct TreeNode* pre2 = NULL;
    while(pre1!=NULL){
        pre2 = pre1->left;
        if(pre2!=NULL){
            while(pre2->right!=NULL&&pre2->right!=pre1){
                pre2 = pre2->right;
            }
            if(pre2->right==NULL){
                pre2->right = pre1;
                pre1 = pre1->left;
            }else{
                revertTraversal(pre1->left,result,returnSize);
                pre1 = pre1->right;
                pre2->right = NULL;     
            }
        }else{
            pre1 = pre1->right;
        }
    }
    revertTraversal(node,result,returnSize);
}

void postOrderTraversalIteration(struct TreeNode* node, int* result, int* returnSize){
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*)*MAXSIZE);
    if(stack == NULL){
        puts("malloc failed");
        exit(EXIT_FAILURE);
    }
    int top = 0;
    struct TreeNode* pre = NULL;
    while(node!=NULL||!isEmpty(&top)){
        if(node!=NULL){
            push(stack,node,&top);
            node = node->left;
        }else{
            struct TreeNode* tmp = pop(stack,&top);
            if(tmp->right!=NULL&&tmp->right!=pre){
                push(stack,tmp,&top);
                node = tmp->right;
            }else{
                pre = tmp;
                result[(*returnSize)++] = tmp->val;
            }            
        }
    }
}

void postOrderTraversalRecrusion(struct TreeNode* node, int* result, int* returnSize){
    if(node == NULL) return;
    postOrderTraversalRecrusion(node->left, result, returnSize);
    postOrderTraversalRecrusion(node->right, result, returnSize);
    result[(*returnSize)++] = node->val;
}

int* postOrderTraversal(struct TreeNode* root,int* returnSize){
    
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