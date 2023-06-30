/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "uthash.h"

typedef struct {
    int key;
    int val;
    UT_hash_handle hh; 
}HashStructNumSum,*HashStructNumSumP;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    HashStructNumSumP numSumHash = NULL;
    int* result = (int*)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize;i++){
        HashStructNumSumP numSumHashItem = NULL;
        int ikey = nums[i];
        HASH_FIND_INT(numSumHash,&ikey,numSumHashItem);
        if(numSumHashItem == NULL){
            numSumHashItem = (HashStructNumSumP)malloc(sizeof(HashStructNumSum));
            if(numSumHashItem == NULL){
                exit(1);
            }
            numSumHashItem->key = ikey;
            numSumHashItem->val = i;
            HASH_ADD_INT(numSumHash,key,numSumHashItem);   
        } 
    }

    for(int i=0;i<numsSize;i++){
        int ikey = target - nums[i];
        HashStructNumSumP numSumHashItem = NULL;
        HASH_FIND_INT(numSumHash,&ikey,numSumHashItem);
        if(numSumHashItem!=NULL&&numSumHashItem->val!=i){
            result[0] = i;
            result[1] = numSumHashItem->val;
            break;         
        }
    }
    *returnSize = 2;
    return result;
}