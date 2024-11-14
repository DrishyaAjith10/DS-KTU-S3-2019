#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sqrt function to optimize prime checking

struct node {
    int data;
    struct node *next;
} *head = NULL;

// Function to insert an element at the beginning of the list
void insert(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation unsuccessful.\n");
        return;
    }
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // Numbers <= 1 are not prime
    if (num == 2) return 1; // 2 is prime
    for (int i = 2; i <= sqrt(num); i++) { // Check up to sqrt(num) for efficiency
        if (num % i == 0) return 0; // If divisible, not prime
    }
    return 1; // Prime number
}

// Function to delete duplicate elements from the list
void delete_dupl() {
    struct node *current = head;
    struct node *temp = NULL;
    struct node *del = NULL;

    // If the list is empty or has only one element, no duplicates to delete
    if (head == NULL || head->next == NULL) return;

    // Traverse the list
    while (current != NULL && current->next != NULL) {
        temp = current;

        // Compare current node with the rest of the nodes
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                // Duplicate found, delete it
                del = temp->next;
                temp->next = temp->next->next;
                free(del); // Free memory of the duplicate node
            } else {
                temp = temp->next;
            }
        }
        current = current->next; // Move to the next node
    }
}

// Function to display the list
void display() {
    struct node *current = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The list is: ");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to display prime numbers in the list
void check_prime() {
    struct node *current = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Prime numbers in the list are: ");
    while (current != NULL) {
        if (is_prime(current->data)) {
            printf("%d\t", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    int ch, data;
    while (1) {
        printf("Choose your operation: \n");
        printf("1. Insert element\n");
        printf("2. Delete duplicate elements\n");
        printf("3. Display prime numbers\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                delete_dupl();
                printf("Duplicate elements deleted.\n");
                break;
            case 3:
                check_prime();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice.\n");
                break;
        }
    }

    return 0;
}
