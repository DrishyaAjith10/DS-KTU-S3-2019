#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int exp;
    struct node *next;
} *p1 = NULL, *p2 = NULL, *p3 = NULL;

int create(struct node **p) {
    int t;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d", &t);

    struct node *temp = NULL, *newnode;
    for (int i = 0; i < t; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation unsuccessful\n");
            return -1;
        }

        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;

        if (*p == NULL) {
            *p = newnode;  // First node
        } else {
            temp->next = newnode;  // Link previous node to new node
        }
        temp = newnode;  // Move temp to the new node
    }
    return t;
}

void AddPoly(struct node *p1, struct node *p2, struct node **p3) {
    struct node *temp3 = NULL, *newnode;
    
    while (p1 != NULL && p2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation unsuccessful\n");
            return;
        }
        
        // If exponents are the same, add the coefficients
        if (p1->exp == p2->exp) {
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        // If p1 exponent is greater, take p1's term
        else if (p1->exp > p2->exp) {
            newnode->coeff = p1->coeff;
            newnode->exp = p1->exp;
            p1 = p1->next;
        }
        // If p2 exponent is greater, take p2's term
        else {
            newnode->coeff = p2->coeff;
            newnode->exp = p2->exp;
            p2 = p2->next;
        }
        
        newnode->next = NULL;
        
        // Link the new node to the result list
        if (*p3 == NULL) {
            *p3 = newnode;  // First node in result
        } else {
            temp3->next = newnode;
        }
        temp3 = newnode;  // Move temp3 to the new node
    }

    // If p1 still has terms, add them
    while (p1 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation unsuccessful\n");
            return;
        }
        newnode->coeff = p1->coeff;
        newnode->exp = p1->exp;
        newnode->next = NULL;
        if (*p3 == NULL) {
            *p3 = newnode;
        } else {
            temp3->next = newnode;
        }
        temp3 = newnode;
        p1 = p1->next;
    }

    // If p2 still has terms, add them
    while (p2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation unsuccessful\n");
            return;
        }
        newnode->coeff = p2->coeff;
        newnode->exp = p2->exp;
        newnode->next = NULL;
        if (*p3 == NULL) {
            *p3 = newnode;
        } else {
            temp3->next = newnode;
        }
        temp3 = newnode;
        p2 = p2->next;
    }
}

void display(struct node *p) {
    if (p == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    
    struct node *temp = p;
    while (temp != NULL) {
        printf("%.2fx^%d ", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t1, t2;

    printf("Enter first polynomial:\n");
    t1 = create(&p1);  // Create first polynomial

    printf("Enter second polynomial:\n");
    t2 = create(&p2);  // Create second polynomial

    p3 = NULL;  // Initialize the result polynomial
    AddPoly(p1, p2, &p3);  // Add polynomials

    printf("Resultant Polynomial: ");
    display(p3);  // Display the resultant polynomial

    return 0;
}
