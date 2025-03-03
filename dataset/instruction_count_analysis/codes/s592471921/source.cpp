#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cctype>

using namespace std;

typedef long long int64;

inline int read(int f = 1, int x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

const int N = 4e3+5;

int n, x, a[N], q[N], l, r;

int64 ans;

int main()

{

    n = read(), x = read(); 

    for(int i = 1; i <= n; ++i) a[i] = read(), a[i+n] = a[i];

    for(int k = 0; k < n; ++k)

    {

        int64 s = 1ll*k*x; l = 1, r = 0;

        for(int i = 1; i <= k; ++i)

        {

            while(l <= r&&a[q[r]] >= a[i]) --r;

            q[++r] = i;

        } 

        for(int i = k+1; i <= n+k; ++i) 

        {

            while(l <= r&&i-k > q[l]) ++l;

            while(l <= r&&a[q[r]] >= a[i]) --r; 

            q[++r] = i; s += a[q[l]];

        }

        ans = k?min(s, ans):s;

    }

    printf("%lld\n", ans);

    return 0;

}