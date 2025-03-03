#include"stdc++.h"

#define rep(i,a,b) for(int i=(a);i<=(b);i++)

#define per(i,a,b) for(int i=(a);i>=(b);i--)

#define REP(i,n) for(int i=(0);i<(n);i++)

#define fi first

#define se second

#define pb push_back

#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

typedef vector<int> vi;

typedef long long ll;

typedef double ld;

 

template<class T> inline void read(T &x){

	int f=0;x=0;char ch=getchar();

	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');

	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';

	if(f)x=-x;

}



const int N=100005;

int fa[N],d[N],a[N],cur[N],c[N],tmp[N],ans[N];

int num,pos,cnt,s,t,n,m,u,v;

vi e[N];



void dfs(int u){

	for(auto v:e[u])

		if(v!=fa[u]){

			d[v]=d[u]+1;

			fa[v]=u,dfs(v);

		}

}



int cmp(int *a,int *b){

	rep(i,1,cnt)

		if(a[i]!=b[i])return a[i]<b[i];

	return 0;

}



int main(){

	read(n);

	rep(i,1,n-1){

		read(u),read(v);

		e[u].pb(v),e[v].pb(u);

	}

	fa[1]=0,d[1]=1,dfs(1);

	s=max_element(d+1,d+n+1)-d;

	fa[s]=0,d[s]=1,dfs(s);

	t=max_element(d+1,d+n+1)-d;

	a[++cnt]=t;

	while(a[cnt]!=s){

		int t=fa[a[cnt]];

		a[++cnt]=t;

	}

	rep(i,1,cnt)cur[a[i]]=i;

	rep(i,1,n)

		if(!cur[i]){

			if(a[cur[fa[i]]]!=fa[i])

				return puts("-1"),0;

			cur[i]=cur[fa[i]];

			++c[cur[i]];

		}

	memcpy(tmp,c,sizeof c);

	reverse(tmp+1,tmp+cnt+1);

	if(cmp(tmp,c))memcpy(c,tmp,sizeof tmp);

	rep(i,1,cnt){

		int tmp=++num;

		rep(j,1,c[i])

			ans[pos+j]=++num;

		pos+=c[i]+1;

		ans[pos]=tmp;

	}

	rep(i,1,n)printf("%d ",ans[i]);

	return 0;

}