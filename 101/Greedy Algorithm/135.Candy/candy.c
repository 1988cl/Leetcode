#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int candy(int* ratings, int ratingsSize){     
    int result = 0;
    int* candy = (int*)malloc(sizeof(int)*ratingsSize);
    for(int i=0;i<ratingsSize;i++){
        candy[i] = 1;
    }
    for(int i =1;i<ratingsSize;i++){
        if(ratings[i]>ratings[i-1]){
            candy[i] = candy[i-1] + candy[i];
        }
    }

    for(int i=ratingsSize-1;i>0;i--){
        if(ratings[i-1]>ratings[i]){
            candy[i-1]= MAX(candy[i-1],candy[i]+1);
        }
    }
    for(int i=0;i<ratingsSize;i++){
        result += candy[i] ;
    }
    return result;
}

void main(){
    int ratings[3] = {1,2,2};
    printf("%d\n",candy(ratings,3));
}