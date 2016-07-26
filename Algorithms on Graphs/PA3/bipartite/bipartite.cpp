#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool was[100001] = {false};
bool color[100001] = {false};

int bipartite(vector<vector<int> > &adj) {
  queue<int> q;
  int start_node = -1;

  bool done = false;

while( !done ) {

  done = true;
  for( int i = 0; i<adj.size(); i++)
     if(adj[i].size() > 0 && !was[i] ) {
       start_node = i;
       done = false;
       break;
     }

  if(start_node == -1) return 1;

  // attempt to 2-color the graph
  q.push(start_node);
  color[start_node] = true;
  was[start_node] = true;

  while( !q.empty() )
  {
    int v = q.front();
    if( !was[v] ) was[v] = true; 
    q.pop();
    for( int w=0; w < adj[v].size(); ++w )
    {
     if( v == adj[v][w] ) return 0;
     if(!was[adj[v][w]]) {
      was[adj[v][w]] = true;
      color[adj[v][w]] = !color[v];
      q.push(adj[v][w]);
     }
    }
  }

}

  // check if any neighbors are colored the same color
  for( int v = 0; v < adj.size(); ++v )
    for( int w = 0; w < adj[v].size(); ++w)
       if( v != adj[v][w] && color[v] == color[adj[v][w]] ) return 0;

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
