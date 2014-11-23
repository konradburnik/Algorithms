#ifndef __RECURSIVE_GCD_H__
#define __RECURSIVE_GCD_H__

namespace Algorithms {
  namespace Numeric {

    template <typename T>
    T recursive_gcd( T m, T n ) {
      if ( n == 0 )
        return m;
      else
        return recursive_gcd(n, m%n);
    }
  } // namespace Numeric
} // namespace Algorithms

#endif
