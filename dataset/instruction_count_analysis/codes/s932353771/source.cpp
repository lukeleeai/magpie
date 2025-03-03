#include <iostream>

using namespace std;

bool carry = false;

int main() {

  ios::sync_with_stdio(0);

  cin.tie(0);

  string S;

  cin >> S;

  int N = S.size();

  int ans = 0;

  for (int i = N; i >= 0; i--) {

    int n = S[i] - '0';

    if (carry) n++;

    switch(n){

    case 5:

      ans+=5;

      break;

    case 0:

    case 10:

      break;

    case 1:

    case 9:

      ans+=1;

      break;

    case 2:

    case 8:

      ans+=2;

      break;

    case 3:

    case 7:

      ans+=3;

      break;

    case 4:

    case 6:

      ans+=4;

      break;

    }

    carry = (n > 5 || (n == 5 && i > 0 && S[i-1] > '4'));

  }

  if (carry) ans++;

  cout << ans << '\n';

  return 0;

}

 