//
// Created by Muhammad Moiz on 02/07/2023.
//
#include "stack.h"

template<typename E> mystack::arrayStack<E>::arrayStack(int cap): arr(new E[cap]), capacity(cap), t(-1){} //constructor

template<typename E>
uint64_t mystack::arrayStack<E>::size() const
{
    return t+1;
}

template<typename E> bool mystack::arrayStack<E>::empty() const
{
    return (t>0);
}

template<typename E>
void mystack::arrayStack<E>::push(const E &e) {
    assert(size() < capacity && "Stack is full!");
    t = t+1;
    arr[t] = e;
}

template<typename E>
void mystack::arrayStack<E>::pop() {
    assert(empty() != 0 && "No entry in the stack!");
    t = t-1;
}

template<typename E>
const E &mystack::arrayStack<E>::top() const
{
    return arr[t];
}