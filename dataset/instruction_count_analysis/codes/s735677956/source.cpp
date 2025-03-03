#include"stdc++.h"

#define LL long long

using namespace std;

int q;

LL n,m;

const int N=105,mod=1e9+7;

vector<pair<LL,LL> >t[N];

LL f[N];

inline LL read()

{

	LL res = 0; char ch = getchar(); bool XX = false;

	for (; !isdigit(ch); ch = getchar())(ch == '-') && (XX = true);

	for (; isdigit(ch); ch = getchar())res = (res << 3) + (res << 1) + (ch ^ 48);

	return XX ? -res : res;

}

void YYCH()

{

	t[1].push_back(make_pair(1,2));

	t[1].push_back(make_pair(1,3));

	t[1].push_back(make_pair(1,4));

	f[0]=f[1]=1;

	for(int i=2;i<=100;++i)f[i]=f[i-1]+f[i-2];

	for(int i=1;i<=100;++i)

		for(int j=0,l=t[i].size()-1;j<=l;++j)

		{

			LL x=t[i][j].second,y=x+t[i][j].first;

			while(y<=f[i+3]+f[i])t[i+1].push_back(make_pair(x,y)),y+=x;

		}

}

signed main()

{

	YYCH();

	cin>>q;

	while(q--)

	{

		n=read();m=read();

		if(n>m)swap(n,m);

		int p=1;LL ans=0;

		while(f[p+1]<=n&&f[p+2]<=m)++p;

		printf("%d ",p);

		if(p==1){printf("%lld\n",n%mod*m%mod);continue;}

		for(int j=0,l=t[p-1].size()-1;j<=l;++j)

		{

			LL x=t[p-1][j].first,y=t[p-1][j].second;

			if(y<=n)(ans+=(m-x)/y)%=mod;

			if(y<=m)(ans+=(n-x)/y)%=mod;

		}

		printf("%lld\n",ans);

	}

	return 0;

}