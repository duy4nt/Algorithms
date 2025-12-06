#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    cout << value << " enqueued to queue" << endl;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is empty" << endl;
        return -1;
    }

    int value = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1;
    }

    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int size() {
    if (isEmpty()) {
        return 0;
    }
    return (rear - front + 1);
}

int main() {
    cout << "=== Queue Operations ===" << endl;

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();
    cout << "Queue size: " << size() << endl;

    cout << "\nFront element: " << peek() << endl;

    cout << "\nDequeuing elements:" << endl;
    cout << dequeue() << " dequeued" << endl;
    cout << dequeue() << " dequeued" << endl;

    display();
    cout << "Queue size: " << size() << endl;

    enqueue(50);
    enqueue(60);

    display();

    cout << "\nIs queue empty? " << (isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (isFull() ? "Yes" : "No") << endl;

    return 0;
}
