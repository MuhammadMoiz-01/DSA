//
// Created by Muhammad Moiz on 04/07/2023.
//

#ifndef LISTSTACK_QUEUE_H
#define LISTSTACK_QUEUE_H

#include "Node.cpp"

namespace Queue{
    template<typename E>
    class queue{
    private:
        LinkedList<E>* queueList;
        int capacity;
        int t;
    public:
        queue(int cap);
        ~queue();
        int size() const;
        bool empty() const;
        void enqueue(const E &e);
        void dequeue();
        const E &front();
        void printQueue() const;
    };
}

#endif //LISTSTACK_QUEUE_H
