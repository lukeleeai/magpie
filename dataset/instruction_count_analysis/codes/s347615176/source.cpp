#include"stdc++.h"

#define ll long long

using namespace std;

ll n,m,sum[200001],f[200001],cnt,q[200001];

void solve(ll x,ll y){

	if(!x)return;

	ll now=upper_bound(q+1,q+cnt+1,x)-q-1;

	if(!now)sum[1]+=y,sum[x+1]-=y;

	 else{

	 	f[now]+=x/q[now]*y;

	 	solve(x%q[now],y);

	 }

}

int main(){

	ll i,t;

	scanf("%lld%lld",&n,&m);

	cnt=1;q[1]=n;

	for(i=1;i<=m;i++){

		scanf("%lld",&t);

		while(cnt&&t<=q[cnt])cnt--;

		q[++cnt]=t;

	}

	f[cnt]=1;

	for(i=cnt;i>1;i--)f[i-1]+=q[i]/q[i-1]*f[i],solve(q[i]%q[i-1],f[i]);

	sum[1]+=f[1];sum[q[1]+1]-=f[1];

	for(i=1;i<=n;i++)printf("%lld\n",sum[i]+=sum[i-1]);

}