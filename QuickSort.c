#include <stdio.h>
#define max 10
int swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
int partition(int lb,int ub, int arr[max]){
    int start = lb;
    int end = ub;
    while(start<=end){
        while(arr[start]<=arr[lb]){
            start++;
        }
        while(arr[end]>arr[lb]){
            end--;
        }
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
        
    }
    swap(&arr[lb],&arr[end]);
    return end;

}

int Quicksort(int low, int high, int arr[]){
    if(low<high){
        int pivot = partition(low,high,arr);
        Quicksort(low,pivot-1,arr);
        Quicksort(pivot+1,high,arr);
    }

    }

int main(){
    int arr[]={1,6,3,8,2,9};
    Quicksort(0,6,arr);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}