#include "stdc++.h"

using namespace std;



#define rep(i,x,y) for(int i=(x);i<(y);++i)

#define mp(a,b) make_pair((a),(b))

#define debug(x) #x << "=" << (x)

 

#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define dump(x)

#endif



typedef long long int ll;

typedef pair<int,int> pii;

//template<typename T> using vec=std::vector<T>;



const int INF=1<<30;

const long long int INFLL=1LL<<58;

const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){

	os << "[";

	for (const auto &v : vec) {

		os << v << ",";

	}

	os << "]";

	return os;

}



const int max_v=100000;

vector<int> graph[max_v],articulations;

bool used_v[max_v];

map<int,bool> used_e[max_v];

int ord[max_v],lowlink[max_v];



void dfs(int v,int p,int &k){ //vが根のときp=-1

    used_v[v]=true;

    ord[v]=lowlink[v]=k++;

    

    bool is_articulation=false;

    int count=0;

    for(int u:graph[v]){

        if(!used_v[u]){

            ++count;

            used_e[v][u]=true;

            dfs(u,v,k);

            lowlink[v]=min(lowlink[v],lowlink[u]);

            if(p!=-1 and ord[v]<=lowlink[u]) is_articulation=true;

        }else if(!used_e[u][v]) lowlink[v]=min(lowlink[v],ord[u]);

    }

    

    if(p==-1 and count>1) is_articulation=true;

    if(is_articulation) articulations.push_back(v);

}



void solve(){

    int v,e;

    cin >> v >> e;

    

    rep(i,0,e){

        int s,t;

        cin >> s >> t;

        graph[s].push_back(t);

        graph[t].push_back(s);

    }

    

    int k=0;

    dfs(0,-1,k);

    

    sort(articulations.begin(),articulations.end());

    articulations.erase(unique(articulations.begin(),articulations.end()),articulations.end());

    

    for(auto &v:articulations) cout << v << endl;

}



int main(){

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	solve();

	return 0;

}