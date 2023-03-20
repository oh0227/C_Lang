#include "Infinite_cal.h"
#include "Dll.h"
#include "Plus.h"

struct node{
    DLL* data;
    struct node* next;
};

typedef struct node* Stack;

Stack new_node(DLL* list)
{
    Stack temp_node = (Stack)malloc(sizeof(struct node));
    temp_node->data = list;
    temp_node->next = NULL;
    return temp_node;
}

int empty(Stack head)
{
    if(!head){
        printf("stack is empty\n");
        return 1;
    }
    return 0;
}

void push(Stack* head, DLL* data)
{
    Stack temp_node = new_node(data);
    temp_node->next = *head;
    *head = temp_node;
}

DLL* pop(Stack* head)
{
    if(empty(*head)){
        return NULL;
    }
    Stack temp = *head;
    *head = (*head)->next;
    DLL* element = temp->data;
    free(temp);

    return element;
}

DLL* top(Stack head)
{
    if(empty(head))
        return NULL;
    return head->data;
}



void postfix(char *p)
{
	DLL *list = newDLL();
    Stack num = NULL;
    Stack oper = NULL;
	int i;
	int length = strlen(p);
	for(i = 0; i < length; i++){
		if(plus(p[i])){
            push(&num, list);
            while(list->size--)
                deleteAt(list, list->size-1);
            append(list, newnode(p[i]));
            push(&oper, list);
            while(list->size--)
                deleteAt(list, list->size-1);
		}
        else
            append(list, newnode(p[i]));
	}
    DLL a = num->data;
    pop(&num);
    DLL b = num->data;
    DLL c = oper->data;
    return;
}





