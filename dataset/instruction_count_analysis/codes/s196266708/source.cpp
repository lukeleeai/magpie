#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

#define x first

#define y second

#define mp make_pair

#define pb push_back

template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}

template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}

template <typename TYPE> void readint(TYPE &x)

{

    x=0;int f=1;char c;

    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;

    for(;isdigit(c);c=getchar())x=x*10+c-'0';

    x*=f;

}

const int MAXN=100005,MAXK=60;



int n,m;ll k;

ll a[MAXN];

int p[MAXN],anc[MAXN][MAXK];

ll res[MAXN];



int main()

{

	int x;

	readint(n);

	for(int i=1;i<=n;++i)readint(a[i]);

	readint(m),readint(k);

	for(int i=2;i<=n;++i)p[i]=i;

	for(int i=1;i<=m;++i)readint(x),swap(p[x],p[x+1]);

	for(int i=2;i<=n;++i)anc[i][0]=p[i];

	for(int j=1;j<MAXK;++j)

		for(int i=2;i<=n;++i)

			anc[i][j]=anc[anc[i][j-1]][j-1];

	for(int i=2;i<=n;++i)

	{

		x=i;

		for(int j=0;j<MAXK;++j)

			if(k&(1ll<<j))x=anc[x][j];

		res[i]=a[x]-a[x-1];

	}

	res[1]=a[1];

	for(int i=2;i<=n;++i)res[i]+=res[i-1];

	for(int i=1;i<=n;++i)printf("%lld\n",res[i]);

	return 0;

}