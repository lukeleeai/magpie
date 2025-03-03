#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N = 5e5+1;

 

 

int n,fa[N],tot[N],fr[N],a[N],b[N],c[N],cnt,head[N];

 

struct nd{int ne,to;}e[N];

 

void in(int x,int y){e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;}

int w1[5001],q[N];

void dfs(int x)

{

	for(int i=head[x];i;i=e[i].ne)dfs(e[i].to);

	if(!fr[x])return;

	q[0]=0;

	int ret=tot[x],tot1=0;

	for(int i=head[x];i;i=e[i].ne)

	{

		ret-=min(a[e[i].to],b[e[i].to]);

		q[++q[0]]=abs(a[e[i].to]-b[e[i].to]);

		tot1+=a[e[i].to]+b[e[i].to];

	}

	if(ret<0){cout<<"IMPOSSIBLE";exit(0);}

memset(w1,0,sizeof(w1));

	w1[0]=x;

	for(int i=1;i<=q[0];++i)

	for(int t=5000;t>=q[i];--t)

	if(w1[t-q[i]]==x)w1[t]=x;

	for(int i=ret;i>=0;--i)

	if(w1[i]==x){ret-=i;break;}

	a[x]=tot[x];b[x]=tot1+ret-a[x];

	return;

}

 

int main()

{

	scanf("%d",&n);

	for(int i=2;i<=n;++i)

	scanf("%d",&fa[i]),in(fa[i],i),fr[fa[i]]++;

	for(int i=1;i<=n;++i)

	{

		scanf("%d",&tot[i]);

		if(!fr[i])a[i]=tot[i],b[i]=0;

	}

	dfs(1);

	cout<<"POSSIBLE";

 

 

}