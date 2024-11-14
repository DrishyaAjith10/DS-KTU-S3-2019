#include <stdio.h>
#define MAX 5

int front = -1;
int rear = -1;
int Q[MAX];

void enq(int data) {
    if ((rear + 1) % MAX == front) {  // Queue is full
        printf("Queue overflow\n");
    } else {
        if (front == -1 && rear == -1) {  // First element to be inserted
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;  // Circular increment
        }
        Q[rear] = data;
        printf("Element %d inserted.\n", data);
    }
}

void deq() {
    if (front == -1 && rear == -1) {  // Queue is empty
        printf("Queue underflow\n");
    } else {
        int del = Q[front];
        printf("The element deleted is: %d\n", del);
        if (front == rear) {  // Only one element was in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;  // Circular increment
        }
    }
}

void peek() {
    if (front == -1 && rear == -1) {  // Queue is empty
        printf("Queue is empty\n");
    } else {
        printf("The front element is: %d\n", Q[front]);
    }
}

void display() {
    if (front == -1 && rear == -1) {  // Queue is empty
        printf("Queue is empty\n");
    } else {
        printf("The Queue is: ");
        if (front <= rear) {  // No wraparound
            for (int i = front; i <= rear; i++) {
                printf("%d ", Q[i]);
            }
        } else {  // Wraparound case
            for (int i = front; i < MAX; i++) {
                printf("%d ", Q[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", Q[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {  // Infinite loop to allow multiple operations
        printf("Select operation\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                int d;
                printf("Enter element to be enqueued: ");
                scanf("%d", &d);
                enq(d);
                break;
            }
            case 2: {
                deq();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                peek();
                break;
            }
            case 5: {
                printf("Exiting...\n");
                return 0;  // Exit the program
            }
            default: {
                printf("Wrong choice\n");
            }
        }
    }
    return 0;
}
