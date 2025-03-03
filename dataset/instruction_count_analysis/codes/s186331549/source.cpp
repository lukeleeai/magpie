#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;



int main() {

  int N, K;

  cin >> N >> K;



  vector cnt(K + 1, vector<int>(K + 1));

  rep(i, N) {

    int x, y, b;

    char c;

    cin >> x >> y >> c;

    if(c=='W')y += K;

    b = x / K % 2 == y / K % 2 ? 1 : -1;

    if(b > 0) cnt[0][0]++;

    int nx = x % K + 1, ny = y % K + 1;

    cnt[nx][0] -= b;

    cnt[0][ny] -= b;

    cnt[nx][ny] += b * 2;

  }

  rep(i, K + 1)rep(j, K)cnt[i][j + 1] += cnt[i][j];

  rep(j, K + 1)rep(i, K)cnt[i + 1][j] += cnt[i][j];

  int ans = 0;

  rep(i, K)rep(j, K)ans = max({ans, cnt[i][j], N - cnt[i][j]});

  cout << ans << endl;

}
