#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<cmath>

#include<vector>

#include<queue>

#include<map>

#include<bitset>

#include<set>

#define N (200010)

#define P ()

#define M (N<<1)

#define inf (0x7f7f7f7f)

#define rg register int

#define Label puts("NAIVE")

#define spa print(' ')

#define ent print('\n')

#define rand() (((rand())<<(15))^(rand()))

#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

typedef long double ld;

typedef long long LL;

typedef unsigned long long ull;

using namespace std;

namespace fastIO1{

	inline char read(){

		static const int IN_LEN=1000000;

		static char buf[IN_LEN],*s,*t;

		return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);

	}

	template<class T>

	inline void read(T &x){

		static bool iosig;

		static char c;

		for(iosig=false,c=read();!isdigit(c);c=read()){

			if(c=='-')iosig=true;

			if(c==-1)return;

		}

		for(x=0;isdigit(c);c=read())x=((x+(x<<2))<<1)+(c^'0');

		if(iosig)x=-x;

	}

	inline char readc(char &c){

		for(c=read();!isalpha(c)&&!isdigit(c);c=read())

		if(c==-1)return 0;

	}

	const int OUT_LEN = 10000000;

	char obuf[OUT_LEN],*ooh=obuf;

	inline void print(char c) {

		if(ooh==obuf+OUT_LEN)fwrite(obuf,1,OUT_LEN,stdout),ooh=obuf;

		*ooh++=c;

	}

	template<class T>

	inline void print(T x){

		static int buf[30],cnt;

		if(x==0)print('0');

		else{

			if(x<0)print('-'),x=-x;

			for(cnt=0;x;x/=10)buf[++cnt]=x%10+48;

			while(cnt)print((char)buf[cnt--]);

		}

	}

	inline void flush(){fwrite(obuf,1,ooh-obuf,stdout);}

}

namespace fastIO2{

	template<class T>

	inline void read(T &x){

		static bool iosig;

		static char c;

		for(iosig=false,c=getchar();!isdigit(c);c=getchar()){

			if(c=='-')iosig=true;

			if(c==-1)return;

		}

		for(x=0;isdigit(c);c=getchar())x=((x+(x<<2))<<1)+(c^'0');

		if(iosig)x=-x;

	}

}

using namespace fastIO1;

int n,E,fi[N],ne[M],b[M]; char str[N];

int f[N],sf[N],siz[N],mn[N]; LL ans;

void add(int x,int y){

	ne[++E]=fi[x],fi[x]=E,b[E]=y;

}

void dfs1(int u,int pre){

//	cout<<u<<endl;

	if(str[u]=='1')mn[u]=0,siz[u]=1;

	else mn[u]=inf;

	for(int i=fi[u];i;i=ne[i]){

		int v=b[i];

		if(v==pre)continue;dfs1(v,u),siz[u]+=siz[v];

		if(f[v]+1>f[u])sf[u]=f[u],f[u]=f[v]+1;

		else sf[u]=max(sf[u],f[v]+1);

		if(siz[v])mn[u]=min(mn[u],f[v]+1);

	}

}

void dfs2(int u,int pre){

//	cout<<u<<endl;

	int tmp=min(f[u]-1,sf[u]+1);

	if(tmp>=mn[u])ans+=(LL)tmp-mn[u]+1;

//	cout<<tmp<<" "<<u<<" "<<mn[u]<<endl;

	for(int i=fi[u];i;i=ne[i]){

		int v=b[i]; if(v==pre)continue;

		int len=(f[u]==f[v]+1)?sf[u]+1:f[u]+1;

		if(f[v]<len)sf[v]=f[v],f[v]=len;

        else sf[v]=max(sf[v],len);

        if(siz[v]<siz[1])mn[v]=min(mn[v],len);

        dfs2(v,u);

	}

}

int main(){

	read(n);

	for(int i=1;i<n;i++){

		int x,y;

		read(x),read(y);

		add(x,y),add(y,x);

	}

	for(int i=1;i<=n;i++)readc(str[i]);

	dfs1(1,0),dfs2(1,0);

	cout<<ans+1;

}