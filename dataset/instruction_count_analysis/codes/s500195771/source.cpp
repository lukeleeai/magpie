#include <iostream>

#include <vector>

#include <queue>

using namespace std;



#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

struct Program {

  int s, t, c;

  Program(int s, int t, int c): s(s), t(t), c(c) {};

  bool operator<(const Program& rhs) const { return s == rhs.s ? t < rhs.t : s < rhs.s; }

  bool operator>(const Program& rhs) const { return s == rhs.s ? t > rhs.t : s > rhs.s; }

};



template<class T>using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;



int main() {

  int N, C; cin >> N >> C;



  vector<priority_queue_rev<Program>> q(30);

  rep(i, N) {

    int s, t, c; cin >> s >> t >> c;

    --c;

    q[c].emplace(s, t, c);

  }



  rep(i, 30) {

    queue<Program> tmp_q;

    while (!q[i].empty()) {

      if (q[i].size() == 1) {

        tmp_q.push(q[i].top());

        q[i].pop();

        break;

      }

      Program p1 = q[i].top(); q[i].pop();

      Program p2 = q[i].top(); q[i].pop();

      if (p1.t == p2.s)

        q[i].emplace(p1.s, p2.t, p1.c);

      else {

        tmp_q.push(p1); tmp_q.push(p2);

      }

    }

    while (!tmp_q.empty()) {

      q[i].push(tmp_q.front()); tmp_q.pop();

    }

  }



  priority_queue_rev<pair<int, int>> tv; // [終了時刻, チャンネル]

  int ans = 0;

  rep(t, 1e5+1) {

    int min_idx = -1;

    rep(i, 30) {

      if (q[i].empty())

        continue;

      if (min_idx == -1 || q[i].top() < q[min_idx].top())

        min_idx = i;

    }

    if (min_idx == -1)

      break;

    Program p = q[min_idx].top(); q[min_idx].pop();

    if (tv.empty())

      tv.emplace(p.t, p.c);

    else {

      if (tv.top().first < p.s || tv.top().first <= p.s && tv.top().second == p.c) {

        tv.pop();

        tv.emplace(p.t, p.c);

      } else

        tv.emplace(p.t, p.c);

    }

    ans = max(ans, (int)tv.size());

  }



  cout << ans << endl;

  return 0;

}
