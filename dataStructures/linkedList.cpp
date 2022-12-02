#include <stdio.h>
#include <stdlib.h>

// node of a linked list
typedef struct node
{
	int data;
	node *next;
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

// remove front element and return its value
void pop_front(node *head){
	node * temp = head;
	temp->data	= (head->next)->data;
	temp->next	= (head->next)->next;
	
	head = temp;
}

// free all dynamically allocated memory
void freeList(node *head){
while(head)
{
	node * temp = head->next;
	free(head);
	head = temp;
}
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
	// check value of nodes at nth index
	// queryInput(head);

	print_list(head);

	return 0;
}
