//
// Created by Muhammad Moiz on 01/07/2023.
//
#include "Node.cpp"
using namespace std;
#define Print(x) std::cout<<x<<std::endl

int main()
{
    LinkedList *l1 = new LinkedList();
    // add elements at the head of the list
    Node n{1, nullptr};
    Node n1{2,&n};
    Node n2{3, &n1};
    Node n3{4, nullptr};
    Node n4{5, nullptr};

    std::cout << "Making linked list " << std::endl;
    std::cout << "List Size :: " << l1->getCapacity() << std::endl;
    l1->addHead(&n);
    l1->addHead(&n1);
    l1->addHead(&n2);
    l1->addTail(&n3);
    l1->print();

//    Node *del_head = l1->deleteHead();
//    std::cout <<"Deleted head: " ;
//    Print(del_head->val);

//    Node *del_tail = l1->deleteTail();
//    std::cout << "Deleted tail: ";
//    Print(del_tail->val);

//    Node *findNode1 = l1->find(2);
//    std::cout << "Found val is ";
//    Print(findNode1->val);

//    l1->addNode(&n4, 0);

    Node *del_node = l1->deleteNode(2);
    cout<<"\nDeleted node: "<< del_node->val;

    cout<<"\nUpdated linked list: ";
    l1->print();
}