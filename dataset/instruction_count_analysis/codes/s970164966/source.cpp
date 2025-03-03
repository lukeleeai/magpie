#include <algorithm>

#include <cctype>

#include <cstring>

#include <cstdio>

using namespace std;

inline int read(int f = 1, int x = 0, char ch = ' ')

{   

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

const int N = 2e5+5;

int n, m;

int a[N], b[N], cnt, ans;

int main()

{

    n = read(), m = read();

    for(int i = 1; i <= m; ++i) a[i] = read(), cnt += (a[i]&1);

    if(cnt > 2) return puts("Impossible"), 0;

    for(int i = 1; i <= m; ++i) if(a[i]&1) swap(a[i], a[1]), i = m;

    for(int i = 2; i <= m; ++i) if(a[i]&1) swap(a[i], a[m]);

    if(a[1] != 1) b[++ans] = a[1]-1;

    for(int i = 2; i < m; ++i) b[++ans] = a[i]; b[++ans] = n;

    for(int i = 1; i < ans; ++i) b[ans] -= b[i];

    for(int i = 1; i <= m; ++i) printf("%d ", a[i]); puts("");

    printf("%d\n", ans);

    for(int i = 1; i <= ans; ++i) printf("%d ", b[i]); puts("");

    return 0;

}