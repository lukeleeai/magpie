#pragma GCC optimize(1)

#pragma GCC optimize(2)

#pragma GCC optimize(3)

#pragma GCC optimize(4)

#pragma comment(linker, "/STACK:1024000000,1024000000")

#pragma GCC optimize("Os")

#pragma GCC optimize("Og")

#pragma GCC optimize("Ofast")

#pragma GCC target("avx,sse,sse2,sse3,ssse3,sse4")

#include <stdio.h>

inline char gc(){

	static char buf[100000],*p1=buf,*p2=buf;

	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;

}

#define gc getchar

inline long long read(){

	long long now=0;int f=0;register char c=gc();

	for(;c<48||c>57;c=='-'&&(f=1),c=gc());for(;c>47&&c<58;now=(now<<3)+(now<<1)+c-'0',c=gc());

	return f?-now:now;

}

#define Maxn 200005

long long n,d,a[Maxn],dpl[Maxn],dpr[Maxn],ans;

long long Min(long long x, long long y) { return (((y - x) >> (64 - 1)) & (x ^ y)) ^ x; }

signed main()

{

	n=read(),d=read();

	for (int i=0;i<n;++i) a[i]=read(),ans+=a[i];

	ans+=(n-1)*d;dpl[0]=a[0];dpr[n-1]=a[n-1];

	for (int i=1;i<n;++i) dpl[i]=Min(a[i],dpl[i-1]+d);

	for (int i=n-2;~i;--i) dpr[i]=Min(a[i],dpr[i+1]+d);

	for (int i=1;i<n-1;++i) ans+=Min(dpl[i],dpr[i]);

	printf("%lld\n",ans);

	return 0;

}