#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

const int infty = 1000000;

vector<int> optimal_sequence(int n) {

  std::vector<int> sequence;
  std::vector<int> last(n+1);
  std::vector<int> C(n+1);

  // calculate the optimum number of operations and keep track which operations was used at each optimum step
  C[1] = 0;

  for( int i = 2; i <= n; ++i ) {

    int a = (i % 2 == 0) ? C[i/2] : infty;
    int b = (i % 3 == 0) ? C[i/3] : infty;
    int c = (i >= 1) ? C[i - 1] : infty;

    if ( a <= b && a <= c )  { C[i] = a + 1; last[i] = 2; } else
    if ( b <= a && b <= c )  { C[i] = b + 1; last[i] = 3; } else
    if ( c <= a && c <= b )  { C[i] = c + 1; last[i] = 1; }

  }

   // reconstruct the optimal order of operations and intermmediate results
   int x = n;
   sequence.push_back(x);  
   while( x > 1 ) {
      switch(last[x]) {
         case 1:  
            x = x - 1;
         break;
         case 2:
            x = x / 2;
         break;
         case 3:
            x = x / 3;
         break;
      };
      sequence.push_back(x);  
   }

   reverse(sequence.begin(), sequence.end());
  
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
