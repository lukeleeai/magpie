#include <set>

#include <map>

#include <deque>

#include <queue>

#include <stack>

#include <cmath>

#include <ctime>

#include <bitset>

#include <cstdio>

#include <string>

#include <vector>

#include <cstdlib>

#include <cstring>

#include <cassert>

#include <iostream>

#include <algorithm>

#define mem(a,b) memset(a,b,sizeof (a))

#define gcd(a,b) __gcd(a,b)

#define all(a) a.begin(),a.end()

#define in(a) insert(a)

#define sz() size()

#include<cstdlib>

#define endl '\n'

#define pb push_back

using namespace std;

typedef long long ll;

const int maxn=100010;

const ll inf=1e18;

const ll mod=1e9+7;

const double pi=3.14159265358979;

const double ep=0.0;

vector<vector<pair<ll,ll>>>vec;

ll n,m;

void dfs(ll v,ll t,vector<ll>&d,vector<ll>&w)

{

    if (w[v]!=-1)

        return ;

    if (t==v)

    {

        w[v]=1;

        return ;

    }

    w[v]=0;

    for (auto i:vec[v])

    {

        ll u=i.first,r=i.second;

        if (d[u]+r==d[v])

        {

            dfs(u,t,d,w);

            w[v]=(w[v]+w[u])%mod;

        }

    }

}

void dij(ll s,vector<ll>&d,vector<ll>&w)

{

    d.resize(n,mod*mod);

    w.resize(n,-1);

    d[s]=0;

    set<pair<ll,ll>>se;

    se.insert({d[s],s});

    while (!se.empty())

    {

        ll v=se.begin()->second;

        se.erase(se.begin());

        for (auto i:vec[v])

        {

            ll u=i.first,r=i.second;

            if (d[u]>d[v]+r)

            {

                se.erase({d[u],u});

                d[u]=d[v]+r;

                se.insert({d[u],u});

            }

        }

    }

    for (ll i=0;i<n;i++)

        dfs(i,s,d,w);

}

int main()

{

    ll s,t;

    cin>>n>>m>>s>>t;

    s--;

    t--;

    vec.resize(n);

    for (ll i=0;i<m;i++)

    {

        ll v,u,w;

        cin>>v>>u>>w;

        v--;

        u--;

        vec[v].pb({u,w});

        vec[u].pb({v,w});

    }

    vector<ll>ds,ws,dt,wt;

    dij(s,ds,ws);

    dij(t,dt,wt);

    ll ans=ws[t]*wt[s],al=ds[t];

    for (ll i=0;i<n;i++)

    {

        if (ds[i]+dt[i]!=al)

            continue;

        if (ds[i]==dt[i])

            ans=(ans-ws[i]*wt[i]%mod*ws[i]%mod*wt[i]%mod+mod)%mod;

    }

    for (ll i=0;i<n;i++)

        for (auto j:vec[i])

        {

            ll u=j.first,w=j.second;

            if (ds[i]+dt[u]+w!=al)

                continue;

            if (w>abs(dt[u]-ds[i]))

                ans=(ans-ws[i]*wt[u]%mod*ws[i]%mod*wt[u]%mod+mod)%mod;

        }

    cout<<ans<<endl;

    return 0;

}
