#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data;
    struct node *next;
} *top = NULL;

void push(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    printf("The element popped is: %d\n", temp->data);
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nSelect operations:\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        int data;
        switch (ch) {
            case 1:
                printf("\nEnter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;
}
