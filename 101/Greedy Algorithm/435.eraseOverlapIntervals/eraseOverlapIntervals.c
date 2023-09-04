#include <stdio.h>
#include <stdlib.h>

void arrSort1(int** arr,int left, int right){
    if (left > right) {
            return;
        }
        int pivot = arr[left][1];  // 定义第一个数为基准数

        int i = left;
        int j = right;

        while (i < j) {
            while (pivot <= arr[j][1] && i < j) {  // 从右往左找比基准数小的
                j = j - 1;
            }
            while (pivot >= arr[i][1] && i < j) {  // 从左往右找比基准数大的
                i = i + 1;
            }
            if (i < j) {
                int temp[2];
                temp[0] = arr[i][0];
                temp[1] = arr[i][1];
                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];
                arr[j][0] = temp[0];
                arr[j][1] = temp[1];
            }
        }
        arr[left][0] = arr[i][0];
        arr[left][1] = arr[i][1];  // i位置的数一定小于基准数，两者可以进行交换
        arr[i][1] = pivot;  // i位置为基准数的最终位置

        arrSort1(arr, left, i-1);
        arrSort1(arr, i+1, right);
}

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
    //[[1,100],[11,22],[1,11],[2,12]] / [1,11] [2,12] [11,22] [1,100]
    int arr[6][2] = {{1,2},{2,3},{3,4},{1,3},{5,8},{4,6}};
    int* arrP[4];
    for(int i=0;i<6;i++){
        arrP[i] = arr[i];
    } 
    arrSort1(arrP,0,5);
    for(int i=0;i<6;i++){
        for(int j=0;j<2;j++){
            printf("[%d,%d]:{%d}\n",i,j,arr[i][j]);
        }
    }
          
}