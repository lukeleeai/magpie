#include <algorithm>

#include <cstdio>



inline int read(){

	char c=getchar(); int x=0;

	for(;c<'0'||c>'9';c=getchar());

	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';

	return x;

}



inline int min(int a,int b){

	return a<b?a:b;

}



inline void swap(int& a,int& b){

	int tmp=a; a=b; b=tmp;

}



const int N=2e5+5;



int n,q,m,w[N],fa[N],sz[N];



struct Edge{

	int u,v,w;

	bool operator < (const Edge& r) const { return w<r.w; }

}e[N<<1];



int find(int x){

	if(x==fa[x]) return x; else return fa[x]=find(fa[x]);

}



inline void unit(int x,int y){

	if(sz[x]<sz[y]) swap(x,y); fa[y]=x; sz[x]+=sz[y];

}



int main(){

	n=read(); q=read(); int pos=0;

	for(int i=0;i<n;++i) w[i]=2e9;

	for(int i=1,a,b,c;i<=q;++i){

		a=read(); b=read(); c=read();

		e[++m]=(Edge){a,b,c};

		w[(a+1)%n]=min(w[(a+1)%n],c+1);

		w[(b+1)%n]=min(w[(b+1)%n],c+2);

	}

	for(int i=0;i<n;++i) if(w[i]<w[pos]) pos=i;

	for(int i=(pos+1)%n,j=pos;i!=pos;){

		w[i]=min(w[i],w[j]+2); j=i; i=(i+1)%n;

	}

	for(int i=0;i<n;++i) e[++m]=(Edge){(i+n-1)%n,i,w[i]};

	std::sort(e+1,e+1+m); long long ans=0;

	for(int i=0;i<n;++i) fa[i]=i,sz[i]=1;

	for(int i=1;i<=m;++i){

		int u=find(e[i].u),v=find(e[i].v);

		if(u^v) unit(u,v),ans+=e[i].w;

	}

	printf("%lld\n",ans);

	return 0;

}