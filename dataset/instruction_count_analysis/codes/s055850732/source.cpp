#include"stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)

#define fi first

#define se second

#define INF 1000000009

#define lINF 1000000000000000009

using ll = long long;



int main(){

  int n,m;

  cin>>n>>m;

  vector<vector<int>>s(n);

  rep(i,m){

    int k;

    cin>>k;

    rep(j,k){

      int a;

      cin>>a;

      a--;

      s[a].push_back(i);

    }

  }

  vector<int>is(m);

  rep(i,m)cin>>is[i];

  int ans=0;

  rep(bits,1<<n){

    vector<int>ok=is;

    rep(i,n){

      if(bits>>i&1){

        for(auto t:s[i]){

          ok[t]=(!ok[t]);

        }

      }

    }

    bool f=true;

    rep(i,m){

      if(ok[i])f=false;

    }

    if(f)ans++;

  }

  cout<<ans<<endl;

  return(0);

}
