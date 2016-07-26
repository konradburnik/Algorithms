#include <iostream>

unsigned long long fibonacci(unsigned long long n, unsigned long long m) {
  //write your code here
   unsigned long long a, b=0;

   if( n <= 1 ) return n;

   a = 0; b = 1;
   for(unsigned long long i = 2; i<=n; i++) {
      unsigned long long t = a%m;
      a = b%m;
      b = (t+b)%m;
   }
   return b;
}


unsigned long long get_fibonaccihuge(unsigned long long n, unsigned long long m) { 
  // find Pisano period for given m
   unsigned long long a=0,b=0,count=0,p = 0;
   a = 0; b = 1;
 
   unsigned long long i = 0; 
   for( ; true; i++) {
      if (a == 0 && b == 1) {  
        count++; 
        if( count == 1 ) p = 2;
      }
      else p++;

      if (count > 1) { p--; break; } 
      unsigned long long t = a%m;
      a = b%m;
      b = (t+b)%m; 
   }
  return fibonacci(n%p, m);
}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
} 
