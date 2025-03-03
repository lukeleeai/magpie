#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <vector>

#include <cassert>

#include <queue>





using namespace std;



using ll = long long;





int main() {

  ll N, M;

  cin >> N >> M;

  vector<ll> A(N);

  for (ll i =0;i<N; i++) cin >> A[i];

  sort(A.begin(), A.end());



  vector<pair<ll, ll>> BC(M);

  for(ll i=0;i<M;i++) cin >> BC[i].second >> BC[i].first;

  sort(BC.begin(), BC.end());

  reverse(BC.begin(), BC.end());



  ll tt = 0;

  ll cidx = 0;

  for (ll i=0; i<N;i++) {

    if (A[i] < BC[cidx].first) {

      tt += BC[cidx].first;

      BC[cidx].second--;



      if (BC[cidx].second == 0) {

        cidx++;

      }

    } else {

      tt += A[i];

    }

  }



  cout << tt << endl;



  return 0;

}
