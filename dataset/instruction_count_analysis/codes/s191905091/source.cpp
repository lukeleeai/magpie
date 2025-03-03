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



#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)



template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }



typedef long long ll;

const int INF = 100000000;

const double EPS = 1e-8;

const int MOD = 1000000007;

typedef pair<int, int> P;

typedef pair<int, P> S;

int main(){

  int N;

  while(cin>>N && N){

    string ss, gs; cin>>ss>>gs;

    int St = 0, G = 0;

    REP(i, N){

      St |= (int)(ss[i] == 'B') << i;

      G |= (int)(gs[i] == 'B') << i;

    }

    priority_queue<S> que;

    int dist[1<<16][16];

    REP(i, 1<<N)REP(j, N) dist[i][j] = INF;

    REP(i, N){

      dist[St][i] = 0;

      que.push(S(0, P(St, i)));

    }

    while(!que.empty()){

      S s = que.top(); que.pop();

      int d = s.first * -1;

      int state = s.second.first;

      int u = s.second.second;

      if(state == G){

        cout<<d<<endl;

        break;

      }

      if(dist[state][u] < d) continue;

      REP(i, N)REP(j, N)if((state >> i & 1) != (state >> j & 1)){

        int nst = state ^ (1 << i) ^ (1 << j);

        int nd = d + abs(i - u) + abs(j - i);

        int nu = j;

        if(dist[nst][nu] > nd){

          dist[nst][nu] = nd;

          que.push(S(nd * -1, P(nst, nu)));

        }

      }

    }

  }

  return 0;

}