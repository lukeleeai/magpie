#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int N=200005;

typedef long long ll;

int n,m,V,E,cnt[3],col[N];

bool vis[N],vise[N*2],colored;

ll ans;

struct node{

    int u,v,w,nxt;

}edge[N*2];

int head[N],mcnt=1;

void add_edge(int u,int v,int w){

    mcnt++;

    edge[mcnt].u=u;

    edge[mcnt].v=v;

    edge[mcnt].w=w;

    edge[mcnt].nxt=head[u];

    head[u]=mcnt;

}

void dfs(int u)

{

	V++; vis[u]=true;

	cnt[col[u]]++;

	for(int i=head[u];i;i=edge[i].nxt){

        if(vise[i|1])

            continue ;

        vise[i|1]=1,E++;

        int v=edge[i].v,w=edge[i].w;

        if(!vis[v]){

            col[v]=(col[u]+w+3)%3;

            dfs(v);

        }

		else if((col[u]+w+3)%3!=col[v])

            colored=true;

	}

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		add_edge(x,y,1);

		add_edge(y,x,-1);

	}

	for(int i=1;i<=n;i++)

		if(!vis[i])

		{

			V=E=cnt[0]=cnt[1]=cnt[2]=colored=0;

			dfs(i);

			if(colored)

                ans+=1ll*V*V;

			else

                if(!cnt[0]||!cnt[1]||!cnt[2])

                    ans+=1ll*E;

			else

			ans+=1ll*cnt[0]*cnt[1]+1ll*cnt[1]*cnt[2]+1ll*cnt[0]*cnt[2];

		}

	printf("%lld\n",ans);

}
