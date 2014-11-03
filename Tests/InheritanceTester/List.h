#ifndef ___MY_LIST_H_
#define ___MY_LIST_H_

namespace Algorithms
{

  template <typename T>
  class ListElement
  {    
  public:   
    virtual T getValue() = 0;
    virtual ListElement<T> *getNext() = 0;
    virtual void setNext(ListElement<T>* new_next) = 0;
    ~ListElement() {}
  };

  template <typename T>
  struct DoubleListElement : public ListElement<T>
  {   
    virtual ListElement<T> *getPrevious() = 0;
  };


  template <typename T>
  class List
  {
  public:
    virtual List<T>& insertFront(T new_value) = 0;
    virtual List<T>& insertBack(T new_value) = 0;
    virtual List<T>& insertAfter(T old_value, T new_value) = 0;
    virtual List<T>& removeElement(T value_to_delete) = 0;
    virtual ListElement<T>* getHead() = 0;
    virtual void setHead(ListElement<T>* new_head) = 0;
    virtual ~List() {}
  };
}


#endif