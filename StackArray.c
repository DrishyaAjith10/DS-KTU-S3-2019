#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top = top + 1;
        printf("Enter element to be pushed to the stack: ");
        scanf("%d", &stack[top]);  // Fix: Use &stack[top]
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The element deleted is: %d\n", stack[top]);
        top = top - 1;
    }
}

void peak() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The stack is: ");
        for (int i = 0; i <= top; i++) {  // Fix: Loop until top, inclusive
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {  // Infinite loop to allow multiple operations
        printf("Select operation\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                push();
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                peak();
                break;
            }
            case 5: {
                printf("Exiting...\n");
                return 0;  // Return 0 to indicate successful exit
            }
            default: {
                printf("Wrong choice\n");
            }
        }
    }
    return 0;  // Although this line is not necessary as we return inside the loop
}
