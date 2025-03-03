#include"stdc++.h"

using namespace std;

#define pii pair<int,int>

#define mk make_pair

pii q[200001];

int h,t;

int n;

set<int> s[200001];

map<pii,int> mp;

int fa[200001];

int findfa(int x){

	return x==fa[x]?fa[x]:fa[x]=findfa(fa[x]);

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=(n-1)*2;++i){

		int u,v;

		scanf("%d%d",&u,&v);

		mp[mk(u,v)]++;mp[mk(v,u)]++;

		s[u].insert(v),s[v].insert(u);

		if(mp[mk(u,v)]==2)q[++t]=mk(u,v);

	}

	for(int i=1;i<=n;++i)fa[i]=i;

	set<int>::iterator id;

	while(h<t){

		int u=q[++h].first,v=q[h].second;

		u=findfa(u),v=findfa(v);

		s[u].erase(v),s[v].erase(u);

		if(s[u].size()<s[v].size())swap(u,v);

		for(id=s[v].begin();id!=s[v].end();++id){

			int to=(*id);

			mp[mk(v,to)]=mp[mk(to,v)]=0;

			s[to].erase(v);s[to].insert(u);

			mp[mk(u,to)]++,mp[mk(to,u)]++;

			if(mp[mk(u,to)]==2){

				q[++t]=mk(u,to);

			}

			s[u].insert(to);

		}

		fa[v]=u;

		s[v].clear();

	}

	int ans=0;

	for(int i=1;i<=n;++i)ans+=fa[i]==i;

	if(ans==1)puts("YES");

	else puts("NO");

}