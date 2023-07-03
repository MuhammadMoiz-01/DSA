//
// Created by Muhammad Moiz on 02/07/2023.
//

#include "Node.cpp"
#include <cstdint>
#include <cassert>

namespace stack_ll{
    template<typename E>
    class listStack {
    private:
        LinkedList<E>* l_stack;
        uint64_t capacity;
        int64_t t;
        enum {DEF_CAPACITY = 500};
//        int a[10]; // stack defined arrayStack
    public:
        listStack(int cap=DEF_CAPACITY);
        ~listStack();
        uint64_t size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        void pop();
        void printStack();
    };

}
