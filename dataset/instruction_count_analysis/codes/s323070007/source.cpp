#include"stdc++.h"

using namespace std;

const int N=2e5+10;

struct E{

	int x,y,nxt,flag;

}mm[N<<2];

int h[N],len,p[N],n,ans[N],cur[N];

bool v[N];

inline int rd(){

	int x=0;int f=1;char s=getchar();

	while(!isdigit(s)) f=(s=='-'?-1:f),s=getchar();

	while(isdigit(s)) x=(x<<1)+(x<<3)+s-'0',s=getchar();

	return x*f;

}



inline void add(int x,int y){

	++len;

	mm[len].x=x;mm[len].y=y;mm[len].nxt=h[x];h[x]=len;

	++len;

	mm[len].x=y;mm[len].y=x;mm[len].nxt=h[y];h[y]=len;

	p[x]++;p[y]++;

	return ;

}

void dfs(int u,int f){

	

	for(int& k=cur[u];k;k=mm[k].nxt){

		int y=mm[k].y;

		if(mm[k].flag||f==y) continue; 

		mm[k].flag=mm[k%2==0?k-1:k+1].flag=1;

		if(v[u] && u<=n && y>n) ans[u]=ans[y]=1; 

		if(v[u] && u>n && y<=n) ans[u]=ans[y]=-1;

		h[u]=mm[k].nxt;

		dfs(y,u);

	}

}

int main(){

//	freopen("t.in","r",stdin);

	n=rd();memset(h,0,sizeof h);

	for(int i=1;i<=n;i++){

		int u=rd();u=max(0,u);

		add(u,i);

	}

	for(int i=1;i<=n;i++){

		int u=rd();u=u==-1?0:(u+n);

		add(u,i+n);

	}

	for(int i=1;i<=2*n;i++){

		if(p[i]%2) v[i]=1;

		else v[i]=0;

	}

	bool flag=true;

	for(int i=1;i<=n;i++)

		if(v[i]!=v[i+n]) flag=0;

	if(flag) printf("POSSIBLE\n");

	else {

		printf("IMPOSSIBLE\n");

		return 0;

	}

	for(int i=1;i<=n;i++)

		if(v[i]) add(i,i+n);//,printf("#%d %d\n",i,i+n);

	for(int i=0;i<=2*n;i++) cur[i]=h[i]; 

	dfs(1,0);

	for(int i=1;i<=n;i++) printf("%d ",ans[i]);printf("\n");

	return 0;

}