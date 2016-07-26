#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  void in_order_traverse(vector<int> &result, int node)
  {
    if( left[node] != -1 ) in_order_traverse(result, left[node]);
    result.push_back(key[node]);
    if( right[node] != -1 ) in_order_traverse(result, right[node]);
  }

  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    in_order_traverse(result, 0);
    return result;
  }

  void pre_order_traverse(vector<int> &result, int node)
  {
    result.push_back(key[node]);
    if( left[node] != -1 ) pre_order_traverse(result, left[node]);
    if( right[node] != -1 ) pre_order_traverse(result, right[node]);
  }


  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    pre_order_traverse(result, 0);
    return result;
  }

  void post_order_traverse(vector<int> &result, int node)
  {
    if( left[node] != -1 ) post_order_traverse(result, left[node]);
    if( right[node] != -1 ) post_order_traverse(result, right[node]);
    result.push_back(key[node]);
  }



  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    post_order_traverse(result, 0);
    
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}
