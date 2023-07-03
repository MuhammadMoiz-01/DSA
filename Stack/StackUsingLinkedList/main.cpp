//
// Created by Muhammad Moiz on 01/07/2023.
//
//#include "../../LinkedList/Node.hpp"
#include "stack_ll.cpp"
//#include "../ArrayStack/stack.cpp"

using namespace std;
#define print(x) std::cout<<x<<std::endl
#define stack stack_ll::listStack

int main()
{
//    ------------------------------------------------------------------------------
//    LinkedList *l1 = new LinkedList();
//    // add elements at the head of the list
//    Node n{1, nullptr};
//    Node n1{2,&n};
//    Node n2{3, &n1};
//    Node n3{4, nullptr};
//    Node n4{5, nullptr};
//
//    std::cout << "Making linked list " << std::endl;
//    std::cout << "List Size :: " << l1->getCapacity() << std::endl;
//    l1->addHead(&n);
//    l1->addHead(&n1);
//    l1->addHead(&n2);
//    l1->addTail(&n3);
//    l1->print();
//
////    Node *del_head = l1->deleteHead();
////    std::cout <<"Deleted head: " ;
////    Print(del_head->val);
//
////    Node *del_tail = l1->deleteTail();
////    std::cout << "Deleted tail: ";
////    Print(del_tail->val);
//
////    Node *findNode1 = l1->find(2);
////    std::cout << "Found val is ";
////    Print(findNode1->val);
//
////    l1->addNode(&n4, 0);
//
//    Node *del_node = l1->deleteNode(2);
//    cout<<"\nDeleted node: "<< del_node->val;
//
//    cout<<"\nUpdated linked list: ";
//    l1->printList();
//
////    ----------------------------------------------------------------------------------
//    print("Int Stack");
//    mystack::arrayStack<int> intStack(5);
//    //print(intStack.empty());
//
//    print("Size of Stack: ");
//    for(int i =10; i<15; i++)
//    {
//        intStack.push(i);
//        print(intStack.size());
//    }
//
//    intStack.pop();
//    print("Updated top after 1st pop: ");
//    print(intStack.top());
//
//    intStack.pop();
//    print("Updated top after 2nd pop: ");
//    print(intStack.top());
//    -----------------------------------------------------------------------------------

//    auto stack = stack_ll::listStack<int>(10); // stack memory
    // heap memory
    auto stack_obj = new stack<int>(10);
//    std::cout << stack_obj->size() << std::endl;
//    stack_obj->push(1);

    for (int i = 1; i <=5; i++)
    {
        stack_obj->push(i);
        print("Adding :: "<< i << " || Size of stack :: " << stack_obj->size());
    }

    std::cout << "After popping (size) : ";
    stack_obj->pop();
    std::cout <<stack_obj->size() <<std::endl;

    print("----------------------------------");
    stack_obj->printStack();
    print("----------------------------------");

    std::cout << "Top Value of Stack:";
    std::cout << stack_obj->top()<<std::endl;

    print("Current size " << stack_obj->size());

    size_t stack_size = stack_obj->size();
    for(auto i=0; i<stack_size; i++){
        stack_obj->pop();
    }
    stack_obj->top();
    // delete stack object
    delete stack_obj;
    return EXIT_SUCCESS;
}
