#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;

const int infty = 100000;

class compFirst
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first>n2.first;
    }
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  priority_queue<pair<int, int>, vector<pair<int,int>>, compFirst > H;
  vector<int> dist(adj.size(),  infty);
  vector<int> prev(adj.size(), -1);
  vector<bool> was(adj.size(), false);
  
  dist[s] = 0;
  H.push(make_pair(dist[s], s));    
  for(int v = 1; v < adj.size(); ++v)
    H.push(make_pair(dist[v], v));

  while(!H.empty()) {
    pair<int, int> p = H.top(); H.pop(); 
    int u = p.second;
    if( !was[u] ) {
     was[u] = true;
     for(size_t i = 0; i < adj[u].size(); ++i)
     {
       int v = adj[u][i];
       if( dist[v] > dist[u] + cost[u][i] ) {
          dist[v] = dist[u] + cost[u][i];
          prev[v] = u;
          H.push(make_pair(dist[v], v));
       }
     }
   }
  }
  return (dist[t] == infty) ? -1 : dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
