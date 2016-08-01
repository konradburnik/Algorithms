#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  int current_node, node;

  node = 0;
  t.resize(1);

  for( int i = 0; i < patterns.size(); ++i )
  {
    current_node = 0;
    for( int j = 0; j < patterns[i].size(); ++j ) {
      char currentSymbol = patterns[i][j]; 
      
      if( t[current_node].count(currentSymbol) > 0 ) 
         current_node = t[current_node][currentSymbol];
      else {
        node = t.size();
        t[current_node][currentSymbol] = node;
        current_node = node;
        t.resize(node+1);
      }
     
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
