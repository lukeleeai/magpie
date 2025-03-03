#include "stdc++.h"

using namespace std;



#define rep(i,x,y) for(int i=(x);i<(y);++i)

#define debug(x) #x << "=" << (x)



#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define show(x)

#endif



typedef long long int ll;

typedef pair<int,int> pii;

template<typename T> using vec=std::vector<T>;



const int inf=1<<30;

const long long int infll=1LL<<62;

const double eps=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){

    os << "[";

    for (const auto &v : vec) {

    	os << v << ",";

    }

    os << "]";

    return os;

}



//???????????¶??¨??¨?????´???????±???????.

pair<int,int> farthest_vertex(const vector<vector<pair<int,int>>> &graph,int v,int p){

    pair<int,int> res(v,0); //(??????????????????,?????¢)

    for(auto &e:graph[v]){

        if(e.first==p) continue;



        auto tmp=farthest_vertex(graph,e.first,v);

        tmp.second+=e.second;

        if(res.second<tmp.second) res=tmp;

    }

    return res;

}



void solve(){

    int n;

    cin >> n;



    vector<vector<pii>> graph(n);

    rep(i,0,n-1){

        int s,t,w;

        cin >> s >> t >> w;

        graph[s].push_back(make_pair(t,w));

        graph[t].push_back(make_pair(s,w));

    }

    auto tmp=farthest_vertex(graph,0,-1);

    cout << farthest_vertex(graph,tmp.first,-1).second << endl;

}



int main(){

    std::cin.tie(0);

    std::ios::sync_with_stdio(false);

    cout.setf(ios::fixed);

    cout.precision(10);

    solve();

    return 0;

}