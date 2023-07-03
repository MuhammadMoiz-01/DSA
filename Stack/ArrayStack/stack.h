//
// Created by Muhammad Moiz on 02/07/2023.
//
#include <cstdint>
#include <cassert>
#pragma  once
#ifndef CPPPROJECTS_STACK_H
#define CPPPROJECTS_STACK_H

namespace mystack {

    template<typename E>
    class arrayStack {
    private:
        E* arr;
        uint64_t capacity;
        int64_t t;
        enum {DEF_CAPACITY = 500};
//        int a[10]; // stack defined arrayStack
    public:
        arrayStack(int cap=DEF_CAPACITY);
        uint64_t size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        void pop();

    };

} // mystack
#include "stack.cpp"

#endif //CPPPROJECTS_STACK_H
