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

 

class lca_solver{

    public:

    vector<vector<int>> children;

    int root;

    // if root,parent is -1.

    vector<int> parent;

    vector<int> depth;

    vector<vector<int>> parent_pow2;

    lca_solver(vector<vector<int>> &children_,int root_)

        : children(children_),root(root_){

        calc_parent_and_depth();

        calc_parent_pow2();

    };

    int lca(int u,int v){

        // make sure depth(u) > depth(v).

        if(depth[u] < depth[v]) swap(u,v);

        for(size_t k=0;k<parent_pow2.size();k++){

            if(((depth[u] - depth[v]) >> k) & 1){

                u = parent_pow2[k][u];

            }

        }

        if(u == v) return u;

        for(int k=(int)parent_pow2.size()-1;k>=0;k--){

            if(parent_pow2[k][u] != parent_pow2[k][v]){

                u = parent_pow2[k][u];

                v = parent_pow2[k][v];

            }

        }

        return parent_pow2[0][u];

    }

    int dist(int u,int v){

        return depth[u]+depth[v]-depth[lca(u,v)]*2;

    }

    private:

    void calc_parent_and_depth(){

        parent = vector<int>(children.size(),-1);

        depth = vector<int>(children.size(),-1);

        sub_calc_parent_and_depth(root,-1,0);

    }

    void sub_calc_parent_and_depth(int cur,int par,int dep){

        parent[cur] = par;

        depth[cur] = dep;

        for(int child : children[cur]){

            if(child != par){

                sub_calc_parent_and_depth(child,cur,dep+1);

            }

        }

    }

    void calc_parent_pow2(){

        // parent_pow2[k][i] = 2^k parent of node i.

        parent_pow2 = vector<vector<int>>(ceil(log(children.size())/log(2)+1),

                                          vector<int>(children.size(),-1));

        parent_pow2[0] = parent;

        for(size_t k=0;k+1<parent_pow2.size();k++){

            for(size_t v=0;v<children.size();v++){

                if(parent_pow2[k][v] >= 0){

                    parent_pow2[k+1][v] = parent_pow2[k][parent_pow2[k][v]];

                }

            }

        }

    }

};

 

void solve(){

    int n,q;

    cin >> n >> q;

    vector<vector<int>> graph(n);

 

    rep(i,0,n-1){

        int a,b;

        cin >> a >> b;

        graph[a].push_back(b);

    }

 

    lca_solver ls(graph,0);

 

    auto contraction=[&](vector<int> &cont_parent,bool used[]){

        static pair<int,int> stk_pool[150000];

        int idx=0;

        stk_pool[idx++]=make_pair(0,0);

        while(idx>0){

            auto p=stk_pool[--idx];

            int u=p.first,v=p.second;

            for(int w:graph[v]){

                if(used[w]){

                    cont_parent[w]=u;

                    stk_pool[idx++]=make_pair(w,w);

                }else stk_pool[idx++]=make_pair(u,w);

            }

        }

    };

 

    int b=1000,r=q;

    vector<int64_t> d(n);

    rep(i,0,(q+b-1)/b){

        int size=min(b,r);

        vector<int> fs(size),us(size),vs(size),lcas(size);

        bool used[150000];

        fill_n((bool*)used,150000,false);

        used[0]=true;

        rep(j,0,size){

            cin >> fs[j] >> us[j] >> vs[j];

            used[us[j]]=true;

            if(fs[j]==0){

                lcas[j]=ls.lca(us[j],vs[j]);

                used[vs[j]]=used[lcas[j]]=true;

            }

        }

 

        vector<int> cont_parent(n,-1);

        contraction(cont_parent,used);

 

        vector<int64_t> add_lazy(n);

        auto calc_dist=[&](int u){

            int64_t res=d[u],v=u;

            while(v!=0){

                v=cont_parent[v];

                res+=add_lazy[v]*(ls.depth[u]-ls.depth[v]);

            }

            return res;

        };

        rep(j,0,size){

            if(fs[j]==1){

                add_lazy[us[j]]+=vs[j];

                continue;   

            }

            cout << calc_dist(us[j])+calc_dist(vs[j])-calc_dist(lcas[j])*2 << endl;

        }

 

        function<void(int,int64_t,int64_t)> propagate=[&](int u,int64_t s,int64_t t){

            d[u]+=s;

            for(int v:graph[u]) propagate(v,s+t+add_lazy[u],t+add_lazy[u]);

        };

        propagate(0,0,0);

 

        r-=b;

    }

}

 

int main(){

    std::cin.tie(0);

    std::ios::sync_with_stdio(false);

    cout.setf(ios::fixed);

    cout.precision(10);

    solve();

    return 0;

}