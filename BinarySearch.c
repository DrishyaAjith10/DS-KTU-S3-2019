#include <stdio.h>
#define MAX 15

int BinarySearch(int size, int arr[], int t) {
    int l = 0, h = size - 1, m; // Initialize l and h
    while (l <= h) {
        m = (l + h) / 2;
        if (arr[m] == t) {
            return m;
        }
        if (arr[m] > t) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {
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

    printf("Enter element to be searched: ");
    int target;
    scanf("%d", &target);

    int result = BinarySearch(size, arr, target);
    if (result == -1) {
        printf("Element not found in the given array.\n");
    } else {
        printf("Element found at position %d in the array.\n", result + 1); // Array position is 1-based.
    }

    return 0;
}
