#include <stdio.h>
#include <stdlib.h>

struct Node;
struct Node* create_node(int data);
void insert_at_beginig(struct Node** headref, int data);
void insert_at_end(struct Node** head_ref, int data);
void delete_from_beginning(struct Node** head_ref);
void delete_from_end(struct Node** head_ref);
void delete_from_position(struct Node** head_ref, int position);
void treverse(struct Node* head);

main() {
    struct Node* head = NULL;

    return 0;
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("memory allocation eoor\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginig(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_at_end(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_from_beginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void delete_from_end(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("list is empty\n");
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_from_position(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("list is empty\n");
        return;
    }
    struct Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("position does not exist\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next->next;
}

void treverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
