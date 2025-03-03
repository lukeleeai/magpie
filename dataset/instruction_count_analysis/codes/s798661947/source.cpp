#include "stdc++.h"

using namespace std;

#define Rep(i,N) for(int i = 0; i < N; i++)



inline void chmax(int &a, int b) { a = max(a, b); }



int main()

{

  int N, M;

  int A[5005], B[5005];

  int maxv = 0;

  

  cin >> N >> M;

  Rep(i,N) cin >> A[i];

  Rep(i,M) cin >> B[i];

  

  Rep(i,M) {

    int now = i, cnt = 0;

    Rep(j,N) {

      if(A[j] == B[now])cnt++, now++;

    }

    chmax(maxv,cnt);

  }



  cout << maxv << endl;

  return 0;

}