#ifndef __SINGLY_LINKED_LIST_
#define __SINGLY_LINKED_LIST_


namespace Algorithms
{
  
  template <typename T>
  struct LinkedListNode 
  {
    T value;
    LinkedListNode *next;

    LinkedListNode(T new_value)
    {
      value = new_value;
      next = nullptr;
    }

    ~LinkedListNode()
    {}

  };


  template <typename T>
  class SinglyLinkedList
  {
  private:
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
      LinkedListNode<T> *current = head;
      while (current != nullptr)
      {
        head = current->next;        
        delete current;
        current = head;
      }      
    }

    LinkedListNode<T>* getHead()
    {
      return head;
    }

    SinglyLinkedList<T> &insertFront(T new_value)
    {
      LinkedListNode<T>* node = new LinkedListNode<T>(new_value);
      node->next = head;
      head = node;
      return *this;
    }

    SinglyLinkedList<T> &insertBack(T new_value)
    {
      LinkedListNode<T>* node = new LinkedListNode<T>(new_value);
      LinkedListNode<T>* current = head;
      LinkedListNode<T>* previous = current;
      
      while (current != nullptr)
      {
        previous = current;
        current = current->next;
      }
      
      if (previous != nullptr)
        previous->next = node;
      else
        head = node;
      
      return *this;
    }

    SinglyLinkedList<T>& insertAfter(T old_value, T new_value)
    {
      if (head == nullptr)
        head = new LinkedListNode<T>(new_value);
      else 
      {
        LinkedListNode<T>* current = head;

        while (current != nullptr && current->value != old_value)
          current = current->next;

        if (current != nullptr && current->value == old_value)
        {
          LinkedListNode<T>* temp = current->next;
          current->next = new LinkedListNode<T>(new_value);
          current->next->next = temp;
        }
      }      
      return *this;
    }


    SinglyLinkedList<T>& removeElement(T value_to_delete)
    {      
      if (head != nullptr)
      {
        LinkedListNode<T>* current;
        LinkedListNode<T>* previous;

        if (head->value == value_to_delete)
        {
          current = head;
          head = head->next;
          delete current;
        }
        else
        {
          previous = head;
          current = head->next;
          
          while (current != nullptr)
          {
            if (current->value == value_to_delete) break;
            previous = current;
            current = current->next;
          }

          if (current != nullptr && previous != nullptr && current->value == value_to_delete )
          {
            previous->next = current->next;
            delete current;
          }
        }                  
      }     
      return *this;
    }


  };
}

#endif