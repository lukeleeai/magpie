#include"stdc++.h"

#define ui unsigned int

#define ll long long

#define db double

#define ld long double

#define ull unsigned long long

#define ft first

#define sd second

#define pb(a) push_back(a)

#define PII std::pair<int,int>

#define PLL std::pair<ll,ll>

#define mp(a,b) std::make_pair(a,b)

#define ITR(a,b) for(auto a:b)

#define REP(a,b,c) for(register int a=(b),a##end=(c);a<=a##end;++a)

#define DEP(a,b,c) for(register int a=(b),a##end=(c);a>=a##end;--a)

const int Mod=998244353;

int type;

template<typename T> inline void read(T &x)

{

	T data=0,w=1;

	char ch=0;

	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();

	if(ch=='-')w=-1,ch=getchar();

	while(ch>='0'&&ch<='9')data=((T)data<<3)+((T)data<<1)+(ch^'0'),ch=getchar();

	x=data*w;

}

template<typename T> inline void write(T x,char ch='\0')

{

	if(x<0)putchar('-'),x=-x;

	if(x>9)write(x/10);

	putchar(x%10+'0');

	if(ch!='\0')putchar(ch);

}

template<typename T> inline bool chkmin(T &x,T y){return y<x?(x=y,true):false;}

template<typename T> inline bool chkmax(T &x,T y){return y>x?(x=y,true):false;}

template<typename T> inline T min(T x,T y){return x<y?x:y;}

template<typename T> inline T max(T x,T y){return x>y?x:y;}

namespace subt1{

	const int MAXN=100000+10;

	int n,m,a[MAXN],b[MAXN];

	std::vector<int> V[MAXN];

	struct Fenwick_Tree{

		int C[MAXN];

		inline int lowbit(int x)

		{

			return x&(-x);

		}

		inline void add(int x,int k)

		{

			while(x<=n)C[x]+=k,x+=lowbit(x);

		}

		inline int sum(int x)

		{

			int res=0;

			while(x>0)res+=C[x],x-=lowbit(x);

			return res;

		}

	};

	Fenwick_Tree T;

	inline bool nosolution()

	{

		REP(i,1,n)if(i<b[a[i]])return true;

		REP(i,1,m)if(i<a[b[i]])return true;

		return false;

	}

	inline void solve()

	{

		ll ans=1;

		read(n);read(m);

		REP(i,1,n)read(a[i]),V[a[i]].pb(i);

		REP(i,1,m)read(b[i]);

		if(nosolution())

		{

			puts("0");

			return ;

		}

		REP(i,1,m)

		{

			int mx=b[i];

			ITR(v,V[i])chkmax(mx,v),T.add(v,1);

			if(mx<=n)ans=1ll*ans*(T.sum(n)-T.sum(mx-1))%Mod;

		}

		write(ans,'\n');

	}

};

namespace subt2{

	const int MAXN=100000+10;

	int n,m,a[MAXN];

	std::vector<int> V[MAXN];

	struct Fenwick_Tree{

		int C[MAXN];

		inline int lowbit(int x)

		{

			return x&(-x);

		}

		inline void add(int x,int k)

		{

			while(x<=n)C[x]+=k,x+=lowbit(x);

		}

		inline int sum(int x)

		{

			int res=0;

			while(x>0)res+=C[x],x-=lowbit(x);

			return res;

		}

	};

	Fenwick_Tree T;

	inline ll C(int x)

	{

		return (1ll*x*(x-1)/2)%Mod;

	}

	inline void solve()

	{

		ll ans=1;

		read(n);read(m);

		REP(i,1,n)read(a[i]),V[a[i]].pb(i);

		REP(i,1,m)

		{

			int mx=1,mn=n;

			ITR(v,V[i])chkmax(mx,v),chkmin(mn,v),T.add(v,1);

			if(mx>=mn)ans=1ll*ans*(T.sum(n)-T.sum(mx-1))%Mod*T.sum(mn)%Mod;

			else ans=1ll*ans*(C(T.sum(n)+1)+1)%Mod;

		}

		write(ans,'\n');

	}

};

namespace subt3{

	const int MAXN=1<<15,MAXM=200+10;

	int r,c,n,m,rev[MAXN];

	ll pw[MAXN],ipw[MAXN],inv3,invn,fac[MAXN],inv[MAXN],a[MAXN],b[MAXN],f[MAXM][MAXN],cnt,ans;

	inline ll qexp(ll a,ll b)

	{

		ll res=1;

		while(b)

		{

			if(b&1)res=res*a%Mod;

			a=a*a%Mod;

			b>>=1;

		}

		return res;

	}

	inline void NTT(ll *A,int tp)

	{

		REP(i,0,n-1)if(i<rev[i])std::swap(A[i],A[rev[i]]);

		for(register int l=2;l<=n;l<<=1)

		{

			ll wn=tp>0?pw[l]:ipw[l];

			for(register int i=0;i<n;i+=l)

			{

				ll w=1;

				for(register int j=0;j<(l>>1);++j)

				{

					ll A1=A[i+j],A2=1ll*A[i+j+(l>>1)]*w%Mod;

					A[i+j]=(A1+A2)%Mod,A[i+j+(l>>1)]=(A1-A2+Mod)%Mod;

					w=1ll*w*wn%Mod;

				}

			}

		}

	}

	inline ll C(int n,int m)

	{

		if(n<m)return 0ll;

		return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;

	}

	inline void solve()

	{

		read(r);read(c);

		m=r+r+3;

		for(n=1,cnt=0;n<m;n<<=1,++cnt);

		REP(i,0,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));

		invn=qexp(n,Mod-2);inv3=qexp(3,Mod-2);

		for(register int l=1;l<=n;l<<=1)

			pw[l]=qexp(3,(Mod-1)/l),ipw[l]=qexp(inv3,(Mod-1)/l);

		fac[0]=1;

		REP(i,1,n+2)fac[i]=1ll*fac[i-1]*i%Mod;

		inv[n+2]=qexp(fac[n+2],Mod-2);

		DEP(i,n+1,0)inv[i]=1ll*inv[i+1]*(i+1)%Mod;

		REP(i,1,r)b[i]=inv[i+2];NTT(b,1);

		f[0][0]=1;

		REP(j,1,c)

		{

			REP(i,0,r)a[i]=1ll*inv[i]*f[j-1][i]%Mod;

			REP(i,r+1,n-1)a[i]=0;

			NTT(a,1);

			REP(i,0,n-1)a[i]=1ll*a[i]*b[i]%Mod;

			NTT(a,-1);

			REP(i,0,r)f[j][i]=1ll*a[i]*invn%Mod*fac[i+2]%Mod;

			REP(i,0,r)(f[j][i]+=1ll*f[j-1][i]*(C(i+1,2)+1)%Mod)%=Mod;

		}

		REP(i,0,r)(ans+=1ll*f[c][i]*C(r,i)%Mod)%=Mod;

		write(ans,'\n');

	}

};

int main()

{

	subt3::solve();

	return 0;

}
