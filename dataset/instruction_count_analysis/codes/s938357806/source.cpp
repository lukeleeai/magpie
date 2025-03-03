#include "stdc++.h"

using namespace std;



#define ll long long

#define endl "\n"



int main() {

  ll a, b, c, d;

  cin >> a >> b >> c >> d;

  ll ans1 = a * c;

  ll ans2 = a * d;

  ll ans3 = b * c;

  ll ans4 = b * d;

  cout << max(max(ans1, ans2), max(ans3, ans4)) << endl;

  return 0;

}