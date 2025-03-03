#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<vector>

#include<map>

#include<set>

#include<string>

#include<queue>

#include<stack>

using namespace std;

#define MOD 1000000007

#define LINF (1LL<<60)

#define EPS (1e-10)

typedef long long Int;

typedef pair<Int, Int> P;



#define max(x, y) ((x)>(y)?(x):(y))

#define min(x, y) ((x)<(y)?(x):(y))





vector<Int> frompoInt(216000);

Int dp[216000];

Int n, C, h[216000];

void add(vector<Int> &bit, Int ind, Int val){

  ind++;

  while(ind < bit.size()){

    bit[ind] = max(bit[ind], val);

    ind += ind & -ind;

  }

}



Int sum(vector<Int> &bit, Int ind){

  ind++;

  Int res = 0;

  while(ind){

    res = max(res, bit[ind]);

    ind -= ind & -ind;

  }

  return res;

}



Int calc(Int x, Int f){

  return (h[f] - h[x]) * (h[f] - h[x]) + C + dp[f];

}



int main(){

  cin >> n >> C;

  

  fill(dp, dp + n, LINF);

  dp[0] = 0;

  for(Int i = 0;i < n;i++)cin >> h[i];

  for(Int i = 0;i < n;i++){



    Int bottom = i, top = n;

    if(i)dp[i] = calc(i, sum(frompoInt,i));

    while(top - bottom > 1){

      Int mid = (top + bottom) / 2;

      if(calc(mid, i) >= calc(mid, sum(frompoInt, mid)))bottom = mid;

      else top = mid;

    }

    add(frompoInt, top, i);

  }

  cout << dp[n-1] << endl;

  return 0;

}