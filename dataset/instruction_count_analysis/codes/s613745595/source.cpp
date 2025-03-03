#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<map>

using namespace std;

#define ll long long

#define MAX 100100

inline ll read()

{

	ll x=0;bool t=false;char ch=getchar();

	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();

	if(ch=='-')t=true,ch=getchar();

	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();

	return t?-x:x;

}

map<ll,int> M,vis;

int n,tot,ans;

ll a[MAX],b[MAX],p[MAX],pri[MAX];

int main()

{

	n=read();

	for(int i=1;i<=n;++i)a[i]=read();

	for(int i=2;i<=2500;++i)

	{

		bool fl=true;

		for(int j=2;j<i;++j)if(i%j==0){fl=false;break;}

		if(fl)pri[++tot]=i;

	}

	for(int i=1;i<=n;++i)

	{

		p[i]=b[i]=1;

		for(int j=1;j<=tot&&a[i]>1;++j)

			if(a[i]%pri[j]==0)

			{

				int cnt=0;

				while(a[i]%pri[j]==0)a[i]/=pri[j],++cnt;

				cnt%=3;if(!cnt)continue;

				if(cnt==1)p[i]*=1ll*pri[j]*pri[j],b[i]*=pri[j];

				else p[i]*=pri[j],b[i]*=1ll*pri[j]*pri[j];

			}

		if(a[i]==1)continue;

		ll s=sqrt(a[i]);b[i]*=a[i];

		if(s*s==a[i])p[i]*=s;

		else p[i]*=a[i]*a[i];

	}

	for(int i=1;i<=n;++i)++M[b[i]];

	for(int i=1;i<=n;++i)

	{

		if(vis[b[i]])continue;

		if(b[i]!=p[i])ans+=max(M[b[i]],M[p[i]]);

		else ans+=1;

		vis[b[i]]=vis[p[i]]=1;

	}

	printf("%d\n",ans);

	return 0;

}
