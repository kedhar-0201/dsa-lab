#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size],front = -1,rear = -1;
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
    while(1)
    {
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
    if(rear==(size-1)){
        printf("Queue is full\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        printf("Enter value to insert: ");
        scanf("%d",&value);
        rear++;
        queue[rear] = value;
        printf("Insertion successful!\n");
    }
}
void deque()
{
    if(front==-1||front>rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted:%d\n",queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1){
        printf("Queue is Empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("Element:%d\n",queue[i]);
        }
    }
}
