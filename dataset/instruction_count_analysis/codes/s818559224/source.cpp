#include<cstdio>

#include<algorithm>

using namespace std;

const int maxn=55,maxm=2500;

struct edge{

	int link,next;

}e[maxm];

int head[maxn],tot,n,m;

inline void insert(int u,int v){

	e[++tot]=(edge){v,head[u]}; head[u]=tot;

}

inline void ins(int u,int v){

	insert(u,v); insert(v,u);

}

inline void init(){

	scanf("%d%d",&n,&m);

	for (int i=1;i<=m;i++){

		int u,v;

		scanf("%d%d",&u,&v);

		ins(u,v);

	}

}

bool instack[maxn];

int ans,tim,cnt,dfn[maxn],stack[maxn],top,low[maxn];

inline void pop(){

	instack[stack[top--]]=0;

}

void tarjan(int u,int fa){

	dfn[u]=low[u]=++tim; stack[++top]=u; instack[u]=1;

	for (int i=head[u];i;i=e[i].next){

		int v=e[i].link;

		if (v!=fa){

			if (!dfn[v]){

				tarjan(v,u);

				low[u]=min(low[u],low[v]);

			}else{

				if (instack[u]){

					low[u]=min(low[u],dfn[v]);

				}

			}

			if (low[v]>dfn[u]){

				ans++;

				while (stack[top]!=v){

					pop();

				}

				pop();

			}

		}else{

			fa=0;

		}

	}

}

inline void solve(){

	tarjan(1,0);

	printf("%d\n",ans);

}

int main(){

	init();

	solve();

	return 0;

}