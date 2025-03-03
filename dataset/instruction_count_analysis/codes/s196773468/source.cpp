#include"stdc++.h"

#define p_ pair<int,int>

#define mp_ make_pair

#define ll long long

#define pb push_back

#define fi first

#define se second

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define show1(a) cout<<#a<<" = "<<a<<endl

#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl

using namespace std;

const ll INF = 1LL<<60;

const int inf = 1<<30;

const int maxn = 2e5+5;

inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int n,m,a[maxn];

vector<int> g[maxn];

int main()

{

    fastio();

    cin>>n>>m;

    rep(i,1,n) cin>>a[i];

    rep(i,1,m) {int u,v;cin>>u>>v;g[u].pb(v),g[v].pb(u);}

    int ans = 0;

    rep(i,1,n){

        int sz = g[i].size();

        int flag = 1;

        for(int v:g[i]) if(a[v]>=a[i]) {flag=0;break;}

        if(flag) ans++;

    }

    cout<<ans<<endl;

    return 0;

}
