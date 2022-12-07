#include <stdio.h>
#include <stdlib.h>

// node of a linked list
typedef struct node
{
	int data;
	struct node *next;
} node;

// returns number of elements in a linked list
int size(node *head)
{

	int size = 0;
	node *temp = head;

	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

// function to check if list is empty
const char *empty(node *head)
{
	const char *yes = "yes";
	const char *no = "no";
	return head == NULL ? yes : no;
}

// function to return the value at nth node
int value_at(node *head, int n)
{
	for (int i = 0; i < n; ++i)
		head = head->next;

	return head->data;
}

void print_list(node *head)
{
	node *temp = head;
	printf("List is:\n");
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// query for checking nth value
void queryInput(node *head)
{
	int index;
	printf("which index values would you like to check? ");
	while (scanf("%d", &index) == 1)
	{
		if (index >= (size(head)))
		{
			printf("\nnode is out of bounds... try again: ");
			continue;
		}
		printf("value is %d.\n", value_at(head, index));
	}
}

// add a node at the beginning of the list
void push_front(int data, node **head)
{
		node *newNode = (node *)malloc(sizeof(*newNode));
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
}

/* 
-another way to implement push_front:
node* push_front(int data, node * head){
	node* newNode = (node *)malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->next = head;
	head = newNode;

	return head;
}
*/

// free all dynamically allocated memory
void freeList(node *head){
while(head)
{
	node * temp = head->next;
	free(head);
	head = temp;
}
}

// places an element at the end of the linked list
void push_back(node * head, int value){
	
	node * newNode = (node *)malloc(sizeof(*newNode));
	
	// if linked list is empty
	if (head == NULL)
	{
		newNode->data = value;
		newNode->next = NULL;
		head = newNode;
	}
	else{
		node * temp = head;

		while(temp->next != NULL){
			temp = temp->next;
		}

		newNode->data = value;
		newNode->next = NULL;
		temp->next = newNode;
	}
}

// removes an end item and returns its value

// TODO:
// int pop_back(node *head){
// 	node * temp = head;

// 	while ((temp->next)->next != NULL){
// 		temp = temp->next;
// 	}
// 	temp->next = NULL;
// }

// remove front element and return its value
// TODO:
void pop_front(node *head){
	node * temp = head;
	temp->data	= (head->next)->data;
	temp->next	= (head->next)->next;
	
	head = temp;
}

// insert node at nth position in linked list
void insert_at(node *head, int value, int n){
	// empty -- out of bounds
	node *temp1 = (node *)malloc(sizeof(*temp1));
	temp1->data = value;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	node *temp2 = head;
	for (int i = 0; i < n - 2; ++i)
	{
		temp2 = temp2->next;
	}
	temp1->next	= temp2->next;
	temp2->next = temp1;
}

// delete node at nth position
void Delete(node ** head, int n){
	
	node * temp1 = *head;
	if (!n){
		*head = temp1 -> next;
		free(temp1);
		return;
	}

	int i;
	for(i = 0; i < n - 1; ++i)
		temp1 = temp1->next;
	// tmp1 now points to (n - 1)th node
	node * temp2 = temp1->next; // points to nth node
	temp1 -> next = temp2 -> next;
	free(temp2);
}

int main(int argc, char const *argv[])
{
	node *head = NULL;

	push_front(6, &head);
	push_front(4, &head);
	push_front(2, &head);
	push_front(0, &head);
	push_front(9, &head);

	printf("is list empty? %s.\n", empty(head));
	printf("Linked List contains %d elements.\n", size(head));

	pop_front(head);
	push_back(head, 99);
	insert_at(head,420,3);

	print_list(head);

	int position;
	scanf("%d", &position);

	Delete(&head, position);

	print_list(head);


	// check value of nodes at nth index
	// queryInput(head);
	return 0;
}
