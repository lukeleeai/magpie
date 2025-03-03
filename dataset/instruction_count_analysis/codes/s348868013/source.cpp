#include <cstdio>

#include <cstring>

#include <algorithm>

#define fo(i,a,b) for(int i=a;i<=b;i++)

#define fd(i,a,b) for(int i=a;i>=b;i--)

#define rep(i,a) for(int i=last[a];i;i=next_[i])

using namespace std;



int read() {

	char ch;

	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());

	int x=ch-'0';

	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';

	return x;

}



const int N=1e6+5,inf=1e9;



struct pty{int x,y,id;}a[N],b[N];

bool cmpx(pty a,pty b) {return a.x<b.x;}

bool cmpy(pty a,pty b) {return a.y<b.y;}



int last[N],now[N],next_[N],t[N],l,cnt;

void add(int x,int y) {

	t[++l]=y;next_[l]=last[x];last[x]=l;

}



namespace Prog2{

	const int N = 10010;

	int m=0,n;

	int v[N<<1],f[N<<1];

	inline bool ok(int x){

		v[0]=-1e9;

		memset(f,0,sizeof f); f[0]=0;

		int j=1;

		for(int i=1;i<=m;++i){

		//	j=lower_bound(v,v+1+m,v[i]-x)-v;

			while(v[j]<=v[i]-x) ++j;

			if (v[j]>v[i]-x) --j;

			f[i]=max(f[i-1],f[j]+1);

		}

		return f[m]>=n;

	}

}

int n,tot;

void init() {

	Prog2::n=n=read();Prog2::m=tot=2*n;

	fo(i,1,n) {

		a[i].x=read();a[i].y=read();a[i].id=i;

		b[i].x=a[i].x;b[i].y=a[i].y;b[i].id=i;

		Prog2::v[i+i-1]=a[i].x;

		Prog2::v[i+i]=a[i].y;

	}

}



int rootx,rooty,le[N],ri[N];

void build(int &v,int l,int r,int flag) {

	if (l==r) {

		v=(flag==1)?(a[l].id+n):b[l].id;

		return;

	}

	v=++tot;

	int mid=l+r>>1;

	build(le[v],l,mid,flag);

	build(ri[v],mid+1,r,flag);

	add(v,le[v]);add(v,ri[v]);

}



void link(int v,int l,int r,int x,int y,int z) {

	if (x>y) return;

	if (l==x&&r==y) {add(z,v);return;}

	int mid=l+r>>1;

	if (y<=mid) link(le[v],l,mid,x,y,z);

	else if (x>mid) link(ri[v],mid+1,r,x,y,z);

	else link(le[v],l,mid,x,mid,z),link(ri[v],mid+1,r,mid+1,y,z);

}



void prepare() {

	sort(Prog2::v+1,Prog2::v+Prog2::m+1);

	sort(a+1,a+n+1,cmpx);

	build(rootx,1,n,1);

	sort(b+1,b+n+1,cmpy);

	build(rooty,1,n,2);

	fo(i,1,tot) now[i]=last[i];cnt=l;

}



int dfn[N],low[N],stack[N],cl[N],tmp,top,id;

bool vis[N],in[N];

void tarjan(int x) {

	vis[x]=in[x]=1;dfn[x]=low[x]=++tmp;stack[++top]=x;

	rep(i,x)

		if (!vis[t[i]]) {

			tarjan(t[i]);

			low[x]=min(low[x],low[t[i]]);

		} else if (in[t[i]]) low[x]=min(low[x],dfn[t[i]]);

	if (low[x]==dfn[x]) {

		stack[top+1]=0;++id;

		for(;stack[top+1]!=x;top--) {

			in[stack[top]]=0;

			cl[stack[top]]=id;

		}

	}

}



bool check(int mid) {

	int lx,rx;

	fo(i,1,tot) last[i]=now[i];l=cnt;

	lx=1,rx=1;

	fo(i,1,n) {

		while (lx<i&&a[i].x-a[lx].x>=mid) lx++;

		while (rx<=n&&a[rx].x-a[i].x<mid) rx++;

		link(rootx,1,n,lx,i-1,a[i].id);

		link(rootx,1,n,i+1,rx-1,a[i].id);

	}

	// xuan x ban x

	lx=1,rx=1;

	fo(i,1,n) {

		while (lx<=n&&b[i].y-a[lx].x>=mid) lx++;

		while (rx<=n&&a[rx].x-b[i].y<mid) rx++;

		link(rootx,1,n,lx,rx-1,b[i].id+n);

	}

	// xuan y ban x

	lx=1,rx=1;

	fo(i,1,n) {

		while (lx<=n&&a[i].x-b[lx].y>=mid) lx++;

		while (rx<=n&&b[rx].y-a[i].x<mid) rx++;

		link(rooty,1,n,lx,rx-1,a[i].id);

	}

	// xuan x ban y

	lx=1,rx=1;

	fo(i,1,n) {

		while (lx<i&&b[i].y-b[lx].y>=mid) lx++;

		while (rx<=n&&b[rx].y-b[i].y<mid) rx++;

		link(rooty,1,n,lx,i-1,b[i].id+n);

		link(rooty,1,n,i+1,rx-1,b[i].id+n);

	}

	// xuan y ban y

	

	tmp=top=id=0;

	fo(i,1,tot) vis[i]=cl[i]=dfn[i]=low[i]=0;

	fo(i,1,tot) if (!vis[i]) tarjan(i);

	fo(i,1,n) if (cl[i]==cl[i+n]) return 0;

	return 1;

}



void solve() {

	int l=0,r=inf;

	while (l<r-1) {

		int mid=l+r>>1;

		if (Prog2::ok(mid)) l=mid;

		else r=mid;

	}

//	printf("%d\n",r);

	l=0;

	while (l<r) {

		int mid=l+r>>1;

		if (check(mid)) l=mid+1;

		else r=mid;

	}

	printf("%d\n",l-1);

}



int main() {

	init();

	prepare();

	solve();

	return 0;

}