#include "DDL1.h"

typedef struct Node{
    DLL data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;


void InitStack(Stack *stack){
    stack->top = NULL;
}

int IsEmpty(Stack *stack){
    return stack->top == NULL;
}

void Push(Stack *stack, DLL head){
    Node *now= (Node*)malloc(sizeof(Node));
    now->data = head; 
    now->next = stack->top;
    stack->top = now;
}

DLL Pop(Stack *stack){
    Node *now;
    DLL re;
    if(IsEmpty(stack)) return NULL;
    now = stack->top;
    re = now->data;

    stack->top = now->next;
    return re;
}

DLL Top(Stack *stack){
    return stack->top->data;
}

void stack_reset(Stack *stack){
    Node *now = stack->top;
    while(now != NULL){
        Node *next = now->next;
        free(now);
        now = next;
    }
}