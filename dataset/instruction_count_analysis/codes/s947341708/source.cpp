// This amazing code is by Eric Sunli Chen.

#include <algorithm>

#include <bitset>

#include <cmath>

#include <cstring>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <set>

#include <string>

#include <utility>

#include <vector>

using namespace std;

template<typename T> bool get_int(T &x)

{

	char t=getchar();

	bool neg=false;

	x=0;

	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());

	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;

	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';

	if(neg)x=-x;return true;

}

template<typename T> void print_int(T x)

{

	if(x<0)putchar('-'),x=-x;

	short a[20]= {},sz=0;

	while(x>0)a[sz++]=x%10,x/=10;

	if(sz==0)putchar('0');

	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);

}

#define ff first

#define ss second

#define pb push_back

#define mp make_pair

#define get1(a) get_int(a)

#define get2(a,b) (get1(a)&&get1(b))

#define get3(a,b,c) (get1(a)&&get2(b,c))

#define printendl(a) print_int(a),puts("")

typedef long long LL;

typedef unsigned long long uLL;

typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;

const LL Linf=1ll<<61;

const double pi=acos(-1.0);





struct Bitset

{

	unsigned a[64];

	void reset(){memset(a,0,sizeof(a));}

	Bitset(){reset();}

	void flip(int x){a[x>>5]^=1u<<(x&31);}

	void set(int x){a[x>>5]|=1u<<(x&31);}

	void reset(int x){a[x>>5]&=~(1u<<(x&31));}

	int test(int x){return (a[x>>5]>>(x&31))&1;}

	Bitset operator ~()const

	{

		Bitset ret;

		for(int i=0;i<64;i++)ret.a[i]=~a[i];

		return ret;

	}

	Bitset operator &(const Bitset &b)const

	{

		Bitset ret;

		for(int i=0;i<64;i++)ret.a[i]=a[i]&b.a[i];

		return ret;

	}

	Bitset operator |(const Bitset &b)const

	{

		Bitset ret;

		for(int i=0;i<64;i++)ret.a[i]=a[i]|b.a[i];

		return ret;

	}

	Bitset operator ^(const Bitset &b)const

	{

		Bitset ret;

		for(int i=0;i<64;i++)ret.a[i]=a[i]^b.a[i];

		return ret;

	}

	Bitset operator <<(const int t)const

	{

		Bitset ret;

		unsigned last=0;

		int high=t>>5,low=t&31;

		for(int i=0;i+high<64;i++)

		{

			ret.a[i+high]=last|(a[i]<<low);

			if(low)last=a[i]>>(32-low);

		}

		return ret;

	}

	Bitset operator >>(const int t)const

	{

		Bitset ret;

		unsigned last=0;

		int high=t>>5,low=t&31;

		for(int i=64-1;i>=high;i--)

		{

			ret.a[i-high]=last|(a[i]>>low);

			if(low)last=a[i]<<(32-low);

		}

		return ret;

	}

	int popcount()

	{

		int ret=0;

		for(int i=0;i<64;i++)ret+=__builtin_popcount(a[i]);

		return ret;

	}

	void ones(vector<int>&ret)const

	{

		ret.clear();

		for(int i=0;i<64;i++)

		{

			unsigned tmp=a[i];

			while(tmp)

			{

				int t=__builtin_ctz(tmp);

				ret.pb(t|(i<<5));

				tmp^=1u<<t;

			}

		}

	}

};



Bitset con[2333],good;

int n,a[2333],tot,cmp[2333],q[2333];

bool ok[2333];

pii best;



int f[2333],last[2333];

int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

pii getcomp()

{

	memset(cmp,0,sizeof(cmp));

	tot=0;best=mp(0,0);pii now;

	for(int i=1;i<=n;i++)

	{

		if(!ok[i]||cmp[i])continue;

		tot++;now=mp(inf,inf);

		Bitset all;all.set(i);

		int front=0,rear=1;q[0]=i;

		vector<int> newv;

		for(;front<rear;front++)

		{

			int x=q[front];cmp[x]=tot;

			if(last[x]==0||__gcd(last[x],a[x])>1)now=min(now,mp(a[x],x));

			(con[x]&~all).ones(newv);all=all|con[x];

			for(auto v:newv)q[rear++]=v;

		}

		best=max(best,now);

	}

	return best;

}

int ans[2333];

int main()

{

	srand((unsigned int)time(NULL));

	get1(n);

	for(int i=1;i<=n;i++)

	{

		get1(a[i]);

		f[i]=i;

	}

	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&__gcd(a[i],a[j])>1)

	{

		con[i].set(j);f[gf(i)]=gf(j);

	}

	for(int i=1;i<=n;i++)ok[i]=1;

	for(int i=1;i<=n;i++)

	{

		pii now=getcomp();

		ok[now.ss]=0;for(int j=1;j<=n;j++)con[j].reset(now.ss);

		for(int j=1;j<=n;j++)if(cmp[now.ss]==cmp[j])last[j]=now.ff;

		ans[i]=now.ff;

	}

	for(int i=1;i<=n;i++)printf("%d ",ans[i]);

	puts("");

//	for(int i=1;i<n;i++)if(ans[i]<ans[i+1]&&__gcd(ans[i],ans[i+1])==1)puts("baojing");

	return 0;

}