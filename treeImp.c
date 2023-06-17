#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

//struct node* root = NULL;

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node* nodeOne;
    nodeOne = createNode(10);
    nodeOne->left = createNode(20);
    nodeOne->right = createNode(30);
    preOrder(nodeOne);

    printf("\n");
    nodeOne->left->left = createNode(40);
    nodeOne->left->right = createNode(50);
    preOrder(nodeOne);

    printf("\n");
    postOrder(nodeOne);

    printf("\n");
    inOrder(nodeOne);
    return 0;
}