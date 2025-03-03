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

ll n,x,x0,x1,x2;

int main(){

	n=read();

	rep(i,1,n){

		x=read();

		if (x%2) ++x0;

		else if (!(x%4)) ++x2;

		else ++x1;

	}

	if (!x1) puts(x2>=x0-1?"Yes":"No");

	else puts(x2>=x0?"Yes":"No");

}