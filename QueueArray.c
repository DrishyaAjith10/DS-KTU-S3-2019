#include <stdio.h>
#define Size 5
int Queue[Size];
int front=rear=-1;

int enqueue(){
    if(rear=Size-1){
        printf("Queue is full");
    }
    else if (rear=front=-1){
        rear = front = 0;
        int e;
        printf("Enter leement to pushed : ");
        scanf("%d",&e);
        Queue[rear]=e;
    }
    else{
        rear = rear+1;
        int e;
        printf("Enter leement to pushed : ");
        scanf("%d",&e);
        Queue[rear]=e;

    }

}

void dequeue(){
    if(rear = front =-1){
        printf("Queue is empty");
    }
    else if (rear = front){
        printf("The element popped is %d", Queue[rear]);
        rear=front=-1
    }
    else{
        printf("Element popped is : %d", Queue[rear]);
        front=front+1;
        
    }

}

void main(){
    
}