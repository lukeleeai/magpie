#include <cstdio>

#include <cstdint>

#include <cmath>



intmax_t f(intmax_t b, intmax_t n) {

  if (n < b)

    return n;



  return f(b, n/b) + n%b;

}



int main() {

  intmax_t n, s;

  scanf("%jd %jd", &n, &s);



  if (s == n)

    return !printf("%jd\n", n+1);



  intmax_t sqrtn=sqrt(n);

  for (intmax_t b=2; b<=sqrtn; ++b)

    if (f(b, n) == s)

      return !printf("%jd\n", b);



  for (intmax_t p=sqrtn; p>0; --p) {

    intmax_t b=(n-s)/p+1;

    if (b < 2) continue;

    if (f(b, n) == s)

      return !printf("%jd\n", b);

  }



  printf("-1\n");

}
