#include <stdio.h>
#include <stdlib.h>


void arrSort(int** arr,int N){
    int pivot;
    int index;
    int tmp[2];
    
    for(pivot=1;pivot<N;pivot++){
        tmp[0] = arr[pivot][0];
        tmp[1] = arr[pivot][1];
        for(index=pivot;index>0&&arr[index-1][1]>tmp[1];index--){
            arr[index][0] = arr[index-1][0];
            arr[index][1] = arr[index-1][1];
        }
        arr[index][0] = tmp[0];
        arr[index][1] = tmp[1];
    }
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int result = 0;
    arrSort(intervals,intervalsSize);
    int pre = intervals[0][1];
    for(int i=1;i<intervalsSize;i++){
        if(intervals[i][0]<pre){
            result++;
        }else{
            pre = intervals[i][1];
        }
    }
    return result;   
}

void main(){
    //[[1,100],[11,22],[1,11],[2,12]] / [1,11] [2,12] [11,22] [1,100] / [2,10] [1,11] [10,11] [11,22] 
    int arr[4][2] = {{1,2},{2,3},{3,4},{1,3}};
    int* arrP[4];
    for(int i=0;i<4;i++){
        arrP[i] = arr[i];
    } 
    
    arrSort(arrP,4);

    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            printf("[%d,%d]:{%d}\n",i,j,arr[i][j]);
        }
    }
          
}