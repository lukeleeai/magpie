#include"stdc++.h"

using namespace std;

 

typedef long long ll;

typedef vector<pair<ll, ll>> pll;

 

#define mod 1000000007

#define all(x) (x).begin(), (x).end()

#define pb push_back

#define popcount(x) __builtin_popcountll(x)

 

const long double PI = acos(-1);

 

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}

ll lcm(ll a,ll b){return a / gcd(a,b) * b;}

ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}

bool isInteger(double x){return floor(x) == x;}



int main(){

  ios::sync_with_stdio(false);

  cin.tie(0);



  ll a, b;

  cin >> a >> b;

  ll ans = 0;

  for(ll i = a; i <= b; i++){

    if(i/10000 == i%10 && i/1000%10 == i/10%10) ans++;

  }

  cout << ans << endl;

  return 0;

}