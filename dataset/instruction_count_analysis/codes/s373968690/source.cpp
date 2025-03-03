#include <cstdio>

#include <algorithm>

#include <cmath>

#include <vector>



using namespace std;



using i64=long long;



i64 f(i64 b, i64 n) {

    return n<b? n:f(b, n/b)+(n%b);

}



int main() {

    i64 n, s;

    scanf("%lld %lld", &n, &s);



    if (n == s)

        return !printf("%lld\n", n+1);



    i64 ub=sqrt(n);

    for (i64 b=2; b<=ub; ++b)

        if (f(b, n) == s)

            return !printf("%lld\n", b);



    for (i64 p=ub+1; --p;) {

        i64 b=(n-s)/p+1;

        if (b < 2) continue;

        if (f(b, n) == s)

            return !printf("%lld\n", b);

    }



    return !printf("-1\n");

}
