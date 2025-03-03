#include"stdc++.h"

using namespace std;

#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)

#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)

typedef long long ll;

inline int read(){

    register int x=0,f=1;register char ch=getchar();

    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}

    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}

    return f?x:-x;

}



#define fail return puts("-1"),0;

const int N=1e5+5,inf=1e9;

const char ch[]="BW";

int n,m,d[N],num=1,head[N],w[N<<1],col[N],fa[N];

struct edge{int to,next,vis;} e[N<<2];

inline void add(int u,int v){

    e[++num]=(edge){v,head[u]},head[u]=num;

    e[++num]=(edge){u,head[v]},head[v]=num;

}



inline void dfs(int u){

    for(int i=head[u];i;i=e[i].next){

	int v=e[i].to;if(!e[i].vis||~col[v])continue;

	col[v]=1-col[u];dfs(v);

    }

}



int main(){

    //freopen("in.in","r",stdin);

//hao我瞎了

    n=read(),m=read();

    REP(i,1,n)d[i]=read();

    REP(i,1,m)add(read(),read()),w[i]=inf;

    REP(u,1,n){

	if(!head[u])fail;

	int p=head[u];

	for(int i=e[p].next;i;i=e[i].next){

	    if(d[e[i].to]<d[e[p].to])p=i;

	    else if(d[e[i].to]==d[e[p].to]&&e[i].to<e[p].to)p=i;

	}

	if(d[e[p].to]>d[u])fail;

	e[p^1].vis=1;w[p>>1]=d[u];fa[u]=e[p].to;

    }

    memset(col,-1,sizeof col);

    REP(i,1,n)if(fa[fa[i]]==i&&!~col[i])col[i]=0,dfs(i);

    REP(i,1,n)putchar(ch[col[i]]);

    puts("");

    REP(i,1,m)printf("%d\n",w[i]);

    return 0;

}
