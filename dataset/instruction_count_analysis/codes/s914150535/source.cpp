#include<cstdio>

#include<vector>

#include<algorithm>

using namespace std;

typedef unsigned uint;

int inline in(){int x=0,c;for(;(uint)((c=getchar())-'0')>=10;)

{if(c=='-')return -in();if(!~c)throw ~0;}do{x=(x<<3)+(x<<1)+(c-'0');}

while((uint)((c=getchar())-'0')<10);return x;}

int n;

void dfs(int u,vector<vector<int> >&E,vector<int>&p,vector<int>&sz){

	sz[u]=1;

	for(int i=0;i<(int)E[u].size();i++){

		int to=E[u][i];

		if(p[u]!=to){

			p[to]=u;

			dfs(to,E,p,sz);

			sz[u]+=sz[to];

		}

	}

}

int main(){

    n=in();

	vector<vector<int> >E(n);

	for(int i=0;i<n-1;i++){

		int a,b;

		a=in();b=in();

		a--;b--;

		E[a].push_back(b);

		E[b].push_back(a);

	}

	vector<int> p(n,-1),sz(n,0);

	dfs(0,E,p,sz);

	vector<int>path;

	int c=n-1,psz=0;

	while(c>=0){

		path.push_back(sz[c]-psz);

		psz=sz[c];

		c=p[c];

	}

	reverse(path.begin(),path.end());

	int ls=0;

	for(int i=0;i<((int)path.size()+1)/2;i++){

		ls+=path[i];

	}

	if(2*ls>n)printf("Fennec");

	else printf("Snuke");

	return 0;

}