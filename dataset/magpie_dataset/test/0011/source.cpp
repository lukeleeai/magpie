#include"stdc++.h"

using namespace std;

typedef		long long       ll;

typedef		vector<ll>      vll;

#define     fi              first

#define     se              second

#define		pb              push_back

#define		nn              "\n"

#define		all(p)          p.begin(),p.end()

#define		zz(v)           (ll)v.size()

#define 	S(a)            scanf("%lld",&a)

#define 	SS(a,b)         scanf("%lld %lld",&a,&b)

#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)

#define		ss              ' '

#define     pii             pair<ll,ll>

const double eps = 1e-8;



ll ar[100010];

ll dp[100010];

ll n,k;

ll solve(ll i)

{

    if(i==n)

        return 0;

    if(i>n)

        return INT_MAX;



    if(dp[i]!=-1)

        return dp[i];

    ll arr[k+10],sz=0;

    for(ll step = 1; step<=k; ++step)

    {

        if(i+step<=n)

        {

            arr[sz++]=abs(ar[i]-ar[i+step])+solve(i+step);

        }

        else

            break;

    }

    ll mn=INT_MAX;

    for(ll x=0; x<sz; x++)

        mn=min(mn,arr[x]);

    return dp[i]=mn;



}



int main()

{

    memset(dp,-1,sizeof(dp));

    cin>>n>>k;

    for(ll i=1; i<=n; i++)

        cin>>ar[i];

    cout<<solve(1);



}












