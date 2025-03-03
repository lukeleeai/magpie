#include<cstdio>

#include<algorithm>

typedef long long LL;

const int MAXN = 100000+10;

const int INF = 0x3f3f3f3f;

int n, t, e;

LL x[MAXN], f[MAXN];

int main(){

   // freopen("t.in", "r", stdin);

    scanf("%d%d%d", &n, &e, &t);

    for(int i=1; i<=n; ++i) scanf("%lld", &x[i]);

    int j=0;

    LL mn = 1e14;

    for(int i=1; i<=n; ++i){

        while((x[i]-x[j+1])*2>=t){

            mn = std::min(mn, f[j] - 2*x[j+1]);

            j++;

        }

        f[i] = std::min(f[j]+t, mn + 2*x[i]);

    }

    printf("%lld\n", f[n]+e);

    return 0;

}
