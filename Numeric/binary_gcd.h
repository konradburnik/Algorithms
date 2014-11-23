
#ifndef __BINARY_GCD_H__
#define __BINARY_GCD_H__

namespace Algorithms {

  namespace Numeric {

    // Greatest common divisor using BinaryGCD algorithm.
    template <typename T>
    inline T __gcd(T m, T n) {
      m = std::abs(m);
      n = std::abs(n);

      if (m == 0)
        return n;

      if (n == 0)
        return m;

      T k = 0;
      T t = m | n;
      while ((t & 1) == 0) {
        t >>= 1;
        ++k;
      }
      m >>= k;
      n >>= k;

      while ((m & 1) == 0)
        m >>= 1;

      do {
        while ((n & 1) == 0)
          n >>= 1;

        if (m > n)
          std::swap(m, n);

        n -= m;
      } while (n != 0);

      return m << k;
    }

  } // namespace Numeric

} // namespace Algorithms
