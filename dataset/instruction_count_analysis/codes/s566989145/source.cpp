#include"stdc++.h"

#define ll long long

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)<(b)?(a):(b))

#define swap(x,y) (x^=y^=x^=y)

inline int read()

{

	int x=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}

	return x*f;

}

#define MN 100005

#define mod 1000000007

int ans,x[MN],y[MN];

int cnt,a[MN],b[MN],B[MN],id[MN];

inline bool cmp(const int&o,const int&oo){return a[o]==a[oo]?b[o]<b[oo]:a[o]<a[oo];}

int t[MN],s[MN];

void C(int x,int v){for(;x<MN;x+=(x&-x))(t[x]+=v)%=mod;}

int G(int x){int r=0;for(;x;x-=(x&-x))(r+=t[x])%=mod;return r;}

int main()

{

	register int i,j,n,m;

	n=read(),m=read();

	for(i=1;i<=n;++i) x[i]=read();

	for(j=1;j<=m;++j) y[j]=read();

	std::sort(x+1,x+n+1);std::sort(y+1,y+m+1);

	for(i=1;i<=n;++i)

	{

		int p=std::lower_bound(y,y+m+1,x[i])-y;

		if(p<=1||p>m||x[i]==y[p]) continue;

		a[++cnt]=x[i]-y[p-1];B[cnt]=b[cnt]=y[p]-x[i];id[cnt]=cnt;

	}

	std::sort(B+1,B+cnt+1);

	int Bcnt=std::unique(B+1,B+cnt+1)-B-1;

	for(i=1;i<=cnt;i++) b[i]=std::lower_bound(B+1,B+Bcnt+1,b[i])-B;

	std::sort(id+1,id+cnt+1,cmp);

	for(i=1,j=1;i<=cnt;++i)

	{

		if(a[id[i]]==a[id[i-1]]&&b[id[i]]==b[id[i-1]]) continue;

		for(;a[id[j]]<a[id[i]];++j) if(a[id[j]]!=a[id[j-1]]||b[id[j]]!=b[id[j-1]]) C(b[id[j]],s[j]%mod);

		s[i]=1+G(b[id[i]]-1);

		(ans+=(s[i]%mod))%=mod;

	}

	printf("%d\n",ans+1);

	return 0;

}