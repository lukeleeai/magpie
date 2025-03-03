#include <cstdio>

const int maxn=2e5+6;

#define read(a) scanf("%I64d",&a)

#define rep(a,b,c) for(int a=b;a<=c;a++)

#define per(a,b,c) for(int a=b;a>=c;a--)

#define ls rt<<1

#define rs rt<<1|1

#define mid ((l+r)>>1)

#define int long long

template<class T>inline T max(T a,T b) { return a>b?a:b; }

template<class T>inline T min(T a,T b) { return a<b?a:b; }

int n,a[maxn],lans[maxn],rans[maxn];

struct Segment_Tree {

	int val[maxn<<2];

	inline void pushup(int rt) { val[rt]=max(val[ls],val[rs]); }

	inline void insert(int rt,int l,int r,int k,int ch) {

		if(l==r) return(void)(val[rt]=ch);

		if(k<=mid) insert(ls,l,mid,k,ch);

		else insert(rs,mid+1,r,k,ch);

		pushup(rt);

	}

	inline int query(int rt,int l,int r,int L,int R) {

		if(L<=l&&r<=R) return val[rt];

		int ans=0;

		if(L<=mid) ans=max(ans,query(ls,l,mid,L,R));

		if(R>mid) ans=max(ans,query(rs,mid+1,r,L,R));

		return ans;

	}

	inline void build(int rt,int l,int r) {

		val[rt]=0; if(l==r) return;

		build(ls,l,mid); build(rs,mid+1,r);

	}

}t;

struct Segment_Tree_ {

	int val[maxn<<2];

	inline void pushup(int rt) { val[rt]=min(val[ls],val[rs]); }

	inline void insert(int rt,int l,int r,int k,int ch) {

		if(l==r) return(void)(val[rt]=ch);

		if(k<=mid) insert(ls,l,mid,k,ch);

		else insert(rs,mid+1,r,k,ch);

		pushup(rt);

	}

	inline int query(int rt,int l,int r,int L,int R) {

		if(L<=l&&r<=R) return val[rt];

		int ans=maxn;

		if(L<=mid) ans=min(ans,query(ls,l,mid,L,R));

		if(R>mid) ans=min(ans,query(rs,mid+1,r,L,R));

		return ans;

	}

	inline void build(int rt,int l,int r) {

		val[rt]=n+1; if(l==r) return;

		build(ls,l,mid); build(rs,mid+1,r);

	}

}T;

int ans;

signed main() {

	read(n);

	rep(i,1,n) read(a[i]);

	rep(i,1,n) {

		t.insert(1,1,n,a[i],i);

		if(a[i]!=1) lans[i]=t.query(1,1,n,1,a[i]-1);

		else lans[i]=0;

	}

	T.build(1,1,n);

	per(i,n,1) {

		T.insert(1,1,n,a[i],i);

		if(a[i]!=1) rans[i]=T.query(1,1,n,1,a[i]-1);

		else rans[i]=n+1;

	}

	rep(i,1,n) ans+=(i-lans[i])*(rans[i]-i)*a[i];

	printf("%lld",ans);

}