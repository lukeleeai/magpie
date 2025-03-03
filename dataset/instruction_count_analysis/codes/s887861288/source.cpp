#include "stdc++.h"

using namespace std;

#define endl '\n'

#define pb push_back

#define mp make_pair

#define SZ(x) ((int)(x).size())

#define all(x) x.begin(),x.end()

#define mem0(s) memset(s,0,sizeof(s))

#define meminf(s) memset(s,0x3f,sizeof(s))

#define mp_insert(a,b,c) mp.insert(map<pair<int,int>,int>::value_type(make_pair(a,b),c))

double pi=acos(-1);

typedef long long ll;

typedef unsigned long long ull;

inline ll lowbit(ll x){return x&(-x);}

inline ll min(ll a,ll b){return a<b?a:b;}

inline ll max(ll a,ll b){return a>b?a:b;}

const int INF=0x3f3f3f3f,max_n=200005,mod=19260817;

inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

inline ll pow(ll a,ll b,ll mod){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

ll a[max_n],b[max_n];int x;

vector<int>v[max_n];

ll ans1;

int main()

{

	int n;cin>>n;

	for(int i=1;i<=n;i++)

	{

		cin>>x;

		a[i]=x+i;

		b[i]=i-x;

	}

	for(int i=1;i<=n;i++)

	{

		if(b[i]>=2&&b[i]<=199999)

		{

			v[b[i]].push_back(i);

		}

	}

	for(int i=1;i<=n;i++)

	{

		x=a[i];

		if(x>=2&&x<=199999)

		{

			if(v[x].size()!=0)

			{

				//¶þ·ÖµØÕÒµÚÒ»¸ö´óÓÚiµÄÊý×Ö

				int ll=upper_bound(v[x].begin(),v[x].end(),i)-v[x].begin();

				//cout<<ll<<endl;

				ans1+=v[x].size()-ll;

			}

		}

	}

	cout<<ans1<<endl;

    return 0;

}