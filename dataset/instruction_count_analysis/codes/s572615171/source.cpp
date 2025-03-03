#include "stdc++.h"



using namespace std;



int N, x[100001], L;

int r[22][100001];



int main()

{



  memset(r, -1, sizeof(r));



  cin >> N;

  for(int i = 0; i < N; i++) {

    cin >> x[i];

  }

  cin >> L;

  for(int i = 0; i < N; i++) {

    r[0][i] = upper_bound(x, x + N, x[i] + L) - x;

    --r[0][i];

  }

  r[0][N - 1] = N - 1;



  for(int k = 0; k < 21; k++) {

    for(int i = 0; i < N; i++) {

      if(r[k][i] < 0) r[k + 1][i] = -1;

      else r[k + 1][i] = r[k][r[k][i]];

    }

  }



  int Q;

  cin >> Q;

  while(Q--) {

    int u, v;

    cin >> u >> v;

    --u, --v;

    if(v > u) swap(u, v);

    int ret = 0, j = v;



    bool f = false;

    for(int k = 21; k >= 0; k--) {

      int j2 = r[k][j];

      if(j2 >= 0 && j2 < u) {

        j = j2;

        ret += 1 << k;

        if(r[0][j2] >= u) {

          cout << ret + 1 << endl;

          f = true;

          break;

        }

      }

    }

    if(!f) cout << 1 << endl;

  }

}
