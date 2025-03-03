#include <cstdio>

#include <queue>

#include <cmath>

#include <algorithm>

#include <iostream>

#include <set>

#include <map>

#include <string>

#include <algorithm>

using namespace std;

#include <string>

#include <cstdio>

#define ll long long

#define TLE std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef pair<int,int> pii;

const ll mod = 1000000007 ;

const int INF=0x3f3f3f3f;

#define test(n) cout<<"Test "<<n<<endl;

#define pb push_back

#define rp(n) for(int i=1;i<=n;i++)

#define rep(n,m) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)

ll ksm(ll x,ll n){ll ans=1;while (n){if (n&1)ans=(ans*x)%mod;x=x*x%mod;n>>=1;}return ans;}

using namespace std;

double pi = atan(1.0)*4 ;

const int mxn = 1e3+7 ;

int n,t,m,k,l,r;

/// ll mat[mxn][mxn], prime[mxn], isprime[mxn];

ll phi[mxn];

string str;char ch[27][27] ;

int a[mxn][mxn];

ll exgcd(ll a,ll b, ll &x ,ll &y)

{

    if(!a&&!b) return -1;/// 无最大公约数

    if(!b) {x=1,y=0;return a;}

    ll d=exgcd(b,a%b,y,x);

    y-=a/b*x ;

    return d;

}

int vis[mxn][mxn];

int main()

{



    rep(3,3) vis[i][j] = 0 ;

    map<int,pair<int,int> >mp;

    rep(3,3) {cin>>a[i][j];mp[ a[i][j] ] = {i,j} ;}

    cin>>n;

    rp(n){ cin>>k;pair<int,int>tmp = mp[k];



    if(mp.find(k)!=mp.end() && tmp.first<=3 && tmp.second<=3 && tmp.first>0 && tmp.second>0)

        vis[ tmp.first ][ tmp.second ] = 1 ;

    }

    int f1 = 0 ;

    for(int i=1;i<=3;i++)

    {

        int ans = 0 ;

        for(int j=1;j<=3;j++)

            if(vis[i][j]==1)

                ans++;

        if(ans==3) {cout<<"Yes"<<endl;f1=1;break;}

    }

    if(!f1)

    {

        if(vis[1][1]&&vis[2][2]&&vis[3][3] || vis[1][3]&&vis[2][2]&&vis[3][1])

            {cout<<"Yes"<<endl;f1=1;}

    }

    if(!f1)

    {

        for(int i=1;i<=3;i++)

        {

            int ans = 0 ;

            for(int j=1;j<=3;j++)

                if(vis[j][i]==1)

                    ans++;

            if(ans==3) {cout<<"Yes"<<endl;f1=1;break;}

        }

    }

    if(!f1) cout<<"No"<<endl;

}


