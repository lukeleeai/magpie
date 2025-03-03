#include "stdc++.h"

using namespace std;



typedef long long int ll;



ll MOD = 1000000007;

ll INF = 100000000;



int main(){

 int N,T;

 cin >> N >> T;

 int ans = INF;

 for(int i = 0;i < N;i++){

   int a,b;cin >> a >> b;

   if(b <= T)ans = min(ans,a);

 }

 if(ans == INF){

   cout << "TLE" << endl;

   return 0;

 }

 cout << ans << endl;

}
