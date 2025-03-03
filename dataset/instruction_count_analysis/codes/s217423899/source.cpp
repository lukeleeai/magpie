#include <cstdio>

#include <algorithm>

#include <cstring>

#include <map>

#define Maxn 1000008 

using namespace std;

typedef long long ll;



int n,cnt,tot;

ll imp;

int U[Maxn],V[Maxn];

ll d;

bool vis[Maxn];

int son[Maxn],head[Maxn];

map <ll,int> M;



struct node{

	int num;

	ll val;

}N[Maxn];



struct edge{

	int to,next;

}E[Maxn];



void adde(int u,int v)

{

	E[tot].to = v;

	E[tot].next = head[u];

	head[u] = tot++;

}



void dfs(int u,ll val)

{

	imp += val,vis[u] = 1;

	for(int i = head[u];~i;i = E[i].next)

	{

		int v = E[i].to;

		if(vis[v]) continue;

		dfs(v,val+1);

	}

}



bool cmp(node a,node b){	return a.val > b.val;}



int main()

{

	memset(vis,0,sizeof(vis));

	memset(head,-1,sizeof(head));

	memset(son,0,sizeof(son));

	scanf("%d",&n);

	for(int i = 1;i <= n;i ++)

	{

		scanf("%lld",&d);

		M[d] = i;

		N[i].num = i,N[i].val = d;

	}

	sort(N+1,N+1+n,cmp);

	map<ll,int>::iterator iter;;

	for(int i = 1;i < n;i ++)

	{

		int u = N[i].num;

		iter = M.find(N[i].val - n + 2 + (son[u] << 1));

		if(iter == M.end())

		{

			printf("-1\n");

			return 0;

		}

		int v = iter->second;

		son[v] += son[u]+1;

		adde(u,v);adde(v,u);

		U[cnt] = u,V[cnt++] = v;

	}

	dfs(N[n].num,0);

	if(N[n].val != imp){	printf("-1\n");return 0;}

	for(int i = 0;i < cnt;i ++) printf("%d %d\n",U[i],V[i]);

	return 0;

}
