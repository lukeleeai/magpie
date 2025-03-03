#include "stdc++.h"



using namespace std;



typedef long long ll;

const ll maxn = 100010;

ll n,q,top,tn;

ll a[maxn],S[maxn],tong[maxn],ci[maxn],sum[maxn];

vector <pair<ll,ll> >V[maxn];



ll find(ll x)

{

    ll l = 1,r = top,res = 1;

    while (l <= r)

    {

        ll mid = (l + r) >> 1;

        if (S[mid] <= x)

        {

            res = mid;

            l = mid + 1;

        }

        else

            r = mid - 1;

    }

    return res;

}



int main()

{

    scanf("%lld%lld",&n,&q);

    tn = n;

    for (ll i = 1; i <= q; i++)

        scanf("%lld",&a[i]);

    S[++top] = n;

    for (ll i = 1; i <= q; i++)

    {

        while (top && S[top] >= a[i])

            top--;

        S[++top] = a[i];

    }

    n = S[1];

    V[1].push_back(make_pair(-n,1));

    for (ll i = 2; i <= top; i++)

    {

        ll x = S[i];

        ll cur = i - 1;

        while (x > n)

        {

            ll temp = x / S[cur];

            V[i].push_back(make_pair(cur,temp));

            x %= S[cur];

            cur = find(x);

        }

        if (x > 0 && x <= n)

            V[i].push_back(make_pair(-x,1));

    }

    ci[top] = 1;

    for (ll i = top; i >= 1; i--)

        for (ll j = 0; j < V[i].size(); j++)

        {

            ll u = V[i][j].first,v = V[i][j].second;

            if (u < 0)

                tong[-u] += v * ci[i];

            else

                ci[u] += v * ci[i];

        }

    for (ll i = 1; i <= n; i++)

        if (tong[i])

        {

            sum[1] += tong[i];

            sum[i + 1] -= tong[i];

        }

    for (ll i = 1; i <= n; i++)

        sum[i] += sum[i - 1];

    for (ll i = 1; i <= n; i++)

        printf("%lld\n",sum[i]);

    for (ll i = n + 1; i <= tn; i++)

        puts("0");



    return 0;

}
