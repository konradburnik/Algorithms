#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::swap;

const double epsilon = 0.001;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  // Sort by unit value, naive sort should be sufficient since it takes roughly maximum of 10^6 operations

  for( int i = 0; i < weights.size(); ++i) 
     for (int j = i; j < weights.size(); ++j)
      if( values[i] * weights[j] < values[j] * weights[i])
      {
        swap(values[i], values[j]);
        swap(weights[i], weights[j]);
      }

  double value = 0.0;
  
  double W = capacity;
  
  int j = 0;

  bool done = false; 

  while( W > epsilon && done == false )
  {
     double valuePerUnit = (double) values[j] / (double) weights[j];
     if( weights.size() == 1 ) done = true;
     if( W >= weights[j] ) { 
         W = W - weights[j];
         value = value + values[j];
     }
     else {
         value = value + (W * valuePerUnit);
         W = 0;
     }
    j++;
  }
  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
