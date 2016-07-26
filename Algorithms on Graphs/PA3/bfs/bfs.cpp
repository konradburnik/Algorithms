#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool was[100001] = {false};
int dist[100001] = {0};

int distance(vector<vector<int> > &adj, int s, int t) {
  queue<int> q;

  q.push(s);
  while( !q.empty() ) 
  {
    int v = q.front();
    q.pop();
    if( v == t ) return dist[t];
    else {
      for( int w=0; w < adj[v].size(); ++w )
       if(!was[adj[v][w]]) {
        was[adj[v][w]] = true;
        q.push(adj[v][w]);
        dist[adj[v][w]] = dist[v] + 1; 
       }
    }
  }

  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
} 
