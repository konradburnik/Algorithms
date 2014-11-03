#ifndef __BINARY_TREE_
#define __BINARY_TREE_

#include <iostream>

namespace Algorithms {

	enum CHILDTYPE { LEFTCHILD, RIGHTCHILD, ROOT };

	template <typename T>
	struct BinaryTreeNode
	{
		T value;
		BinaryTreeNode* parent;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		CHILDTYPE type;

		BinaryTreeNode<T>(T new_value, BinaryTreeNode<T>* new_parent, CHILDTYPE new_type)
		{
			value = new_value;
			parent = new_parent;			
			type = new_type;
			left = nullptr;
			right = nullptr;
		}
	};

	template <typename T>
	class BinaryTree
	{
	private:
		BinaryTreeNode<T>* root = nullptr;
		BinaryTreeNode<T>* current = root;

	public:

		BinaryTree<T>()
		{
			root = nullptr;
			current = nullptr;
		}

		BinaryTree<T>(BinaryTreeNode<T>* node)
		{
			root = node;
		}

		BinaryTree(T _root_value)
		{
			root = new BinaryTreeNode < T >(_root_value, nullptr, ROOT) ;			
			current = root;
		}

		~BinaryTree<T>()
		{
			clear(root);
		}


		BinaryTree<T>& addChild(CHILDTYPE t, T node_value)
		{
		
				switch (t)
				{
				case LEFTCHILD:
					if ( current != nullptr && current->left == nullptr)
					{ 
						current->left = new BinaryTreeNode < T >(node_value, current, LEFTCHILD);																		
						current = current->left;																		
					}
					break;
				case RIGHTCHILD:
					if (current != nullptr && current->right == nullptr)
					{
						current->right = new BinaryTreeNode < T >(node_value, current, RIGHTCHILD);						
						current = current->right;						
					}					
					break;
				case ROOT:
					current = new BinaryTreeNode < T >(node_value, nullptr, ROOT);
					root = current;
					break;
				default:					
					break;
				};							
			return *this;
		}

		BinaryTreeNode<T>* getCurrent()
		{
			return current;
		}

		BinaryTree<T>& moveLeft()
		{
			if (current != nullptr)
			  current = current->left;
			return *this;
		}

		BinaryTree<T>& moveRight()
		{
			if (current != nullptr)
			  current = current->right;
			return *this;
		}


		BinaryTree& moveUp()
		{
			if (current !=  nullptr )				
			  current = current->parent;
			return *this;
		}

		BinaryTreeNode<T>* getRoot()
		{
			return root;
		}
		
		void setCurrent(BinaryTreeNode<T>* new_current)
		{
			current = new_current;
		}

		void clear(BinaryTreeNode<T>* start)
		{
			if (start != nullptr)
			{
				clear(start->left);
				clear(start->right);
				delete start;
			}
		}

	};

}
#endif