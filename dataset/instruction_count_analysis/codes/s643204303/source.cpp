#include<algorithm>

#include<cstring>

#include<cctype>

#include<cstdio>

#define rep(i,x,y) for(int i=x; i<=y; ++i)



using namespace std;

const int N=100005;

int n,m,cnt,h[N],siz[N],fa[N],dep[N],x,y,a[N];

struct edge{int v,n;} e[N<<1];

typedef long long LL;

LL ans;



int getint()

{

	char ch;

	while(!isdigit(ch=getchar()));

	int x=ch-48;

	while(isdigit(ch=getchar())) x=x*10+ch-48;

	return x;

}



void addedge(int u,int v)

{

	e[cnt]=(edge){v,h[u]},h[u]=cnt++;

	e[cnt]=(edge){u,h[v]},h[v]=cnt++;

}



void dfs(int x,int f,int tp)

{

	siz[x]=tp,dep[x]=dep[f]+1,fa[x]=f;

	for(int i=h[x]; i!=-1; i=e[i].n)

		if(e[i].v!=f)

		{

			if(dep[e[i].v]) ::x=e[i].v,y=x;

			else dfs(e[i].v,x,-tp),siz[x]+=siz[e[i].v];

		}

}



int main()

{

	n=getint(),m=getint();

	memset(h,-1,sizeof(h));

	rep(i,1,m) addedge(getint(),getint());

	dfs(1,0,1);

	if(m==n-1)

	{

		if(siz[1]) return puts("-1"),0;

		rep(i,1,n) ans+=abs(siz[i]);

		return printf("%lld\n",ans),0;

	}

	if((dep[x]^dep[y])&1)

	{

		if(siz[1]) return puts("-1"),0;

		rep(i,1,n) ans+=abs(siz[i]);

		*a=1;

		while(x!=y) dep[x]>dep[y]?(a[++*a]=siz[x],ans-=abs(siz[x]),x=fa[x]):(a[++*a]=-siz[y],ans-=abs(siz[y]),y=fa[y]);

		int mid=(*a)+1>>1;

		nth_element(a+1,a+mid,a+1+*a);

		rep(i,1,*a) ans+=abs(a[i]-a[mid]);

		printf("%lld\n",ans);

	}

	else

	{

		if(siz[1]&1) return puts("-1"),0;

		int c=siz[1]>>1;

		ans=abs(c);

		while(x) siz[x]-=c,x=fa[x];

		while(y) siz[y]-=c,y=fa[y];

		rep(i,1,n) ans+=abs(siz[i]);

		printf("%lld\n",ans);

	}

	return 0;

}