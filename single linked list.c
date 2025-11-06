#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;};
struct Node*createNode(int data){
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display(struct Node*head){
    if(head==NULL){
       printf("List is empty\n");
       return;
    }
    struct Node*temp = head;
    printf("Linked List:");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertAtBeginning(struct Node**head,int data){
    struct Node*newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    }
void insertAtEnd(struct Node**head,int data){
    struct Node*newNode = createNode(data);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    struct Node*temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtPosition(struct Node**head,int data,int position){
    struct Node*newNode = createNode(data);
    if(position==1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node*temp = *head;
    int i;
    for(i=1;i<position-1&&temp!=NULL;i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Invalid position!");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int main(){
    int choice,data,position;
    struct Node*head = NULL;
    printf("\n---Single Linked List---\n");
    printf("1.Insert at beginning\n");
    printf("2.Insert at end\n");
    printf("3.Insert at position\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    while(1){
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to insert at beginning:");
                    scanf("%d",&data);
                    insertAtBeginning(&head,data);
                    break;
            case 2: printf("Enter value to insert at end:");
                    scanf("%d",&data);
                    insertAtEnd(&head,data);
                    break;
            case 3: printf("Enter value to insert at position: ");
                    scanf("%d",&data);
                    printf("Enter position:");
                    scanf("%d",&position);
                    insertAtPosition(&head,data,position);
                    break;
            case 4: display(head);
                    break;
            case 5: printf("Program is exiting");
                    exit(0);
            default: printf("Invalid choice!Try Again");
                     break;
        }
    }
}
