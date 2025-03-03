//bad_bat

#include"stdc++.h"

using namespace std;



#define Fast           ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)

#define FO             freopen("in.txt", "r", stdin)

#define FC             freopen("out.txt", "w", stdout)

#define aise           cout<<"aise"<<endl

#define pb             push_back

#define pf             push_front

#define ppb            pop_back

#define ppf            pop_front

#define mp             make_pair

#define ll             long long

#define all(x)         x.begin(), x.end()

#define mset(v, a)     memset(v, a, sizeof(v))

#define pll            pair< ll, ll >

#define pd             pair< double, double >

#define ff             first

#define ss             second

#define pi             acos(-1.0)

#define mxN            2010

#define inf            1e14

#define mod            1000000007

#define tc             ll tc;scanf("%lld",&tc);while(tc--)



//NCR iterative

/*voidcomb_table(intN)

{

    for(inti=0; i<=N; ++i)

    {

        for(intj=0; j<=i; ++j)

        {

            if(j==0or j==i)

            {

                C[i][j]=1LL;

            }

            else

            {

                C[i][j]=(C[i-1][j-1]+C[i-1][j]);

            }

        }

    }

}*/





//NCR recursive

/*ll dp[55][55];



ll NCR(ll n,ll r)

{



    if(n==r)

        return dp[n][r]=1;

    if(r==0)

        return dp[n][r]= 1;

    if(r==1)

        return dp[n][r]=n ;

    if(dp[n][r] != -1)

        return dp[n][r];

    return dp[n][r] = NCR(n-1,r)+NCR(n-1,r-1);

}*/



//Sieve:

/*bool Flag[1000010];

vector<ll> Prime;



void sieve()

{



    ll val=sqrt(1000010);

    for(ll i=4;i<=1000005; i+=2) Flag[i]=1;

    for(ll i=3;i <= val;i+=2)

    {



        if(Flag[i]==0)

        {



            for(ll j=i*i;j<=1000005;j+=i) Flag[j]=1;

        }

    }

    Flag[1]=1;

    for(ll i=1;i<=1000000;i++)

        if(Flag[i]==0) Prime.pb(i);

}*/





//Conversion

/*string bin(ll x)

{



    string ret;

    while(x)

    {



        ll t=x%2;

        char c;

        if(t==1)

            c='1';

        else

            c='0';

        ret.pb(c);

        x/=2;

    }

    reverse(all(ret));

    return ret;

}*/



/*ll lcm(ll x, ll y)

{



    ll ret=__gcd(x,y);

    return (x*y)/ret;

}*/



/*ll dx[]= {0,0,1,-1};

ll dy[]= {1,-1,0,0};*/



ll col[100010];

vector<pll> adj[100010];

bool vis[100010];



void dfs(ll nd, ll cl)

{



    vis[nd]=1;

    col[nd]=cl;

    ll rev;

    if(cl==1) rev=0;

    else rev=1;

    for(ll i=0;i<adj[nd].size();i++)

    {



        ll v=adj[nd][i].ff;

        ll dis=adj[nd][i].ss;

        if(vis[v]) continue;

        if(dis%2) dfs(v,rev);

        else dfs(v,cl);

    }

}



int main()

{



    ll n;

    cin >> n;

    vector<ll> v(n,0);

    for(ll i = 0; i < n; i++) cin >> v[i];

    ll ans = v[0];

    for(ll  i= 1; i < n; i++)

    {



        if(v[i-1] < v[i]) ans+=v[i]-v[i-1];

    }

    cout << ans;

}
