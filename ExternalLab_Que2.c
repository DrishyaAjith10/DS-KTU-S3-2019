//Queue implementation using array
#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int Queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int e){
    if(rear==MAX-1){
        printf("Queue is full");
    }
    else if(rear==-1 && front==-1){
        rear=front=0;
        Queue[rear]=e;
    }
    else{
        rear = rear+1;
        Queue[rear]=e;

    }
}

void dequeue(){

    if (front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        printf("The deleted element is %d",Queue[front]);
        front=rear=-1;
        printf("Queue is empty");
    }
    else{
        printf("The element deleted is %d", Queue[front]);
        front=front+1;
    }
}

void display(){
    if(front==-1 &&rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("\nThe Queue is : ");
        for(int i=front;i<=rear;i++){
            printf("%d\t",Queue[i]);
        }

    }
    printf("\n");

}

int main(){
    int ch;
    int e;
    while(1){
        printf("\nChoose operation\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your Choice : ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1: 
    printf("Enter element to be pushed");
    scanf("%d",&e);
    enqueue(e);
    break;
    case 2: dequeue();
    break;
    case 3: display();
    break;
    case 4: exit(1);
    break;

    default:
    printf("Wrong choice");
        break;
    }

    }
    return 0;
    

}