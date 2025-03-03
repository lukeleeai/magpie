#include"stdc++.h"



using namespace std;



int main(){

  int N;

  cin >> N;

  vector<int> P(N);

  vector<int> minP(N);

  cin >> P[0];

  minP[0] = P[0];

  for(int i = 1; i < N; i++){

    cin >> P[i];

    minP[i] = min(P[i], minP[i - 1]);

  }

  

  int cnt = 0;

  for(int i = 0; i < N; i++){

    if(minP[i] >= P[i]) cnt++;

  }

  

  cout << cnt << endl;

  

  return 0;

}