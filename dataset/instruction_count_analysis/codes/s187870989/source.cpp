#include "stdc++.h"



using namespace std;



#define int long long

#define PB push_back

#define INF (1LL<<61LL)



typedef pair<int, int> pii;



int N, L, a[100005], dx[] = {-1, 1};

bool flg[100005];



int cal(int x) {

  int res = L - a[x], temp = 0;

  for (int i = 0; i < 2; ++i) {

    if (a[x] < a[x + dx[i]]) continue;

    temp = max(temp, cal(x + dx[i]));

  }



  return res + temp;

}



signed main() {

  fill(a, a + 100005, INF);

  cin >> N >> L;

  for (int i = 1; i <= N; ++i)

    cin >> a[i];



  int maxt = 0;

  for (int i = 1; i <= N; ++i) {

    int count = 0;

    for (int j = 0; j < 2; ++j) {

      if (a[i + dx[j]] < a[i]) {

	count++;

      }

    }



    if ((count == 2) || (((i == 1) || (i == N)) && (count == 1)))

      maxt = max(maxt, cal(i));

  }



  cout << maxt << endl;

  

  return 0;

}