#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int N=100005;

struct node{

    int u,v,nxt;

}edge[N*2];

int head[N],mcnt;

void add_edge(int u,int v){

    mcnt++;

    edge[mcnt].u=u;

    edge[mcnt].v=v;

    edge[mcnt].nxt=head[u];

    head[u]=mcnt;

}

int n,k,a[N],deep[N],ans;

void dfs(int u)

{

	for(int i=head[u];i;i=edge[i].nxt)

	{

		int v=edge[i].v;

		dfs(v);

		deep[u]=max(deep[u],(deep[v]+1)%k);

		if(u!=1&&deep[v]==k-1)

            ans++;

	}

}

int main()

{

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

        scanf("%d",&a[i]);

	if(a[1]!=1)

        ans++;

	for(int i=2;i<=n;i++)

        add_edge(a[i],i);

	dfs(1);

	printf("%d\n",ans);

}
