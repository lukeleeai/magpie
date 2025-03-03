#include "stdc++.h"

#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = pow(10,18);

#define rep(n) for(ll i=0; i<n; i++)



ll n,m;

vector<ll> a;

vector<ll> num;

vector<ll> dp;



void num_set()

{

  num.push_back(2);

  num.push_back(5);

  num.push_back(5);

  num.push_back(4);

  num.push_back(5);

  num.push_back(6);

  num.push_back(3);

  num.push_back(7);

  num.push_back(6);

}



ll dp_query(ll x)

{

  if(x<0) return -INF;

  return dp[x];

}



void dp_set(ll x)

{

  dp.push_back(0);

  // each iteration computes dp[i+1]

  for (ll i = 0; i < x; i++)

  {

    ll cur = -INF;

    for (ll j = 0; j < m; j++)

    {

      cur = max(cur,dp_query(i+1-num[a[j]-1]));

    }

    cur++;

    dp.push_back(cur);

  }

}



void ans(ll x)

{

  ll last = n;

  for (ll i = 0; i < x; i++)

  {

    for (int j = 0; j < m; j++)

    {

      if(dp_query(last-num[a[j]-1])==x-i-1) {

        last -= num[a[j]-1];

        cout << a[j];

        break;

      }

    }

  }

  cout << endl;

}



void print_vec(vector<ll> v)

{

  vector<ll>::iterator itr;

  for(itr = v.begin(); itr!=v.end(); itr++)

  {

    cout << *itr << endl;

  }

}



int main()

{

  num_set();

  cin >> n >> m;

  rep(m){

    ll tmp;

    cin >> tmp;

    a.push_back(tmp);

  }

  sort(a.begin(),a.end(),greater<ll>());

  dp_set(n);

  ans(dp[n]);

  return 0;

}