#include<cstdio>

#include<algorithm>

using namespace std;

int heap[500005],top;

struct tree{

	int max;

}t[2000005];

struct link{

	int next,to;

}l[500005];

int n,sum,cnt,k;

int a[500005],p[500005],pre[500005],ans[500005],tmp[500005],head[500005];

inline int read(){

	int ret=0;char c=getchar();

	while((c<'0')||(c>'9'))c=getchar();

	while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();

	return ret;

}

int P[20],pcnt;

void print(int x){

	if(x==0){puts("0");return;}

	while(x)P[++pcnt]=x%10,x/=10;

	while(pcnt)putchar(P[pcnt--]+'0');

	putchar('\n');

}

#define mid ((l+r)>>1)

#define lson index<<1

#define rson index<<1|1

inline int query(int L,int R,int l,int r,int index){

	if((L<=l)&&(R>=r))return t[index].max;

	if(R<=mid)return query(L,R,l,mid,lson);

	if(L>mid)return query(L,R,mid+1,r,rson);

	return max(query(L,R,l,mid,lson),query(L,R,mid+1,r,rson));

}

void updata(int l,int r,int index,int k,int x){

	t[index].max=x;

	if(l==r)return;

	if(k<=mid)updata(l,mid,lson,k,x);

	else updata(mid+1,r,rson,k,x);

}

void add(int u,int v){l[++cnt]=(link){head[u],v};head[u]=cnt;}

void ins(int x){

	heap[++top]=x;int k=top;

	while(k>1){

		if(heap[k>>1]>heap[k])swap(heap[k],heap[k>>1]);

		else break;

		k>>=1;

	}

}

void pop(){

	heap[1]=heap[top];int k=1;top--;

	while((k<<1)<=top){

		int v=k<<1;

		if(v<top)if(heap[v|1]<heap[v])v|=1;

		if(heap[v]<heap[k])swap(heap[k],heap[v]);

		else break;

		k=v;

	}

}

int main(){

	n=read();k=read();

	for(int i=1;i<=n;i++)p[i]=read(),a[p[i]]=i;

	for(int i=1;i<=n;i++){

		int r=min(n,a[i]+k-1);

		pre[i]=a[query(a[i],r,1,n,1)];

		updata(1,n,1,a[i],i);

	}

	for(int i=1;i<=n;i++)if(pre[i])add(pre[i],a[i]);

	for(int i=1;i<=n;i++)if(pre[i]==0)ins(a[i]);

	cnt=0;

	for(int i=1;i<=n;i++){

		int u=heap[1];ans[u]=++cnt;pop();

		for(int j=head[u];j;j=l[j].next)ins(l[j].to);

	}

	for(int i=1;i<=n;i++)print(ans[i]);

}