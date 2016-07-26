#include <iostream>
#include <vector>
#include <algorithm>

class TreeHeight {
  int n;             
  std::vector<int> parent;
  std::vector<int> height;
  std::vector<bool> is_leaf;
  std::vector<int> all_leafs;

public:
  void read() {
    std::cin >> n;
    parent.resize(n);
    is_leaf.resize(n);
    height.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> parent[i];
      is_leaf[i] = true;
      height[i] = -1;
    }
  }

  int get_height( int vertex ) {
        int h = 0;
        int i = vertex; 
	
        for (; i != -1 && height[i] == -1; i = parent[i], h++);
        
        height[vertex] = height[i] + h;
        return height[vertex];
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
        all_leafs.push_back(vertex);

    for( int i=0; i < all_leafs.size(); i++ ) 
          maxHeight =   std::max(maxHeight, get_height(all_leafs[i]));

    return maxHeight;
  }     

};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
