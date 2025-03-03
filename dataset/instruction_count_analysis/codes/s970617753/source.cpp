#include<cstdio>

#include<iostream>

#include<cstring>

#include<vector>

#include<queue>

#define RG register

using namespace std;

const int N=5e5+10;

struct dabt{

	int next,to;

}e[N<<2];

int head[N],k,n,m,tree[N<<2],ru[N],pos[N],p[N],cnt,ans[N];

priority_queue<int, vector<int> ,greater<int> > pn;

inline void add(int from,int to){e[++k]=(dabt){head[from],to}; head[from]=k; ru[to]++;}

inline int read(){

	char ch=getchar(); int x=0, f=1;

	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}

	while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}

	return x*f;}

inline int mi(int a,int b){return a<b ? a : b;}

inline int mx(int a,int b){return a>b ? a : b;}

int sum(int l,int r,int st,int ed,int o)

{

	if(st<=l && r<=ed) return tree[o];

//	printf("%d %d %d %d %d\n",l,r,st,ed,o);

	if(l==r) return 2e9;

	int mid=l+(r-l)/2, ans=2e9;

	if(mid>=st) ans=mi(ans,sum(l,mid,st,ed,o<<1));

	if(mid<ed) ans=mi(ans,sum(mid+1,r,st,ed,o<<1|1));

	return ans;

}

void upd(int l,int r,int pos,int kk,int o)

{

	if(l==r) 

	{

		tree[o]=kk;

		return ;

	}

	int mid=l+(r-l)/2;

	if(pos<=mid) upd(l,mid,pos,kk,o<<1);

	else upd(mid+1,r,pos,kk,o<<1|1);

	tree[o]=mi(tree[o<<1],tree[o<<1|1]);

}

inline void topo()

{

	for(int i=1;i<=n;i++) if(!ru[i]) pn.push(i);

	while(!pn.empty())

	{

		int x=pn.top(); pn.pop(); ans[x]=++cnt;

		for(int i=head[x];i;i=e[i].next)

		{

			int v=e[i].to;

			if(--ru[v]==0) pn.push(v);

		}

	}

}

int main()

{

//	freopen("Wide Swap.in","r",stdin);

//	freopen("Wide Swap.out","w",stdout);

	n=read(); m=read();

	for(int i=1;i<=(n<<2);i++) tree[i]=2e9;

	for(int i=1;i<=n;i++)

	{

		pos[p[i]=read()]=i;

	}

	for(int i=n,x;i;i--)

	{

		x=sum(1,n,pos[i]+1,mi(pos[i]+m-1,n),1);

		if(x<2e9) add(pos[i],pos[x]);

		x=sum(1,n,mx(pos[i]-m+1,1),pos[i]-1,1);

		if(x<2e9) add(pos[i],pos[x]);

		upd(1,n,pos[i],i,1);

	}

	topo();

	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);

	//fclose(stdin); fclose(stdout);

	return 0;

}