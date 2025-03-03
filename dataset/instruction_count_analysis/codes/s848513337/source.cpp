// luogu-judger-enable-o2

#include <cstdio>

#include <algorithm>

using namespace std;

#define N 200005

#define M 200005

#define mid ((l+r)/2)

#define ls 2*rt

#define rs 2*rt+1

int head[M];

int cnt;

struct edge{ int des,next; }e[N];



void ins(int u,int v){ e[++cnt].des=v;  e[cnt].next=head[u];  head[u]=cnt; }





int n,m;

// 人数+r -( m+1 +l ) 

struct node{

	int l,r;

}a[N];



bool cmp(node a,node b){ return a.l<b.l; }



int maxn[M<<2],lazy[M<<2];



void pushup(int rt){ maxn[rt]=max(maxn[ls],maxn[rs]); }



void build(int rt,int l,int r){

	if(l==r){ maxn[rt]=l; return; }

	build(ls,l,mid);

	build(rs,mid+1,r);

	pushup(rt);

}





void pushdown(int rt){

	int t=lazy[rt];  lazy[rt]=0;

	lazy[ls]+=t;   lazy[rs]+=t;

	maxn[ls]+=t;   maxn[rs]+=t;

}



void update(int rt,int l,int r,int ll,int rr){

	if(l>=ll&&r<=rr){

		maxn[rt]+=1;

		lazy[rt]+=1;

		return;

	}

	if(lazy[rt])    pushdown(rt);

	if(ll<=mid)     update(ls,l,mid,ll,rr);

	if(rr>=mid+1)   update(rs,mid+1,r,ll,rr);

	pushup(rt);

}



int query(int rt,int l,int r,int ll,int rr){

	if(l>=ll&&r<=rr) return maxn[rt];

	int res=0;

	if(lazy[rt])   pushdown(rt);

	if(ll<=mid)    res=max(res,query(ls,l,mid,ll,rr));

	if(rr>=mid+1)  res=max(res,query(rs,mid+1,r,ll,rr));

	return res;

}





int main(){

	int ans=0;

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;++i){

		scanf("%d %d",&a[i].l,&a[i].r);

		ins(a[i].l,a[i].r);

	}

	sort(a+1,a+1+n,cmp);

	build(1,0,m+1);

	for(int i=0;i<=m;++i){

		for(int j=head[i];j;j=e[j].next){

			int r=e[j].des;

			update(1,0,m+1,1,r);

		}

		ans=max(ans,query(1,0,m+1,i+1,m+1)-(m+i+1));

	}

	ans=max(ans,n-m);

	printf("%d\n",ans);

	return 0;

}












































