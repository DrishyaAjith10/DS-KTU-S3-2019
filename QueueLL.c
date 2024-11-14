#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Queue overflow\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;  // The next pointer of the new node is NULL, as it will be the last element in the queue.

    if (rear == NULL) {  // If the queue is empty, both front and rear point to the new node.
        front = rear = newnode;
    } else {
        rear->next = newnode;  // Link the current rear node to the new node.
        rear = newnode;  // Update rear to point to the new node.
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        struct node *temp = front;
        front = front->next;  // Move the front pointer to the next node.
        if (front == NULL) {  // If the queue is empty, set rear to NULL as well.
            rear = NULL;
        }
        printf("The element deleted is: %d\n", temp->data);
        free(temp);  // Free the memory of the removed node.
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *current = front;
        printf("Queue elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nSelect operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        int data;
        switch (ch) {
            case 1:
                printf("\nEnter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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
