#include"stdc++.h"

#define For(i,l,r) for(int i=l;i<=r;i++)

#define ll long long

using namespace std;

const int M=1e5+5;

int n,a[M],b[M],x[M],y[M],vis[M],cnt,ans;

map<int,int>d;

vector<int>Q[M];

inline int read(){

	int f=1,sum=0;

	char ch=getchar();

	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}

	while(isdigit(ch)){sum=(sum<<1)+(sum<<3)+(ch^48);ch=getchar();}

	return f*sum; 

}

inline void dfs(int x){

	vis[x]=1;

	For(i,0,Q[x].size()-1){

		if(!vis[Q[x][i]]){

			dfs(Q[x][i]);

		}

	}

}

int main(){

	n=read();

	For(i,1,n){

		a[i]=read();a[n+1]^=a[i];

	    if(!d[a[i]]) d[a[i]]=++cnt;

	}

	if(!d[a[n+1]]) d[a[n+1]]=++cnt;

	For(i,1,n){

		b[i]=read();b[n+1]^=b[i];

		if(!d[b[i]]) d[b[i]]=++cnt;

	}

	if(!d[b[n+1]]) d[b[n+1]]=++cnt;

	memcpy(x,a,sizeof(x));memcpy(y,b,sizeof(y));

	sort(x+1,x+n+2);sort(y+1,y+n+2);

	For(i,1,n) if(x[i]!=y[i]){printf("-1");return 0;}

	For(i,1,n+1) a[i]=d[a[i]],b[i]=d[b[i]];

	For(i,1,n) if(a[i]!=b[i]) ans++,Q[a[i]].push_back(b[i]);

	if(a[n+1]!=b[n+1]) Q[a[n+1]].push_back(b[n+1]); 

	For(i,1,cnt-1) if(Q[i].size()&&!vis[i]) dfs(i),ans++;

	if(!vis[cnt]) ans++;

	printf("%d",ans-1);

	return 0;

}