#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


int min( int a, int b, int c)
{
  if( a <= b && a <= c ) return a;
  if( b <= a && b <= c ) return b;
  if( c <= a && c <= b ) return c;
}

int edit_distance(const string &str1, const string &str2) {
  
  vector<vector<int> > dist(str1.size() + 1, vector<int>(str2.size() + 1, 0));

  for( size_t i = 0; i <= str1.size(); ++i ) dist[i][0] = i;
  for( size_t j = 0; j <= str2.size(); ++j ) dist[0][j] = j;

  for( size_t i = 1; i <= str1.size(); ++i )
    for( size_t j = 1; j <= str2.size(); ++j )
       dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1] + ((str1[i - 1] != str2[j - 1]) ? 1 : 0));    
  
  return dist[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
} 
