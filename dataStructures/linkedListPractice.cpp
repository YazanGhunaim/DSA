#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// implementing various functions working with linked lists.

typedef struct node
{
	int data;
	struct node *next;
} node;

// adds an item to the front of the list
void pushFront(node **head, int data);
// print elements of the linked list in order
void print(node *head);
// returns size of linked list
void sizeOflist(node *head, int *size);
// free dynamically allocated memory occupied by the linked list nodes
void freeList(node *head);
// returns true if linked list is empty
bool empty(node *head);
// returns value of nth node
int valueAt(node *head, size_t index);
// removes an item from the front and returns its value
int popFront(node **head);
// adds an item to the end of the list
void pushBack(node *head, int data);
// removes the last item and returns its value
int popBack(node *head);
// return front item
int front(node *head);
// return back item
int back(node *head);
// insert item at nth position in list
void insertAt(node **head, int data, int index);
// removes node at given index
void erase(node **head, int index);
// reverse linked list
void reverse(node **head);

int main()
{
	node *head = NULL;

	assert(empty(head));

	pushFront(&head, 15);
	assert(head->data == 15 && head->next == NULL);

	pushFront(&head, 2);
	assert(head->data == 2 && head->next->data == 15);

	int size = 0;
	sizeOflist(head, &size);
	assert(size == 2);
	assert(!empty(head));

	pushFront(&head, 7);
	assert(head->data == 7 && head->next->data == 2 && head->next->next->data == 15);
	assert(valueAt(head, 0) == 7 && valueAt(head, 1) == 2 && valueAt(head, 2) == 15);

	assert(popFront(&head) == 7);

	pushBack(head, 4);
	assert(head->data == 2 && head->next->data == 15 && head->next->next->data == 4);

	popBack(head);
	assert(head->data == 2 && head->next->data == 15 && head->next->next == NULL);

	pushFront(&head, 100);
	pushBack(head, 400);
	assert(front(head) == 100 && back(head) == 400);

	insertAt(&head, 19, 2);
	assert(head->data == 100 && head->next->data == 2 && head->next->next->data == 19 &&
		   head->next->next->next->data == 15 && head->next->next->next->next->data == 400 &&
		   head->next->next->next->next->next == NULL);

	erase(&head, 0);
	assert(head->data == 2 && head->next->data == 19 && head->next->next->data == 15 &&
		   head->next->next->next->data == 400  &&
		   head->next->next->next->next == NULL);

	reverse(&head);
	assert(head->data == 400  && head->next->data == 15 && head->next->next->data == 19 &&
		   head->next->next->next->data == 2  &&
		   head->next->next->next->next == NULL);

	freeList(head);

	return EXIT_SUCCESS;
}

void pushFront(node **head, int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		*head = newNode;
	}
}

void print(node *head)
{
	node *tmp = head;
	if (!head)
		return;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

void sizeOflist(node *head, int *size)
{
	node *tmp = head;
	int count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}

	*size = count;
}

void freeList(node *head)
{
	while (head)
	{
		node *tmp = head->next;
		free(head);
		head = tmp;
	}
}

bool empty(node *head)
{
	return !head ? true : false;
}

int valueAt(node *head, size_t index)
{
	if (index < 0)
		return 0;
	if (!index)
		return head->data;
	else
	{

		node *tmp = head;
		while (index)
		{
			index--;
			tmp = tmp->next;
		}

		return tmp->data;
	}
	return 0;
}

int popFront(node **head)
{
	if (*head == NULL)
		return 0;
	node *tmp = *head;
	*head = tmp->next;

	int value = tmp->data;
	free(tmp);
	return value;
}

void pushBack(node *head, int data)
{
	node *tmp = head;
	node *newNode = (node *)malloc(sizeof(node));

	newNode->data = data;
	newNode->next = NULL;

	while (tmp->next)
	{
		tmp = tmp->next;
	}

	tmp->next = newNode;
}

int popBack(node *head)
{
	node *tmp = head;

	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	node *tmp2 = tmp->next;
	int value = tmp2->data;
	free(tmp2);
	tmp->next = NULL;
	return value;
}

int front(node *head)
{
	return head->data;
}

int back(node *head)
{
	node *tmp = head;

	while (tmp->next)
	{
		tmp = tmp->next;
	}

	return tmp->data;
}

void insertAt(node **head, int data, int index)
{

	int size = 0;
	sizeOflist(*head, &size);

	if (index < 0 || index >= size)
		return;

	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;

	node *tmp = *head;
	node *tmp2 = *head;

	if (index == 0)
	{
		newNode->next = tmp;
		*head = newNode;
	}
	else
	{
		while (index && tmp->next != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			index--;
		}
		tmp2->next = newNode;
		newNode->next = tmp;
	}
}

void erase(node **head, int index)
{
	// Check if the linked list is empty
	if (head == NULL)
		return;

	// If the index is 0, then we want to remove the head of the list
	if (index == 0)
	{
		// Store a pointer to the head of the list
		node *temp = *head;

		// Set the head of the list to point to the next node in the list
		*head = (*head)->next;

		// Free the memory allocated for the original head of the list
		free(temp);

		// Return from the function
		return;
	}

	// Store a pointer to the current node
	node *current = *head;

	// Iterate through the linked list until we reach the node before the one we want to delete
	for (int i = 0; i < index - 1; i++)
	{
		// If the current node is NULL, then we have reached the end of the list
		if (current == NULL)
			return;

		// Move to the next node in the list
		current = current->next;
	}

	// Store a pointer to the node we want to delete
	node *temp = current->next;

	// If the node we want to delete is NULL, then we have reached the end of the list
	if (temp == NULL)
		return;

	// Set the next pointer of the current node to point to the node after the one we want to delete
	current->next = temp->next;

	// Free the memory allocated for the node we want to delete
	free(temp);
}

void reverse(node **head)
{
	node *current = *head;
	node *prev = NULL;
	node *next = NULL;

	while (current)
	{

		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}

	*head = prev;
}
