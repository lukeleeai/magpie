#include "stdc++.h"

using namespace std;

const int64_t INF = (1LL << 60);

int64_t N, K;

vector<int64_t> scores[5005];

vector<int64_t> P(5005), C(5005);

int64_t tot[5005];

vector<int64_t> maxs(5005, -INF);



bool visited[5005];

void dfs(int64_t v, int64_t score, int64_t start)

{

  if (visited[v])

  {

    scores[start].push_back(score);

    tot[start] = score;

    return;

  }

  visited[v] = true;

  scores[start].push_back(score);

  dfs(P.at(v), score + C.at(P.at(v)), start);

}



int main()

{

  cin >> N >> K;

  for (int64_t i = 0; i < N; i++)

  {

    cin >> P.at(i);

    P.at(i)--;

  }

  for (int64_t i = 0; i < N; i++)

  {

    cin >> C.at(i);

  }

  for (int i = 0; i < N; i++)

  {

    for (int j = 0; j < 5005; j++)

    {

      visited[j] = false;

    }

    dfs(i, 0, i);

  }

  for (int i = 0; i < N; i++)

  {

    int64_t cyc = scores[i].size() - 1;

    int64_t cycles = K / cyc, r = K % cyc;

    if (tot[i] < 0 || cycles == 0)

    {

      int64_t ma = -INF;

      for (int j = 1; j <= min(K, cyc); j++)

      {

        ma = max(ma, scores[i].at(j));

      }

      maxs[i] = ma;

    }

    else

    {

      if (r == 0)

      {

        int64_t ma = -INF;

        for (int j = 1; j <= cyc; j++)

        {

          ma = max(ma, scores[i].at(j));

        }

        ma += (cycles - 1) * tot[i];

        maxs[i] = ma;

      }

      else

      {

        int64_t ma = 0;

        for (int j = 1; j <= r; j++)

        {

          ma = max(ma, scores[i].at(j));

        }

        ma += cycles * tot[i];

        maxs[i] = ma;

      }

    }

  }

  int64_t ans = -INF;

  for (int64_t i = 0; i < N; i++)

  {

    ans = max(ans, maxs[i]);

  }

  cout << ans << endl;

}