#include<cstdio>

#include<iostream>

#include<cstring>

#include<queue>

#include<map>

#define RG register

using namespace std;

const int N=1e5+10, M=2e5+10;

const long long mod=1e5+7;

struct dabt{

	int next,to,dis;

}e[M*6],hsh[M*2];

struct node{

	int u,dis;

	bool operator < (const node&x)const{return x.dis<dis;}

};

int n,m,head[N+2*M],k,dist[N+2*M],st[2*M],ed[2*M],cnt,kk;

int kh,h[mod+1];

bool vis[N+2*M];

template<typename I> inline void read(I &ot){

	I ch=getchar(), x=0, f=1;

	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}

	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}

	ot=x*f;}

template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}

inline void add(int from,int to,int d){

	e[++k]=(dabt){head[from],to,d}; head[from]=k;

	e[++k]=(dabt){head[to],from,d}; head[to]=k;

}

inline void adde(int from,int to,int d){hsh[++kh]=(dabt){h[from],to,d}; h[from]=kh;}

inline int id(int a,int b){

	int ss=((long long)a*n%mod+b)%mod;

	for(int i=h[ss];i;i=hsh[i].next)

	{

		int v=hsh[i].to;

		if(st[v]==a && ed[v]==b) return hsh[i].dis;

	}

	st[++kk]=a; ed[kk]=b;

	adde(ss,kk,++cnt);

	return cnt;

}

/*

map<pair<int,int>,int> P;

int id(int u,int c) {

    if(P.find(make_pair(u,c))!=P.end())

        return P[make_pair(u,c)];

    return P[make_pair(u,c)]=++cnt;

}*/

inline void dij()

{

	priority_queue<node> pn;

	while(!pn.empty()) pn.pop();

	for(int i=1;i<=n+m*2;i++) dist[i]=2e9;

	pn.push((node){1,0}); dist[1]=0;

	while(!pn.empty())

	{

		node u=pn.top(); pn.pop();

		int x=u.u; vis[x]=1;

		for(int i=head[x];i;i=e[i].next)

		{

			int v=e[i].to;

			if(dist[v]>dist[x]+e[i].dis)

			{

				dist[v]=dist[x]+e[i].dis;

				if(!vis[v]) pn.push((node){v,dist[v]});

			}

		}

	}

}

int main()

{

//	freopen("Snuke's Subway Trip.in","r",stdin);

//	freopen(". out","w",stdout);

	read(n,m); cnt=n;

	for(int i=1,a,b,c;i<=m;i++)

	{

		read(a,b,c);

		int id1=id(a,c), id2=id(b,c);

		add(a,id1,1); add(id1,id2,0); add(id2,b,1);

	}

	dij();

	printf("%d\n",dist[n]==2e9 ? -1 : dist[n]/2);

//	for(int i=1;i<=9;i++) printf("%d\n",dist[i]);

	//fclose(stdin); fclose(stdout);

	return 0;

}