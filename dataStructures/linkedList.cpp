#include <stdio.h>
#include <stdlib.h>


// node of a linked list
typedef struct node {
	int data;
	node *next;	
}node;

// returns number of elements in a linked list
void size(node *head) {
	int size = 0;

	while(head != NULL){
		size++;
		head = head->next;
	}

	printf("Linked List contains %d elements.\n", size);
}

void init_list(node *p1, node *p2, node *p3){
	p1->data = 4;
	p1->next = p2;

	p2->data = 2;
	p2->next = p3;

	p3->data = 0;
	p3->next = NULL;
}

bool empty(node *head) {
	return head->next == NULL ? true : false;
}

int main(int argc, char const *argv[])
{	
	node p1,p2,p3;

	init_list(&p1,&p2,&p3);
	printf("is list empty? %d.\n", empty(&p1));
	size(&p1);
	

	return 0;
}
