#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector<Node> buildTrie(vector<string> patterns) {
        vector <Node> trie;
        int node = 0, current_node;
        trie.resize(1);
        for( int i = 0; i < patterns.size(); ++i ) {
          current_node = 0;
          for( int j = 0; j < patterns[i].size(); ++j ) {
             char currentSymbol = patterns[i][j];
             if( trie[current_node].next[letterToIndex(currentSymbol)] != NA )  
                current_node = trie[current_node].next[letterToIndex(currentSymbol)];
             else {
                node = trie.size();
                trie[current_node].next[letterToIndex(currentSymbol)] = node;
                current_node = node;
                trie.resize(node + 1);
             }
             if (j + 1 == patterns[i].size() ) trie[current_node].patternEnd = true;
          }
        }
        return trie;
}


bool prefixTrieMatching( string text, const vector<Node> &trie ) {
  vector<int> result;

  int current_node = 0;
  for ( int i = 0; i < text.size(); ++i ) // parse the input string and follow the path through the trie until we reach patternEnd = true or a dead-end
  {
     char currentSymbol = text[i];     
     if (trie[current_node].next[letterToIndex(currentSymbol)] != NA ) {
       current_node = trie[current_node].next[letterToIndex(currentSymbol)];
       if( trie[current_node].patternEnd ) return true;
     } else break;
  }
  return false;
}

vector <int> solve (string text, int n, vector <string> patterns)
{
	vector <int> result;

	// build a trie from patterns
        vector <Node> trie = buildTrie(patterns);

        // extract the mathches from the trie
        for( int k = 0; k < text.size(); ++k ) {
          string currentText = text.substr(k);
          if( prefixTrieMatching(currentText, trie) )
            result.push_back(k); 
        }

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
