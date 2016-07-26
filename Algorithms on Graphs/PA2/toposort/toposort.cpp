#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::stack;
using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, stack<int> &order, int x) {

    used[x] = true;

    for(int i = 0; i<adj[x].size(); ++i)
    
      if( !used[adj[x][i]] )
        dfs(adj, used, order, adj[x][i]);
      order.push(x);
  
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  stack<int> reverseOrder;

  //write your code here
  for(int i = 0; i<adj.size(); ++i)
    if(!used[i]) dfs(adj, used, reverseOrder, i);

  while( !reverseOrder.empty() )
  {
    order.push_back(reverseOrder.top());
    reverseOrder.pop();
  }
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
