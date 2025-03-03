#include"stdc++.h"

using namespace std;



#define y1 as214

#define ii pair < int , int >

#define iii pair < int , ii >

#define iv pair < ii , ii >



#define fi first

#define se second

#define fr front()

#define pb push_back

#define t top()



#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define FORD(i , x , n) for(int i = x ; i >= n ; --i)



#define ll long long

#define oo 1e17



const int N = 3e3 + 5;

const int VAL = 1e5 + 5;

int n , m , k , mod = 1e9 + 7;

ll fact[2 * VAL] , dp[N] , g[2 * VAL];

ii a[N];



int mulmod(int a , int b)

{

    return (1LL * a * b) % mod;

}



void mult(ll &a , int b)

{

    a = (1LL * a * b) % mod;

}



void addmod(ll &a , int b)

{

    a = (a + b) % mod;

}



void subtract(ll &a , int b)

{

    a = (((a - b) % mod + mod) % mod);

}



int powmod(ll a , int b)

{

    ll res = 1;

    while(b)

    {

        if(b & 1)

            mult(res , a);

        mult(a , a);

        b >>= 1;

    }

    return res;

}



inline int C(int n , int k)

{

    return mulmod(fact[n] , mulmod(g[k] , g[n - k]));

}



main()

{

    //freopen("Y.inp","r",stdin);

    ios::sync_with_stdio(0);

    cin >> n >> m >> k;

    fact[0] = 1;

    FOR(i , 1 , n + m)

        fact[i] = mulmod(fact[i - 1] , i);

    g[n + m] = powmod(fact[n + m] , mod - 2);

    FORD(i , n + m - 1 , 0)

        g[i] = mulmod(g[i + 1], i + 1);

    FOR(i , 1 , k)

        cin >> a[i].fi >> a[i].se;

    sort(a + 1 , a + 1 + k);

    FOR(i , 1 , k)

    {

        dp[i] = (C(a[i].fi + a[i].se - 2 , a[i].fi - 1));

        FOR(j , 1 , i - 1)

            if(a[j].fi <= a[i].fi && a[j].se <= a[i].se)

                addmod(dp[i] , mulmod(-dp[j] , C(a[i].fi - a[j].fi + a[i].se - a[j].se , a[i].fi - a[j].fi)));

    }

    ll res = C(n + m - 2 , n - 1);

    FOR(i , 1 , k)

        subtract(res , mulmod(dp[i] , C(n - a[i].fi + m - a[i].se , n - a[i].fi)));

    cout << res;

}
