#include "stdc++.h"

#define repd(i,a,b) for (int i=(a);i<(b);i++)

#define rep(i,n) repd(i,0,n)

//#define int long long

typedef long long ll;

using namespace std;

const int MOD = 1000000007;

const int INF = 1010000000;

const double EPS = 1e-10;

const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 



signed main(){

  int n;cin>>n;int a[100000], b[100000];pair<int,int> c[100000];

  rep(i,n){

    cin>>a[i]>>b[i];

    c[i] = make_pair(a[i]+b[i], i);

  }

  sort(c,c+n,greater<pair<int,int>>());

  ll ans = 0;

  rep(i,n){

    if(!(i%2)){

      ans += a[c[i].second];

    }else{

      ans -= b[c[i].second];

    }

  }

  cout << ans << endl;

}
