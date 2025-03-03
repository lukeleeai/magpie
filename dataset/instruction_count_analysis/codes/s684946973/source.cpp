#include <iostream>

#include <algorithm>

#include <cmath>

#include <limits>

#include <vector>

#include <cstdio>

#include "stdc++.h"

#include <set>

#include <map>

#include <stdio.h>

#include <stack>

#include <queue>

#include <deque>

#include <numeric>

#include "stdc++.h"

#include <utility>

#include <iomanip>



#define ALL(obj) (obj).begin(), (obj).end()

#define FOR(i,a,b) for(int i = (a); i < (b); i++)

#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)

#define REP(i,n) for(int i = 0; i < (n); i++)

#define RREP(i,n) for(int i = n; n <= i; i--)

#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))

#define elif else if

#define MOD 1000000007

#define INF (1<<29)



using namespace std;



#define ld long double

#define ll long long



map <int ,int> mpa,mpb;

typedef pair<ll, ll> P;

priority_queue<P, vector<P>, greater<P>> pque;



int main(){

  ios::sync_with_stdio(false);

  cin.tie(NULL);

  ll N;

  cin >> N;

  ll ans=0;

  ll A[1000100];

  for(int i=1;i<=N;i++){

    cin >> A[i];

  }

  for(int i=1;i<=N;i++){

    if(A[i]%2==1 && A[i+1]>0){

      A[i]--;

      A[i+1]--;

      ans++;

    }

    ans+=A[i]/2;

  }

  cout << ans << endl;

  return 0;

}

// AGC003_考え方
