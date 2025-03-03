#include "stdc++.h"

using namespace std;

typedef long long ll;



constexpr ll N=100001;

vector <ll> tree[N];

vector <ll> exam (N,0);

map<pair<ll,ll>,ll> I;

vector <pair <ll,ll>> v(N);



ll maxcol=0;

void dfs(pair <int,int> now){

  ll ncol=1;



  for (auto i:tree[now.first]){

    if (exam[i]) continue;

    if (ncol==now.second) ncol++;

    exam[i]=ncol;

    I[make_pair(now.first,i)]=I[make_pair(i,now.first)]=ncol;

    maxcol=max(maxcol,ncol);



    dfs(make_pair(i,ncol));

    ncol++;

  }



}



  int main(){

    ll n;

    cin>>n;

    for (int i=0; i<n-1; i++){

      ll a,b;

      cin>>a>>b;

      tree[a].emplace_back(b);

      tree[b].emplace_back(a);

      v[i]=make_pair(a,b);

    }

    exam[1]=N;



    dfs(make_pair(1,0));





    cout<<maxcol<<endl;

    for (ll i=0;i<n-1; i++){

      cout<<I[v[i]]<<endl;

    }



  }
