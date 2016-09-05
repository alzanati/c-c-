/**
 *@author: Mohamed Hosny Ahmed
 *@date: 5 / 9 / 2016
 *@purpose: implement queue data structure
 */

#include <iostream>

template< class T >
void println(T data) {
    std::cout << data << std::endl;
}

class QueueEmpty {
public:
    QueueEmpty () {
        println("queue is empty");
    }
};

template< class T >
struct Node {
    T data;
    Node* next;
};

template< class T >
class Queue {
public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    void enqueue(T element) {
        node temp = new Node<T>();
        temp->data = element;
        temp->next = nullptr;
        if (isEmpty()) {
            front = back = temp;
        }
        else {
            temp->next = back;
            back = temp;
        }
        count++;
    }

    T dequeue() {
        node temp = back;
        T ret;
        if (isEmpty()) {
            throw new QueueEmpty();
        }
        else {
            if (front == back) {
                return front->data;
            }
            while (true) {
                if (temp->next == front) {
                    ret = temp->next->data;
                    break;
                }
                else {
                    temp = temp->next;
                }
            }
            delete front;
            front = temp;
            count--;
            return ret;
        }
    }

    bool isEmpty() {
        return (count == 0) ? true : false;
    }

    int Size() {
        return count;
    }

    void printQueueSize() {
        println(count);
    }

    ~Queue() {}

protected:
    typedef struct Node<T> *node;

private:
    node front, back;
    int count;
};

int main (int argc, char** argv) {
    Queue<int> myQueue;
    myQueue.enqueue(2);
    myQueue.enqueue(45);
    myQueue.enqueue(47);
    myQueue.enqueue(870);
    myQueue.enqueue(234);
    myQueue.enqueue(2364);
    myQueue.enqueue(-1);
    println(myQueue.dequeue());
    println(myQueue.dequeue());
    println(myQueue.dequeue());
    println(myQueue.dequeue());
    println(myQueue.dequeue());
    println(myQueue.dequeue());
    println(myQueue.dequeue());
}
