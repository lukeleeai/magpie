#include<iostream>

#include<vector>

#include<cmath>

#include<algorithm>

#include<limits>

using namespace std;

using uint = unsigned int;

using ll = long long;



#define FOR(i,a,b) for (int i = a; i < b; ++i)

#define REP(i,n) FOR(i,0,n)



uint N;

ll A[200001];

uint l, c, r;



ll getVal() {

  ll prev_diff, curr_diff;

  ll cval = A[c], eval = A[N];



  // left side

  prev_diff = numeric_limits<ll>::max();

  while (1) {

    curr_diff = abs((cval - A[l]) - (A[l] - 0));

    if (curr_diff > prev_diff) {

      --l;

      break;

    }



    prev_diff = curr_diff;

    ++l;

    if (l >= c) {

      --l;

      break;

    }

  }



  // right side

  prev_diff = numeric_limits<ll>::max();

  while(1) {

    curr_diff = abs((eval - A[r]) - (A[r] - cval));

    if (curr_diff > prev_diff) {

      --r;

      break;

    }



    prev_diff = curr_diff;

    ++r;

    if (r >= N) {

      --r;

      break;

    }

  }



  // calc val

  ll sum[4];

  sum[0] = A[l] - 0;

  sum[1] = cval - A[l];

  sum[2] = A[r] - cval;

  sum[3] = eval - A[r];

  ll maxval = *max_element(sum, sum+4);

  ll minval = *min_element(sum, sum+4);

  return maxval - minval;

}



int main() {

  scanf("%u", &N);



  A[0] = 0;

  REP(i,N) {

    scanf("%llu", &A[i+1]);

    A[i+1] += A[i];

  }



  ll minval = numeric_limits<ll>::max();

  for (l = 1, c = 2, r = 3; c <= N - 2; ++c) {

    if (r <= c) r = c + 1;   

    ll val = getVal();

    if (val < minval) minval = val;

  }



  printf("%llu\n", minval);

  return 0;

}