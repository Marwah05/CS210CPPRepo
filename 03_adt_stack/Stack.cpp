// TASK 03 -- The Stack ADT's implementation
//
// This is where "how" lives. We chose std::vector as the backing
// storage: push_back is our push, back() is our top, pop_back() is our
// pop. A student could rewrite this whole file to use a raw fixed-size
// array instead, and as long as push/pop/top/isEmpty/size still behave
// the same way, nothing calling this class would ever notice.

#include "Stack.h"
#include <iostream>

Stack::Stack() {
    topIndex = -1; // Initialize the topIndex as -1 because it starts off empty
}

void Stack::push(int value) {
    if (isFull()) { // Check if the list is full
        std::cout << "Stack is full, cannot push." << std::endl;
        return;
    }
    topIndex++; // Increments the top index
    data[topIndex] = value; // Assigns the value
}

int Stack::pop() {
    if (isEmpty()) { // Check if the list is empty
        std::cout << "Stack is empty, cannot pop." << std::endl;
        return -1;
    }
    int value = data[topIndex]; // Return the top index
    topIndex--; // Decrement the topIndex
    return value; // Return to the top element and decrement
}

// int Stack::top() const {
    // TODO: return the top element of data_
    // undefined if empty -- callers should check isEmpty() first. We'll
    // harden this kind of thing later in the course.
// }

int Stack::peek() const {
    if (isEmpty()) {
        std::cout << "Stack is empty, cannot peek." << std::endl;
        return -1;
    }
    return data[topIndex];
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

bool Stack::isFull() const {
    return topIndex == 99;
}
int Stack::size() const {
    return topIndex + 1;
}
