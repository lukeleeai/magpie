#include "stdc++.h"

using namespace std;



int gcd(int a, int b) {

  if(b == 0) return a;

  else return gcd(b, a%b);

}



int main() {

  int N, K; cin >> N >> K;

  int g = -1, m = -1;

  for(int i=0; i<N; i++) {

    int p; cin >> p;

    if(i == 0) g = p;

    else g = gcd(g, p);

    m = max(m, p);

  }

  if(K % g == 0 && K <= m) cout << "POSSIBLE" << endl;

  else cout << "IMPOSSIBLE" << endl;

  return 0;

}
