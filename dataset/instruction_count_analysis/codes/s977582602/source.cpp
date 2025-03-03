#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <vector>

#include <cstring>

#define SIZE 200005

#define INF 10000000000000000LL

 

using namespace std;

typedef long long int ll;

typedef pair <int,int> P;

typedef pair <ll,P> PP;

 

struct edge

{

	int to;

	ll cost;

	edge(int to=0,ll cost=0):to(to),cost(cost){}

};

struct UF

{

	int par[SIZE],rank[SIZE];

	

	void init(int n)

	{

		for(int i=0;i<n;i++)

		{

			par[i]=i;

			rank[i]=0;

		}

	}

	int find(int x)

	{

		if(par[x]==x) return x;

		return par[x]=find(par[x]);

	}

	void unite(int x,int y)

	{

		x=find(x);

		y=find(y);

		if(x==y) return;

		if(rank[x]<rank[y]) par[x]=y;

		else

		{

			par[y]=x;

			if(rank[x]==rank[y]) rank[x]++;

		}

	}

	bool same(int x,int y)

	{

		return find(x)==find(y);

	}

};

UF uf;

vector <edge> vec[SIZE];

ll X[SIZE];

int v1[SIZE],v2[SIZE];

ll d1[SIZE],d2[SIZE];

int id[SIZE],ch[SIZE];

int now_id;

 

void dfs(int v=0,int p=-1)

{

	id[v]=now_id++;

	d1[v]=d2[v]=INF;

	v1[v]=v2[v]=-1;

	for(int i=0;i<vec[v].size();i++)

	{

		edge e=vec[v][i];

		if(e.to!=p)

		{

			dfs(e.to,v);

			ll vl=d1[e.to]+e.cost;

			int vv=v1[e.to];

			if(vl>e.cost+X[e.to])

			{

				vl=e.cost+X[e.to];

				vv=e.to;

			}

			if(vl<d1[v])

			{

				swap(vl,d1[v]);

				swap(vv,v1[v]);

			}

		}

	}

	ch[v]=now_id;

}

void make(int v=0,int p=-1)

{

	for(int i=0;i<vec[v].size();i++)

	{

		edge e=vec[v][i];

		if(e.to!=p)

		{

			ll vl=d1[v]+e.cost;

			int vv=v1[v];

			if(id[e.to]<=id[vv]&&id[vv]<ch[e.to])

			{

				vl=d2[v]+e.cost;

				vv=v2[v];

			}

			if(vl>e.cost+X[v])

			{

				vl=e.cost+X[v];

				vv=v;

			}

			if(vl<d1[e.to])

			{

				swap(vl,d1[e.to]);

				swap(vv,v1[e.to]);

			}

			make(e.to,v);

		}

	}

}

int A[SIZE],B[SIZE];

ll C[SIZE];

int main()

{

	int n;

	scanf("%d",&n);

	for(int i=0;i<n;i++) scanf("%lld",&X[i]);

	for(int i=0;i<n-1;i++)

	{

		int a,b;

		ll c;

		scanf("%d %d %lld",&a,&b,&c);a--,b--;

		vec[a].push_back(edge(b,c));

		vec[b].push_back(edge(a,c));

		A[i]=a,B[i]=b,C[i]=c;

	}

	dfs();

	make();

	uf.init(n+2);

	ll ret=0;

	for(int i=0;i<n;i++)

	{

		if(v1[v1[i]]==i&&i<v1[i]) continue;

		ret+=d1[i]+X[i];

		uf.unite(i,v1[i]);

	}

	for(int i=0;i<n-1;i++)

	{

		if(!uf.same(A[i],B[i]))

		{

			ret+=min(X[A[i]],d1[A[i]]);

			ret+=min(X[B[i]],d1[B[i]]);

			ret+=C[i];

		}

	}

	printf("%lld\n",ret);

	return 0;

}