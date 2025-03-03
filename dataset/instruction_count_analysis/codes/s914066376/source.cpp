#include"stdc++.h"

using namespace std;

#define int long long

typedef vector<int> vi;

typedef pair<int,int> ii;

typedef vector<ii> vii;

vi dist;

vector<vii> AdjList;

const int inf=1e18+7;

void dijkstra(int s) {

    dist[s]=0;

    priority_queue<ii,vii,greater<ii>> pq;

    pq.push(ii(0,s));

    while (!pq.empty()) {

    ii front=pq.top();

	pq.pop();

    int d=front.first;

	int u=front.second;

    if(d==dist[u]) {

        for(int j=0 ; j<(int)AdjList[u].size() ; j++) {

            ii v=AdjList[u][j];

            if(dist[u]+v.second<dist[v.first]) {

                dist[v.first]=dist[u]+v.second;

                pq.push(ii(dist[v.first],v.first));

                }

            }

        }

    }

}

signed main() {

	int n,m;

	cin>>n>>m;

	AdjList.assign(n,vii());

	dist.assign(n,inf);

	for(int i=1 ; i<n ; i++) {

		AdjList[i].push_back(ii(i-1,0));

	}

	for(int i=0 ; i<m ; i++) {

		int u,v,w;

		cin>>u>>v>>w;

		u--; v--;

		AdjList[u].push_back(ii(v,w));

	}

	dijkstra(0);

	if(dist[n-1]==inf) cout<<-1;

	else cout<<dist[n-1];

}