#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize){     
    int result = 0;
    int* candy = (int*)malloc(sizeof(int)*ratingsSize);
    for(int i=0;i<ratingsSize;i++){
        candy[i] = 1;
    }
    for(int i =0;i<ratingsSize;i++){
        if(i!=0 && ratings[i]>ratings[i-1] && candy[i]<=candy[i-1]){
            candy[i] = candy[i-1] + 1;
        }
        if(i!=ratingsSize-1 && ratings[i]>ratings[i+1]&&candy[i]<=candy[i+1]){
            candy[i] = candy[i+1] + 1;
        }
    }

    for(int i=ratingsSize-1;i>-1;i--){
        if(i!=ratingsSize-1 && ratings[i]>ratings[i+1] && candy[i]<=candy[i+1]){
            candy[i] = candy[i+1] + 1;
        }
        if(i!=0 && ratings[i]>ratings[i-1] && candy[i]<=candy[i-1]){
            candy[i] = candy[i-1] + 1;
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