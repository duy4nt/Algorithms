#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack_node {
    int data;
    struct stack_node* next;
};

struct stack_node* new_node(int data) {
    struct stack_node* stack_Node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (!stack_Node) {
        printf("heap overflow\n");
        return NULL;
    }
    stack_Node->data = data;
    stack_Node->next = NULL;
    
    return stack_Node;
}

int is_empty(struct stack_node* top) {
    return !top;
}

void push(struct stack_node** top_ref, int data) {
    struct stack_node* stack_Node = new_node(data);
    if (!stack_Node) return;

    stack_Node->next = *top_ref;
    *top_ref = stack_Node;
}

int pop(struct stack_Node** top_ref) {
    if (is_empty(*top_ref)) {
        printf("not enough space\n");
        return INT_MIN;
    }

    struct stack_node* temp = *top_ref;
    int popped = temp->data;
    *top_ref = (*top_ref)->next;
    free(temp);

    return popped;
}

int peek(struct stack_node* top) {
    if (is_empty(top)) {
        printf("stack is empty\n");
        return INT_MIN;
    }

    return top->data;
}

main() {
    struct stack_node* top = NULL;

}
