#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
struct Node *bottom = NULL;

int main() {
    int choice;
    while(1){
      printf("\n1.push \n2.pop \n3.display stack \n4.exit");
      printf("\nenter a choice: ");
      scanf("%d",&choice);
      switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice!!");
      }
    }
}

void push(){
  int newVal;
  printf("\nenter data to push: ");
  scanf("%d",&newVal);
  struct Node *newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = newVal;
  newNode->next = top;
  top=newNode;
  printf("pushed...");
}

void display(){
    if(top == NULL){
        printf("\nstack is empty!!");
    }else{
        struct Node *temp = top;
        while(temp != NULL){
            printf("%d->", temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}

void pop(){
   if(top == NULL) printf("\n ---Stack underflow,--Empty Stack");
   else{
    struct Node *temp = top;
    int temp_data = top->data;
    top = top->next;
    free(temp);
    printf("\n deleted ", temp_data);
   }
}

void isEmpty(){
    if(top == NULL) printf("\nstack is empty");
    else printf("\n stack is not empty");
}