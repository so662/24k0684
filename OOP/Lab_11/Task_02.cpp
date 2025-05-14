
#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template<typename T>
class Queue {
    T* arr;
    int front, rear, size, capacity;
public:
    Queue(int cap) : front(0), rear(-1), size(0), capacity(cap) {
        arr = new T[capacity];
    }
    ~Queue() { delete[] arr; }
    void enqueue(T val) {
        if (size == capacity)
            throw QueueOverflowException();
        rear++;
        if (rear == capacity) 
            rear = 0;
        arr[rear] = val;
        size++;
    }
    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();
        T val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }
};

int main() {
    Queue<int> q(2);
    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3); 
    } catch (QueueOverflowException& ex) {
        cout << "Caught QueueOverflowException - what(): " << ex.what() << endl;
    }
    try {
        cout << "\nAttempting to dequeue from an empty queue..." << endl;
        q.dequeue();
        q.dequeue();
        q.dequeue();
    } catch (QueueUnderflowException& ex) {
        cout << "Caught QueueUnderflowException - what(): " << ex.what() << endl;
    }
    return 0;
}