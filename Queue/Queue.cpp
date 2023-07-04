//
// Created by Muhammad Moiz on 04/07/2023.
//
#include "Queue.h"
#include <iostream>
#include <cassert>

template <typename E>
Queue::queue<E>::queue(int cap) {
    queueList = new LinkedList<E>();
    capacity = cap;
    t = -1;
}

template <typename E>
Queue::queue<E>::~queue() {
    delete queueList;
}

template <typename E>
int Queue::queue<E>::size() const{
    return t+1;
}

template <typename E>
bool Queue::queue<E>::empty() const {
    return (t>0);
}

template <typename E>
void Queue::queue<E>::enqueue(const E &e) {
    assert(size()<=capacity && "Stack Size Exceeded!");
    Node<E>* temp = new Node<E>{e, nullptr};
    queueList->addTail(temp);
    t++;
    temp = nullptr;
    delete temp;
}

template <typename E>
void Queue::queue<E>::dequeue() {
    Node<E>* var = queueList->deleteHead();
    std::cout << "Popping: " << var->val << std::endl;
    t--;
}

template <typename E>
const E &Queue::queue<E>::front() {
    assert(queueList->getCapacity() != 0 && "Queue is empty!");
    Node<E>*temp = queueList->find(0);
    std::cout << temp->val << std::endl;
}

template <typename E>
void Queue::queue<E>::printQueue() const {
    std::cout << "Queue contains: " << std::endl;
    queueList->printList();
}