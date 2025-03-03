#include<cstdio>

#include<cstring>

#include<algorithm>

#include<map>

#define ll long long

#define N 200005

#define mod 1000000007

#define rep(i,j,k) for (ll i=j;i<=k;++i)

#define per(i,j,k) for (ll i=j;i>=k;--i)

using namespace std;

inline ll read(){

	char ch=getchar(); ll x=0,f=1;

	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }

	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }

	return x*f;

}

map<ll,ll>mp[N];

ll n,m;

int main(){

	n=read(); m=read();

	rep(i,1,m){

		ll u=read(),v=read();

		mp[u][v]=1; mp[v][u]=1;

	}

	rep(i,2,n-1) if (mp[1][i]&&mp[i][n]) return puts("POSSIBLE")&0;

	puts("IMPOSSIBLE");

}