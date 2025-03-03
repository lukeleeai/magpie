#include "stdc++.h"

using namespace std;

#define N 100010

int ea[N*2],eb[N*2],ec[N],tot,n;

void add(int x,int y){

	tot++;ea[tot]=y;eb[tot]=ec[x];ec[x]=tot;

}

int d[N],q[N],f[N],sum,minx;

bool die[N];

char s[N];

int read(){

	int x=0,f=1;

	char ch=getchar();

	while (ch<'0' || ch>'9'){

		if (ch=='-') f=-1;

		ch=getchar();

	}

	while (ch>='0' && ch<='9'){

		x=x*10+ch-'0';ch=getchar();

	}

	return x*f;

}

void topsort(){

	int t=1,w=0;

	for (int i=1;i<=n;++i) if (s[i]=='B' && d[i]==1) q[++w]=i;

	while (t<=w){

		int x=q[t++];die[x]=1;

		for (int i=ec[x];i;i=eb[i]){

			if (d[ea[i]]) d[ea[i]]--;

			if (s[ea[i]]=='B' && d[ea[i]]==1 && !die[ea[i]]) q[++w]=ea[i];

		}

	}

}

int check(int x){

	return (d[x]&1)^(s[x]=='W'); 

}

int val(int x){

	if (check(x)==1) return -2;

	else return 0;

}

void dfs(int fa,int x){

	sum+=(check(x)==1)+2;

	f[x]=val(x);

	for (int i=ec[x];i;i=eb[i]){

		if (ea[i]!=fa && !die[ea[i]]){

			dfs(x,ea[i]);

			minx=min(minx,f[x]+f[ea[i]]);

			f[x]=min(f[x],f[ea[i]]+val(x));

		}

	}

}

signed main(){

	n=read();

	for (int i=1;i<n;++i){

		int x=read(),y=read();

		add(x,y);add(y,x);d[x]++;d[y]++;

	}

	scanf("%s",s+1);

	topsort();int x;

	for (x=1;x<=n;++x) if (!die[x]) break;

	if (x>n) puts("0");

	else{

		dfs(0,x);sum-=2;cout<<sum+minx<<endl;

	}

	return 0;

}