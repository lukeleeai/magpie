#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll int

#define N 305

#define rep(i,j,k) for (ll i=j;i<=k;++i)

#define per(i,j,k) for (ll i=j;i>=k;--i)

using namespace std;

inline ll read(){

	char ch=getchar(); ll x=0,f=1;

	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }

	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }

	return x*f;

}

ll n,m,ans,a[N][N],now[N],flag[N],tmp[N];

int main(){

	n=ans=read(); m=read();

	rep(i,1,n) rep(j,1,m) a[i][j]=read();

	rep(i,1,n) now[i]=1;

	rep(T,1,m-1){

		rep(i,1,n) while (flag[a[i][now[i]]]) ++now[i];

		ll num=0; memset(tmp,0,sizeof tmp);

		memset(tmp,0,sizeof tmp);

		rep(i,1,n) ++tmp[a[i][now[i]]];

		rep(i,1,m) if (tmp[i]>tmp[num]) num=i;

		ans=min(ans,tmp[num]); flag[num]=1;

	}

	printf("%d",ans);

}