#include"stdc++.h"

#define int long long

const int inf = 1e18;

using namespace std;



template<typename tp> inline void read(tp &x) {

	x=0;char c=getchar();

	for(;c<'0'||c>'9';c=getchar());

	for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0',c=getchar());

}

const int N = 2e5 + 10 ; 

int x,y,z,n;

struct P {

	int a,b,c;

}p[N];

inline bool cmp(P a, P b) {

	return a.a-a.b<b.a-b.b;

}

int suma,sumb,sum,t1[N],t2[N],ans=0;

priority_queue<int,vector<int> , greater<int> > q;



main() {

	memset(t1,168,sizeof(t1));

	memset(t2,168,sizeof(t2));

	cin>>x>>y>>z;

	n=x+y+z;

	for(int i=1;i<=n;i++) {

		read(p[i].a);read(p[i].b);read(p[i].c);

		p[i].a-=p[i].c;

		p[i].b-=p[i].c;

		sum+=p[i].c;

	}

	sort(p+1,p+n+1,cmp);

	int ans=-inf;

	for(int k=1;k<=y;k++) q.push(p[k].b),sumb+=p[k].b,t1[k]=max(t1[k],sumb);

	for(int k=y+1;k<=n;k++) {

		int u=q.top();q.pop();

		sumb-=u;

		sumb+=max(u,p[k].b);

		t1[k]=max(t1[k],sumb);

		q.push(max(u,p[k].b));

	}

	while(!q.empty()) q.pop();

	for(int k=n;k>=n-x+1;k--) 

		q.push(p[k].a),suma+=p[k].a,t2[k]=max(t2[k],suma);

	for(int k=n-x;k>=1;k--) {

		int u=q.top();q.pop();

		suma-=u;

		suma+=max(u,p[k].a);

		t2[k]=max(t2[k],suma);

		q.push(max(u,p[k].a));

	}

//	for(int i=1;i<=n;i++) {

//		printf("%d %d %d\n",p[i].a,p[i].b,p[i].c);

//	}

//	puts("____________");

//	for(int i=1;i<=n;i++) {

//		printf("%d ",t1[i]);

//	}puts("____________");

//	for(int i=1;i<=n;i++) {

//		printf("%d ",t2[i]);

//	}puts("____________");

	for(int k=y;k<=n-x;k++)

		ans=max(ans,t1[k]+t2[k+1]);

	cout<<ans+sum<<"\n";

}