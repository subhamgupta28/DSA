// C++ program to find union and intersection of 
// two unsorted linked lists in O(m+n) time. 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
int data; 
struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
/* allocate node */
struct Node* new_node = (struct Node*)malloc( 
sizeof(struct Node)); 

/* put in the data */
new_node->data = new_data; 

/* link the old list of the new node */
new_node->next = (*head_ref); 

/* move the head to point to the new node */
(*head_ref) = new_node; 
} 

struct Node* getIntersection(Node *head1,Node *head2) 
{ 
unordered_map<int, bool> m; 
struct Node* result = NULL; 

Node *p=head1; 
while(p!=NULL){ 
	m[p->data]=true; 
	p=p->next; 
} 
p=head2; 
while(p!=NULL){ 
	if(m[p->data]==true){ 
		push(&result,p->data); 
	} 
	p=p->next; 
} 
return result; 
} 

struct Node *getUnion(Node *head1,Node *head2){ 
set<int> union_list; 
Node *p=head1; 
while(p!=NULL){ 
	union_list.insert(p->data); 
	p=p->next; 
} 
p=head2; 
while(p!=NULL){ 
	union_list.insert(p->data); 
	p=p->next; 
} 
Node *result=NULL; 
for(auto i:union_list){ 
	push(&result,i); 
} 
return result; 
} 
void printList(struct Node* node) 
{ 
while (node != NULL) { 
printf("%d ", node->data); 
node = node->next; 
} 
} 

void printUnionIntersection(Node* head1,Node* head2) 
{ 
Node* intersection_list = getIntersection(head1,head2); 
Node* union_list = getUnion(head1,head2); 

printf("\nIntersection list is \n"); 
printList(intersection_list); 
printf("\nUnion list is \n"); 
printList(union_list); 
} 
int main() 
{ 
struct Node* head1 = NULL; 
struct Node* head2 = NULL; 
//list1 
push(&head1, 1); 
push(&head1, 2); 
push(&head1, 3); 
push(&head1, 3); 
push(&head1, 4); 
push(&head1, 5); 

//list 2 
push(&head2, 1); 
push(&head2, 5); 
push(&head2, 6); 

printf("First list is \n"); 
printList(head1); 

printf("\nSecond list is \n"); 
printList(head2); 

printUnionIntersection(head1, head2); 

return 0; 
}
