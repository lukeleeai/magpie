#include"stdc++.h"

using namespace std;

typedef pair<int,int> par;

int read(){

	int x=0,f=1; char ch=getchar();

	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}

	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}

	return x*f;

}

int fa[1000005];

map <par,int>m,a;

multiset<int>s[100005];

queue<par>q;

par makep(int x,int y){

	if (x>y) return par(y,x);

	else return par(x,y);

}

int find(int x){

	return fa[x]==x?x:find(fa[x]);

}

int main(){

	int n=read();

	for (int i=1;i<=2*n-2;i++){

		int u=read(),v=read();

		par w=makep(u,v);

		m[w]++; 

		if (m[w]>1&&a[w]==0){

			a[w]=1; q.push(w);

		}

		if (i<=n) fa[i]=i; 

		s[v].insert(u); s[u].insert(v);

	}

	for (int k=1;k<n;k++){

		int x,y;

		while (1){

			if (q.empty()){printf("NO\n"); return 0;}

			par w=q.front(); q.pop();

			x=find(w.first); y=find(w.second);

			if (x!=y) break;

		}

		if (s[x].size()>s[y].size()) swap(x,y);

		fa[x]=y;

		for (set<int>::iterator i=s[x].begin();i!=s[x].end();i++){

			int v=find(*i);

			if (v==y) continue;

			par z=makep(v,y);

			m[z]++; 

			if (m[z]>1&&a[z]==0){

				q.push(z); a[z]=1;

			}

			s[v].erase(s[v].find(x)); s[y].insert(v); s[v].insert(y);

		}

		s[y].erase(x);

		s[x].clear();

	}

	printf("YES\n");

	return 0;

}