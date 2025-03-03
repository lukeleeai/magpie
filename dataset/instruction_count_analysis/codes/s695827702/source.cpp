#include<iostream>

#include<algorithm>

#include<vector>

#include<functional>

#include<string>

#include<cmath>

#include<map>

#include<set>

#include<queue>

#include<stack>

#include<cstdio>

using namespace std;

using ll = long long;

#define MOD (int)1e9 + 7

int main(){

  int n, m;

  cin >> n >> m;

  if(abs(n - m) > 1){

    cout << 0 << endl;

    return 0;

  }

  ll ans = 1;

  for(int i = 0; i < n; i++){

    ans *= (i + 1);

    ans %= MOD;

  }

  for(int i = 0; i < m; i++){

    ans *= (i + 1);

    ans %= MOD;

  }

  if(m == n){

    ans *= 2;

  }

  ans %= MOD;

  cout << ans << endl;

  return 0;

}