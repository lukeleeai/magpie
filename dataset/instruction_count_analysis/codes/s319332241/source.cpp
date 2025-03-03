#include "stdc++.h"

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);i++)

#define rep(i,n) repd(i,0,n)

typedef long long ll;

typedef long double lb;

#define int long long

#define double long double

#define endn "\n"

typedef pair<int,int> P;

const int MOD = 1000000007;

const ll INF = 1e16;

const double EPS = 1e-10;

const double PI = 3.141592653589793;

template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}

template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}

const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 





////////////////////////////////////////////////////////////////////



int n;P p[210000], q[210000];

signed main(){

  cin>>n;rep(i,n)cin>>p[i].first>>p[i].second;

  sort(p,p+n);

  rep(i,n){

    q[i].first = p[i].first + p[i].second;

    q[i].second = i;

  }

  sort(q,q+n, greater<P>());

  int ans = 0;

  rep(i,n){

    int t = q[i].second;

    if(i%2 == 0){

      ans += p[t].first;

    }else{

      ans -= p[t].second;

    }

  }

  cout << ans << endl;

}
