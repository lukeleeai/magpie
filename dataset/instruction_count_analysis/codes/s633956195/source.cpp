#include"stdc++.h"

using namespace std;

#define int long long

int N,answer;

int table[100000+10],ans[100000+10];

signed main(){

  cin >> N;

    for(int i=0;i<N;i++){

      int a,b;

      cin >> a >> b;

      a--,b--;

      table[a]++;

      table[b+1]--;

    }

    for(int i=1;i<=N;i++){

      ans[i]+=ans[i-1]+table[i];

      //cout << ans[i] << endl;

      if(i<=ans[i]) answer=i;

    }

    cout << answer << endl;

  return 0;

}


