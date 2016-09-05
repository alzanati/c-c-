/**
 *@author: Mohamed Hosny Ahmed
 *@date: 5 / 9 / 2016
 *@purpose: implement stack data structure
 */

#include <iostream>

template< class T >
inline void println(T data) {
    std::cout << data << std::endl;
}

class stackUnderFlowException {

public:
    stackUnderFlowException() {
        std::cout << "stack underflow " << std::endl;
    }
};

template< class T>
struct Node {
    T data;
    Node* next;
};

template< class T>
class Stack {

public:
    Stack() : count(0), top(NULL) {}

    void push (T element) {
        node temp = new Node<T>();
        temp->next = top;
        temp->data = element;
        top = temp;
        count++;
    }

    T pop () {
        if (top == NULL) {
            throw new stackUnderFlowException();
        }
        T ret = top->data;
        node temp = top->next;
        delete top;
        top = temp;
        count--;
        return ret;
    }

    T Top() {
        if (top == NULL) {
            throw new stackUnderFlowException();
        }
        else
            return top->data;
    }

    bool isEmpty() {
        return (top == NULL) ? true : false;
    }

    void Size() {
        std::cout << "number of nodes : " << count << std::endl;
    }

    void printAllItems() {
        node temp = top;
        while (true) {
            println(temp->data);
            temp = temp->next;
            if (temp->next == NULL) {
                println(temp->data);
                break;
            }
        }
    }

    int searchFirstOccurance(T item) {
        node temp = top;
        int position = -1;
        int index = 0;
        while (true) {
            index++;
            if (temp->data == item) {
                position = index;
                break;
            }
            if (temp->next == NULL) {
                if (temp->data == item) {
                    position = index;
                }
                break;
            }
            temp = temp->next;
        }
        return position;
    }

    ~Stack() {}

protected:
    typedef Node<T> *node; // pointer to node

private:
    int count;
    node top; // top node
};

int main(int argc, char** argv) {
    std::cout << "Hello World!!!" << std::endl;

    Stack<const char*> myStack;
    myStack.push("10");
    myStack.push("20");
    myStack.push("50");
    myStack.push("60");
    myStack.Size();
    myStack.printAllItems();
    println(myStack.searchFirstOccurance("320"));
}