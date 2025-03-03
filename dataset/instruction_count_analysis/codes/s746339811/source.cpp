#include"stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)

#define chmax(a, b) a = max(a, b)

#define chmin(a, b) a = min(a, b)

#define fi first

#define se second

#define INF 1000000009

#define LLINF 1000000000000000009LL

using ll = long long;

#define MX 100009



int mp[MX][29];



int main(){

  string s,t;

  cin>>s>>t;

  int n=s.size();

  int m=t.size();

  rep(i,MX)rep(j,29)mp[i][j]=-1;

  for(int i=n-1;i>=0;i--){

    rep(j,26){

      mp[i][j]=mp[i+1][j];

    }

    mp[i][s[i]-'a']=i;

  }

  ll ans=0;

  int p=-1;

  rep(i,m){

    int x=mp[p+1][t[i]-'a'];

    int nxt=mp[0][t[i]-'a'];

    if(p<x){

      ans+=x-p;

      p=x;

    }

    else{

      if(nxt==-1){

        ans=-1;

        break;

      }

      ans+=n-p+nxt;

      p=nxt;

    }

  }

  cout<<ans<<endl;

  return(0);

}
