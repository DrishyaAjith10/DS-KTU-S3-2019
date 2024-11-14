#include <stdio.h>
#include <string.h>
#define MAX 10

char stack[MAX];
int top = -1;
char str[MAX], e;

void push(char a) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top = top + 1;
        stack[top] = a;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';  // Return null character in case of underflow
    } else {
        return stack[top--];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%c   ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("\nEnter the string to check: ");
    scanf("%s", str);
    int n = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        e = str[i];
        push(e);
    }

    // Display stack contents
    printf("\nThe stack after pushing the string:\n");
    display();

    int found = 0;

    // Check whether the string is a palindrome
    printf("\nCheck whether palindrome: \n");
    for (int i = 0; i < n; i++) {
        if (str[i] == pop()) {
            found++;
        }
    }

    // If all characters matched, it's a palindrome
    if (found == n) {
        printf("\nPALINDROME\n");
    } else {
        printf("\nNOT PALINDROME\n");
    }

    return 0;
}
