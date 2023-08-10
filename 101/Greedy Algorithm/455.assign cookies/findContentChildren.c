#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b); 
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g,gSize,*g,cmpFunc);
    qsort(s,sSize,*s,cmpFunc);
    int g_index = 0;
    int s_index = 0;
    
    while(g_index<gSize&&s_index<sSize){
        if(g[g_index]<s[s_index]){
            g_index ++;
        }
        s_index++;
    }
    return g_index;
}

void main(){
    int g[3] = {1,2,3};
    int s[2] = {1,1};
    printf("the result is %d\n",findContentChildren(g,3,s,2));
}