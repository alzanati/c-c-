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
    
};

class Queue {
public:
    Queue();
    
    ~Queue();
    
};

int main (int argc, char** argv) {
    println("Hello world!!!");
}