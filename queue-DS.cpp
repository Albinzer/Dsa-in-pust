# QUESTION NUMBER 6: write a program to implement a queue data structure along with its typical operations .
#include <iostream>
using namespace std;

// Queue class definition
class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor to initialize the queue
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << value << endl;
        } else {
            if (front == -1) {
                front = 0;  // First element added
            }
            rear++;
            arr[rear] = value;
            cout << value << " enqueued to the queue." << endl;
        }
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue." << endl;
        } else {
            cout << arr[front] << " dequeued from the queue." << endl;
            front++;
            if (front > rear) {
                front = rear = -1;  // Reset queue after all elements are dequeued
            }
        }
    }

    // Function to get the front element of the queue (peek)
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);  // Create a queue of the given size

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display the queue
    q.display();

    // Peek the front element
    q.peek();

    // Dequeue an element
    q.dequeue();

    // Display the queue again
    q.display();

    // Dequeue all elements
    q.dequeue();
    q.dequeue();

    // Try to dequeue from empty queue
    q.dequeue();

    return 0;
}
