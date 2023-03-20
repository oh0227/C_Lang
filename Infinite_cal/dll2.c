#include "Infinite_cal.h"

typedef struct Node{
	char val;
	struct Node *prev;
	struct Node *next;
} Node;

typedef Node* DLL;

Node *newnode(char s) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = s;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

DLL *newDLL()
{
	DLL *temp = (DLL *)malloc(sizeof(DLL));
	temp->link = NULL;
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
	Node *temp = list->link;
	if (size == 0) {
		list->link = newnode;
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
	Node *temp = list->link;
	if (index < 0 || index > size) {
		printf("INSERT ERROR: Out of Bound.\n");
		return;
	}
	if (size == 0 && index == 0) {
		list->link = newnode;
	}
	else if (size > 0 && index == 0){
		newnode->next = list->link;
		newnode->next->prev = newnode;
		list->link = newnode;
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
	Node *temp = list->link;
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
		list->link = NULL;
		free(temp);
	}
	else if (size > 1 && index == 0) {
		list->link = temp->next;
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
	Node *temp = list->link;
	if (size == 0) {
		printf("Empty List.\n");
	}
	else {
		while (temp->next != NULL) {
			printf("%c", temp->val);
			temp = temp->next;
		}
		printf("%c", temp->val);
	}

	return;
}

void print_reverse(DLL *list)
{
	int size = list->size;
	Node *temp = list->link;
	if (size == 0) {
		printf("Empty List.\n");
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp->prev != NULL) {
			printf("%c", temp->val);
			temp = temp->prev;
		}
		printf("%c", temp->val);
	}

	return;
}

void postfix(DLL* list){
    DLL* new = newDLL();
    if(list->val == '+' || list->val == '-'){
        
    }
}

DLL* DLLOF()
{
	DLL* list = newDLL();
	char *p = "0.0011587485515643105446118192352259559675550405561993047508690614136732329084588644264194669756662804171494785631517960602549246813441483198146002317497103128621089223638470451911935110081112398609501738122827346465816917728852838933951332560834298957126303592120509849362688296639629200463499420625724217844727694090382387022016222479721900347624565469293163383545770567786790266512166859791425260718424101969872537659327925840092699884125144843568945538818076477404403244495944380069524913093858632676709154113557358053302433371958285052143684820393974507531865585168018539976825028968713789107763615295480880648899188876013904982618771726535341830822711471610660486674391657010428736964078794901506373117033603707995365005793742757821552723059096176129779837775202780996523754345307068366164542294322132097334878331402085747392815758980301274623406720741599073";
	int length = strlen(p);
	for (int i = 0; i < length; i++) {
		append(list, newnode(p[i]));
	}
	// print(list);

	return list;
}
