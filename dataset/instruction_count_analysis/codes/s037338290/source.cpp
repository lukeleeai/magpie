#include<cstdio>

#include<cstring>

#include<algorithm>

const int M=207,mod=998244353;

int read(){

	int ans=0,f=1,c=getchar();

	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}

	while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}

	return ans*f; 

}

int n,f[M],sz[M];

int find(int x){while(f[x]!=x) x=f[x]=f[f[x]]; return x;}

int gcd(int x,int y){return y?gcd(y,x%y):x;} 

struct pos{int x,y;}q[M];

int cnt;

struct node{

	int u,v,w;

	bool operator <(const node &x)const{return w<x.w;}

	void calc(){

		int p=find(u),q=find(v);

		if(p!=q) f[q]=p,sz[p]+=sz[q];

	}

}e[M*M];

int pw[M],ans;

void prepare(){

	pw[0]=1; 

	for(int i=1;i<=n;i++) pw[i]=(pw[i-1]<<1)%mod;

}

int main(){

	n=read(); 

	prepare(); ans=(pw[n]-n-1)%mod;

	for(int i=1;i<=n;i++) q[i].x=read(),q[i].y=read();

	for(int i=1;i<=n;i++)

		for(int j=1;j<i;j++){

			int x=q[i].x-q[j].x,y=q[i].y-q[j].y,g=gcd(x,y);

			x/=g; y/=g;

			if(!x) y=1;

			if(!y) x=1;

			if(x<0) x=-x,y=-y;

			e[++cnt]=(node){i,j,x*30000+y};

		}

	std::sort(e+1,e+1+cnt);

	for(int i=1,j=1;i<=cnt;i=j){

		for(int k=1;k<=n;k++) sz[f[k]=k]=1;

		while(j<=cnt&&e[j].w==e[i].w) e[j++].calc();

		for(int k=1;k<=n;k++) if(f[k]==k&&sz[k]>=2) ans=(ans-pw[sz[k]]+sz[k]+1)%mod;

	}printf("%d\n",(ans+mod)%mod);

	return 0;

}