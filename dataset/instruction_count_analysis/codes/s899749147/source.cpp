#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#include<algorithm>

#include<queue>

#include<set>

#include<map>

#include<iostream>

using namespace std;

#define ll long long

#define REP(a,b,c) for(int a=b;a<=c;a++)

#define re register

#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

typedef pair<int,int> pii;

#define mp make_pair

inline int gi()

{

	int f=1,sum=0;char ch=getchar();

	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}

	return f*sum;

}

const int N=110;

int n,x,D,p[N],v[N],id[N];

ll m[N],f[N*N*N];

void upt(ll m,int val){for(int i=n*n*n;i>=val;i--)f[i]=min(f[i],f[i-val]+m);}

bool cmp(int x,int y){return 1ll*m[y]*v[x]>1ll*m[x]*v[y];}

int main()

{

	n=gi();x=gi();D=gi();m[1]=gi();

	for(int i=2;i<=n;i++){m[i]=gi();p[i]=gi();}

	for(int i=1;i<=n;i++)v[i]=1,id[i]=i;

	for(int i=n;i>1;i--)m[p[i]]+=m[i],v[p[i]]+=v[i];

	memset(f,63,sizeof(f));f[0]=0;//package

	for(int i=1;i<=n;i++)

	{

		int lim=1,ret=(i==1)?n:min(n,D);

		while(ret>=lim)

		{

			ret-=lim;upt(1ll*m[i]*lim,1ll*lim*v[i]);lim<<=1;

		}

		upt(1ll*m[i]*ret,1ll*ret*v[i]);

	}

	int ans=0;sort(id+1,id+n+1,cmp);

	for(int i=0;i<=n*n*n;i++)

		if(f[i]<=x)

		{

			int res=x-f[i],sum=i;

			for(int j=1;j<=n;j++)

			{

				int del=(id[j]==1)?res/m[1]:min(max(0ll,(ll)D-n),res/m[id[j]]);

				sum+=v[id[j]]*del;

				res-=del*m[id[j]];

			}

			ans=max(ans,sum);

		}

	printf("%d\n",ans);

	return 0;

}
