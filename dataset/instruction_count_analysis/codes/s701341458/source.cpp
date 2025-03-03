#include"stdc++.h"

using namespace std;



const int maxn=5e5+10;



void read(int &x)

{

	char c=getchar(); x=0;

	while (c<'0'||c>'9') c=getchar();

	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();

}



int n,k,p[maxn],q[maxn],deg[maxn];

int tote,FIR[maxn],TO[maxn<<1],NEXT[maxn<<1];

priority_queue<int> pq;



namespace SegTree{

	int mn[maxn<<2];

#define lc (nd<<1)

#define rc (nd<<1|1)

#define mid ((s+t)>>1)



	void init()

	{

		memset(mn,0x3f3f3f3f,sizeof(mn));

	}



	void update(int nd,int s,int t,int id,int val)

	{

		if (s==t) {mn[nd]=val; return;}

		if (id<=mid) update(lc,s,mid,id,val);

		else update(rc,mid+1,t,id,val);

		mn[nd]=min(mn[lc],mn[rc]);

	}



	int query(int nd,int s,int t,int l,int r)

	{

		if (l<=s&&t<=r) return mn[nd];

		int Ans=0x7fffffff;

		if (l<=mid) Ans=min(Ans,query(lc,s,mid,l,r));

		if (r> mid) Ans=min(Ans,query(rc,mid+1,t,l,r));

		return Ans;

	}

}



void addedge(int u,int v)

{

	TO[++tote]=v;

	NEXT[tote]=FIR[u];

	FIR[u]=tote;

	deg[v]++;

}



int main()

{

	int i,x;

	read(n); read(k);

	for (i=1;i<=n;i++)

		read(p[i]),q[p[i]]=i;

	SegTree::init();

	for (i=n;i>=1;i--)

	{

		x=SegTree::query(1,1,n,q[i]-k+1,q[i]);

		if (x<=n) addedge(q[x],q[i]);

		x=SegTree::query(1,1,n,q[i],q[i]+k-1);

		if (x<=n) addedge(q[x],q[i]);

		SegTree::update(1,1,n,q[i],i);

	}

	for (i=1;i<=n;i++)

		if (!deg[i]) pq.push(i);

	for (i=n;i>=1;i--)

	{

		int u=p[i]=pq.top(); pq.pop();

		for (int p=FIR[u];p;p=NEXT[p])

			if (!(--deg[TO[p]])) pq.push(TO[p]);

	}

	for (i=1;i<=n;i++) q[p[i]]=i;

	for (i=1;i<=n;i++) printf("%d\n",q[i]);

}
