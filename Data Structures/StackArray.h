#ifndef __STACK_ARRAY_H
#define __STACK_ARRAY_H

#include <exception>

const int __MAX_STACK_ARRAY_SIZE = 10000;

class StackArrayOverflowException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "StackArray overflow!";
  }
} StackArrayOverflow;

class StackArrayUnderflowException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "StackArray underflow!";
  }
} StackArrayUnderflow;


template <typename T>
class StackArray {
 private:
  T store[__MAX_STACK_ARRAY_SIZE];
  int size = 0;
 public:
  StackArray()
  {
   size = 0;
  }
  ~StackArray() {}

 StackArray &push(T value)
 {
  if ( size  == __MAX_STACK_ARRAY_SIZE )
    throw StackArrayOverflow;
  else {
   size++;
   store[size] = value;
  }
  return *this;
 }

 StackArray &pop()
 {
  if ( size  < 1 )
   throw StackArrayUnderflow;
  else
   size--;
  return *this;
 }

 T &top()
 {
  return store[size];
 }

 bool empty()
 {
  return size == 0;
 }
};

#endif // __STACK_ARRAY_H
