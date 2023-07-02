//
// Created by Muhammad Moiz on 02/07/2023.
//
#include "stack.h"
#include <iostream>
#define print(X) std::cout << X << std::endl

int main(){
    print("Int Stack");
    mystack::arrayStack<int> intStack(5);
    //print(intStack.empty());

    print("Size of Stack: ");
    for(int i =10; i<15; i++)
    {
        intStack.push(i);
        print(intStack.size());
    }

    intStack.pop();
    print("Updated top after 1st pop: ");
    print(intStack.top());

    intStack.pop();
    print("Updated top after 2nd pop: ");
    print(intStack.top());
}
