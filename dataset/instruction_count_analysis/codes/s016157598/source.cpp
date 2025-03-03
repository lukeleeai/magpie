#include <cstring>

#include <algorithm>

#include <cctype>

#include <cstdio>

using namespace std;

inline int read(int f = 1, int x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

const int N = 2e5+5;

int n, p[N], ans = 2;

bool valid(int mid)

{   

    for(int i = 0; i < n-1; ++i)

        if(max(p[n-i], p[n-i-1]) <= mid||max(p[n+i], p[n+i+1]) <= mid) return true;

        else if(min(p[n-i], p[n-i-1]) > mid||min(p[n+i], p[n+i+1]) > mid) return false;

    return p[1] <= mid;

}

int main()

{

    n = read();

    for(int i = 2*n-1; i; --i) p[i] = read();

    int l = 2, r = 2*n-2;

    while(l <= r)

    {

        int mid = (l+r)>>1;

        if(valid(mid)) r = mid-1, ans = mid;

        else l = mid+1;

    }

    printf("%d\n", ans);

    return 0;

}
