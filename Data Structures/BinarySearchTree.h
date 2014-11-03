#ifndef __BINARY_SEARCH_TREE_
#define __BINARY_SEARCH_TREE_

#include "BinaryTree.h"

namespace Algorithms
{
	template <typename T>
	class BinarySearchTree
	{
	private:
		BinaryTree <T> B;
	public:
		BinarySearchTree& insertValue(T new_value)
		{
			CHILDTYPE insertion = ROOT;

			BinaryTreeNode<T>* current = B.getRoot();
			BinaryTreeNode<T>* temp = current;

			if (current == nullptr)
				insertion = ROOT;
			else
			{
				while (B.getCurrent() != nullptr)
				{
          if (B.getCurrent()->value < new_value)
					{
						temp = B.getCurrent();
						B.moveRight();
						insertion = RIGHTCHILD;
					}
					else
					{
						temp = B.getCurrent();
						B.moveLeft();
						insertion = LEFTCHILD;
					}
				}
			}

			switch (insertion)
			{
			case LEFTCHILD:
				B.setCurrent(temp);
				B.addChild(LEFTCHILD, new_value);
				break;
			case RIGHTCHILD:
				B.setCurrent(temp);
				B.addChild(RIGHTCHILD, new_value);
				break;
			case ROOT:
				B.setCurrent(temp);
				B.addChild(ROOT, new_value);
			default:
				break;
			}
			return *this;
		}

		BinaryTreeNode<T> *getRoot()
		{
			return B.getRoot();
		}

	};
}
 
#endif
