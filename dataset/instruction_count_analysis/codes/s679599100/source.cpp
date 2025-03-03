#include <map>

#include <set>

#include <list>

#include <cmath>

#include <queue>

#include <stack>

#include <cstdio>

#include <string>

#include <vector>

#include <complex>

#include <cstdlib>

#include <cstring>

#include <numeric>

#include <sstream>

#include <iomanip>

#include <iostream>

#include <algorithm>

#include <functional>

  

#define mp       make_pair

#define pb       push_back

#define all(x)   (x).begin(),(x).end()

#define rep(i,n) for(int i=0;i<(n);i++)

  

using namespace std;

  

typedef    long long          ll;

typedef    unsigned long long ull;

typedef    vector<bool>       vb;

typedef    vector<int>        vi;

typedef    vector<vb>         vvb;

typedef    vector<vi>         vvi;

typedef    pair<int,int>      pii;

  

const int INF=1<<29;

const double EPS=1e-9;

  

const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};



int main() {

  int N;

  cin >> N;

  vector<ll> A(N);

  for (int i = 0; i < N; i++) {

    cin >> A[i];

  }

  vector<ll> acc(N + 1);

  for (int i = 0; i < N; i++) {

    acc[i + 1] = acc[i] + A[i];

  }



  ll ans = 1LL << 62;

  for(int j = 1; j < N - 2; j++) {

    int i1 = lower_bound(acc.begin(), acc.begin() + j + 1, acc[j + 1] / 2) - acc.begin() - 1;

    int i2 = i1 - 1;



    ll ss = acc[N] - acc[j + 1];

    int k1 = lower_bound(acc.begin() + j + 1, acc.end(), ss / 2 + acc[j + 1]) - acc.begin() - 1;

    int k2 = k1 - 1;

    

    vector<int> I, K;

    I.push_back(i1);

    K.push_back(k1);



    if (i2 >= 0) {

      I.push_back(i2);

    }



    if (k2 > j) {

      K.push_back(k2);

    }

    

    for(int u = 0; u < I.size(); u++) {

      for(int v = 0; v < K.size(); v++) {

        int i = I[u];

        int k = K[v];



        vector<ll> area;

        ll areaB = acc[i + 1];

        ll areaC = acc[j + 1] - acc[i + 1];

        ll areaD = acc[k + 1] - acc[j + 1];

        ll areaE = acc[N] - acc[k + 1];



        area.push_back(areaB);

        area.push_back(areaC);

        area.push_back(areaD);

        area.push_back(areaE);



        sort(area.begin(), area.end());

        ans = min(ans, area.back() - area[0]);

      }

    }



  }

  cout << ans << endl;

  return 0;

}