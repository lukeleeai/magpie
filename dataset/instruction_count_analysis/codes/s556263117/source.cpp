#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cctype>

using namespace std;

typedef long long int64;

inline int64 read(int f = 1, int64 x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

const int N = 1e5+5;

int n, q, top;

int64 d[N], s[N], f[N];

void solve(int64 p, int64 q)

{

    if(!p) return;

    int r = upper_bound(s+1, s+1+top, p)-s-1;

    if(!r) d[1] += q, d[p+1] -= q;

    else f[r] += p/s[r]*q, solve(p%s[r], q);

}

int main()

{

    s[++top] = n = read(), q = read(); 

    while(q--)

    {

        int64 m = read();

        while(top&&s[top] >= m) --top;

        s[++top] = m;

    }

    f[top] = 1; 

    for(int i = top; i >= 2; --i) 

        f[i-1] += s[i]/s[i-1]*f[i], solve(s[i]%s[i-1], f[i]);

    d[1] += f[1], d[s[1]+1] -= f[1];

    for(int i = 1; i <= n; ++i) printf("%lld\n", d[i] += d[i-1]);

    return 0;

}