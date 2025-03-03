#include <iostream>



#include <algorithm>

#include <vector>

#include <queue>



using namespace std;

using pii = pair<int, int>;

using vi = vector<int>;



#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n) FOR(i,0,n)

#define IN(v) int v;cin>>v;

#define OUT(v) cout<<v<<endl



int main() {

  IN(N); IN(C);



  vector<vector<pii>> program(C, vector<pii>());

  REP(i, N) {

    IN(s); IN(t); IN(c);

    program[c-1].push_back(make_pair(s, t));

  }

  REP(c, C) {

    priority_queue<pii, vector<pii>, greater<pii>> q;

    for (const auto& e : program[c])

      q.push(e);

    program[c].clear();

    while (!q.empty()) {

      pii p = q.top(); q.pop();

      if (p.second == q.top().first) {

        pii p2 = q.top(); q.pop();

        q.push(make_pair(p.first, p2.second));

      } else {

        program[c].push_back(p);

      }

    }

  }

  vi indexes(C);

  int res = 0;

  REP(s, 200002) {

    int count = 0;

    REP(c, C) {

      if (program[c].size() == indexes[c])

        continue;

      if (2 * program[c][indexes[c]].first - 1 <= s && s < 2 * program[c][indexes[c]].second)

        ++count;

      else if (2 * program[c][indexes[c]].second <= s)

        ++indexes[c];

    }

    res = max(res, count);

  }

  OUT(res);



  return 0;

}
