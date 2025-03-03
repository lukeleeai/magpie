#include "stdc++.h"



#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const int INF = 1e9;



ll a, b, n, c1, c2, ans = 0;



ll f(ll x) { return floor(a * x / b) - a * floor(x / b); }



int main() {

  cin >> a >> b >> n;



  cout << f(min(b - 1, n)) << endl;

  return 0;

}
