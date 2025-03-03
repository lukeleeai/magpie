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

   vector<int> par,cnt;

   vector<ll> sum;

   UnionFind(int n):par(n,-1),sum(n),cnt(n){

       rep(i,n)sum[i]=a[i];

   }

   int find(int x){

       if(par[x]<0)return x;

       return par[x]=find(par[x]);

   }

   bool unite(int x,int y){

       x=find(x);

       y=find(y);

       if(x==y){

           ++cnt[x];

           return false;

       }

       if(par[x]>par[y]){

           par[y]+=par[x];

           sum[y]+=sum[x];

           cnt[y]+=cnt[x]+1;

           par[x]=y;

       }

       else{

           par[x]+=par[y];

           sum[x]+=sum[y];

           cnt[x]+=cnt[y]+1;

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



int main(){

    int n,m;

    cin>>n>>m;

    rep(i,n)cin>>a[i];

    int l[m],r[m],w[m];

    rep(i,m){

        cin>>l[i]>>r[i]>>w[i];

        --l[i];--r[i];

    }

    vector<int> ord(m);

    iota(ord.begin(),ord.end(),0);

    sort(ord.begin(),ord.end(),[&](int x,int y){

        return w[x]<w[y];

    });

    UnionFind uf(n);

    int ans=0;

    for(auto idx:ord){

        uf.unite(l[idx],r[idx]);

        if(uf.get(l[idx])>=w[idx]){

            int x=uf.find(l[idx]);

            ans+=uf.cnt[x];

            uf.cnt[x]=0;

        };

    }

    cout<<m-ans<<endl;

    return 0;

}