#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size],front=-1,rear = -1;
int isfull()
{
    return(front==(rear+1)%size);
}
int isempty()
{
    return(front==-1);
}
void enque();
void deque();
void display();
void main()
{
    int choice;
    printf("***Menu***\n");
    printf("1.Enque\n");
    printf("2.Deque\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    while(1){
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enque();
                    break;
            case 2: deque();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Wrong selection!!\n");
                     break;
        }
    }
}
void enque()
{
    int value;
    if(isfull()){
        printf("Queue is full!\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        printf("Enter value to insert:");
        scanf("%d",&value);
        rear = (rear+1)%size;
        queue[rear] = value;
        printf("Insertion isSuccessful!\n");
    }
}
void deque()
{
    if(isempty()){
        printf("Queue is empty!\n");
    }
    else{
        printf("Deleted:%d\n",queue[front]);
        if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%size;
        }
    }
}
void display()
{
    if(isempty()){
        printf("Queue is empty!\n");
    }
    else{
        printf("Queue elements: \n");
        int i=front;
        while(1){
            printf("%d",queue[i]);
            if(i==rear){
                break;
            }
            else{
                i = (i+1)%size;
            }
            printf("\n");
        }
    }
}
