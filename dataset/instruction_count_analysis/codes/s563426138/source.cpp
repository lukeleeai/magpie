#include"stdc++.h"

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define fr first

#define sc second

#define N 300009

#define inf 2e16

#define pi pair<ll,ll>

#define pb push_back

using namespace std;

typedef long long ll;

void slv()

{

}

vector<int>adj[N];

bool vis[N];

int dis[N];

void vfs(int s)

{

    queue<int>q;

    q.push(s);

    dis[s]=0;

    vis[s]=1;

    while (!q.empty())

    {

        int u=q.front();

        q.pop();

        for(auto v : adj[u])

        {

            if(!vis[v])

            {

                vis[v]=1;

                dis[v]=dis[u]+1;

                q.push(v);

            }

        }

    }

    

}

int main()

{

    ll n,x;

    cin>>n>>x;

    vector<ll>a(n+1,0);

    for(ll i=1;i<=n;i++) cin>>a[i];

    ll ans=0LL;

    for(ll i=1;i<=n;i++)

    {

        ll s=a[i]+a[i-1];

        if(s>x)

        {

            ans += s-x;

            a[i] = min(a[i],a[i]-(s-x));

        }

    }

    cout<<ans<<endl;

    return 0;

}
