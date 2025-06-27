#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted)
{
	*num_deleted = 0;
	
	if (head == NULL)
		return NULL;
	
	Node *current, *temp, *new_head;
	current = head;
	while (current->value == delete_value)
	{
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted += 1;

		if (current == NULL)
			return NULL;
	}

	new_head = current;

	while (current->next != NULL)
	{
		if (current->next->value == delete_value)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*num_deleted += 1;
		}
		else
			current = current->next;
	}

	return new_head;
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

Node *append_list(Node *head1, Node *head2)
{
	if (head1 == NULL)
		return head2;
	Node *current = head1;
	while(current->next != NULL)
		current = current->next;
	current->next = head2;

	return head1;
}

Node *reverse_list(Node *head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	
	Node *current = head;
	Node *next_node = head->next;

	current->next = NULL;

	while (next_node != NULL)
	{
		Node *temp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = temp;
	}

	return current;
}

void sort_list(Node *head)
{
	if (head == NULL)
	       return ;
	if (head->next == NULL)
		return ;

	bool swapped = false;

	do
	{
		Node *current = head;
		Node *prev = NULL;
		swapped = false;

		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
			if (current->value < prev->value)
			{
				int temp = prev->value;
				prev->value = current->value;
				current->value = temp;
				swapped = true;
			}

		}
	} while (swapped);	
}

int main()
{
	Node *list1 = NULL;

	list1 = insert_at_tail(list1, 5);
	list1 = insert_at_tail(list1, 9);
	list1 = insert_at_tail(list1, 1);
	list1 = insert_at_tail(list1, 8);
	list1 = insert_at_tail(list1, 0);
	list1 = insert_at_tail(list1, 4);
	list1 = insert_at_tail(list1, 7);
	list1 = insert_at_tail(list1, 3);
	list1 = insert_at_tail(list1, 6);
	list1 = insert_at_tail(list1, 2);

	printf("List1: \n");
	print_list(list1);


	sort_list(list1);
	
	printf("List1 after sorting:\n");
	print_list(list1);
}
