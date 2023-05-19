#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void display();

struct Node {
    int data;
    struct Node *next;
};

struct Node *front=NULL, *rear=NULL;

int main(){
    int choice;
    while(1){
    printf("\n enter a choice:");
    printf("\n1.display queue \n2.Enqueue \n3.Dequeue \n4.Quit \n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        display();
        break;
    case 2:
        enqueue();
        break;
    case 3:
        dequeue();
        break;
    case 4:
        exit(0);
    default:
        printf("\ninvalid choice!!");
     }
    }
    return 0;
}

void enqueue(){
 int newVal;
 printf("\nEnter data to push: ");
 scanf("%d", &newVal);
 struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = newVal;
 newNode->next = NULL;
 if(front == NULL){
    front = newNode;
    rear = newNode;
 }else{
    rear->next = newNode;
    rear=newNode;
 }
  printf("pushed new value into queue: %d", newVal);
}

void display(){
    struct Node *temp = front;
    if(temp == NULL) printf("\n No elements in queue:Queue underflow \n");
    else{
        while(temp != NULL){
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

void dequeue(){
    if(front == NULL) printf("\n--No elements in queue, Underflow");
    else{
        struct Node *temp = front;
        front=front->next;
        printf("\n deleting", front->data);
        free(temp);
    }
}