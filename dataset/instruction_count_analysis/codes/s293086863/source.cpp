#include <cstdio>

#include <cstring>

#define Inf 0x7f7f7f7f

int dist[100005];

int head[100005],arrive[200005],nxt[200005],tot;

void add_edge(int from,int to){

	arrive[++tot]=to;

	nxt[tot]=head[from];

	head[from]=tot;

}

int mx(int a,int b){

	return a>b?a:b;

}

int mn(int a,int b){

	return a<b?a:b;

}

int left[100005],right[100005];

int father[100005];

bool visit[100005];

bool get_ans;

int ab(int a){

	return a<0?-a:a;

}

void dfs(int root){

	if(!get_ans){

		return;

	}

	left[root]=-Inf;

	right[root]=Inf;

	if(visit[root]){

		left[root]=right[root]=dist[root];

	}

	for(int i=head[root];i;i=nxt[i]){

		if(arrive[i]==father[root]){

			continue;

		}

		father[arrive[i]]=root;

		dfs(arrive[i]);

		if(!get_ans){

			return;

		}

		if(left[arrive[i]]>-Inf/2){

			if(left[root]<-Inf/2){

				left[root]=left[arrive[i]]-1;

				right[root]=right[arrive[i]]+1;

			}

			else{

				if((ab(left[arrive[i]])&1)==(ab(left[root])&1)){

					get_ans=0;

					return;

				}

				left[root]=mx(left[root],left[arrive[i]]-1);

				right[root]=mn(right[root],right[arrive[i]]+1);

				if(left[root]>right[root]){

					get_ans=0;

					return;

				}

			}

		}

	}

}

void find_ans(int root){

	if(!visit[root]){

		dist[root]=left[root];

	}

	for(int i=head[root];i;i=nxt[i]){

		if(arrive[i]==father[root]){

			continue;

		}

		if(!visit[arrive[i]]){

			if(dist[root]-1>=left[arrive[i]]&&dist[root]-1<=right[arrive[i]]){

				dist[arrive[i]]=dist[root]-1;

				visit[arrive[i]]=1;

			}

			else{

				dist[arrive[i]]=dist[root]+1;

				visit[arrive[i]]=1;

			}

		}

		find_ans(arrive[i]);

	}

}

int main(){

	int n;

	scanf("%d",&n);

	int u,v;

	for(int i=1;i<n;i++){

		scanf("%d%d",&u,&v);

		add_edge(u,v);

		add_edge(v,u);

	}

	int k;

	scanf("%d",&k);

	for(int i=1;i<=k;i++){

		scanf("%d%d",&u,&v);

		dist[u]=v;

		visit[u]=1;

	}

	get_ans=1;

	dfs(1);

	if(!get_ans){

		puts("No");

	}

	else{

		find_ans(1);

		puts("Yes");

		for(int i=1;i<=n;i++){

			printf("%d\n",dist[i]);

		}

	}

	return 0;

}
