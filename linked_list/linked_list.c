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
	
	if(head != NULL)
		new_node->next = head;

	return new_node;			
}

Node *insert_at_tail(Node *head, int new_value)
{
	Node *new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	
	// If first node, no need to find the tail node
	if ( head == NULL)
	       return new_node;
	
	// If not first node, traverse until tail node is found
	// Tail node has (node->next == NULL)
	Node *current = head;
	while( current->next != NULL)	// current is now the tail node
		current = current->next;
	// new_node is not the tail node
	current->next = new_node;
	return head;	
		
}

Node *delete_at_head(Node *head)
{
	if ( head == NULL )
		return NULL;
	else if ( head->next == NULL)
	{
		free(head);
		return NULL;	
	}
	else
	{
		Node *to_return = head->next;
		free(head);
		return to_return;
	}
}

Node *delete_at_tail(Node *head)
{
	if ( head == NULL )
		return NULL;
	else if ( head->next == NULL )
	{
		free(head);
		return NULL;
	}
	else
	{
		Node *current = head;
		Node *prev = NULL;
	
		while( current->next != NULL )
		{
			prev = current;
			current = current->next;
		}

		prev->next = NULL;
		free(current);

		return head;
	}
}

int main()
{
	Node *list1_head = NULL;
	list1_head = insert_at_head(list1_head, 1);
	list1_head = insert_at_head(list1_head, 2);
	list1_head = insert_at_head(list1_head, 3);
	list1_head = insert_at_tail(list1_head, 4);
	list1_head = insert_at_tail(list1_head, 8);
	list1_head = insert_at_tail(list1_head, 12);

	print_list(list1_head);

	list1_head = delete_at_head(list1_head);
	list1_head = delete_at_head(list1_head);
	list1_head = delete_at_tail(list1_head);
	list1_head = delete_at_tail(list1_head);
	

	print_list(list1_head);
}
