

#include<math.h>

#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



const int maxn = 100009;

long long n, A, B, h[maxn];

long long l = 0, r = 9e18, mid;



bool check(long long x)

{

    long long res = 0;

    for (long long i=1; i<=n; i++)

        if (h[i] > B*x)

            res+= (int)ceil(h[i]-B*x+A-B-1)/(A-B);

    return res <= x;

}

int main()

{

    scanf("%lld%lld%lld", &n, &A, &B);

    for (long long i=1; i<=n; i++) scanf("%lld", &h[i]);

    while (l < r)

    {

        mid = (l+r) >> 1;

        if (check(mid)) r = mid;

        else l = mid + 1;

    }

    printf("%lld\n", l);

    return 0;

}


