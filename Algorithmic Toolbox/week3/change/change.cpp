#include <iostream>

int get_change(int n) {
  
  int current =  n, count = 0, w = 0;

  while(current > 0)
  {
    if(current  >= 10) w = 10;
    else if(current  >= 5 ) w = 5;
    else if(current  >= 1 ) w = 1;
    current -= w;
    count++;
  }   

  return count;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
