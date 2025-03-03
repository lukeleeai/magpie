#include"stdc++.h"

using namespace std;

#define ll long long

const int N=55;

const int M=255;

inline ll read(){ll x=0,f=1;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-48;return x*f;}

inline void write(ll x){if(x>9)write(x/10);putchar('0'+x%10);}

inline void writeln(ll x){write(x);puts("");}

int head[N],tail[M],nxt[M],from[M];

bool b[M],vis[N];

int ans,n,m,t,x,y;

void addto(int x,int y)

{

	nxt[++t]=head[x];

	from[t]=x;

	head[x]=t;

	tail[t]=y;

}

void dfs(int k)

{

	vis[k]=true;

	for(int i=head[k];i;i=nxt[i]){

		if(b[i])continue;

		if(vis[tail[i]])continue;

		dfs(tail[i]);

	}

}

int main()

{

	n=read();m=read();

	for(int i=1;i<=m;i++){

		x=read();y=read();

		addto(x,y);

		addto(y,x);

	}

	ans=0;

	for(int i=1;i<=t;i+=2){

		b[i]=true;

		b[i+1]=true;

		memset(vis,false,sizeof(vis));

		dfs(1);

		b[i]=false;

		b[i+1]=false;

		for(int j=1;j<=n;j++)

			if(!vis[j]){

				ans++;

				break;

			}

	}

	writeln(ans);

}