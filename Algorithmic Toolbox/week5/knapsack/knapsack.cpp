#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {

  vector< vector<long> > current_weight(W + 1, vector<long>(w.size() + 1, 0) );

  for( int i = 0; i <= W; ++i ) current_weight[i][0] = 0;
  for( int j = 1; j <= w.size(); ++j ) current_weight[0][j - 1] = 0;

  for (size_t i = 1; i <= w.size(); ++i) {
    for (size_t j = 1; j <= W; ++j ) {
      current_weight[j][i] = current_weight[j][i - 1];
      if (w[i - 1] <= j) {
        size_t val = current_weight[j - w[i - 1]][i - 1] + w[i - 1];
        if ( current_weight[j][i] < val )
             current_weight[j][i] = val;
      }    
    }
  }
  return current_weight[W][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
