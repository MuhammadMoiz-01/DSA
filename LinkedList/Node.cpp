#include "Node.hpp"
#include <iostream>
#define Node ll::Node

class LinkedList{
public:
    LinkedList() {
        head = nullptr;
    }
    LinkedList(int64_t val, Node* next){
        head = new Node;
        head->val = val;
        head->next = next;
    }

    // Function to return size of LL
    size_t getCapacity(){
        size_t s1 = 0;
        if(head == nullptr) {
            return s1;
        }
        Node *temp = head;
        while(temp) {
            temp = temp->next;
            s1++;
        }
        return s1;
    }

    // Function to return val at the specific index
    Node* find(uint64_t v){
        Node *temp = head;
        if(head == nullptr)  return nullptr;
        while(temp->next) {
            if(temp->val == v) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    // Function to add Node at the head of list
    void addHead(Node* newNode){
        if (getCapacity() == 0) {
            head = newNode;
            return;
        }

        // temp -> new node
        Node* temp = newNode;
        temp->next = head;
        head = temp;
        return;

    }

    // Function to print linked list
    void print(){
        Node* temp = head;
        while(temp!= nullptr){
            std::cout << temp->val << " ,";
            temp = temp->next;
        }
    }

    // Function to add Node at the end of list
    void addTail(Node* newNode){
        Node *temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to delete at the head of list
    Node* deleteHead(){
        if (head == nullptr) return nullptr;

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;

        return temp;
    }

    // Function to delete at the tail of list
    Node* deleteTail(){
        Node *temp = head;
        while(temp->next->next) {
            temp = temp->next;
        }
        Node *temp2;
        temp2 = temp->next;
        temp->next = nullptr;
        return temp2;
    }

    // Function to add anywhere in the list
    void addNode(Node* newNode, uint64_t idx){
        Node *temp = head;
        Node *prev = nullptr;
        int count = 0;
        // If list is empty and idx is 0
        if(temp == nullptr && idx == 0)
        {
            temp = newNode;
            return;
        }
        // If list is not empty but idx is 0, using add head method
        if (idx ==0)
        {
            addHead(newNode);
            return;
        }
        // Counting total indices
        while(temp && count<idx)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if(count<idx)
        {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        prev->next = newNode;
        newNode->next = temp;
    }

    // Function to delete anywhere in the list
    Node* deleteNode(uint64_t idx){
        Node *temp = head;
        int count = 0;
        Node* prev = nullptr;
        if(temp == nullptr){
            std::cout<<"No node to delete!"<<std::endl;
            return nullptr;
        }
        if(idx == 0)
        {
            Node *temp = deleteHead();
            return temp;
        }
        while(temp && count<idx)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if(count < idx)
        {
            std::cout<<"\nIndex out of bound! No node to delete."<<std::endl;
            return nullptr;
        }
        prev->next = temp->next;
        return temp;
    }

private:
    Node* head;
};

