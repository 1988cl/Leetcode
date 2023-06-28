#include <stdio.h>
//pivotInteger
int pivotInteger(int n){   
    int middle  = 0;
    int left = 1;
    int right = n;  
    while(left<=right){
        middle = left + (right-left)/2;       
        int left_sum = ((1+middle)*(middle))/2;
        int right_sum = ((middle+n)*(n-middle+1))/2;
        if(left_sum > right_sum){
            right = middle - 1;
        }else if(left_sum < right_sum){
            left = middle + 1;           
        }else{
            return middle;
        }
              
    }
    return -1;
}

void main(){
    printf("the result is %d\n",pivotInteger(4));
}