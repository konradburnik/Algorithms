#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>


const double infty = 1000000.0;

using std::vector;
using std::priority_queue;

using std::cout;

bool in_queue[10000];
double cost[10000] = {infty};
bool was[10000];

struct point {
 
 int id;
 int x;
 int y;

 double cost; 

 point(int _id, int _x, int _y, double _cost) { id = _id; x = _x;  y = _y; cost = _cost; }
};


struct compare  
 {  
   bool operator()(const point& p1, const point& p2)  
   {  
       return p1.cost > p2.cost;  
   }  
 };  

double distance(const point &p1, const point &p2) {

  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
 
  priority_queue<point, std::vector<point>, compare> pq;

  for( int i = 0; i < x.size(); ++i ) {
     point p(i, x[i], y[i], (double)((i == 0) ? 0 : infty));
     pq.push(p);
     in_queue[i] = true;
     cost[i] = infty;
  }
 
  cost[0] = 0.;

  while(!pq.empty()) {

    point v = pq.top(); pq.pop(); 
    in_queue[v.id] = false;
         was[v.id] = true;

    for( int i = 0; i < x.size(); ++i )
    { 
      point z(i, x[i], y[i], cost[i]);

      if (v.id != z.id && in_queue[i] && !was[i] && cost[i] > distance(v, z) ) 
      {
        z.cost = distance(v, z);
        cost[i] = z.cost;
        pq.push(z);
      }
    }
    
  }
  
  for(int i = 0; i < x.size(); ++i )
    result += cost[i];
 
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
