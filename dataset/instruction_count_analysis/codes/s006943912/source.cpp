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



vector<pair<int,int>> graph[100000];



pair<int,int> dfs(int v,int p){

    pair<int,int> res(v,0);

    for(auto &e:graph[v]){

        if(e.first==p) continue;

        

        auto tmp=dfs(e.first,v);

        tmp.second+=e.second;

        if(res.second<tmp.second) res=tmp;

    }

    

    return res;

}



void solve(){

    int n;

    cin >> n;

    rep(i,0,n-1){

        int s,t,w;

        cin >> s >> t >> w;

        graph[s].push_back(make_pair(t,w));

        graph[t].push_back(make_pair(s,w));

    }

    

     int v=dfs(0,-1).first;

     cout << dfs(v,-1).second << endl;

}



int main(){

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	solve();

	return 0;

}