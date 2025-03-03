#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

#define MAXN 131100

#define LL long long

#define INF 40000000000

struct node

{

	LL in,out;

	node(LL _in=0,LL _out=0){in=_in,out=_out;}

};

vector<node>dp[MAXN],tmp1,tmp2;

LL lim;

void vector_merge(vector<node>&G,vector<node>&l,vector<node>&r)

{

	G.clear();

	int s1=l.size(),s2=r.size(),p1=0,p2=0;

	if(s2==0) return;

	while(p1<s1)

	{

		while(p2<s2&&l[p1].out+r[p2].in<=lim) p2++;

		if(p2) p2--;

		if(l[p1].out+r[p2].in<=lim) G.push_back(node(l[p1].in,r[p2].out));

		p1++;

	}

}

void Insert(vector<node>&G,node &x)

{

	int k=G.size();

	if(k==0) G.push_back(x);

	else if(G[k-1].out>x.out) G.push_back(x);

}

void merge_sort(vector<node>&G,vector<node>&l,vector<node>&r)

{

	G.clear();

	int s1=l.size(),s2=r.size(),p1=0,p2=0;

	while(p1!=s1||p2!=s2)

	{

		if(p1==s1) Insert(G,r[p2++]);

		else if(p2==s2) Insert(G,l[p1++]);

		else if(l[p1].in<r[p2].in) Insert(G,l[p1++]);

		else Insert(G,r[p2++]);

	}

}

int d[MAXN],ch[MAXN][2],fa[MAXN],n;

LL dep[MAXN];

void dfs(int u)

{

	if(!d[u])

	{

		dp[u].clear();

		dp[u].push_back(node(dep[u],dep[u]));

		return;

	}

	int ls=ch[u][0],rs=ch[u][1];

	dfs(ls);

	dfs(rs);

	lim+=2*dep[u];

	vector_merge(tmp1,dp[ls],dp[rs]);

	vector_merge(tmp2,dp[rs],dp[ls]);

	merge_sort(dp[u],tmp1,tmp2);

	lim-=2*dep[u];

}

int main()

{

	scanf("%d",&n);

	for(int i=2;i<=n;i++)

	{

		scanf("%d%lld",&fa[i],&dep[i]);

		ch[fa[i]][d[fa[i]]++]=i;

		dep[i]+=dep[fa[i]];

	}

	LL l=0,r=INF,ans;

	while(l<r)

	{

		lim=(l+r)/2;

		dfs(1);

		if(dp[1].size()) r=lim,ans=lim;

		else l=lim+1;

	}

	printf("%lld\n",ans);

}