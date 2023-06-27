#include <stdio.h>
//pivotInteger
int pivotInteger(int n){
    if(n==1){
        return 1;
    }
    unsigned char changed = 0;
    int middle  = n>>1;
    int left = 0;
    int right = n;  
    while(left!=right){      
        left = ((1+middle)*(middle))>>1;
        right = ((middle+n)*(n-middle+1))>>1;
        if(left > right){
            middle = middle - 1;
            changed = changed | 1;
        }else if(left < right){
            middle = middle + 1;
            changed =  changed | 2;
        }
        if((changed & 1) == ((changed>>1) & 1)){
            middle = -1;
            break;
        }      
    }
    return middle;
}

void main(){
    printf("the result is %d\n",pivotInteger(8));
}