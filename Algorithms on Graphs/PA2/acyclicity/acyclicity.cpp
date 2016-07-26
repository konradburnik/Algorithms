#include <iostream>
#include <vector>
#include <stack>


using std::vector;
using std::pair;
using std::stack;
using std::cout;
using std::cin;

const int MAX_VERTICES = 1000;

bool visited[MAX_VERTICES];
int count[MAX_VERTICES];

bool DFS(vector<vector<int> > &adj, int start) {
  stack<int> S;

  for( int i = 0; i<adj.size(); ++i) {
     visited[i] = false;
     count[i] = 0;
  } 
 
  S.push(start);
  while(!S.empty())
  {
    int v = S.top();
    S.pop();
    count[v]++;
    if(count[v] > 1) return true; 
    for( int i = 0; i<adj[v].size(); ++i)
    {
       if(!visited[adj[v][i]] ) {
          visited[adj[v][i]] = true;
          S.push(adj[v][i]);
       }
    }    
  }
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  for( int i = 0; i < adj.size(); ++i)
     if( DFS(adj, i) ) 
       return 1;
  return 0;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << acyclic(adj);
}
