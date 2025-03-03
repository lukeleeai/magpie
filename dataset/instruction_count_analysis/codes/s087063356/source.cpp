#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define MN 100005

using namespace std;

inline ll in(){

    ll x=0;bool f=0; char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

ll a[MN],n,mx,mn,x,y;

int main()

{

	n=in();

	for (int i=1;i<=n;++i) a[i]=in();a[n+1]=2ll;mn=mx=2ll;

	for (int i=n;i;--i){

		mx/=a[i];if (!mx) {printf("-1");return 0;}

		mx=(mx+1ll)*a[i]-1ll;

		if (mn%a[i]) mn=(mn/a[i]+1ll)*a[i];

	}x=mx,y=mn;

	for (int i=1;i<=n;++i){

		x-=(x%a[i]);y-=(y%a[i]);

	}if (x!=2||y!=2) {printf("-1");return 0;}

	printf("%lld %lld",mn,mx);return 0;

}