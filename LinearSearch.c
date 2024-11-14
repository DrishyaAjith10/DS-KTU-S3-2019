#include <stdio.h>

int LinearSearch(int arr[],int n,int a){
    int found=0;
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            found=1;
            printf("The element is found at %d index position",i );
            break;
        }
    }
    if(found!=1){
        printf("Search element not found");
    }
}

int main(){
    printf("Enter size of array");
    int n;
    int arr[25];
    scanf("%d",&n);
    printf("Enter elements of the array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int a;
    printf("Enter element to search");
    scanf("%d",&a);
    LinearSearch(arr,n,a);
}