#include "stdc++.h"



using namespace std;





int main() {

  string S;

  cin >> S;



  // グーのとき: 貯金が出来る

  // グーのとき: 貯金を使って利益を得る

  // パーのとき: 貯金が出来る

  // パーのとき: 貯金を使って利益を得る



  int ret = 0;

  for(auto &p : S) ret -= p == 'p';

  cout << ret + S.size() / 2 << endl;

}