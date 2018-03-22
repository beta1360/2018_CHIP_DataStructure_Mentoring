#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

typedef struct Node	Node;

Node *create_node(int data) {
	Node *new_node;
	new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void insert_node(Node **header, Node *front_node, Node *new_node) {
	if (header == NULL) {
		new_node->next = NULL;
		*header = new_node;
	}
	else if (front_node == NULL) {
		new_node->next = *header;
		*header = new_node;
	}
	else {
		new_node->next = front_node->next;
		front_node->next = new_node;
	}
}

void delete_node(Node **header, Node *front_node, Node *removed_node) {
	if (front_node == NULL)
		*header = (*header)->next;
	else
		front_node->next = removed_node->next;
	free(removed_node);
}

void print_list(Node *header, char listname[]) {
	Node *print_node = header;
	
	printf("%s", listname);
	while (print_node != NULL) {
		printf("->%d", print_node->data);
		print_node = print_node->next;
	}
	printf("\n");
}

Node *search_node(Node *header, int data) {
	Node *search_node = header;

	while (search_node != NULL) {
		if (search_node->data == data)
			return search_node;
		search_node = search_node->next;
	}
	return search_node;
}

int main(void) {

	// practice 1-1. create list

	Node *list = NULL;
	char listname[20] = "header";
	insert_node(&list, NULL, create_node(0));

	for (int i = 1; i < 16; i++) {
		Node *front_node = search_node(list, i - 1);
		insert_node(&list, front_node, create_node(i));
	}
	print_list(list,listname);

	// practice 1-2. remove even number

	for (int even = 0; even < 16; even += 2) {
		Node *removed_node = search_node(list, even);
		Node *front_node = search_node(list, even - 1);
		delete_node(&list, front_node, removed_node);
	}

	// practice 1-3. print this list.

	print_list(list, listname);

	return 0;
}
