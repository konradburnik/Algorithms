#ifndef __SINGLY_LINKED_LIST_
#define __SINGLY_LINKED_LIST_

#include "List.h"

namespace Algorithms
{
  
  template <typename T>
  class LinkedListNode : public ListElement<T> 
  {     
  private:
    T value;
    LinkedListNode<T> *next;
  public:

    void setNext(ListElement<T>* new_next)
    {
      next = dynamic_cast<LinkedListNode<T>*>(new_next);
    }

    ListElement<T> *getNext()
    {
      return dynamic_cast<ListElement<T>* >(next);
    };

    T getValue()
    {
      return value;
    }

    LinkedListNode() {}

    LinkedListNode(T new_value)
    {
      value = new_value;
      next = nullptr;
    }

    ~LinkedListNode()
    {}

  };


  template <typename T>
  class SinglyLinkedList : public virtual List<T>
  {
  protected:
    LinkedListNode<T> *head;

  public:

    SinglyLinkedList()
    {
      head = nullptr;
    }

    SinglyLinkedList(T new_value)
    {
      head = new LinkedListNode<T>(new_value);
    }
    
    ~SinglyLinkedList()
    {
      LinkedListNode<T> *current = dynamic_cast<LinkedListNode<T> *>(getHead());
      while (current != nullptr)
      {
        head = dynamic_cast<LinkedListNode<T>* >(current->getNext());
        delete current;
        current = dynamic_cast<LinkedListNode<T>* >(head);
      }      
    }

    virtual void setHead(ListElement<T>* new_head)
    {
      head = dynamic_cast<LinkedListNode<T>*>(new_head);
    }

    virtual ListElement<T>* getHead()
    {
      return head;
    }

    List<T> &insertFront(T new_value)
    {
      LinkedListNode<T>* node = new LinkedListNode<T>(new_value);
      node->setNext(dynamic_cast<LinkedListNode<T> *>(getHead()));
      setHead(node);
      return dynamic_cast<List<T>& >(*this);
    }

    List<T> &insertBack(T new_value)
    {
      ListElement<T>* node = new LinkedListNode<T>(new_value);
      ListElement<T>* current = head;
      ListElement<T>* previous = current;
      
      while (current != nullptr)
      {
        previous = current;
        current = current->getNext();
      }
      
      if (previous != nullptr)
        previous->setNext(node);
      else
        setHead(node);
      
      return dynamic_cast<List<T>& >(*this);
    }

    List<T>& insertAfter(T old_value, T new_value)
    {
      if (head == nullptr)
        head = new LinkedListNode<T>(new_value);
      else 
      {
        LinkedListNode<T>* current = head;

        while (current != nullptr && current->getValue() != old_value)
          current = dynamic_cast<LinkedListNode<T>* >(current->getNext());

        if (current != nullptr && current->getValue() == old_value)
        {
          LinkedListNode<T>* temp = dynamic_cast<LinkedListNode<T>* >(current->getNext());
          current->setNext(new LinkedListNode<T>(new_value));
          current->getNext()->setNext(temp);
        }
      }      
      return dynamic_cast<List<T>& >(*this);
    }


    List<T>& removeElement(T value_to_delete)
    {      
      if (head != nullptr)
      {
        ListElement<T>* current;
        ListElement<T>* previous;

        if (head->getValue() == value_to_delete)
        {
          current = head;
          head = dynamic_cast<LinkedListNode<T>* >(head->getNext());
          delete current;
        }
        else
        {
          previous = head;
          current = dynamic_cast<LinkedListNode<T>* >(head->getNext());
          
          while (current != nullptr)
          {
            if (current->getValue() == value_to_delete) break;
            previous = current;
            current = current->getNext();
          }

          if (current != nullptr && previous != nullptr && current->getValue() == value_to_delete )
          {
            previous->setNext(current->getNext());
            delete current;
          }
        }                  
      }     
      return dynamic_cast<List<T>& >(*this);
    }


  };
}

#endif