#include "stdc++.h"

#define res register int

#define N 100005

using namespace std;

int n,d[N],tot,a[N],ans,k,f[N];

inline int read(){

	res X=0,w=0;register char ch=0;

	while(!isdigit(ch)){w|ch=='-';ch=getchar();}

	while(isdigit(ch)){X=(X<<1)+(X<<3)+(ch^48);ch=getchar();}

	return w?-X:X;

}

struct papa{

	int to,next;

}e[N];

inline void add(res x,res y){

	e[++tot].to=y;

	e[tot].next=d[x];

	d[x]=tot;

}

inline void dfs(res now){

	f[now]=0;

	for(res i=d[now];i;i=e[i].next){

		res x=e[i].to;

		dfs(x);

		f[now]=max(f[now],f[x]+1);

	}

	if(f[now]==k-1&&a[now]!=1){

		ans++;

		f[now]=-1;

	}

}

int main(){

	n=read(),k=read();

	a[1]=read();

	for(res i=2;i<=n;i++){

		a[i]=read();

		add(a[i],i);

	}

	if(a[1]!=1){

		ans++;

		a[1]=1;

	}

	dfs(1);

	printf("%d\n",ans);

	return 0;

}