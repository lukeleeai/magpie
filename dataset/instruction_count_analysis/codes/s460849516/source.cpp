#include <cstdio>

#include <cstring>

#include <algorithm>

void Unused(...) {}

#ifndef DEBUG

  #define echo(...) Unused(__VA_ARGS__)

#else

  #define echo(...) fprintf(stderr, __VA_ARGS__)

#endif



typedef long long laolin;



const int MaxN = int(1e5) + 7;



int n, k;



int main()

{

    scanf("%d %d", &n, &k);

    laolin ans = n / k;

    laolin ano = 0;

    if (k % 2 == 0)

        ano = n / k + (n % k >= k / 2);

    printf("%lld\n", ans * ans * ans + ano * ano * ano);

    return 0;

}



/*

 * given a, then:

 *  - a + b %=k 0 => b = sk - a

 *  - a + c %=k 0 => c = tk - a

 *  - b + c %=k 0 => (s+t-p)k = 2a

 */


