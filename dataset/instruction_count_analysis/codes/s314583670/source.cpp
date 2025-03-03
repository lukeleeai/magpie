#include "stdc++.h"



using namespace std;



typedef long long ll;



const ll MOD = 1e9+7;



int n, m, k;

ll fac[900100];

ll fnv[900100];

ll f[600100];

ll p[600100];



ll po(ll a, ll n) {

    if (!n) return 1;

    ll t = po(a,n/2);

    return t*t%MOD*(n%2?a:1)%MOD;

}



ll comb(ll n, ll r) {

    if (r<0||r>n) return 0;

    return fac[n]*fnv[r]%MOD*fnv[n-r]%MOD;

}



int main() {

    int i;

    scanf("%d%d%d",&n,&m,&k);

    fac[0] = 1; for (i=1;i<=n+m+k;i++) fac[i]=fac[i-1]*i%MOD;

    for (i=0;i<=n+m+k;i++) fnv[i]=po(fac[i],MOD-2);

    f[m+k] = comb(m+k,m); for (i=m+k-1;i>=0;i--) f[i] = (MOD+1)/2*(f[i+1]+comb(i,i-m)+comb(i,k))%MOD;

    p[0] = 1; for (i=1;i<=m+k;i++) p[i]=p[i-1]*3%MOD;

    ll ans = 0;

    for (i=0;i<=m+k;i++) ans = ans+comb(n-1+i,n-1)*p[m+k-i]%MOD*f[i]%MOD;

    printf("%lld\n",ans%MOD);



    return 0;

}
