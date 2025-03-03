#include"stdc++.h"



using namespace std;



using int64 = long long;





int N, L, Q, X[100000];

int step[21][100000];



int main() {



  cin >> N;

  for(int i = 0; i < N; i++) {

    cin >> X[i];

  }

  cin >> L >> Q;



  int ptr = 0;

  for(int i = 0; i < N; i++) {

    while(ptr < N && X[i] + L >= X[ptr]) ++ptr;

    step[0][i] = ptr - 1;

  }

  for(int i = 1; i < 21; i++) {

    for(int j = 0; j < N; j++) {

      step[i][j] = step[i - 1][step[i - 1][j]];

    }

  }

  while(Q--) {

    int x, y;

    cin >> x >> y;

    --x, --y;

    if(x > y) swap(x, y);

    int ret = 0;

    for(int i = 20; i >= 0; i--) {

      if(step[i][x] < y) {

        ret |= 1 << i;

        x = step[i][x];

      }

    }

    cout << ret + 1 << endl;

  }



}