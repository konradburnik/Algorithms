#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>

using std::vector;
using std::pair;



/*
KRUSKAL(G):
1 A = ∅
2 foreach v ∈ G.V:
3    MAKE-SET(v)
4 foreach (u, v) in G.E ordered by weight(u, v), increasing:
5    if FIND-SET(u) ≠ FIND-SET(v):
6       A = A ∪ {(u, v)}
7       UNION(u, v)
8 return A
*/

const int max_nodes = 1000;

struct Edge 
{
  int from;
  int to;
  double weight = 0.0;
};

struct compare  
 {  
   bool operator()(const Edge& l, const Edge& r)  
   {  
       return l.weight > r.weight;  
   }  
 };  

std::priority_queue<Edge, std::vector<Edge>, compare> edge_queue;
int parent[max_nodes];


double clustering(vector<int> x, vector<int> y, int k) {
  vector<Edge> result;
  // put each node in it's own connected component
  for( int i = 0; i < n; ++i )
     makeset(i);

  // store edges in max priority queue by weight
  for( int i = 0; i < n - 1; ++i )
    for( int j = i + 1; j < n; ++j)
    {
      Edge e(i, j, dist(x[i], y[i], x[j], y[j]));
      edge_queue.push(e);
    }
  
  // for each edge in priority queue do the main step of Kruskal's algorithm  
    while( !edge_queue.empty() )
    {
      Edge e = edge_queue.top(); edge_queue.pop();
      if( find_set(e.from) !=  find_set(e.to) )
      {
         union_set(e.from, e.to); 
         result.push_back(e);
      }
    }

  // Sort resulting edges desceding by weight and take the first k, the k-th one's weight is the solution 
   qsort(result, compare);

  return result[k];

  return -1.;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
