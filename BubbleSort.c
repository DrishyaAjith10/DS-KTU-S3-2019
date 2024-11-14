#include <stdio.h>
#define MAX 20

// Swap function with pass-by-reference using pointers
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// BubbleSort function
void BubbleSort(int n, int arr[]) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]); // pass by reference
            }
        }
    }
}

int main() {
    int arr[MAX], n;

    printf("Enter size of elements: ");
    scanf("%d", &n);

    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    BubbleSort(n, arr);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Correct printing of elements
    }

    printf("\n");

    return 0; // Return success
}
