#include <iostream>



constexpr int MOD = 1e9 + 7;



constexpr long long exp(const int &a, const int &b) {

  // Calculate a ** b by binary exponentation

  long long ret  = 1;

  long long base = a;

  int exponent   = b;



  while (exponent) {

    if (exponent & 1) {

      ret *= base;

      ret %= MOD;

    }

    base *= base;

    base %= MOD;

    exponent >>= 1;

  }



  return ret;

}



constexpr long long binomial(const int &n, const int &r) {

  // Calculate binomial(n, r)

  //

  // to do this, we need to calculate these values:

  //  - n * (n-1) * (n-2) * ... * (n-r+1)

  //  - 1/r! (inverse of the r factorial)

  //

  // Calculate n * (n-1) * (n-2) * ... * (n-r+1) using for loop

  long long prod_r = 1;



  for (int i = n - r + 1; i <= n; i++) {

    prod_r *= i;

    prod_r %= MOD;

  }



  // Calculate a! using for loop

  long long r_factorial = 1;



  for (int i = 1; i <= r; i++) {

    r_factorial *= i;

    r_factorial %= MOD;

  }



  // Calculate 1/a! by Fermat's little theorem

  //

  // Fermat's little theorem:

  //   x^(p-2) = 1/x (mod p)

  constexpr int exponent    = MOD - 2;

  long long inv_r_factorial = exp(r_factorial, exponent);



  // Return binomial(n, a)

  return (prod_r * inv_r_factorial) % MOD;

}



int main() {

  // Input

  int n, a, b;

  std::cin >> n >> a >> b;



  // Want to calculate 2 ** n - binomial(n, a) - binomial(n, b) - 1

  //

  // Calculate 2 ** n

  long long two_to_the_n = exp(2, n);



  // Calculate binomial(n, a), binomial(n, b)

  long long binomial_n_a = binomial(n, a);

  long long binomial_n_b = binomial(n, b);



  // Output

  long long ans = (two_to_the_n - binomial_n_a - binomial_n_b - 1) % MOD;



  if (ans < 0)

    std::cout << ans + MOD << std::endl;

  else

    std::cout << ans << std::endl;

}