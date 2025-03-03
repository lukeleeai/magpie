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

#include<assert.h>

#include<string>

#include<cstdlib>

#include<cctype>

#include<unordered_map>

#include<sstream>

#include<numeric>

#include<stack>

// #include"stdc++.h"

using namespace std;

using ll = long long;

using P = pair<int,int>;

constexpr ll INF = 1LL<<60;

const double INFD = 1e100;

const ll mod = 1000000007;

const double PI = 3.1415926535897932384626433832795028841971;

const int dx[4] = {1, 0, -1, 0};

const int dy[4] = {0, 1, 0, -1};

template<class T> inline bool chmin(T& a, T b) {

    if (a > b) {

        a = b;

        return true;

    }

    return false;

};

template<class T> inline bool chmax(T& a, T b) {

    if (a < b) {

        a = b;

        return true;

    }

    return false;

};



// intやllをstringに変換

template<typename T> inline string toString(const T &a){

  ostringstream oss;

  oss << a;

  return oss.str();

};

// ----------------------------------------------------------------------------



int main(){

  int N,M;

  cin >> N >> M;

  vector<vector<int>> G(N);

  vector<P> id(M);

  for(int i=0; i<M; i++){

    int P,Y;

    cin >> P >> Y;

    P--;

    G[P].push_back(Y);

    id[i] = make_pair(P,Y);

  }

  for(int i=0; i<N; i++){

    sort(G[i].begin(),G[i].end());

  }

  for(int i=0; i<M; i++){

    id[i].second = lower_bound(G[id[i].first].begin(),G[id[i].first].end(),id[i].second) - G[id[i].first].begin();

  }

  for(int i=0; i<M; i++){

    cout << setfill('0') << right << setw(6) << id[i].first+1;

    cout << setfill('0') << right << setw(6) << id[i].second+1 << endl;

  }

  return 0;

}
