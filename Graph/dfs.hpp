#pragma once

#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

typedef std::string string;

// Integer class derived from object base class
template<typename T>
class Integer : public Object<T> {
private:
    T value;

public:
    explicit Integer(T v = 0) : value(v) {};

    T getValue() const { T temp = intValue(); return temp; }

    T intValue() const override {
        const auto *p = dynamic_cast<const Integer *>(this);
        if (p == nullptr) {
            try {
                throw std::bad_cast();
            } catch (const std::bad_cast &e) {
                std::cerr << "Illegal attempt to Integer casting" << std::endl;
            }
        }
        return p->value;
    }
};

template<typename T>
class Decorator {
private:                             // member data
    std::map<string, Object<T> *> map; // the map
public:
    Object<T> *get(const string &a) // get value of attribute
    {
        return map[a];
    }

    void set(const string &a, Object<T> *d) // set value
    {
        map[a] = d;
    }
};

namespace graph {

    template<typename T>
    class Graph {
    private:
        size_t numNodes_;
//        std::map<Decorator<T>, std::vector<Decorator<T>>> adj_list;
        std::vector<std::vector<Decorator<T>>> adj_list;

    public:
        explicit Graph() : numNodes_(0) {}

        void make_graph(const string &filename);

        void print_graph() const;
    };

}; // namespace graph
