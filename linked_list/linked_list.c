#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
	if (head == NULL)
	{
		*was_deleted = false;
		return NULL;
	}
	// If head node is a match, then just start head from the next node
	else if (head->value == delete_value)
	{
		Node *temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}
	else
	{
		Node *current = head;
		Node *prev = NULL;
		while (current != NULL)
		{
			if (current->value == delete_value)
			{
				// Found delete_value, point previous->next to skip current node
				prev->next = current->next;
				free(current);
				*was_deleted = true;
				return head;
			}
			prev = current;
			current = current->next;
		}
		// End of list, could not find delete_value
		*was_deleted = false;
		return head;
	}
}

// Inefficient method as it traverses through the list multiple times
Node *delete_all_matches(Node *head, int delete_value, int *num_deleted)
{
	Node *current = head;
	*num_deleted = 0;
	bool deleted = false;
	
	do
	{
		current = delete_first_match(current, delete_value, &deleted);
		if (deleted)
			*num_deleted += 1;
	} while(deleted);
	
	return current;
}

int length(Node *node)
{
	Node *current = node;
	int len = 0;

	while ( node != NULL )
	{
		len++;
		node = node->next;
	}
	return len;
}

int recursive_length(Node * node)
{
	if ( node == NULL )
		return 0;
	return 1 + recursive_length(node->next);
}

bool is_member(Node *node, int find_value)
{
	if ( node == NULL )
		return false;
	else if ( node->value == find_value )
		return true;
	else
		return is_member( node->next, find_value);
}

int count_matches(Node *node, int find_value)
{
	if (node == NULL)
		return 0;
	else if (node->value == find_value)
		return 1 + count_matches(node->next, find_value);
	else
		return count_matches(node->next, find_value);
}

void replace_matches(Node *node, int find_value, int replace_value)
{
	if (node != NULL)
	{
		if (node->value == find_value)
			node->value = replace_value;
		replace_matches(node->next, find_value, replace_value);
	}
}

int main()
{
	Node *list1_head = NULL;
	list1_head = insert_at_head(list1_head, 1);
	list1_head = insert_at_head(list1_head, 2);
	list1_head = insert_at_head(list1_head, 2);
	list1_head = insert_at_head(list1_head, 4);
	list1_head = insert_at_tail(list1_head, 8);
	list1_head = insert_at_tail(list1_head, 12);
	list1_head = insert_at_tail(list1_head, 12);
	list1_head = insert_at_tail(list1_head, 12);
	list1_head = insert_at_tail(list1_head, 12);
	list1_head = insert_at_tail(list1_head, 12);

	print_list(list1_head);
	bool deleted;
	list1_head = delete_first_match(list1_head, 9, &deleted);

	if (deleted)
	{
		printf("List after deleting first item:\n");
		print_list(list1_head);
	}
	else
		printf("Item not found\n");

	int num_deleted;

	list1_head = delete_all_matches(list1_head, 12, &num_deleted);
	if (num_deleted)
		printf("Deleted %d instances of 12. Updated list:\n", num_deleted);
	else
		printf("No instances of 12 found in list\n");
	print_list(list1_head);
}
