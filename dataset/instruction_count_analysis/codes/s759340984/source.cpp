#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int mod=1000000007;

inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}

inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}

inline int kpow(int a,long long b)

{

	int s=1;

	for(;b;b>>=1,a=1ll*a*a%mod)

		if(b&1)s=1ll*s*a%mod;

	return s;

}

int n,m;

long long k;

char mp[1010][1010];

struct matrix

{

	int a[2][2];

	friend matrix operator * (matrix a,matrix b)

	{

		static matrix c;

		#define calc(i,j) (1ll*a.a[i][0]*b.a[0][j]+1ll*a.a[i][1]*b.a[1][j])%mod

		for(int i=0;i<2;++i)

			for(int j=0;j<2;++j)

				c.a[i][j]=calc(i,j);

		return c;

		#undef calc

	}

}t,s;

int main()

{

	scanf("%d %d %lld",&n,&m,&k);

	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);

	for(int i=1;i<=n;++i)

		for(int j=1;j<=m;++j)

			mp[i][j]=mp[i][j]=='#';

	bool flag1=0,flag2=0;

	for(int i=1;i<=n;++i)if(mp[i][1]&&mp[i][m])flag1=1;

	for(int i=1;i<=m;++i)if(mp[1][i]&&mp[n][i])flag2=1;

	if((flag1&&flag2)||k==0)return printf("1"),0;

	int c0=0,c1=0,c2=0;

	for(int i=1;i<=n;++i)

		for(int j=1;j<=m;++j)

		{

			c0+=mp[i][j];

			if(mp[i][j]&&mp[i][j+1])++c1;

			if(mp[i][j]&&mp[i+1][j])++c2;

		}

	--k;

	if(!flag1&&!flag2)return printf("%d",kpow(c0,k)),0;

	s.a[0][0]=1;

	if(flag1)

	{

		t.a[0][0]=c0,t.a[0][1]=c1;

		for(int i=1;i<=n;++i)if(mp[i][1]&&mp[i][m])++t.a[1][1];

		for(;k;k>>=1,t=t*t)if(k&1)s=s*t;

	}

	else

	{

		t.a[0][0]=c0,t.a[0][1]=c2;

		for(int i=1;i<=m;++i)if(mp[1][i]&&mp[n][i])++t.a[1][1];

		for(;k;k>>=1,t=t*t)if(k&1)s=s*t;

	}

	printf("%d",pl(s.a[0][0],mod-s.a[0][1]));

	return 0;

}