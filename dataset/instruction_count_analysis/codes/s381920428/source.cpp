#include<map>

#include<set>

#include<cmath>

#include<ctime>

#include<queue>

#include<stack>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define qmax(x,y) (x=max(x,y))

#define qmin(x,y) (x=min(x,y))

#define mp(x,y) make_pair(x,y)

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

inline int read(){

	int ans=0,fh=1;

	char ch=getchar();

	while(ch<'0'||ch>'9'){

		if(ch=='-') fh=-1;

		ch=getchar();

	}

	while(ch>='0'&&ch<='9')

		ans=ans*10+ch-'0',ch=getchar();

	return ans*fh;

}

const int maxn=2e5+100,inf=2e9;

struct node{

	int x,y,z;

}e[maxn<<1];

int n,a[maxn],m,q,fa[maxn];

ll Ans;

bool cmp(node x,node y){return x.z<y.z;}

int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}

int main(){

//	freopen("nh.in","r",stdin);

//	freopen("zhy.out","w",stdout);

	n=read(),q=read();

	for(int i=0;i<n;i++) a[i]=inf;

	for(int i=1;i<=q;i++){

		int x=read(),y=read(),z=read();

		e[++m]=(node){x,y,z};

		qmin(a[x],z+1),qmin(a[y],z+2);

	}

	for(int i=0;i<n;i++) qmin(a[i],a[(i-1+n)%n]+2);

	for(int i=0;i<n;i++) qmin(a[i],a[(i-1+n)%n]+2);

	for(int i=0;i<n;i++) e[++m]=(node){i,(i+1)%n,a[i]};

	for(int i=0;i<n;i++) fa[i]=i;

	sort(e+1,e+m+1,cmp);

	for(int i=1;i<=m;i++){

		int x=getfa(e[i].x),y=getfa(e[i].y);

		if(x==y) continue;

		fa[x]=y,Ans+=e[i].z;

	}

	printf("%lld\n",Ans);

	return 0;

}




















