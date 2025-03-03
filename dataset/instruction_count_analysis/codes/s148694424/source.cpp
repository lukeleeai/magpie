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

vector<int> graph[max_v];

bool used_v[max_v];

map<int,bool> used_e[max_v];

int ord[max_v],lowlink[max_v];

vector<pii> bridges;



void dfs(int v,int &k){

    used_v[v]=true;

    ord[v]=lowlink[v]=k++;

    for(int u:graph[v]){

        if(!used_v[u]){

            used_e[v][u]=true;

            dfs(u,k);

            lowlink[v]=min(lowlink[v],lowlink[u]);

            if(ord[v]<lowlink[u]) bridges.push_back(make_pair(min(v,u),max(v,u)));

        }else if(!used_e[u][v]) lowlink[v]=min(lowlink[v],ord[u]);

    }

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

    dfs(0,k);

    

    sort(bridges.begin(),bridges.end());

    

    for(auto &e:bridges) cout << e.first << " " << e.second << endl;

}



int main(){

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	solve();

	return 0;

}