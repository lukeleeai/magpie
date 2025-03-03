#include<algorithm>

#include<cstring>

#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<stack>

using namespace std;



const int maxn = 300010,inf = 1<<29;

int W,H,N,ans,tree[maxn*4],tag[maxn*4];



inline int gi()

{

	char ch; int ret = 0,f = 1;

	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');

	if (ch == '-') f = -1,ch = getchar();

	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');

	return ret*f;

}



struct node

{

	int x,y;

	inline node(int _x = 0,int _y = 0):x(_x),y(_y) {}

	inline void read() { x = gi(); y = gi(); }

	friend inline bool operator <(const node &a,const node &b) { return a.x < b.x; }

}P[maxn];



inline void build(int now,int l,int r)

{

	tree[now] = -inf; tag[now] = 0; if (l == r) return;

	int mid = (l+r) >> 1;

	build(now<<1,l,mid); build(now<<1|1,mid+1,r);

}



inline void pushdown(int now,int l,int r)

{

	if (l != r)

	{

		tree[now<<1] += tag[now]; tag[now<<1] += tag[now];

		tree[now<<1|1] += tag[now]; tag[now<<1|1] += tag[now];

	}

	tag[now] = 0;

}



inline void modify(int now,int l,int r,int ql,int qr,int key)

{

	if (tag[now]) pushdown(now,l,r);

	if (l == ql&&r == qr) { tree[now] += key; tag[now] = key; return; }

	int mid = (l+r) >> 1;

	if (qr <= mid) modify(now<<1,l,mid,ql,qr,key);

	else if (ql > mid) modify(now<<1|1,mid+1,r,ql,qr,key);

	else modify(now<<1,l,mid,ql,mid,key),modify(now<<1|1,mid+1,r,mid+1,qr,key);

	tree[now] = max(tree[now<<1],tree[now<<1|1]);

}



inline void change(int now,int l,int r,int pos,int key)

{

	if (tag[now]) pushdown(now,l,r);

	if (l == r) { tree[now] = key; return; }

	int mid = (l+r) >> 1;

	if (pos <= mid) change(now<<1,l,mid,pos,key);

	else change(now<<1|1,mid+1,r,pos,key);

	tree[now] = max(tree[now<<1],tree[now<<1|1]);

}



inline void work()

{

	sort(P+1,P+N+1); build(1,1,N+1);

	stack <node> S1,S2; int mid = H>>1;

	change(1,1,N+1,1,H); S1.push(node(mid,0)); S2.push(node(H-mid,0));

	for (int i = 1;i <= N;++i)

	{

		ans = max(ans,(P[i].x+tree[1])<<1); int h,last;

		if (P[i].y <= mid)

		{

			for (h = mid,last = i;!S1.empty()&&mid-P[i].y < (S1.top()).x;h = (S1.top()).x,last = (S1.top()).y,S1.pop())

				modify(1,1,N+1,(S1.top()).y+1,last,mid-P[i].y-h);

			if (S1.empty()) S1.push(node(mid-P[i].y,0));

			else modify(1,1,N+1,(S1.top()).y+1,last,mid-P[i].y-h);

			S1.push(node(mid-P[i].y,i));

		}

		else

		{

			for (h = H-mid,last = i;!S2.empty()&&P[i].y-mid < (S2.top()).x;h = (S2.top()).x,last = (S2.top()).y,S2.pop())

				modify(1,1,N+1,(S2.top()).y+1,last,P[i].y-mid-h);

			if (S2.empty()) S2.push(node(P[i].y-mid,0));

			else modify(1,1,N+1,(S2.top()).y+1,last,P[i].y-mid-h);

			S2.push(node(P[i].y-mid,i));

		}

		change(1,1,N+1,i+1,H-P[i].x);

	}

	ans = max(ans,(W+tree[1])<<1);

}



int main()

{

	//freopen("D.in","r",stdin);

	//freopen("D.out","w",stdout);

	W = gi(); H = gi(); N = gi();

	for (int i = 1;i <= N;++i) P[i].read();

	ans = max((H+1)<<1,(W+1)<<1);

	work();

	for (int i = 1;i <= N;++i) swap(P[i].x,P[i].y); swap(H,W);

	work();

	cout << ans << endl;

	return 0;

}