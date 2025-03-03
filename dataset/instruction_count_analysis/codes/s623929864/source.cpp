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



template <class T>

void cout_vec2(const vector<vector<T>> &vec){

  rep(i,vec.size()){

    rep(j,vec[i].size()){

      cout<<vec[i][j]<<' ';

    }

    cout<<endl;

  }

}



typedef pair<ll,ll> P;

const ll mod=1e9+7;

const ll inf=1e15;



ll n,k;

vector<ll> a(200010),f(200010);



bool solve(ll x){

  ll ret=k;

  rep(i,n){

    if(a[i]*f[i]<=x) continue;

    ll now=(a[i]*f[i]-x+f[i]-1)/f[i];

    if(now<=ret) ret-=now;

    else{

      return false;

    }

  }

  return true;

}





int main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  cin>>n>>k;

  rep(i,n) cin>>a[i];

  rep(i,n) cin>>f[i];

  sort(begin(a),begin(a)+n);

  sort(begin(f),begin(f)+n,greater<ll>());

  ll ans=0;

  ll high=1e18,low=-1,mid;

  while(high-low>1){

    mid=(high+low)/2;

    if(solve(mid)) high=mid;

    else low=mid;

  }

  cout<<high<<endl;

}