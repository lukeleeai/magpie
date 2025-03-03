#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int N=200005;

int n,m,t,p,ans;

int d[N],first[N],v[N],w[N],_next[N];

struct Node{

    int u,v;

}e[N];

void add(int x,int y)

{

	t++;

	_next[t]=first[x];

	first[x]=t;

	v[t]=y;

}

void dfs(int x,int father)

{

	int i,j;

	for(i=first[x];i;i=_next[i])

	{

		j=v[i];

		if(j==father)

		  continue;

		d[j]=d[x]+1;

		dfs(j,x);

	}

}

int main()

{

	int x,y,z,i,k,u;

	scanf("%d%d",&n,&k);

	m=k/2;

	ans=0x3f3f3f3f;

	for(i=2;i<=n;++i)

	{

		scanf("%d%d",&x,&y);

		e[i].u=x;

		e[i].v=y;

		add(x,y);

		add(y,x);

	}

	if ((k&1)==0){

		int res=0;

		for (int i=1;i<=n;i++){

			res = d[i] = 0;

			dfs(i,i);

            for (int j=1;j<=n;j++) if(d[j]>m) ++res;

            ans = min(ans,res);

		}

	}

	else{

		int res = 0;

       	for (int i=2;i<=n;i++){

            d[e[i].u] = d[e[i].v] = res = 0;

            dfs(e[i].u,e[i].v);

			dfs(e[i].v,e[i].u);

            for (int j=1;j<=n;j++) if(d[j]>m) ++res;

            ans = min(ans,res);

        }

	}

	printf("%d\n",ans);

	return 0;

}