#include <algorithm>

#include <bitset>

#include <cmath>

#include <functional>

#include <iomanip>

#include <iostream>

#include <limits>

#include <map>

#include <queue>

#include <random>

#include <set>

#include <tuple>

#include <vector>



using namespace std;



#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)

#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)

#define rirep(i, n) for (int64_t i = n; i >= 0; i--)



#define chmax(a, b) (a) = max(a, b)

#define chmin(a, b) (a) = min(a, b)



int D;

vector<int> c(26);

vector<vector<int>> s;



int main() {

  cin.tie(0);

  ios::sync_with_stdio(false);



  cin >> D;



  rep(i, 26) { cin >> c[i]; }



  s.resize(D, vector<int>(26));

  rep(i, D) rep(j, 26) { cin >> s[i][j]; }



  const int width = 10;



  vector<vector<int16_t>> last;

  vector<int> parent;

  vector<char> kind;



  using P = pair<int64_t, int>;

  priority_queue<P, vector<P>, greater<P>> q;



  last.push_back(vector<int16_t>(26, -1));

  parent.push_back(-1);

  kind.push_back(-1);

  q.push(P(0, 0));



  mt19937 rng(111);

  uniform_int_distribution<int> dist(0, 500 - 1);



  rep(i, D) {

    priority_queue<P, vector<P>, greater<P>> nxt;

    queue<P> mutant;



    while (!q.empty()) {

      int64_t z;

      int idx;

      tie(z, idx) = q.top();

      q.pop();



      int64_t penalty = 0;

      rep(j, 26) { penalty += c[j] * (i - last[idx][j]); }



      rep(j, 26) {

        int nidx = last.size();

        int64_t w = z + s[i][j] - penalty + c[j] * (i - last[idx][j]);

        nxt.push(P(w, nidx));

        if (nxt.size() > width) {

          if (dist(rng) == 0) {

            mutant.push(nxt.top());

          }

          nxt.pop();

        }



        last.push_back(last[idx]);

        last[nidx][j] = i;

        parent.push_back(idx);

        kind.push_back(j);

      }

    }



    q = move(nxt);

    while (!mutant.empty()) {

      q.push(mutant.front());

      mutant.pop();

    }

  }



  while (q.size() > 1) {

    q.pop();

  }



  int64_t score;

  int idx;

  tie(score, idx) = q.top();

  vector<int> sln;

  while (idx != 0) {

    sln.push_back(kind[idx]);

    idx = parent[idx];

  }

  rrep(i, D) { cout << sln[i] + 1 << "\n"; }

  // cerr << score << "\n";



  return 0;

}