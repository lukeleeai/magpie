

#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<ll, ll> l_l;

typedef pair<int, int> P;

#define rep(i,n) for(ll i=0;i<n;++i)

const int INF=1001001001;

int main(){

  ll n;

  cin>>n;

  vector<vector<P>> g(n);

  vector<int> cn(n,INF);

  vector<int> ce(n-1,INF);

  rep(i,n-1){

    int a1,b1;

    cin>>a1>>b1;

    a1--;b1--;

    g[a1].push_back(make_pair(b1,i));

    g[b1].push_back(make_pair(a1,i));



  }





queue <int> q;

q.push(0);

int maxc=0;

while (!q.empty()){

  int now=q.front();

  q.pop();

  int cnt=1;



  for(auto to:g[now]){

    int nod=to.first;

    int edg=to.second;



    if (ce[edg]!=INF)continue;

    if (cn[now]==cnt) cnt++;

    ce[edg]=cnt;

    cn[nod]=cnt;

    maxc=max(maxc,cnt);

    q.push(nod);

    cnt++;

  }



}

cout<<maxc<<endl;

rep(i,n-1){

  cout<<ce[i]<<endl;

}













  }
