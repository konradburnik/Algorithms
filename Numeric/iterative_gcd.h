#ifndef __ITERATIVE_GCD_H__
#define __ITERATIVE_GCD_H__

namespace Algorithms {
  namespace Numeric {
    template <typename T>
    T iterative_gcd(T m, T n) {
      if ( m<0 ) m = -m;
      if ( n<0 ) n = -n;

      T r;
      while (n!=0) {
        r = n;
        n = m%n;
        m = r;
      }

      return m;
    }
  } // namespace Numeric
} // namespace Algorithms

#endif
