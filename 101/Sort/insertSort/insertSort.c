#include<stdio.h>

void insertionSort(int arr[],int N){
    int pivot,index;
    int tmp;
    for(pivot=1;pivot<N;pivot++){
        tmp = arr[pivot];
        for(index=pivot;index>0&&arr[index-1]>tmp;index--){
            arr[index] = arr[index-1];
        }
        arr[index] = tmp;
    }
}

void main(){
    int arr[5] = {2,5,1,3,9};
    insertionSort(arr,5); 
    for(int i=0;i<5;i++){
        printf("the arr[%d] is %d\n",i,arr[i]);
    }
}