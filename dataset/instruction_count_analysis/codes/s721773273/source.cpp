#include"stdc++.h"

using namespace std;

int n,m,dis[200001],l,r,d;

bool Error,f[200001];

struct edge {

	int to,cost;

	edge(int a=0,int b=0) {

		to=a;

		cost=b;

	}

};

vector<edge> path[200001];

void spfa(int x) {

	for(int i=0; i<path[x].size(); i++) {

		edge e=path[x][i];

		if(f[e.to])

			if(e.cost+dis[x]!=dis[e.to]) {

				Error=true;

				return;

			} else continue;

		f[e.to]=true;

		dis[e.to]=dis[x]+e.cost;

		spfa(e.to);

		if(Error) return;

	}

}

int main() {

	cin>>n>>m;

	for(int i=0; i<m; i++) {

		scanf("%d%d%d",&l,&r,&d);

		path[l].push_back(edge(r,d));

		path[r].push_back(edge(l,-d));

	}

	for(int i=0; i<n; i++) {

		if(!f[i]) {

			spfa(i);

			if(Error) break;

		}

	}

	if(!Error) printf("Yes");

	else printf("No");

	return 0;

}