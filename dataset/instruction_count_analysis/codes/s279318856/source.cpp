#include "stdc++.h"

using namespace std;



//repetition

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)



//container util

#define all(x) (x).begin(),(x).end()



//typedef

typedef long long ll;

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<ll> VLL;

typedef vector<VLL> VVLL;

typedef vector<string> VS;

typedef pair<int, int> PII;

typedef pair<ll, ll> PLL;



//const value

//const ll MOD = 1e9 + 7;

//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};

//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};



//conversion

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}

inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}

template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}





void solve(ll b){

  int s = 0;

  int e = 0;

  for(ll n = 1; n*n < 2*b; n++){

    if( (2 * b  - n * (n-1)) % (2*n) == 0){

      s = (2 * b  - n * (n-1)) / (2*n);

      e = n;

    }

  }

  cout << s << " " << e << endl;

  return;

}



int main(){

  ios::sync_with_stdio(false);

  cin.tie(0);

  ll b;

  while(true){

    cin >> b;

    if(b == 0) break;

    solve(b);

  }

  return 0;

}


