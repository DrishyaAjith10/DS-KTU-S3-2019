#include <stdio.h>
#include <stdlib.h>  // For malloc and free

struct node {
    int data;
    struct node *next;
} *head = NULL;

void display() {
    if (head == NULL) {
        printf("The list is empty\n");
    } else {
        printf("The list is: ");
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int insert_front(int data) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Failed to allocate memory\n");
    } else {
        newnode->data = data;
        newnode->next = head;
        head = newnode; 
    }
    display();
    return 0; // Return type should be consistent, assuming success here.
}

int insert_end(int data) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Failed to allocate memory\n");
    } else {
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            struct node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newnode;
        }
    }
    display();
    return 0; // Return type should be consistent, assuming success here.
}

void insert_pos(int data, int pos) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation unsuccessful\n");
        return;
    }

    newnode->data = data;

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    // If inserting at the front
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        struct node *current = head;
        int count = 1; // Position counting starts from 1
        while (current != NULL && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            printf("Position is out of range\n");
            free(newnode);  // Free memory if position is invalid
            return;
        }

        newnode->next = current->next;
        current->next = newnode;
    }
    display();
}

void delete_front() {
    if (head == NULL) {
        printf("The list is empty\n");
    } else {
        struct node *current = head;
        printf("The deleted element is: %d\n", current->data);
        head = current->next;
        free(current);
    }
    display();
}

void delete_end() {
    if (head == NULL) {
        printf("The list is empty\n");
    } else {
        struct node *current = head;
        struct node *sl = NULL;

        while (current->next != NULL) {
            sl = current;
            current = current->next;
        }

        printf("The deleted element is: %d\n", current->data);
        if (sl != NULL) {
            sl->next = NULL;
        } else {
            head = NULL;  // If there was only one node
        }

        free(current);
    }
    display();
}

void delete_pos(int pos) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    struct node *current = head;
    struct node *prev = NULL;
    int count = 1;

    // Special case if deleting the first node
    if (pos == 1) {
        head = current->next;
        printf("The deleted element is: %d\n", current->data);
        free(current);
        display();
        return;
    }

    while (current != NULL && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position is out of range\n");
    } else {
        prev->next = current->next;
        printf("The deleted element is: %d\n", current->data);
        free(current);
    }
    display();
}

int main() {
    // Test code here
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_front(5);
    insert_pos(25, 3);
    delete_front();
    delete_end();
    delete_pos(2);
    
    return 0;
}
