#include<iostream>

#include <algorithm>

using namespace std;



int N;



typedef long long ll;



ll T = 0,AO = 0,ans=0;



struct Data {

  ll  A[100000];

  ll  B[100000];

  ll  C[100000];

};



int main() {

  cin >> N;

  Data data;

  for ( int i = 0; i < 100000; i++ ) data.C[i] = 0;

  for ( int i = 0; i < N; i++ ) {

    cin >> data.A[i] >> data.B[i];

    data.C[i] = data.A[i] + data.B[i];

  }



  sort(data.C,data.C+N);



  for ( int i = 0; i < N; i++ ) ans -= data.B[i];

  

  for ( int i = N-1; i >= 0; i-=2 ) {

    ans += data.C[i];

  }



  cout << ans << endl;

  

  return 0;

}
