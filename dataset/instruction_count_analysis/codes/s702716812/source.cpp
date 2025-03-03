#include <iostream>

#include <string>

#include <vector> 

using namespace std;

 

int main() {

  ios::sync_with_stdio(false);

  int N, Q;

  string S;

  cin >> N >> Q >> S;

  

  vector<int> sum(S.size()+1, 0);

  // 0 0 1

  for(int i = 1; i < S.size(); i++)

    sum[i+1] = sum[i] + (S[i-1] == 'A' && S[i] == 'C');

  

  while(Q--) {

    int l, r;

    cin >> l >> r;

    cout << sum[r] - sum[l] << "\n";

  }

  return 0;

}