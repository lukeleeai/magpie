#include"stdc++.h"



using namespace std;



#define int long long



const int N=1e5+5;

int n,pset[N],lazy[N],ans[N];

vector<int> child[N];

vector< pair<int, pair<int,int> > > edge;



void joinset(int u, int v, int w){

    if(child[ pset[u] ].size() > child[ pset[v] ].size()) swap(u, v);

    int pau = pset[u];

    lazy[ pset[v] ] += w * (child[ pset[u] ].size());

    for(int cu : child[ pset[u] ]){

        ans[cu] += lazy[ pset[u] ] + w * child[ pset[v] ].size() - lazy[ pset[v] ];

    }

    for(int cu : child[ pset[u] ]) child[ pset[v] ].push_back(cu), pset[cu] = pset[v];

    child[ pau ].clear();

}



signed main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;

    for(int i=1;i<n;++i){

        int u,v,w; cin>>u>>v>>w;

        edge.push_back(make_pair(w,make_pair(u,v)));

    }

    sort(edge.begin(), edge.end());



    for(int i=1;i<=n; ++i) pset[i] = i, child[i].push_back(i);



    for(int i = edge.size()-1; i >= 0; --i){

        joinset(edge[i].second.first, edge[i].second.second, edge[i].first);

    }



    for(int i = 1; i <= n; ++i) cout << ans[i] + lazy[ pset[i] ] << "\n";



    return 0;

}
