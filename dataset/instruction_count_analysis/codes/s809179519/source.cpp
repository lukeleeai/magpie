#include "stdc++.h"

using namespace std;

const int N = 1e5+20 , SIZE = 1020 , Mod = 1e9+7;

int n,m,p[SIZE],a[SIZE],cnt,fac[2*N],inv[2*N],Max,ans;

inline int add(int x,int y) { return x + y >= Mod ? x + y - Mod : x + y; }

inline int mul(int x,int y) { return 1LL * x * y % Mod; }

inline void Add(int &x,int y) { x = add( x , y ); }

inline void Mul(int &x,int &y) { x = mul( x , y ); }

inline int quickpow(int a,int b) { int res = 1; for (;b;Mul(a,a),b>>=1) if ( 1 & b ) Mul(res,a); return res; }

inline int C(int a,int b) { return 1LL * fac[a] * inv[b] % Mod * inv[a-b] % Mod; }

int main(void)

{

    scanf("%d%d",&n,&m);

    int val = m;

    for (int i=2;i*i<=val;i++)

        if ( m % i == 0 )

        {

            p[++cnt] = i;

            while ( m % i == 0 )

                m /= i , Max = max( Max , ++a[cnt] );

        }

    if ( m > 1 ) p[++cnt] = m , Max = max( Max , a[cnt] = 1 );

    fac[0] = inv[0] = 1LL;

    for (int i=1;i<=n+Max;i++)

        fac[i] = mul( fac[i-1] , i );

    inv[n+Max] = quickpow( fac[n+Max] , Mod-2 );

    for (int i=n+Max-1;i>=1;i--)

        inv[i] = mul( inv[i+1] , i+1 );

    ans = 1LL;

    for (int i=1;i<=cnt;i++)

        ans = 1LL * ans * C( a[i] + n - 1 , n - 1 ) % Mod;

    printf("%d\n",ans);

    return 0;

}
