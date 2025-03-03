#include "stdc++.h"

using namespace std;

using ll = long long;

using pii = pair<int, int>;



const ll INF = 1LL << 40;

int N, M;

int a[2010], b[2010], c[2010];

ll dis[1010];



int main() {

  cin.tie(0);

  ios_base::sync_with_stdio(false);

  cout << fixed << setprecision(10);

  

  cin >> N >> M;

  for (int i = 0; i < M; i++) {

    cin >> a[i] >> b[i] >> c[i];

    a[i]--; b[i]--;

    c[i] *= -1;

  }

  fill_n((ll*)dis, N, INF);

  dis[0] = 0;

  for (int t = 0; t < N; t++) {

    for (int i = 0; i < M; i++) {

      if (dis[a[i]] == INF) continue;

      if (dis[b[i]] > dis[a[i]] + c[i]) {

        dis[b[i]] = dis[a[i]] + c[i];

        if (t == N - 1 && b[i] == N - 1) {

          cout << "inf" << endl;

          return 0;

        }

      }

    }

  }

  cout << -dis[N - 1] << endl;



  return 0;

}