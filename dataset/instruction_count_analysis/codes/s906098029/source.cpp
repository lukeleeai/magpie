/******************************************

* AUTHOR : RAJAGOPALAN *

* NICK : ARNO *

* INSTITUTION : VIT *

******************************************/

#include "stdc++.h"

#include <ext/pb_ds/detail/standard_policies.hpp>

#define ll long long

#define ull unsigned long long

#define pb push_back

#define mp make_pair

#define all(x) (x).begin(),(x).end()

#define alli(a, n, k) (a+k),(a+n+k)

#define FP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)

#define FS(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)

#define IT(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define eps 1e-6

#define pi 3.141592653589793

using namespace std;

using namespace __gnu_pbds;



template<class T> inline T gcd(T x, T y) { if (!y) return x; return gcd(y, x%y);}

typedef vector<int> VII;

typedef vector<ll> VLL;

typedef pair<int, int> PII;

typedef vector< pair<int, int> > VPII;

typedef vector< pair<int, PII > > VPPI;

const int MOD = 1e9 + 7;

const int INF = 1e9;



inline ll modulo(ll a, ll m)

{

    return (a % m + m) % m;

}



inline ll modInverse(ll a, ll m)

{

    assert(__gcd(a, m) == 1);

    ll m0 = m;

    ll y = 0, x = 1;



    if (m == 1)

        return 0;



    while (a > 1)

    {

        ll q = a / m;

        ll t = m;



        m = a % m, a = t;

        t = y;



        y = x - q * y;

        x = t;

    }



    if (x < 0)

        x += m0;



    return x;

}



inline ll modPow(ll x, ll y, ll m)

{ //x^y % m

    if (y == 0)

        return 1LL;

    else if (y == 1)

        return x;

    else

    {

        ll ans = modPow(x, y / 2, m) % m;

        if (y & 1)

        {

            return (((ans * ans) % m) * x) % m;

        }

        else

        {

            return (ans * ans) % m;

        }

    }

}



int main(int argc, char* argv[])

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int n;

    string s;

    cin>>n>>s;

    for(int i=0;i<s.size();++i)

    {

        s[i]=(s[i]-'A'+n)%26 +'A';

    }

    cout<<s;

    return 0;

}