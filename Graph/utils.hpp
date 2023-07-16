#pragma once

// Object Class
template <typename T> class Object {
public:
  virtual T intValue() const = 0;
  virtual void setValue(T newval) =0;
};
