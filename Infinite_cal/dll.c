#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} DLL;

Node *newnode(int n) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = n;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

DLL *newDLL()
{
	DLL *temp = (DLL *)malloc(sizeof(DLL));
	temp->head = NULL;
	temp->size = 0;
	return temp;
}


/* TODO: implement following functions. */
void append(DLL *list, Node *newnode);
void insertAt(DLL *list, int index, Node *newnode);
void deleteAt(DLL *list, int index);
void print(DLL *list);
void print_reverse(DLL *list);

void append(DLL *list, Node *newnode)
{
	int size = list->size;
	Node *temp = list->head;
	if (size == 0) {
		list->head = newnode;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
	list->size++;

	return;
}

void insertAt(DLL *list, int index, Node *newnode)
{
	int size = list->size;
	int i;
	Node *temp = list->head;
	if (index < 0 || index > size) {
		printf("INSERT ERROR: Out of Bound.\n");
		return;
	}
	if (size == 0 && index == 0) {
		list->head = newnode;
	}
	else if (size > 0 && index == 0){
		newnode->next = list->head;
		newnode->next->prev = newnode;
		list->head = newnode;
	}
	else if (size > 0 && index < size) {
		for (i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->next->prev = newnode;
		newnode->prev = temp;
		temp->next = newnode;
	}
	else if (size > 0 && index == size) {
		for (i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
	}
	list->size++;
	
	return;
}

void deleteAt(DLL *list, int index)
{
	int size = list->size;
	int i;
	Node *temp = list->head;
	Node *temp2;
	if (size == 0) {
		printf("DELETE ERROR: This List is Empty.\n");
		return;
	}
	if (index < 0 || index >= size) {
		printf("DELETE ERROR: Out of Bound.\n");
		return;
	}
	if (size == 1 && index == 0){
		list->head = NULL;
		free(temp);
	}
	else if (size > 1 && index == 0) {
		list->head = temp->next;
		temp->next->prev = NULL;
		free(temp);
	}
	else if (size > 2 && index > 0 && index < size - 1) {
		for (i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
	else if (size > 1 && index == size - 1) {
		for (i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
	}
	list->size--;
	
	return;

}

void print(DLL *list)
{
	int size = list->size;
	Node *temp = list->head;
	if (size == 0) {
		printf("Empty List.\n");
	}
	else {
		while (temp->next != NULL) {
			printf("[%d] ", temp->val);
			temp = temp->next;
		}
		printf("[%d]\n", temp->val);
	}

	return;
}

void print_reverse(DLL *list)
{
	int size = list->size;
	Node *temp = list->head;
	if (size == 0) {
		printf("Empty List.\n");
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp->prev != NULL) {
			printf("[%d] ", temp->val);
			temp = temp->prev;
		}
		printf("[%d]\n", temp->val);
	}

	return;
}

int main()
{
	DLL *list = newDLL();
	int i;
	for (i = 1; i < 6; i++) {
		append(list, newnode(i));
	}
	print(list);
	append(list, newnode(8));
	print(list);

	return 0;
}