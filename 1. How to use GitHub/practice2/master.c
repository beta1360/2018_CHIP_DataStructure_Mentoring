// Available after Mar 16, 2018

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	Node *next;
} Node;

Node *create_node(element data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	
	return new_node;
}

void insert_node(Node **header, Node *current, Node *new_node)
{
	// #1. Empty List case
	if (*header == NULL) {
		new_node->next = NULL;
		*header = new_node;
	}

	// #2. Insert to first node ( connect beside header and current. )
	else if (current == NULL) { 
		new_node->next = *header;
		*header = new_node;
	}

	// #3. Other case ( connect beside current and other node(next node).)
	else {
		new_node->next = current->next;
		current->next = new_node;
	}
}

