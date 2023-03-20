#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    char data;               /* 4BYTE */
    struct node* next;      /* 8BYTE */
};

struct node* new_node(char data)
{
    struct node* temp_node = (struct node*)malloc(sizeof(struct node));
    // struct node real_node = *temp_node;
    temp_node->data = data;

    temp_node->next = NULL;

    printf("temp_node = %p\ndata = \t%c\n", temp_node, &(temp_node->data));

    return temp_node;
}

// int empty(struct node* head)
// {
//     if(!head){
//         printf("stack is empty\n");
//         return 1;
//     }
//     return 0;
// }

// void push(struct node** head, int data)
// {
//     struct node* temp_node = new_node(data);
//     temp_node->next = *head;
//     *head = temp_node;
//     printf("PUSH: [%d]\n", data);
// }

int main(void)
{
    printf("%ld\n", sizeof(struct node));
    new_node('a');
    return 0;
}
