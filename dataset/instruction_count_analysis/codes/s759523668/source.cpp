/*ANKON GHOSH

  KUET,ECE 2K16*/

#include"stdc++.h"

using namespace std;

#define ll long long

#define inf 1e18

#define MAX 3100

#define mod 1000000007

#define sf(a) scanf("%lld",&a)

#define sff(a,b) scanf("%lld %lld",&a,&b)

#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define Case(i) cout<<"Case #"<<i<<": "

#define pf(a) printf("%lld\n",a)

#define pfsn printf("NO\n")

#define pfs  printf("YES\n")

#define pff(a,b) printf("%lld %lld\n",a,b)

#define pfff(a,b,c) printf("%lld %lld %lld\n",a,b,c)

#define pffff(a,b,c,d) printf("%lld %lld %lld %lld\n",a,b,c,d)

#define FOR(i,n) for(ll i=0;i<n;i++)

#define FOR1(i,n) for(ll i=1;i<=n;i++)

#define LOOP(x,y) for(ll r=x;r<=y;r++)

#define RFOR(i,n) for(ll i=n-1;i>=0;i--)

#define RFOR1(i,n) for(ll i=n;i>0;i--)

#define RLOOP(x,y) for(ll i=y;i>=x;i--)

#define m_p(a,b) make_pair(a,b)

#define p_b(a) push_back(a)

#define ff first

#define ss second

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

map<ll,ll>mp1,mp;

vector<pair<ll,pair<ll,ll> > >vpp,vpp1;

vector<pair<ll,ll> >vp,fin;

vector<ll>v1,v2,dummy;

map<pair<ll,ll>,bool>mbb;

map<ll,bool>mb;

vector<double>v;

ll n,k,a,b,c,d,ta,sum=0,cnt=0,m,l,req,sz,maxi;

bool sortbysec(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)

{

    return (a.second < b.second);

}

///vector<pair<ll,ll> >adj[MAX+10];

double dp[MAX][MAX];

double calc(ll pos,ll nisi)

{

    if(pos>=n)

    {

        if(nisi>=req) return 1.0;

        else return 0.0;

    }

    else if(dp[pos][nisi]!=-1.0) return dp[pos][nisi];

    double r1=0.00,r2=0.0;

    double head=v[pos];

    double tail=1.00-v[pos];

    r1+=(calc(pos+1,nisi+1)*head);

    r2+=(calc(pos+1,nisi)*tail);

    ///visited[pos][nisi]=true;

    return dp[pos][nisi]=r1+r2;

}

int main()

{

    sf(n);

    req=(n+2)/2;

    FOR(i,n)

    {

         FOR(j,n) dp[i][j]=-1.0;

    }

    FOR(i,n)

    {

        double a;

        scanf("%lf",&a);

        v.p_b(a);

    }

    double ans=calc(0,0);

    printf("%.10lf",ans);

    return 0;

}
