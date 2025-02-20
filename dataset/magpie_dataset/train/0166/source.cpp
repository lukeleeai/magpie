#include "stdc++.h"



using namespace std;



#define int long long

#define PB push_back

#define INF (1LL<<61LL)



typedef pair<int, int> pii;



int N, L, a[100005], dx[] = {-1, 1};

vector<int> g[100005];

bool flg[100005];



int cal(int x) {

  int res = L - a[x], temp = 0;

  for (int i = 0; i < g[x].size(); ++i) {

    temp = max(temp, cal(g[x][i]));

  }



  return res + temp;

}



signed main() {

  fill(a, a + 100005, INF);

  cin >> N >> L;

  for (int i = 1; i <= N; ++i)

    cin >> a[i];



  for (int i = 1; i <= N; ++i) {

    int count = 0;

    for (int j = 0; j < 2; ++j) {

      if (a[i + dx[j]] < a[i]) {

	g[i].PB(i + dx[j]);

	count++;

      }

    }



    if ((count == 2) || (((i == 1) || (i == N)) && (count == 1)))

      flg[i] = true;

  }



  int maxt = 0;

  for (int i = 1; i <= N; ++i) {

    if (!flg[i]) continue;

    maxt = max(maxt, cal(i));

  }



  cout << maxt << endl;

  

  return 0;

}