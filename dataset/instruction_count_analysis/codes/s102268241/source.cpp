#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define len(v) ll(v.size())

#define fi first

#define se second



template <class T>

void cout_vec(const vector<T> &vec){

  for(auto itr:vec) cout<<itr<<' ';

  cout<<endl;

}



typedef pair<ll,ll> P;

const ll mod=1e9+7;

const ll inf=1e15;



int main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  int n;

  cin>>n;

  vector<vector<int>> g(n);

  rep(i,n-1){

    int a,b;

    cin>>a>>b;

    a--,b--;

    g[a].push_back(b);

    g[b].push_back(a);

  }

  vector<int> d1(n,-1),d2(n,-1);

  queue<int> q1,q2;

  d1[0]=0,d2[n-1]=0;

  q1.push(0),q2.push(n-1);

  while(!q1.empty()){

    int now=q1.front();

    q1.pop();

    for(auto itr:g[now]){

      if(d1[itr]==-1){

        d1[itr]=d1[now]+1;

        q1.push(itr);

      }

    }

  }

  while(!q2.empty()){

    int now=q2.front();

    q2.pop();

    for(auto itr:g[now]){

      if(d2[itr]==-1){

        d2[itr]=d2[now]+1;

        q2.push(itr);

      }

    }

  }

  int cnt=0;

  rep(i,n) if(d1[i]<=d2[i]) cnt++;

  if(cnt>n-cnt) cout<<"Fennec"<<endl;

  else cout<<"Snuke"<<endl;

}