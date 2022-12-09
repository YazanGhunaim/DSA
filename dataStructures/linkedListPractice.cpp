#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// implementing various functions working with linked lists.
typedef struct node{
	int data;
	struct node * next;
}node;

// adds an item to the front of the list
void pushFront(node ** head, int data);
// print elements of the linked list in order
void print(node *head);
// returns size of linked list
void sizeOflist(node * head, int * size);
// free dynamically allocated memory occupied by the linked list nodes
void freeList(node *head);
// returns true if linked list is empty
bool empty(node * head);

int main()
{
	node * head = NULL;
	pushFront(&head, 15);
	assert(head->data == 15 && head -> next == NULL);
	pushFront(&head, 2);
	assert(head -> data == 2 && head -> next -> data == 15);

	int size = 0;
	sizeOflist(head, &size);
	assert(size == 2);
	assert(!empty(head));
	
	freeList(head);
	assert(empty(head));

	

return EXIT_SUCCESS;
}

void pushFront(node **head, int data){
	node * newNode = (node *)malloc(sizeof(node));
	newNode -> data = data;
	newNode -> next = NULL;

	if(*head == NULL){
		*head = newNode;
	}
	else{
		newNode -> next = *head;
		*head = newNode;
	}
}

void print(node * head){
	node * tmp = head;
	if(!head) return;
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

void sizeOflist(node * head, int * size){
	node * tmp = head;
	int count = 0;
	while(tmp){
		tmp = tmp -> next;
		count ++;
	}

	*size = count;
}

void freeList(node *head){
	while(head){
		node * tmp = head -> next;
		free(head);
		head = tmp;
	}
}

bool empty(node * head)
{
	return !head ? true : false;
}
