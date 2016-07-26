#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::max;

int count_frequency(vector<int> &a, int left, int right, int x)
{
  int count = 0;
  for( int i=left; i<=right; ++i)
    if( a[i] == x ) count ++;
  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
  if (left + 1 == right)
   return a[left];

  int mid = (left + right) / 2;

  int m1 = get_majority_element(a, left, mid);
  int m2 = get_majority_element(a, mid+1, right);

  int freq1 = count_frequency(a, left, right, m1);
  int freq2 = count_frequency(a, left, right, m2);  

  int k = (right - left + 1) / 2;

  if( freq1 > k )
    return m1;
  else if( freq2 > k )
    return m2;
  else 
   return -1;  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  if( n == 1 ) 
    std::cout << 1 << '\n';
  else
    std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
