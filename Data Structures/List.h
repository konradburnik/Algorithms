#ifndef __LIST_H_
#define __LIST_H_

namespace Algorithms
{

  template <typename T>
  class ListElement {
  public:
    virtual T getValue() const = 0;
    virtual ListElement<T>* getNext() const = 0;
    virtual void setValue(T new_value) = 0;
    virtual void setNext(ListElement<T>* new_next) = 0;
  };



  template <typename T>
  class List
  {
  public:
    virtual ListElement<T>* getHead() const = 0;
    virtual void setHead(ListElement<T>* new_head) = 0;
    virtual void addFront(T new_value) = 0;
  };

  template <typename T>
  class MyListElement : public ListElement < T >
  {
  public:
    T getValue() const
    {
      return value;
    }

    ListElement<T>* getNext() const
    {
      return next;
    }

    void setValue(T new_value)
    {
      value = new_value;
    }

    void setNext(ListElement<T>* new_next)
    {
      next = static_cast<MyListElement<T>*>(new_next);
    }

  private:
    T value;
    MyListElement<T>* next;
  };

  template <typename T>
  class MyList : public List < T >
  {
  public:
    ListElement<T>* getHead() const
    {
      return head;
    }

    void setHead(ListElement<T>* new_head)
    {
      head = static_cast<MyListElement<T>*>(new_head);
    }

    void addFront(T new_value)
    {
      MyListElement<T> *node = new MyListElement < T > ;
      node->setValue(new_value);
      node->setNext(static_cast<ListElement<T>*>(head));
      setHead(node);
    }

  private:
    MyListElement<T> *head;
  };

}

#endif // __LIST_H_
