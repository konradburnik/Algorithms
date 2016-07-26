#include <iostream>
#include <vector>
#include <queue>


using std::vector;
using std::pair;
using std::queue;


int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  queue<int> q;
  bool was[100000];

  int hasPath = 0;
   
  q.push(x);
  while( !q.empty() )
  {
    int p = q.front();
    q.pop();
    for( int i = 0; i < adj[p].size(); ++i) 
       if (!was[adj[p][i]]) {
         q.push(adj[p][i]);
         was[adj[p][i]] = true; 
       }
    if( p == y ) {
      hasPath = 1;
      break;
    }     
  } 
  return hasPath;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
