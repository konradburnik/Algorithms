#include <iostream>

int get_fibonacci_last_digit(int n) {
  //write your code here
   long a, b;

   if( n <= 1 ) return n;

   a = 0; b = 1;
   for(int i = 2; i<=n; i++) {
      long t = a%10;
      a = b%10;
      b = (t+b)%10;
   }
   return b;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
