#include <stdio.h>
#define MAX 20

int swap(int *a,int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int SelectionSort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }

}

int main(){
    int size, arr[MAX];
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    // Check for array size validity
    if (size <= 0 || size > MAX) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX);
        return 1;
    }
    
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    SelectionSort(size,arr);

     printf("Array after sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Correct printing of elements
    }

    printf("\n");

    return 0; // Return success



}