#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define N 100005

#define rep(i,j,k) for (ll i=j;i<=k;++i)

#define per(i,j,k) for (ll i=j;i>=k;--i)

using namespace std;

inline ll read(){

	char ch=getchar(); ll x=0,f=1;

	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }

	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }

	return x*f;

}

ll n,m,sum,ans,a[N],b[N],c[N];

int main(){

	n=read(); m=read();

	rep(i,1,n) a[i]=read();

	rep(i,1,n-1){

		if (a[i+1]>a[i]){

			sum+=a[i+1]-a[i];

			b[a[i]+1]+=a[i]+1;

			b[a[i+1]+1]-=a[i]+1;

			++c[a[i]+1]; --c[a[i+1]+1];

		}else{

			sum+=m-a[i]+a[i+1];

			b[1]-=m-(a[i]+1); b[a[i+1]+1]+=m-(a[i]+1);

			b[a[i]+1]+=a[i]+1;

			++c[1]; --c[a[i+1]+1]; ++c[a[i]+1];

		}

	}

	rep(i,1,m) b[i]+=b[i-1],c[i]+=c[i-1];

	rep(i,1,m) ans=max(ans,i*c[i]-b[i]);

	printf("%lld",sum-ans);

}