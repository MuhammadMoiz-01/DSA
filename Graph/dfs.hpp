#pragma once

#include "utils.hpp"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <vector>

typedef std::string string;

// Integer class derived from object base class
class Integer : public Object {
private:
  int value;

public:
  explicit Integer(int v = 0) : value(v){};
  int getValue() const { return value; };
  int intValue() const override {
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

class Decorator {
private:                          // member data
  std::map<string, Object *> map; // the map
public:
  Object *get(const string &a) // get value of attribute
  {
    return map[a];
  }
  void set(const string &a, Object *d) // set value
  {
    map[a] = d;
  }
};

// namespace graph {
//
// class Vertex {
//
// private:
//   std::map<string, Object *> map;
//
// public:
//   Object *get(const string &a) { return map[a]; }
//
//   void set(const string &a, Object *d) { map[a] = d; }
// };
//
// }; // namespace graph
