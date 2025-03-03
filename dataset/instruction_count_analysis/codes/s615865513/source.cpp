#include<iostream>

#include<vector>

#include<algorithm>

#include<map>

#include<cstring>

#include<math.h>

#include<bitset>

#include<queue>

#include<set>

#include<iomanip>

#include<math.h>

// #include"stdc++.h"

using namespace std;

#define ll long long

constexpr long long int INFLL = 1001001001001001LL;

constexpr int INFI = 1000000007;



int main(){

  int N,M;

  cin >> N >> M;

  vector<int> P(1000000),Y(1000000);

  vector<int> yd[100001];

  for(int i=0; i<M; i++){

    cin >> P[i] >> Y[i];

    yd[P[i]].push_back(Y[i]);

  }

  for(int i=0; i<N; i++){

    sort(yd[i+1].begin(),yd[i+1].end());

  }

  for(int i=0; i<M; i++){

    cout << setfill('0') << right << setw(6) << P[i];

    cout << setfill('0') << right << setw(6) << lower_bound(yd[P[i]].begin(),yd[P[i]].end(),Y[i])-(yd[P[i]].begin())+1 << endl;

  }

  return 0;

}
