#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class TreeHeight {
  int n;             
  std::vector<int> parent;
  std::vector<int> height;
  std::vector<bool> is_leaf;
  std::stack<int> vertex_stack;

public:
  void read() {
    std::cin >> n;
    parent.resize(n);
    height.resize(n);
    is_leaf.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> parent[i];
      height[i] = -1;  
      is_leaf[i] = true;
    }
  }

  int compute_height_old() {
    // Replace this code with a faster implementation
    int maxHeight = 0;
    for (int vertex = 0; vertex < n; vertex++) {
      int height = 0;
      for (int i = vertex; i != -1; i = parent[i])
        height++;
      maxHeight = std::max(maxHeight, height);
    }
    return maxHeight;
  }


  int get_height( int vertex ) {
     
     if( parent[vertex] != -1 && height[parent[vertex]] != -1 ) { 
       height[vertex] = height[parent[vertex]] + 1;
       return height[vertex];
     }
     else {
	// push path to root on stack
	for (int i = vertex; i != -1 || height[i] == -1; i = parent[i])
           vertex_stack.push(i);
	 
	// unwind stack, update heights for all vertices on the path including the starting vertex
	while(!vertex_stack.empty()) {
	   int v = vertex_stack.top();
	   if( parent[v] == -1 ) 
	       height[v] = 0;
	    else 
	       height[v] = 1 + height[parent[v]];
	   vertex_stack.pop(); 
        }
	return height[vertex];
     }
  }

  int compute_height() {
    int maxHeight = 0;

    for( int vertex = 0; vertex < n; vertex++ ) 
        if ( parent[vertex] != -1 )
          is_leaf[parent[vertex]] = false;
        else
          is_leaf[vertex] = false;

    for( int vertex = 0; vertex < n; vertex++ ) 
        if ( is_leaf[vertex] )
          maxHeight =   std::max(maxHeight, get_height(vertex));

    return maxHeight;
  }     

};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() + 1 << std::endl;
}
