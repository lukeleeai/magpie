#include <iostream>

#include <cstring>

#include <cstdio>

#define ll long long

#define int ll

#define lowbit(a) a&(-a)

using namespace std;



inline int read(){

	int sum=0,f=1;char c=getchar();

	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}

	while(c<='9'&&c>='0'){sum=sum*10+c-'0';c=getchar();}

	return f*sum;

}



const int N=200000;

const int M=100000;

int n,m,a[N+5];

ll t[N+5],c[N+5],tem;



inline void add(int x){for(;x<=N;x+=lowbit(x)) t[x]++;}



inline ll ask(int x){ll ret=0;for(;x;x-=lowbit(x)) ret+=t[x];return ret;}



inline int check(int x){

	ll cnt=0;

	memset(t,0,sizeof(t));

	for(int i=1;i<=n;i++) c[i]=c[i-1]+(a[i]<=x? 1:-1);

	add(1+M);

	for(int i=1;i<=n;i++){

		cnt+=ask(c[i]+M);

		add(c[i]+1+M);

	}

	return cnt>tem;

}



signed main(){

	n=read();

	for(int i=1;i<=n;i++) a[i]=read();

	ll l=0,r=0;

	for(int i=1;i<=n;i++) r=max(r,(ll)a[i]);

	ll ans=r;

	tem=n*(n+1)/2;tem/=2;

	while(l<=r){

	ll mid=(l+r)>>1;

	if(check(mid)) ans=min(ans,mid),r=mid-1;

	else l=mid+1;

}

	printf("%lld\n",ans);

	return 0;

}
