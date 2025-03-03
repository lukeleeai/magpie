#include "stdc++.h"

#define ull unsigned long long

#define ll long long

#define endl '\n'

#define pb push_back

#define mod 1000000007

#define mp make_pair

#define pi acos(-1)

#define line cout<<"----------------------------"<<endl

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

#define filein freopen("input.txt","r",stdin)

#define fileout freopen("output.txt","w",stdout)

using namespace std;

const ll mx=200009;	

vector<int> v[mx]; 

ll ans[mx];

int n,m; 

ll upor[mx]; 

void dfs(int s, int par)

{

	ans[s]=1;

	for(auto x: v[s])

	{

		if(x==par) continue; 

		dfs(x,s);

		ans[s]*=ans[x]+1;

		ans[s]%=m;

	}

}

void dfs1(int s, int par)

{

	vector<ll> pre((int)v[s].size()+5),suf((int)v[s].size()+5);

	pre[0]=1; 

	for(int i=1;i<=(int)v[s].size();i++)

	{

		int x=v[s][i-1] ;

		pre[i] =pre[i-1];

		if(x==par) continue; 

		pre[i]*=(ans[x]+1); 

		pre[i]%=m; 

	}

	suf[(int)v[s].size()+1]=1; 

	for(int i=(int)v[s].size();i>0;i--)

	{

		suf[i]=suf[i+1] ; 

		int x=v[s][i-1] ; 

		if(x==par) continue; 

		suf[i]*=(ans[x]+1); 

		suf[i]%=m; 

	}

	upor[1]=1; 

	for(int i=1;i<=(int)v[s].size();i++)

	{

		int x=v[s][i-1]; 

		if(x==par) continue; 

		upor[x]=1; 

		upor[x]=(upor[x]*pre[i-1])%m; 

		upor[x]=(upor[x]*suf[i+1])%m; 

		upor[x]*=upor[s];  

		upor[x]++; 

		upor[x]%=m; 

		dfs1(x,s);

	}

}

int main()

{

	

	cin>>n>>m;

	for(int i=0;i<n-1;i++)

	{

		ll a,b; 

		cin>>a>>b;

		v[a].pb(b);

		v[b].pb(a);

	}

	dfs(1,-1);

	dfs1(1,-1);

	upor[1]=1; 

	for(int i=1;i<=n;i++) 

	{

		ans[i]=(ans[i]*upor[i])%m; 

		cout<<ans[i]<<endl; 

	}

}
