#include <iostream>

#include "..\Data Structures\BinaryTree.h"
#include "..\Data Structures\BinarySearchTree.h"
#include "..\Data Structures\SinglyLinkedList.h"
#include "..\Data Structures\List.h"

template <typename T>
void preorder(Algorithms::BinaryTreeNode<T> *start)
{
		if (start != nullptr)
		{
		 std::cout << start->value;

		 if (start->parent != nullptr)
			 std::cout << "(" << start->parent->value << "," << start->type << ")" << std::endl;
		 else
			 std::cout << "()" << std::endl;

		 preorder(start->left);
		 preorder(start->right);
		}
}

void printList(Algorithms::SinglyLinkedList <int>& L)
{

  std::cout << "Printing list:" << std::endl;
  for (Algorithms::LinkedListNode<int>* current = L.getHead(); current != nullptr; current = current->next)
  {
    std::cout << current->value << std::endl;
  }
  std::cout << "Printing list done!" << std::endl;
}

void printMyList(Algorithms::List <int>* L)
{

  std::cout << "Printing list:" << std::endl;
  for (Algorithms::ListElement<int>* current = L->getHead(); current != nullptr; current=current->getNext())
  {
    std::cout << current->getValue() << std::endl;
  }
  std::cout << "Printing list done!" << std::endl;
}



int main(void){

  Algorithms::MyList<int> *M = new Algorithms::MyList < int >;

	Algorithms::BinaryTree<int> B(1);
	Algorithms::BinarySearchTree<int> S;
  Algorithms::SinglyLinkedList<int> L;

	//for (long long i = 0; i < 1000L; ++i)
	//	S.insertValue((i*4321+37)%3371);

	B.addChild(Algorithms::LEFTCHILD, 2).addChild(Algorithms::RIGHTCHILD, 3).moveUp().addChild(Algorithms::LEFTCHILD, 4);
	
	//preorder(B.getRoot());
	preorder(S.getRoot());
  
  L.insertAfter(2, 4);
  L.insertBack(0);
  L.insertFront(1);
  L.insertFront(2);
  L.insertAfter(2, 4);
  L.insertBack(3);
  printList(L);
  L.removeElement(3);  
  printList(L);
  M->addFront(1);
  M->addFront(2);
  M->addFront(3);
  printMyList(M);
  int a;
  std::cin >> a;
  return 0;
}