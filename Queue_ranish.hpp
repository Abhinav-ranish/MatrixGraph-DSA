#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* rear;
    int size_;

public:
    Queue() : head(nullptr), rear(nullptr), size_(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size_++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size_--;
    }

    T getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return T();
        }
        return head->data;
    }

    int size() {
        return size_;
    }

    void empty() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }
};
