#include "stdc++.h"

#define mem(s,t) memset(s,t,sizeof(s))

#define pb(s) push_back(s)

#define inf 0x3f3f3f3f

#define mn 100010

typedef long long ll;

using namespace std;

bool nusd[mn],musd[mn];

queue<int> q;

vector<int> K[mn],L[mn];

int main()

{

	int n,m;scanf("%d%d",&n,&m);

	for(int i=0;i<n;++i){

		int k,l;scanf("%d",&k);

		while(k--){

			scanf("%d",&l);

			L[i].pb(l);

			K[l].pb(i);

		}

	}

	int e=0;

	nusd[0]=1;

	q.push(e);

	while(!q.empty()){

		e=q.front();q.pop();

		for(int i=0;i<L[e].size();++i){

			int t=L[e][i];

			if(musd[t])continue;

			musd[t]=1;

			for(int j=0;j<K[t].size();++j){

				int p=K[t][j];

				if(nusd[p])continue;

				nusd[p]=1;

				q.push(p);

			}

		}

	}

	bool ok=1;

	for(int i=0;i<n&&ok;++i){

		if(!nusd[i])ok=0;

	}

	if(ok)printf("YES");else printf("NO");



    return 0;

}
