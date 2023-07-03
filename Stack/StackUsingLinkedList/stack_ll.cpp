//
// Created by Muhammad Moiz on 02/07/2023.
//

#include "stack_ll.h"

template <typename E>stack_ll::listStack<E>::listStack(int cap)
{
    l_stack = new LinkedList<E>();
    capacity=cap;
    t = -1;
}

template <typename E>stack_ll::listStack<E>::~listStack() {
    delete l_stack;
}

template <typename E>
uint64_t stack_ll::listStack<E>::size() const
{
    return t+1;
}

template <typename E>
bool stack_ll::listStack<E>::empty() const
{
    return t>0;
}

template <typename E>
void stack_ll::listStack<E>::push(const E &e)
{
    auto temp = new Node<E>{e, nullptr};
    l_stack->addHead(temp);
    t += 1;
    temp = nullptr;
    delete temp;
    return;
}

template <typename E>
void stack_ll::listStack<E>::pop()
{
    Node<E>* var = l_stack->deleteHead();
    std::cout << "Popping : " << var->val << std::endl;
    t--;
}

template<typename E>
const E &stack_ll::listStack<E>::top() const
{
    assert(l_stack->getCapacity() != 0 && "Stack is empty");
    Node<E>* temp = l_stack->find(0);
    return temp->val;
}

template<typename E>
void stack_ll::listStack<E>::printStack() {
    std::cout << "Stack contains (head of stack is at leftmost position)" << std::endl;
    l_stack->printList();
    return;

}