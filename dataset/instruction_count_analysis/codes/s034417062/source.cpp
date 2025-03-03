#include <iostream>

#include <algorithm>

#include <cstring>

#include <cstdio>

using namespace std;

const int MAXN=1e5+10;

int num1[MAXN],num2[MAXN];

int T,n;

int head[MAXN],net[2*MAXN],u[2*MAXN],v[2*MAXN],tot;

int read()

{

	int f=0,w=1; char ch=getchar();

	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }

	while(ch>='0'&&ch<='9') { f=(f<<3)+(f<<1)+ch-'0'; ch=getchar(); }

	return f*w;

}

void add(int l,int r)

{

	u[++tot]=l; v[tot]=r; net[tot]=head[l]; head[l]=tot;

}

int vt[MAXN];

void dfs(int now,int step,int flag)

{

	vt[now]=1; 

	if(flag==1) num1[now]=step;

	if(flag==2) num2[now]=step;

	for(int i=head[now];i;i=net[i])

		if(vt[v[i]]==0)

			dfs(v[i],step+1,flag);

}

int main()

{

	//freopen("T3.in","r",stdin);

	//freopen("T3.out","w",stdout);

	T=1;

	while(T--)

	{

		n=read(); tot=0;

		memset(head,0,sizeof(head));

		memset(net,0,sizeof(net));

		memset(u,0,sizeof(u));

		memset(v,0,sizeof(v));

		memset(num1,0,sizeof(num1));

		memset(num2,0,sizeof(num2));

		for(int i=1;i<n;i++)

		{

			int l=read(),r=read();

			add(l,r);

			add(r,l);

		}

		memset(vt,0,sizeof(vt));

		dfs(1,0,1);

		memset(vt,0,sizeof(vt));

		dfs(n,0,2);

		int p1=0,p2=0;

		for(int i=1;i<=n;i++)

		{

			if(num1[i]<num2[i])

				p1++;

			if(num2[i]<num1[i])

				p2++;

			if(num1[i]==num2[i])

				p1++;

		}

		if(p1>p2) printf("Fennec\n");

		else printf("Snuke\n");

	}

}