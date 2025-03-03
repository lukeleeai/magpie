#include"stdc++.h"

using namespace std;

#define int long long

const int mod=1e9+7;

const int N=2e5+5;

int n,A,B,cnt,ans1,ans2,num,c[N],w[N],jc[N],inv[N],fa[N],a[N],id[N],sum[N],xu[N];

vector<int>b[N];

struct node{

	int val,id;

}xjh[N];

char buf[1<<21],*p1=buf,*p2=buf;

inline int gc()

{

	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;

}

inline int read()

{

	int res=0,f=0;

	char c;

	c=gc();

	while(!isdigit(c))

	{

		if(c=='-')f=1;

		c=gc();

	}

	while(isdigit(c))

	{

		res=res*10+c-48;

		c=gc();

	}

	if(f)return -res;

	else return res;

}

int find(int x)

{

	if(fa[x]==x)return x;

	fa[x]=find(fa[x]);

	return fa[x];

}

int kuai(int a,int b)

{

	if(b==1)return a;

	int x=kuai(a,b/2);

	if(b%2==0)return x*x%mod;

	else return x*x%mod*a%mod;

}

bool cmp(node a,node b)

{

	return a.val<b.val;

}

signed main()

{

	n=read();A=read();B=read();

	for(int i=1;i<=n;i++)

	{

		c[i]=read(),w[i]=read();

		xu[i]=c[i];

	}

	sort(xu+1,xu+n+1);

	int len=unique(xu+1,xu+n+1)-xu-1;

	for(int i=1;i<=len;i++)xjh[i].val=1e18;

	for(int i=1;i<=n;i++)

	{

		c[i]=lower_bound(xu+1,xu+len+1,c[i])-xu;

		if(xjh[c[i]].val>w[i])

		{

			xjh[c[i]].val=w[i];

			xjh[c[i]].id=i;

		}

	}

	for(int i=1;i<=n;i++)fa[i]=i;

	for(int i=1;i<=n;i++)

		if(w[i]+xjh[c[i]].val<=A)fa[find(i)]=xjh[c[i]].id;

	sort(xjh+1,xjh+len+1,cmp);

	for(int i=1;i<=n;i++)

		if(c[i]!=c[xjh[1].id]&&w[i]+xjh[1].val<=B)fa[find(i)]=xjh[1].id;

	for(int i=1;i<=n;i++)

		if(c[i]==c[xjh[1].id]&&w[i]+xjh[1].val<=A)fa[find(i)]=xjh[1].id;

	for(int i=1;i<=n;i++)

		if(c[i]==c[xjh[1].id]&&w[i]+xjh[2].val<=B)fa[find(i)]=xjh[1].id;

	jc[0]=1ll;

	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;

	inv[1]=1ll;

	for(int i=2;i<=n;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;

	for(int i=2;i<=n;i++)inv[i]=inv[i]*inv[i-1]%mod;

	for(int i=1;i<=n;i++)

	{

		if(!a[find(i)])

		{

			id[find(i)]=++cnt;

			a[find(i)]=1;

		}

		sum[id[find(i)]]++;

		b[id[find(i)]].push_back(c[i]);

	}

	for(int i=1;i<=cnt;i++)sort(b[i].begin(),b[i].end());

	ans1=1ll;

	for(int i=1;i<=cnt;i++)

	{

		ans2=jc[sum[i]];

		num=1ll;

		for(int j=1;j<sum[i];j++)

			if(b[i][j]!=b[i][j-1])

			{

				ans2=ans2*inv[num]%mod;

				num=1ll;

			}

			else num++;

		

		ans2=ans2*inv[num]%mod;

		ans1=ans1*ans2%mod;

	}

	cout<<ans1;

	return 0;

}

/*

3 7 5

1 3

1 4

2 2

*/