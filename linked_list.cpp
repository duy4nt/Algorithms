#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void insertAtFront(Node** headRef, int newData) {
    Node* newNode = createNode(newData);

    newNode->next = *headRef;

    *headRef = newNode;
    std::cout << "Inserted " << newData << " at front.\n";
}

void printList(Node* head) {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "List: ";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << "\n";
}

void deleteNode(Node** headRef, int key) {
    Node* current = *headRef;
    Node* prev = nullptr;

    if (current != nullptr && current->data == key) {
        *headRef = current->next; // Change head
        delete current;           // Free old head
        std::cout << "Deleted " << key << " (head).\n";
        return;
    }

    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Key " << key << " not found for deletion.\n";
        return;
    }

    prev->next = current->next;
    delete current;
    std::cout << "Deleted " << key << ".\n";
}

void cleanupList(Node** headRef) {
    Node* current = *headRef;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *headRef = nullptr;
    std::cout << "List memory cleaned up.\n";
}

int main() {
    Node* head = nullptr;

    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    deleteNode(&head, 30);
    printList(head);

    cleanupList(&head);
    printList(head);

    return 0;
}
