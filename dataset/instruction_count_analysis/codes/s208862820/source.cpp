#include <iostream>

#include <sstream>

#include <string>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <cassert>



using namespace std;



#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)



template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }



typedef long long ll;

const int INF = 100000000;

const double EPS = 1e-8;

const int MOD = 1000000007;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int count_fox_number(ll a, ll b){

  if(a < 2) a = 2;

  if(!(a < b)) return 0;

  int ans = b - a;

  bool prime_small[1000100] = {};

  //for(int i = 2; (ll) i * i < b; i++) prime_small[i] = true;

  int cnt_pow[1000100];

  REP(i, b - a) cnt_pow[i] = INF;

  for(int i = 2; (ll)i * i < b; i++){

    if(!prime_small[i]){

      for(int j = 2 * i; (ll) j * j < b; j += i) prime_small[j] = true;

      for(ll j = max(2LL, (a + i - 1)/i) * i; j < b; j += i){

        if(cnt_pow[j - a] == -1) continue;

        ll t = j;

        int cnt = 0;

        while(t % i == 0){

          t /= i;

          cnt++;

        }

        assert(cnt != 0);

        if(cnt_pow[j - a] < cnt){

          cnt_pow[j - a] = -1;

          ans--;

        }else{

          cnt_pow[j - a] = cnt;

        }

      }

    }

  }

  return ans;

}



int main(){

  ll a, b;

  while(cin>>a>>b){

    cout<<count_fox_number(a - b, a + b + 1)<<endl;

  }

  return 0;

}