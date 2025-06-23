#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;


void print_list(Node *head)
{
	Node *current;
	current = head;
	int i = 0;

	while ( current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

Node *insert_at_head(Node *head, int new_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	
	if(head !=NULL)
		new_node->next = head;

	return new_node;			
}

int main()
{
	Node *list1_head = NULL;
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_head(list1_head, 6);
	list1_head = insert_at_head(list1_head, 7);

	print_list(list1_head);
}
