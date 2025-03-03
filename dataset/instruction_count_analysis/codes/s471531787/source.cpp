#include "stdc++.h"



#define FOR(i,a,b) for(long long i=(a);i<(b);++i)

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define all(x) (x).begin(),(x).end()



using namespace std;



int main(){

  long long b;

  while(true){

    cin >> b;

    if(b == 0) break;

    pair<int,int> ans;

    FOR(n,1, sqrt(2*b) ){

      //b = n(2a+n-1)/2

      //2b/n = 2a + n - 1

      // (2b/n - n + 1)/2 = a

      //cout << " n :" << n;

      long long a = ((2 * b) / n - n + 1) / 2;

      //cout << " a: " << a << endl;

      if((2 * b == n * (2*a + n - 1))  ){

        //cout << a << ' ' << a + n - 1 << endl;

        ans.first = a;

        ans.second = n;

      }

    }

    cout << ans.first << ' ' << ans.second << endl;

  }

  return 0;

}


