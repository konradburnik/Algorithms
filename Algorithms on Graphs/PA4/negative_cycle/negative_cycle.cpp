#include <iostream>
#include <vector>

using std::vector;


const int infty = 1000000;

bool relax( vector<int> &dist, const vector<vector<int> > &adj, const vector<vector<int> > &cost, int u, int i )
{
   int v = adj[u][i];
   if( dist[v] > dist[u] + cost[u][i] ) {
          dist[v] = dist[u] + cost[u][i];
          return true;
   } 
   else
   return false;  
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  size_t n = adj.size();
  vector<int> dist(n, infty);
  for( int k = 1; k <= n; ++k )
  {
    for( int u = 0; u < n; ++u )
     for ( int v = 0; v < adj[u].size(); ++v )
     {
        bool relaxed = relax(dist, adj, cost, u, v); 
        if( k == n && relaxed ) return 1;
     } 
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
} 
