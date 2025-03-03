#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#define ll long long

using namespace std;



const int mod=1000000007;

const int N=100005;



int n,k,l,r,ans;

ll x,y;

int dp1[N],dp2[N],f[2][N],p1[N],p2[N];

ll a[N];



void add(bool b,int x,int y){

	for (;x<=n+2;x+=x&-x){

		f[b][x]+=y;

		(f[b][x]>=mod)?f[b][x]-=mod:0;

	}

}



int query(bool b,int x){

	int s=0;

	for (;x;x-=x&-x){

		s+=f[b][x];

		(s>=mod)?s-=mod:0;

	}

	return s;

}



int ask(bool b,int x,int y){

	int s;

	if (x>y) return 0;

	s=(query(b,y)-query(b,x-1)+mod)%mod;

	return s;

}



int main(){

	scanf("%d%lld%lld",&n,&x,&y);

	if (x>y) swap(x,y);

	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);

	l=r=n;

	for (int i=n;i>=1;i--){

		if (a[i+1]-a[i]<x) l=i;

		if (a[i+1]-a[i]<y) r=i;

		p1[i]=l;

		p2[i]=r;

	}

	for (int i=n;i>1;i--){

		if (p2[i]==n) dp1[i]=1;

		if (p1[i]==n) dp2[i]=1;

		

		l=lower_bound(a+1,a+1+n,a[i-1]+x)-a; l=max(l,i+1);

		r=p2[i]+1;

		dp1[i]+=ask(1,l,r);

		(dp1[i]>=mod)?dp1[i]-=mod:0;

		

		l=lower_bound(a+1,a+1+n,a[i-1]+y)-a; l=max(l,i+1);

		r=p1[i]+1;

		dp2[i]+=ask(0,l,r);

		(dp2[i]>=mod)?dp2[i]-=mod:0;

		

		add(0,i,dp1[i]);

		add(1,i,dp2[i]);

		if (p1[1]>=i-1) ans+=dp1[i];

		(ans>=mod)?ans-=mod:0;

		if (p2[1]>=i-1) ans+=dp2[i];

		(ans>=mod)?ans-=mod:0;

	}

	if (p1[1]==n) ans++;

	if (p2[1]==n) ans++;

	ans%=mod;

	printf("%d\n",ans);

	return 0;

}