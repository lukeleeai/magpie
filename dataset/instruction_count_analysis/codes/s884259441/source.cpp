#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<math.h>

#include<complex>

#include<queue>

#include<deque>

#include<stack>

#include<map>

#include<set>

#include<bitset>

using namespace std;

#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )

#define rep(i,n) REP(i,0,n)

typedef long long ll;

typedef pair<int,int> pint;

typedef pair<ll,int> pli;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;

struct StronglyConnectedComponents{

    vector<int> used,cmp,vs;

    vector<vector<int>> v,rv,g;

    StronglyConnectedComponents(int n):used(n),cmp(n,-1),v(n),rv(n){}



    void add_edge(int x,int y){

        v[x].push_back(y);

        rv[y].push_back(x);

    }

    void dfs(int x){

        used[x]=true;

        for(auto to:v[x])if(!used[to])dfs(to);

        vs.push_back(x);

    }



    void rdfs(int x,int k){

        cmp[x]=k;

        for(auto to:rv[x])if(cmp[to]==-1)rdfs(to,k);

    }



    int scc(){

        rep(i,used.size())if(!used[i])dfs(i);

        reverse(vs.begin(),vs.end());

        int k=0;

        for(auto x:vs)if(cmp[x]==-1)rdfs(x,k++);

        return k;

    }

    void build(){

        int k=scc();

        g.resize(k);

        rep(i,v.size()){

            for(auto& to:v[i]){

                int x=cmp[i],y=cmp[to];

                if(x!=y)g[x].push_back(y);

            }

        }

    }

};

int main(){

    int n,m;

    cin>>n>>m;

    StronglyConnectedComponents scc(n);

    rep(i,m){

        int x,y;

        cin>>x>>y;

        scc.add_edge(x, y);

    }

    scc.scc();

    int q;cin>>q;

    rep(i,q){

        int x,y;

        cin>>x>>y;

        cout<<(scc.cmp[x]==scc.cmp[y])<<endl;

    }

    return 0;

}


