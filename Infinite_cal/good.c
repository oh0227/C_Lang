#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



struct node {
    char data;
    struct node* next;
};

struct node* new_node(char arg)
{
    struct node* temp_node = (struct node*)malloc(sizeof(struct node));
    temp_node->data = arg;
    temp_node->next = NULL;
    return temp_node;
}

int empty(struct node* head)
{
    if (!head) {
        return 1;
    }
    return 0; 
}

void push(struct node* head, char data)
{
    struct node* temp_node = new_node(data);
    head->next = temp_node;
}

char pop(struct node* head)
{
    if (empty(head)) {

        return 'a';
    }
    struct node* temp = head;
    head = head->next;
    char element = temp->data;
    free(temp);

    return element;
}

char top(struct node* head)
{
    if (empty(head))
        return 'a';
    return head->data;
}
int prec(char a)
{
    switch (a) {
    case '+': case '-':
        return 1;
    case ' ':
        return 2;
    case '(':
    case ')':
        return 0;
    }
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
}

void postfix(struct node* head, int len)
{ 
    char ch, top_op;
    for (int i = 0; i < len; i++) {
        ch = head->data;
        switch (ch) {
        case '+': case '-': case ' ':
            // while (!empty(head) && prec(ch) < prec(top(head))){
            //     push(head, ch);
            // }
            // push(head, ch);
            break;

        // case '(':
        //     push(head, ch);
        //     break;

        // case ')':
        //     pop(head);
        //     while (top_op != '(') {
        //         pop(head);
        //         j++;
        //     }
        //     break;

        default :
            push(head, ch);
        }
    }
}

int main()
{
    FILE* ifp,* ofp;
    ifp = fopen("ifp", "r");
    ofp = fopen("ofp", "w");



    char c[50];
    int i = 0;
    while (fscanf(ifp, "%d", &i) == 1){
        c[i] = getc(ifp);
        fprintf(ifp,"%c", &i);
        printf("%c", c[i]);
        i++;
    }
    // int i ;
    // struct node* head = NULL;

    // for(int i = 0; i < strlen(c); i++) {
    //     c[i] = getc(ifp);
    //     printf("%c", c[0]);
    //     // push(head, c[i]);
    // }

    // postfix(head,i);
    // display(*head);
    fclose(ifp);
    fclose(ofp);

    return 0;
}