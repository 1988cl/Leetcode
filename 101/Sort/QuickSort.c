#include <stdio.h>

void swap(int* para1,int* para2){
    int tmp = *para1;
    *para1 = *para2;
    *para2 = tmp;
}

int median3(int arr[],int left,int right){
    int center = (left + right)/2;
    if(arr[left] > arr[center]){
        swap(&arr[left],&arr[center]);
    }
    if(arr[left] > arr[right]){
        swap(&arr[left],&arr[right]);
    }
    if(arr[center]>arr[right]){
        swap(&arr[center],&arr[right]);
    }
    swap(&arr[center],&arr[right-1]);
    for(int i=0;i<5;i++){
        printf("the arr[%d] is %d\n",i,arr[i]);
    }  
    return arr[right-1];
}

void qSort(int arr[],int left,int right){
    int i = 0;
    int j = 0;
    int pivot;
    pivot = median3(arr,left,right);
    i = left; j = right-1;
    for(;;){
        while(arr[i]<pivot){i++;}
        while(arr[j]>pivot){j--;}
        if(i<j){
            swap(&arr[i],&arr[j]);
        }else{
            break;
        }
    }
    swap(&arr[i],&arr[right-1]);
    qSort(arr,left,i-1);
    qSort(arr,i+1,right);    
}
void qSort1(int arr[],int left,int right){
    if (left > right) {
            return;
        }
        int pivot = arr[left];  // 定义第一个数为基准数

        int i = left;
        int j = right;

        while (i < j) {
            while (pivot <= arr[j] && i < j) {  // 从右往左找比基准数小的
                j = j - 1;
            }
            while (pivot >= arr[i] && i < j) {  // 从左往右找比基准数大的
                i = i + 1;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        arr[left] = arr[i];  // i位置的数一定小于基准数，两者可以进行交换
        arr[i] = pivot;  // i位置为基准数的最终位置

        qSort1(arr, left, i-1);
        qSort1(arr, i+1, right);
}
void quickSort(int arr[],int N){
    qSort(arr,0,N-1);
}
void main(){
    int arr[5] = {2,5,1,3,9};
    quickSort(arr,5); 
    for(int i=0;i<5;i++){
        printf("the arr[%d] is %d\n",i,arr[i]);
    }  
}