#include"stdc++.h"

using namespace std;

#define endl '\n'

#define pb push_back

#define mp make_pair

#define SZ(x) ((int)(x).size())

#define all(x) x.begin(),x.end()

#define mem0(s) memset(s,0,sizeof(s))

#define meminf(s) memset(s,0x3f,sizeof(s))

#define mp_insert(a,b,c) mp.insert(map<pair<int,int>,int>::value_type(make_pair(a,b),c))

//double pi=acos(-1);

typedef long long ll;

typedef unsigned long long ull;

inline ll lowbit(ll x){return x&(-x);}

inline ll min(ll a,ll b){return a<b?a:b;}

inline ll max(ll a,ll b){return a>b?a:b;}

const int INF=0x3f3f3f3f,max_n=200005;

inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

inline ll pow(ll a,ll b,ll mod){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int n,p;

char s[max_n];

int u[max_n];

ll ans[10005];

ll ans1;

int main()

{

	cin>>n>>p;

	cin>>s+1;

	if(p==2)

	{

		for(int i=n;i>=1;i--)

		{

			if((s[i]-'0')%p==0)

			{

				ans1+=i;

			}

		}

		cout<<ans1<<endl;

	}

	else if(p==5)

	{

		for(int i=n;i>=1;i--)

		{

			if((s[i]-'0')%p==0)

			{

				ans1+=i;

			}

		}

		cout<<ans1<<endl;

	}

	else

	{

		u[n+1]=0;

		ans[0]++;

		for(int i=n;i>=1;i--)

		{

			if(i==n)

			{

				u[i]=(s[n]-'0')%p;

				ans[u[i]]++;

			}

			else

			{

				u[i]=((s[i]-'0')%p*pow(10,n-i,p)%p+u[i+1])%p;

				ans[u[i]]++;

			}

		}

		for(int i=0;i<10001;i++)

		{

			ans1+=ans[i]*(ans[i]-1)/2;

		}

		cout<<ans1;

	}

    return 0;

}