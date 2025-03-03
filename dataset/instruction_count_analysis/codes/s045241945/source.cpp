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

#include<functional>

#include<assert.h>

#include<numeric>

using namespace std;

#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )

#define rep(i,n) REP(i,0,n)

typedef long long ll;

typedef pair<int,int> pint;

typedef pair<ll,int> pli;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;





ll a[101010];

struct UnionFind{

   vector<int> par;

   vector<ll> sum;

   UnionFind(int n):par(n,-1),sum(n){

       rep(i,n)sum[i]=a[i];

   }

   int find(int x){

       if(par[x]<0)return x;

       return par[x]=find(par[x]);

   }

   bool unite(int x,int y){

       x=find(x);

       y=find(y);

       if(x==y)return false;

       if(par[x]>par[y]){

           par[y]+=par[x];

           sum[y]+=sum[x];

           par[x]=y;

       }

       else{

           par[x]+=par[y];

           sum[x]+=sum[y];

           par[y]=x;

       }

       return true;

   }



   bool same(int x,int y){

       return find(x)==find(y);

   }

   ll get(int x){

       return sum[find(x)];

   }

};



vector<pint> v[101010];

bool used[101010];

int ans;



void dfs(int x, int M){

    if(used[x])return;

    used[x]=true;

    for(auto to:v[x]){

        if(to.second>M)continue;

        ++ans;

        if(used[to.first])continue;

        dfs(to.first,M);

    }

}

int main(){

    int n,m;

    cin>>n>>m;

    rep(i,n)cin>>a[i];

    int l[m],r[m],w[m];

    rep(i,m){

        cin>>l[i]>>r[i]>>w[i];

        --l[i];--r[i];

        v[l[i]].emplace_back(r[i],w[i]);

        v[r[i]].emplace_back(l[i],w[i]);

    }

    vector<int> ord(m);

    iota(ord.begin(),ord.end(),0);

    sort(ord.begin(),ord.end(),[&](int x,int y){

        return w[x]<w[y];

    });

    UnionFind uf(n);

    vector<int> ok;

    for(auto idx:ord){

        uf.unite(l[idx],r[idx]);

        if(uf.get(l[idx])>=w[idx])ok.push_back(idx);

    }

    reverse(ok.begin(),ok.end());

    for(auto idx : ok){

        dfs(l[idx],w[idx]);

    }

    cout<<m-ans/2<<endl;

    return 0;

}