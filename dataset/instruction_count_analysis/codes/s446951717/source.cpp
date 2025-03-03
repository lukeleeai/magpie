#include "stdc++.h"

using namespace std;



#define rep(i,x,y) for(int i=(x);i<(y);++i)

#define debug(x) #x << "=" << (x)



#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define print(x)

#endif



const int inf=1e9;

const int64_t inf64=1e18;

const double eps=1e-9;



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){

    os << "[";

    for (const auto &v : vec) {

    	os << v << ",";

    }

    os << "]";

    return os;

}



//O(|V|+|E|)



template<class graph_type> class bridge_and_articulation{

public:

    const int size;

    graph_type graph;

    vector<bool> used,is_art;

    vector<int> ord,low,articulations;

    vector<pair<int,int>> bridges;



    bridge_and_articulation(const graph_type &graph):graph(graph),size(graph.size()),used(size),is_art(size),ord(size),low(size){

        int k=0;

        for(int i=0; i<size; ++i) if(!used[i]) dfs(i,-1,k);

    }



    void dfs(int v,int p,int &k){ //v???????????¨???p=-1

        used[v]=true;

        ord[v]=low[v]=k++;



        int count=0;

        for(const auto &edge:graph[v]){

            const int u=edge.to;

            if(!used[u]){

                ++count;

                dfs(u,v,k);

                low[v]=min(low[v],low[u]);



                if(ord[v]<low[u]) bridges.push_back(make_pair(min(v,u),max(v,u)));

                if(p!=-1 and ord[v]<=low[u]) is_art[v]=true;

            }else if(ord[u]<ord[v]) low[v]=min(low[v],ord[u]);

        }



        if(p==-1 and count>1) is_art[v]=true;

        if(is_art[v]) articulations.push_back(v);

    }



    bool is_bridge(int u,int v)const{

        if(ord[u]>ord[v]) swap(u,v);

        return ord[u]<low[v];

    }



    bool is_articulation(int v)const{

        return is_art[v];

    }

};



struct edge{

    int to;

};



void solve(){

    int v,e;

    cin >> v >> e;

    vector<vector<edge>> graph(v);

    rep(i,0,e){

        int s,t;

        cin >> s >> t;

        graph[s].push_back(edge({t}));

        graph[t].push_back(edge({s}));

    }

    bridge_and_articulation<vector<vector<edge>>> ba(graph);

    vector<int> ans=ba.articulations;

    sort(ans.begin(),ans.end());

    for(int v:ans) cout << v << endl;

}



int main(){

    std::cin.tie(0);

    std::ios::sync_with_stdio(false);

    cout.setf(ios::fixed);

    cout.precision(10);

    solve();

    return 0;

}