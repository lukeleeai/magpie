#include"stdc++.h"

#define int long long

using namespace std;

const int N=4e5+10;

int a[N],b[N];

int ta[N],tb[N];

int dp[N],fa[N];

int n,m,ans;

int find(int x){

	return fa[x]==x?x:fa[x]=find(fa[x]);

}

signed main(){

	scanf("%lld",&n);

	for(int i=1;i<=n;++i){

		scanf("%lld",&a[i]);

		a[n+1]^=a[i];

		ta[i]=a[i];

	}

	for(int i=1;i<=n;++i){

		scanf("%lld",&b[i]);

		b[n+1]^=b[i];

		tb[i]=b[i];

	}

	++n;

	ta[n]=a[n];tb[n]=b[n];

	sort(ta+1,ta+n+1);sort(tb+1,tb+n+1);

	for(int i=1;i<n;++i)

		if(ta[i]!=tb[i]){

			printf("-1");

			return 0;

		}

	for(int i=1;i<=n;++i) 

		if(a[i]!=b[i]||i==n){

			dp[++m]=a[i];

			dp[++m]=b[i];

			if(i<n)++ans;

		}

	if(!ans){

		printf("0");

		return 0;

	}

	sort(dp+1,dp+m+1);

	m=unique(dp+1,dp+m+1)-dp-1;

	for(int i=1;i<=m;++i)

		fa[i]=i;

	for(int i=1;i<=n;++i)

		if(a[i]!=b[i]){

			a[i]=lower_bound(dp+1,dp+m+1,a[i])-dp,

			b[i]=lower_bound(dp+1,dp+m+1,b[i])-dp;

			fa[find(a[i])]=find(b[i]);

		}

	for(int i=1;i<=m;++i)

		if(fa[i]==i)

			++ans;

	printf("%lld",ans-1);

	return 0;

}