#include <iostream>
#include <vector>
#include <algorithm>

class TreeHeight {
  int n;             
  std::vector<int> parent;
  std::vector<int> height;

public:
  void read() {
    std::cin >> n;
    parent.resize(n);
    height.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> parent[i];
      height[i] = -1;  
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
    if ( parent[vertex] == -1 ) 
    {
      height[vertex] = 0;
      return 0;
    }
    else { 
      if (height[vertex] == -1 )
         height[vertex] = 1 + get_height(parent[vertex]);
      return height[vertex];
    }
  }

  int compute_height() {
    int maxHeight = 0;
    for( int vertex = 0; vertex < n; vertex++ ) 
        get_height(vertex);

    for( int vertex = 0; vertex < n; vertex++ ) 
        maxHeight =   std::max(maxHeight, height[vertex]);

    return maxHeight;
  }     

};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() + 1 << std::endl;
}
