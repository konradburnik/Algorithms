#include <iostream>
#include <vector>

using std::vector;

const int MAX_ITEMS = 10000;

const double epsilon = 0.001;

bool used[MAX_ITEMS];


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  // Sort by unit value, naive sort should be sufficient since it is maximum order of 10^6 operations

  for( int i = 0; i < weights.size(); ++i) 
     for (int j = i; i < weights.size(); ++j)
      if( values[i] * weight[j] < values[j] * weight[i])
      {
        swap(values[i], values[j]);
        swap(weights[i], weights[j]);
      }

  double value = 0.0;
  
  double W = capacity;

  bool done = false;
  
  while( W > epsilon && done == false )
  {
   double maxRatio = 0.0;
   double valuePerUnit = 0.0;
   int j = -1;

   for(int i = 0; i<weights.size(); ++i )
   {
     // Find the item with maximum value per unit of weight
     if( used[i] ) continue; 
        valuePerUnit = (double)(values[i]) / (double)weights[i];
        if( valuePerUnit > maxRatio ) {
           maxRatio = valuePerUnit;
           j = i;
        } 
   }
   if( j != -1 ) {
     used[j] = true;
     if( weights.size() == 1 ) done = true;
     if( W >= weights[j] ) { 
         W = W - weights[j];
         value = value + values[j];
     }
     else {
         value = value + (W * valuePerUnit);
         W = 0;
     }
   }
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
