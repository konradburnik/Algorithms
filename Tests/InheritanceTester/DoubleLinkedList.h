#ifndef __DOUBLE_LINKED_LIST_
#define __DOUBLE_LINKED_LIST_

#include "List.h"

namespace Algorithms 
{

  template <typename T>
  struct DoubleLinkedListNode : ListElement< T >
  {
    DoubleLinkedListNode<T>* previous;

    DoubleLinkedListNode(T new_value)
    {
      value = new_value;
      next = nullptr;
      previous = nullptr;
    }

  };

  template <typename T>
  class DoubleLinkedList : public virtual List<T>
  {
  protected:
    DoubleLinkedListNode<T>* head;
  
  public:
    DoubleLinkedList<T> &insertFront(T new_value)
    {
      DoubleLinkedListNode<T>* node = new DoubleLinkedListNode<T>(new_value);
      node->previous = nullptr;
      node->next = head;
      head = node;
      return *this;
    }

    DoubleLinkedListNode<T>& insertBack(T new_value)
    {
      return *this;
    }

    DoubleLinkedListNode<T>& insertAfter(T old_value, T new_value)
    {
      return *this;
    }

    DoubleLinkedListNode<T>& removeElement(T value_to_delete)
    {
      return *this;
    }

    DoubleLinkedListNode<T>* getHead() const
    {
      return head;
    }

  };
}
#endif