#include <cstdio>

typedef long long ll;

inline int rd(){

    int x=0,p=1;

    char a=getchar();

    while((a<48||a>57)&&a!='-')a=getchar();

    if(a=='-')p=-p,a=getchar();

    while(a>47&&a<58)x=(x<<1)+(x<<3)+(a&15),a=getchar();

    return x*p;

}

const int N=3002;

struct Edge{

	int to,next;

}edge[N<<1];

int head[N],cnt;

int n,a[N],f[N];

inline void add(int f,int t){

	edge[++cnt].next=head[f];

	edge[cnt].to=t;

	head[f]=cnt;

}

inline void dp(int u,int ft){

	f[u]=0;

	for(int i=head[u];i;i=edge[i].next){

		int v=edge[i].to;

		if(v==ft)continue;

		dp(v,u);

		if(f[v]==0&&a[u]>a[v])f[u]=1;

	}

}

int main(){

	n=rd();

	for(int i=1;i<=n;i++)a[i]=rd();

	for(int i=1;i<n;i++){

		int u=rd(),v=rd();

		add(u,v),add(v,u);

	}

	for(int i=1;i<=n;i++){

		dp(i,0);

		if(f[i])printf("%d ",i);

	}

	puts("");

    return 0;

}