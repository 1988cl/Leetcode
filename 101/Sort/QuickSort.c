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
    return arr[right-1];
}

void qSort(int arr[],int left,int right){
    int i,j;
    int pivot;
    pivot = median3(arr,left,right);
    i = left; j = right - 1;
    for(;;){
        while(arr[++i]<pivot){}
        while(arr[--j]>pivot){}
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