#include <stdio.h>
#include <stdlib.h>

void arrSort(int** intervals){
    
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int compare1 = 0;
    int compare2 = 0;
    int result = 0;
    for(int i=1;i<intervalsSize;i++){
        compare1 = intervals[i-1][1];
        compare2 = intervals[i][0];
        if(compare1>compare2){
            result++;
        }

    }
    return result;   
}

void main(){
    
}