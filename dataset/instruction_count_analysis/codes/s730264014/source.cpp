#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define N 100005

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

ll n,tot,ans1,ans2,a[N];

int main(){

	n=read();

	rep(i,1,n) a[i]=read();

	sort(a+1,a+1+n);

	for (ll l=1,r=1;l<=n;l=++r){

		while (a[l]==a[r+1]) ++r;

		if (r-l+1>=2) ans2=ans1,ans1=a[l];

		if (r-l+1>=4) ans2=ans1,ans1=a[l];

	}

	printf("%lld",ans1*ans2);

}