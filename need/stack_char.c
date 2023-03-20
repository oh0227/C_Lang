#include "Infinite_cal.h"
#include "DLL1.h"


struct node{
    char data;
    struct node* next;
};

struct node* new_node(char list)
{
    struct node* temp_node = (struct node*)malloc(sizeof(struct node));
    temp_node->data = list;
    temp_node->next = NULL;
    return temp_node;
}

int empty(struct node* head)
{
    if(!head){
        printf("stack is empty\n");
        return 1;
    }
    return 0;
}

void push(struct node** head, char data)
{
    struct node* temp_node = new_node(data);
    temp_node->next = *head;
    *head = temp_node;
    size++;
    printf("PUSH: [%c]\n", data);
}

char pop(struct node** head)
{
    // if(empty(*head)){
    //     return NULL;
    // }
    struct node* temp = *head;
    *head = (*head)->next;
    char element = temp->data;
    free(temp);
    size--;

    printf("POP: [%c]\n", element);
    // printf("%d", size);
    return element;
}

char top(struct node* head)
{
    // if(empty(head))
    //     return 'a';
    return head->data;
}

void display(struct node* head)
{
    if(empty(head)){
        return;
    }
    struct node* cursor = NULL;
    cursor = head;

    printf("STACK:");
    while(cursor != NULL){
        printf(" [%c]", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
    return;
}

void postfix(struct node* head, char s)
{ 
    if(s == '+' || s == '-'){
        push(&head,s);
    }
}

int main()
{
    struct node* head = NULL;
    DLL *ls = DLLOF();

    for(int i = 0 ; i < 30; i++){
        push(&head, ls->link->val);
    }
    push(&head, 'a');
    push(&head, 'b');
    push(&head, 'c');

    // postfix(head);

    display(head);
    // print(ls);

    // pop(&head);

    // display(head);

    // printf("TOP: [%c]\n", top(head));

    // display(head);

    pop(&head);
    pop(&head);
    pop(&head);

    return 0;
}