#include "stdc++.h"

using namespace std;

int64_t N, K, p, c;

vector<int64_t> to(5005), C(5005);



int64_t solve(int start)

{

  vector<bool> visited(N, false);

  int64_t k = K, score = 0, moves = 0, ret = -(1LL << 62), next = to[start];

  while (!visited[next])

  {

    visited[next] = true;

    moves++;

    score += C.at(next);

    ret = max(ret, score);

    if (moves == K)

    {

      return ret;

    }

    next = to[next];

  }

  if (score <= 0)

  {

    return ret;

  }

  if (k % moves == 0)

  {

    return score * (k / moves - 1) + ret;

  }

  ret = score = score * (k / moves), k %= moves;



  while (k > 0)

  {

    k--;

    score += C.at(next);

    ret = max(ret, score);

    next = to[next];

  }

  return ret;

}



int main()

{

  cin >> N >> K;

  for (int i = 0; i < N; i++)

  {

    cin >> to[i];

    to[i]--;

  }

  for (int i = 0; i < N; i++)

  {

    cin >> C.at(i);

  }

  int64_t ans = -(1LL << 62);

  for (int i = 0; i < N; i++)

  {

    ans = max(ans, solve(i));

  }

  cout << ans << endl;

}
