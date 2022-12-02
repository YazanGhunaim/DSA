#include <stdio.h>
#include <stdlib.h>


// node of a linked list
typedef struct node {
	int data;
	node *next;	
}node;

// returns number of elements in a linked list
int size(node *head) {
	int size = 0;

	while(head != NULL){
		size++;
		head = head->next;
	}

	printf("Linked List contains %d elements.\n", size);
	return size;
}

// initializes three nodes in the list
void init_list(node *p1, node *p2, node *p3){
	p1->data = 4;
	p1->next = p2;

	p2->data = 2;
	p2->next = p3;

	p2->data = 0;
	p2->next = NULL;
}

// function to check if list is empty
bool empty(node *head) {
	return head->next == NULL ? true : false;
}

// function to return the value at nth node
int value_at(node *head, int n){
	for(int i = 0; i < n; ++i)
		head = head->next;

	return head->data;
}

void print_list(node *head){
	while(head != NULL){
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
}

// query for checking nth value
int queryInput(node *head){
	int index;
	printf("which index values would you like to check?\n");

	while (scanf("%d", &index) == 1){
	if (index >= (size(head)))
	{
		printf("\nnode is out of bounds... try again:\n");
		continue;
	}
	printf("value is %d.\n", value_at(head,index));
	}	

	return index;
}

// add a node at the beginning of the list
node * push_front(int data, node *head){
	if (head == NULL)
	{
		node * newNode = (node *)malloc(sizeof(*newNode));
		newNode->data = data;
		head = newNode;

		return newNode;
	}
	else
	{
		node * newNode = (node *)malloc(sizeof(*newNode));
		newNode->data = data;
		newNode->next = head;
		head = newNode;

		return newNode;
	}
}

int main(int argc, char const *argv[])
{	
	node p1,p2,p3;

	//initializing
	init_list(&p1,&p2,&p3);

	printf("is list empty? %d.\n", empty(&p1));
	size(&p1);

	queryInput(&p1);

	// push_front(6,&p1);
	// print_list(&p1);
	

	return 0;
}
