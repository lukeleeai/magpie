#include"stdc++.h"

using namespace std;

#define ll long long

#define FOR(i,n,m) for(int i=(n);i<(m);i++)

#define REP(i,n) FOR(i,0,n)

#define REPR(i,n) for(int i=(n);i>=0;i--)

#define all(vec) vec.begin(),vec.end()

using vi=vector<int>;

using vvi=vector<vi>;

using vl=vector<ll>;

using vvl=vector<vl>;

using P=pair<ll,ll>;

using PP=pair<ll,P>;

using vp=vector<P>;

using vpp=vector<PP>;

using vs=vector<string>;

#define fi first

#define se second

#define pb push_back

template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}

template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

const ll MOD=1000000007LL;

const int INF=1<<30;

const ll LINF=1LL<<60;

struct DAG{

    int V;

    vector<vector<int>> G;

    vector<int> in;

    DAG(int V):V(V),G(V),in(V){}

    void add_edge(int f,int t){

        G[f].push_back(t);

        in[t]++;

    }

    vector<int> topological_sort(){

        vector<int> res;

        stack<int> st;

        for(int i=0;i<V;i++){

            if(!in[i]){

                st.push(i);

            }

        }

        while(st.size()){

            int t=st.top();st.pop();

            res.push_back(t);

            for(int i=0;i<G[t].size();i++){

                if(!(--in[G[t][i]])){

                    st.push(G[t][i]);

                }

            }

        }

        return res;

    }

};

int main(){

    int V,E;

    cin>>V>>E;

    E+=V-1;

    DAG G(V);

    vvi inv(V);

    REP(i,E){

        int f,t;

        cin>>f>>t;

        f--;t--;

        G.add_edge(f,t);

        inv[t].pb(f);

    }

    auto tops=G.topological_sort();

    vi topl(V);

    REP(i,V){

        topl[tops[i]]=i;

    }

    vi ans(V,-1);

    REP(i,V){

        int v=tops[i];

        int x=-1;

        int vx=-1;

        REP(j,inv[v].size()){

            if(chmax(x,topl[inv[v][j]])){

                vx=inv[v][j];

            }

        }

        ans[v]=vx+1;

    }

    REP(i,V){

        cout<<ans[i]<<endl;

    }

    return 0;

}