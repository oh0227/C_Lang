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


int main()
{
	DLL *list = newDLL();
	int i;
	for (i = 1; i < 6; i++) {
		append(list, newnode(i));
	}
	print(list);

	deleteAt(list, -1);
	deleteAt(list, 5);
	deleteAt(list, 0);
	print(list);
	deleteAt(list, 2);
	print(list);
	deleteAt(list, 2);
	print(list);

	insertAt(list, -1, newnode(6));
	insertAt(list, 3, newnode(6));
	insertAt(list, 0, newnode(7));
	print(list);
	insertAt(list, 1, newnode(8));
	print(list);
	insertAt(list, 4, newnode(9));
	print(list);
	print_reverse(list);

	return 0;
}